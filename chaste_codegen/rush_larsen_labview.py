from functools import partial

from sympy.codegen.rewriting import Wild

from chaste_codegen._linearity_check import get_non_linear_state_vars, subst_deriv_eqs_non_linear_vars
from chaste_codegen._partial_eval import partial_eval
from chaste_codegen.rush_larsen_model import RushLarsenModel
from chaste_codegen._labview_printer import LabviewPrinter
from sympy import Derivative, Piecewise, Eq
from chaste_codegen.model_with_conversions import get_equations_for, add_conversions, get_cytosolic_calcium_concentration_var, get_membrane_voltage_var
import networkx as nx
from cellmlmanip.model import Variable
from chaste_codegen._rdf import OXMETA
from sympy.codegen.rewriting import log1p_opt
import chaste_codegen as cg


def get_variable_name(s, interface=False):
    """Get the correct variable name based on the variable and whether it should be in the chaste_interface."""
    s_name = s.expr if isinstance(s, Derivative) else s
    s_name = str(s_name).replace('$', '__')

    if isinstance(s, Derivative):
        return 'd_dt_' + s_name
    else:
        return s_name

class RushLarsenLabview(RushLarsenModel):
    """ Holds template and information specific for the RushLarsen model type"""

    DEFAULT_EXTENSIONS = ('.h', '.m')
    
    def __init__(self, model, file_name, **kwargs):
        cg._optimize.LOG_OPTIMS = tuple(o for o in cg._optimize.LOG_OPTIMS if o != log1p_opt)

        add_conversions(model, use_modifiers=False, skip_chaste_stimulus_conversion=True)
        
        # For equations containing a piecewise not at the top level, pull it out into it's own equation
        for eq in tuple(model.equations):
            # Piecewises cannot be inline, so attach each to a new variable
            if eq.has(Piecewise):
                if eq.rhs.has(Piecewise) and (not isinstance(eq.rhs, Piecewise) or len(eq.rhs.atoms(Piecewise)) > 1):
                    new_rhs = eq.rhs
                    for i, pw in enumerate(eq.rhs.atoms(Piecewise)):
                        new_pw_lhs = model.add_variable(eq.lhs.name + '_PW_' + str(i), eq.lhs.units)
                        model.add_equation(Eq(new_pw_lhs, pw))
                        new_rhs = new_rhs.replace(pw, new_pw_lhs)
                    model.remove_equation(eq)
                    model.add_equation(Eq(eq.lhs, new_rhs))


        super().__init__(model, file_name, **kwargs)
        self._cpp_template = 'labview.m'
        self._hpp_template = 'labview.h'        
        
        self._vars_for_template['model_type'] = 'RushLarsenLabview'

    def _add_printers(self, lookup_table_function=lambda e: None):
        """ Initialises Printers for outputting chaste code. """
        # Printer for printing chaste regular variable assignments (var_ prefix)
        # Print variables in interface as var_chaste_interface
        # (state variables, time, lhs of default_stimulus eqs, i_ionic and lhs of y_derivatives)
        # Print modifiable parameters as mParameters[index]
        self._printer = \
            LabviewPrinter(lambda variable:
                           get_variable_name(variable, variable in self._in_interface)
                           if variable not in self._model.modifiable_parameters
                           else self._print_modifiable_parameters(variable),
                           lambda deriv: get_variable_name(deriv),
                           lookup_table_function)

        # Printer for printing variable in comments e.g. for ode system information
        self._name_printer = LabviewPrinter(lambda variable: get_variable_name(variable))

    def _print_rhs_with_modifiers(self, modifier, eq, modifiers_with_defining_eqs=set()):
        """ Print modifiable parameters in the correct format for the model type"""
        return self._printer.doprint(eq)#?

    def _print_modifiable_parameters(self, variable):
        """ Print modifiable parameters in the correct format for the model type"""
        return get_variable_name(variable)#?

    def format_derivative_equation(self, eq, modifiers_with_defining_eqs):
        """ Format an individual derivative equation
            specified so that other model types can specify more detailed printing """
        formatted_eq = super().format_derivative_equation(eq, modifiers_with_defining_eqs)
        formatted_eq['is_piecewise'] = isinstance(eq.rhs, Piecewise)
        if formatted_eq['is_piecewise']:
            formatted_eq['pw_expr_conds'] = [(self._printer.doprint(a[0]), self._printer.doprint(a[1])) for a in eq.rhs.args]
        return formatted_eq

#in/out
#+i_inj