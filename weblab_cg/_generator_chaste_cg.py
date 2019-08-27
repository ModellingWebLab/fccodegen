#
# Functions related to generating model code for Chaste.
#
import logging
import os
import sympy as sp
import enum
import time
import weblab_cg as cg
from functools import cmp_to_key

logging.getLogger().setLevel(logging.INFO)
MEMBRANE_VOLTAGE_INDEX = 0
CYTOSOLIC_CALCIUM_CONCENTRATION = 1

class ChasteModelType(enum.Enum):
    """ Enum used to indicate what type of model we have """
    Normal = 1
    Opt = 2
    CvodeAnalyticJ = 3
    CvodeNumericalJ = 4
    BE=5
  
def mkdir_p(path):
    """ Tries to create the path """
    try:
        os.makedirs(path)
    except:
        pass

def get_model_variable(model, var_name):
    try:
        var = model.get_symbol_by_cmeta_id(var_name)
    except:
        var = model.get_symbol_by_ontology_term("https://chaste.comlab.ox.ac.uk/cellml/ns/oxford-metadata",var_name)
    return var

def get_unique_names(model):
    """
    Creates unique names for all symbols in a CellML model.
    """
    # Component variable separator
    # Note that variables are free to use __ in their names too, it makes the
    # produced code less readable but doesn't break anything.
    sep = '__'

    # Create a symbol => name mapping, and a reverse name => symbol mapping
    symbols = {}
    reverse = {}

    def uname(name):
        """ Add an increasing number to a name until it's unique """
        root = name + '_'
        i = 0
        while name in reverse:
            i += 1
            name = root + str(i)
        return name

    for v in model.get_equation_graph():
        if isinstance(v, sp.Derivative):
            continue

        # Try simple name
        parts = v.name.split('$')
        assert len(parts) == 2
        #name = parts[-1]
        name = parts[0] + sep + parts[1]

        # If already taken, rename _both_ variables using component name
        if name in reverse:

            # Get existing variable
            other = reverse[name]

            # Check it hasn't been renamed already
            if symbols[other] == name:
                oparts = other.name.split('$')
                assert len(oparts) == 2
                oname = uname(oparts[0] + sep + oparts[1])
                symbols[other] = oname
                reverse[oname] = other

            # Get new name for v
            name = uname(parts[0] + sep + parts[1])

        # Store symbol name
        symbols[v] = name
        reverse[name] = v

    return symbols

def format_equation_list(printer, equations, model, units=None, secondary_units=None, secondary_unit_rhs_multiplier=""):
    """ Formats list of equations for printing to the chaset cpp.
    Arguments

    ``printer``
        The printer to can transform sympy equations
    ``euations``
        The list of equations to format
    ``model``
        A :class:`cellmlmanip.Model` object.
    ``units``
        Optional units to convert rhs to
    ``secondary_units``
        Optional secondary units to convert rhs to if conversion to units fails
    ``secondary_unit_rhs_multiplier``
        A string to add as multiplier to the rhs in case secondary_units conversion is applied
                
    """
    formatted_equations=[]
    rhs_multiplier = ""
    for equation in equations:
        eq = equation
        if not units is None:
            try:
                current_units = model.units.summarise_units(eq.lhs)
                factor = model.units.get_conversion_factor(1 * current_units, units)
                eq=sp.relational.Equality(eq.lhs, factor * eq.rhs)
            except:
                try:
                    #var_chaste_interface__membrane__stim_amplitude might be in different units and need multiplying with capacitance
                    if not secondary_units is None:
                        factor = model.units.get_conversion_factor(1 * current_units, secondary_units)
                        eq=sp.relational.Equality(eq.lhs, factor * eq.rhs)
                        rhs_multiplier=secondary_unit_rhs_multiplier
                except:
                    print("UNIT ERROR")
        formatted_equations.append({
            'lhs': printer.doprint(eq.lhs),
            'rhs': printer.doprint(eq.rhs)+ rhs_multiplier
        })
    return formatted_equations

def get_initial_value_comment(model, symbol):
    initial_value = str(model.get_initial_value(symbol))
    unit_name = str(model.units.summarise_units(symbol))
    return "// Units: "+unit_name+"; Initial value: "+initial_value

def create_chaste_model(path, model_name, model, model_type=ChasteModelType.Normal):
    """
    Takes a :class:`cellmlmanip.Model`, generates a ``.cpp`` and ``.cpp`` model 
    for use with Chaste, and stores it at ``path``.

    Arguments

    ``path``
        The path to store the generated model code at. (Just the path, excluding the file name as file name will be determined by the model_name)
    ``model_name``
        A name for the generated model.
    ``model``
        A :class:`cellmlmanip.Model` object.
    """
    #TODO: handle models with no metadata for embrane_voltage and cytosolic_calcium_concentration

    # First steps to generate files with the correct file name.
    path = os.path.join(path, model_type.name)
    
    #Make sure the folder exists for the type of model
    mkdir_p(path)
    
    #Add file name (based on model name)
    hhp_file_path = os.path.join(path, model_name+".hpp")

    #Add file name (based on model name)
    cpp_file_path = os.path.join(path, model_name+".cpp")

    # Add all neded units to the model (for conversion) if they don't yet exist
    try:
        model.units.add_custom_unit('uA_per_cm2', [{'prefix': 'micro', 'units': 'ampere'}, {'exponent': '-2', 'prefix': 'centi', 'units': 'metre'}])
    except:
        pass #unit already exists
    try:
        model.units.add_custom_unit('uA_per_uF', [{'prefix': 'micro', 'units': 'ampere'}, {'exponent': '-1', 'prefix': 'micro', 'units': 'farad'}])
    except:
        pass #unit already exists        
    try:
        model.units.add_custom_unit('ms', [{'prefix': 'milli', 'units': 'second'}])
    except:
        pass #unit already exists

    # Set up printer to be able to write equations   
    # Get unique names for all symbols
    unames = get_unique_names(model)

    # Symbol naming function
    def symbol_name(symbol, prefix = "chaste_interface__"):
        return 'var_' + prefix + unames[symbol]

    # Derivative naming function
    def derivative_name(deriv):
        var = deriv.expr if isinstance(deriv, sp.Derivative) else deriv
        return 'd_dt_' + unames[var]

    printer = cg.WebLabPrinter(symbol_name, derivative_name)

    if model_type == ChasteModelType.Normal :
        # Check if the model has cytosolic_calcium_concentration, if so we need to add GetIntracellularCalciumConcentration, otherwise leave blank
        try:
            get_model_variable(model, "cytosolic_calcium_concentration")
            use_get_intracellular_calcium_concentration = True
        except:
            use_get_intracellular_calcium_concentration = False

        #Output a default cell stimulus from the metadata specification as long as the following metadata exists:
        # * membrane_stimulus_current_amplitude
        # * membrane_stimulus_current_period         
        # * membrane_stimulus_current_duration 
        # * optionally: offset and end
        # Ensures that the amplitude of the generated RegularStimulus is negative.
        cellml_default_stimulus_equations = None
        try:
            cellml_default_stimulus_equations = dict()
            #todo: apply unit conversions
            # * period     // millisecond
            # * duration   // millisecond
            # * amplitude  // uA_per_cm2
            # * offset     // millisecond
            # * end     // millisecond

            #start, period, duration, amplitude
            cellml_default_stimulus_equations['period'] = format_equation_list(printer, model.get_equations_for([get_model_variable(model, "membrane_stimulus_current_period")]) , model, model.units.ureg.ms)
            cellml_default_stimulus_equations['duration'] =  format_equation_list(printer, model.get_equations_for([get_model_variable(model, "membrane_stimulus_current_duration")]) , model, model.units.ureg.ms)
            cellml_default_stimulus_equations['amplitude'] =  format_equation_list(printer, model.get_equations_for([get_model_variable(model, "membrane_stimulus_current_amplitude")]) , model, model.units.ureg.uA_per_cm2, model.units.ureg.uA_per_uF, " * HeartConfig::Instance()->GetCapacitance()")
           
        except:
            cellml_default_stimulus_equations = None
            print("No default_stimulus_equations\n")

        #optional default_stimulus_equation offset
        try:
            cellml_default_stimulus_equations['offset'] =  format_equation_list(printer, model.get_equations_for([get_model_variable(model, "membrane_stimulus_current_offset")]) , model, model.units.ureg.ms)
        except:
            pass #offset is optional

        #optional default_stimulus_equation end         
        try:
            cellml_default_stimulus_equations['end'] =  format_equation_list(printer, model.get_equations_for([get_model_variable(model, "membrane_stimulus_current_end")]) , model, model.units.ureg.ms)
        except:
            pass #end is optional

        # get state variables
        state_vars = model.get_state_symbols()

        #function used to order state variables in the same way as pycml does (for easy comparison)
        def state_var_key_order(membrane_voltage_var, cai_var, var):
            if var == membrane_voltage_var:
                return MEMBRANE_VOLTAGE_INDEX
            elif var == cai_var:
                return CYTOSOLIC_CALCIUM_CONCENTRATION
            else:
                return MEMBRANE_VOLTAGE_INDEX + CYTOSOLIC_CALCIUM_CONCENTRATION + 1

        membrane_voltage_var = get_model_variable(model, "membrane_voltage")
        try:
            cytosolic_calcium_concentration_var = get_model_variable(model, "cytosolic_calcium_concentration")
        except:
            cytosolic_calcium_concentration_var = None
            print("MODEL HAS NO cytosolic_calcium_concentration VARIABLE")
        state_vars = sorted(state_vars,key=lambda state_var: state_var_key_order(membrane_voltage_var, cytosolic_calcium_concentration_var, state_var))

        #Get the initial values and units as comment for the chanste output
        initial_value_comments_state_vars = [get_initial_value_comment(model, var) for var in state_vars]

        #Format the state variables
        state_vars = [printer.doprint(var) for var in state_vars]

        # Generate hpp for model
        template = cg.load_template('chaste', 'normal_model.hpp')
        with open(hhp_file_path, 'w') as f:
            f.write(template.render({
                'ucase_model_name': model_name.upper(),
                'model_name': model_name,
                'generation_date': time.strftime('%Y-%m-%d %H:%M:%S'),
                'cellml_default_stimulus_equations':cellml_default_stimulus_equations,
                'use_get_intracellular_calcium_concentration':use_get_intracellular_calcium_concentration,
            }))

        # Generate cpp for model
        template = cg.load_template('chaste', 'normal_model.cpp')
        with open(cpp_file_path, 'w') as f:
            f.write(template.render({
                'model_name': model_name,        
                'generation_date': time.strftime('%Y-%m-%d %H:%M:%S'),
                'cellml_default_stimulus_equations':cellml_default_stimulus_equations,
                'use_get_intracellular_calcium_concentration':use_get_intracellular_calcium_concentration,
                'membrane_voltage_index':MEMBRANE_VOLTAGE_INDEX,
                'cytosolic_calcium_concentration_index':CYTOSOLIC_CALCIUM_CONCENTRATION,
                'state_vars': state_vars,
                'initial_value_comments_state_vars':initial_value_comments_state_vars,
            }))

    elif model_type == ChasteModelType.Opt:
        pass

    elif model_type == ChasteModelType.CvodeAnalyticJ:
        pass

    elif model_type == ChasteModelType.CvodeNumericalJ:
        pass

    elif model_type == ChasteModelType.BE:
        pass