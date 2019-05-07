# cython: profile=True
#
#
# Web Lab model {{model_name}}
#
# Generated by {{generator_name}} on {{generation_date}}
#
#
#
cimport fc.sundials.sundials as Sundials
cimport libc.math as math
cimport numpy as np

import numpy as np
import os
import shutil
import sys

import fc.language.values as V
from fc.environment import ModelWrapperEnvironment
from fc.error_handling import ProtocolError
from fc.sundials.solver cimport CvodeSolver


cdef int _evaluate_rhs(Sundials.realtype {{ free_variable }},
                       Sundials.N_Vector y,
                       Sundials.N_Vector ydot,
                       void* user_data):
    """
    Cython wrapper around a model RHS that uses numpy, for calling by CVODE.

    See :meth:`fc.sundials.solver._evaluate_rhs()`.
    """
    # We passed the Python model object in as CVODE user data; get it back as an object
    model = <object>user_data
    cdef np.ndarray[Sundials.realtype, ndim=1] parameters = <np.ndarray>model.parameters

    # Unpack state variables
    {%- for state in states %}
    cdef double {{state.var_name}} = (<Sundials.N_VectorContent_Serial>y.content).data[{{state.index}}]
    {%- endfor %}

    # Mathematics
    {%- for eq in rhs_equations %}
    {%- if eq.parameter_index is none %}
    cdef double {{ eq.lhs }} = {{ eq.rhs }}
    {%- else %}
    cdef double {{ eq.lhs }} = parameters[{{ eq.parameter_index }}]
    {%- endif %}
    {%- endfor %}

    # Pack state variable derivatives
    {%- for state in states %}
    (<Sundials.N_VectorContent_Serial>ydot.content).data[{{state.index}}] = {{state.deriv_name}}
    {%- endfor %}


cdef class {{ class_name }}(CvodeSolver):

    # The name of the free variable, for use in the ModelWrapperEnvironment
    # From: fc.simulations.AbstractOdeModel
    cdef public char* free_variable_name

    # The value of the free variable
    # From: fc.simulations.AbstractOdeModel
    cdef public double free_variable

    # A mapping from variable name to index within the state variable vector,
    # for use in the ModelWrapperEnvironment
    # From: fc.simulations.AbstractOdeModel
    cdef public object state_var_map

    # A numpy array containing initial values for the state variables
    # From: fc.simulations.AbstractOdeModel
    cdef public np.ndarray initial_state

    # A mapping from parameter name to index within the parameters vector, for
    # use in the ModelWrapperEnvironment
    # From: fc.simulations.AbstractOdeModel
    cdef public object parameter_map

    # A numpy array containing model parameter values
    # From: fc.simulations.AbstractOdeModel
    cdef public np.ndarray parameters

    # An ordered list of the names of the model outputs, as they will be
    # returned by get_outputs
    # From: fc.simulations.AbstractOdeModel
    cdef public object output_names

    # Mapping from names to saved model states.
    # From: fc.simulations.AbstractOdeModel
    cdef public object saved_states

    # Maps qualified variable names to model variables (outputs, states,
    # parameters, or the free variable).
    # From: fc.simulations.AbstractOdeModel
    # See: fc.environment.ModelWrapperEnvironment
    cdef public object env

    # True if the solver needs to be reset due to a model change made in the
    # ModelWrapperEnvironment.
    # From: fc.simulations.AbstractOdeModel
    cdef public bint dirty

    # Environment for the simulation running this model. Mainly useful when
    # evaluating set_variable() type modifiers during the course of a
    # simulation.

    # Where to write protocol outputs, error logs, etc.
    # From: fc.simulations.AbstractModel
    cdef public char* output_path

    # Level of indentation to use for progress output.
    # From: fc.simulations.AbstractModel
    cdef public object indent_level

    # Link to generated module.
    # Set in: fc.protocol.Protocol
    # Note: Nobody seems to ever access this variable. Seems this is just to
    # prevent garbage collection.
    cdef public object _module

    # TODO: Not sure if needed
    cdef public object sim_env

    # Cached list of output values (single values or vectors e.g. the state) to
    # avoid recreating a list every time output is returned.
    cdef public object _outputs

    # Seems to be unused at the moment
    #cdef Sundials.N_Vector _parameters

    def __init__(self):
        self.free_variable_name = "time"
        self.free_variable = 0.0

        # State values
        self.state = np.zeros({{ states|length }})

        # Mapping from qualified names to state indices; only for states that
        # have a variable name.
        self.state_var_map = {}
        {%- for state in states %}
        {%- endfor %}

        # Initial state
        self.initial_state = np.zeros({{ states|length }})
        {%- for state in states %}
        self.initial_state[{{ state.index }}] = {{ state.initial_value }}
        {%- endfor %}

        # Mapping of parameter qualified names to parameter array indices
        self.parameter_map = {}
        {%- for parameter in parameters %}
        self.parameter_map['{{ parameter.annotation[1] }}'] = {{ parameter.index }}
        {%- endfor %}

        # Initial parameter values
        self.parameters = np.zeros({{ parameters|length }})
        {%- for parameter in parameters %}
        self.parameters[{{ parameter.index }}] = {{ parameter.initial_value }}
        {%- endfor %}

        # Local names of output variables
        self.output_names = []
        {%- for output in outputs %}
        {%- if output.length is none %}
        self.output_names.append('{{ output.annotation[1] }}')
        {%- else %}
        self.output_names.append('{{ output.annotation }}')
        {%- endif %}
        {%- endfor %}

        # Create and cache list of arrays, to avoid constant list/array
        # creation
        self._outputs = []
        {%- for output in outputs %}
        {%- if output.length is none %}
        self._outputs.append(np.array(0.0))
        {%- else %}
        self._outputs.append(np.zeros({{ output.length }}))
        {%- endif %}
        {%- endfor %}
        # TODO Handle vector outputs other than state_variable

        self.state = self.initial_state.copy()
        self.saved_states = {}
        self.dirty = False
        self.indent_level = 0
        self.associate_with_model(self)
        #self._parameters = Sundials.N_VMake_Serial(
        #    len(self.parameters),
        #    <Sundials.realtype*>(<np.ndarray>self.parameters).data
        #)
        self.env = ModelWrapperEnvironment(self)

    #def __dealloc__(self):
    #    if self._parameters != NULL:
    #        Sundials.N_VDestroy_Serial(self._parameters)

    def get_environment_map(self):
        """
        Get a map from ontology prefix to the environment containing model
        variables annotated with that ontology.

        See :meth:`fc.simulations.AbstractOdeModel.get_environment_map()`.
        """
        # TODO Some part of this might need to be generated
        return {
            'pycml': self.env,
            'cmeta': self.env,
            'cg': self.env,
            'csub': self.env,
            'cs': self.env,
            'oxmeta': self.env,
            'lut': self.env,
            'proto': self.env,
            'None': self.env,
            'bqs': self.env,
            'pe': self.env,
            'dcterms': self.env,
            'xml': self.env,
            'dc': self.env,
            'bqbiol': self.env,
            'cml': self.env,
            'solver': self.env,
            'doc': self.env,
            'm': self.env,
            'rdf': self.env,
            'cellml': self.env,
            'vCard': self.env,
        }

    cpdef get_outputs(self):
        """
        Return a list of the model's outputs at its current state.

        NB: this should return a Python list containing the model outputs as
        numpy arrays, not subclasses of V.AbstractValue.
        The order of outputs in this list must match self.output_names, a list
        of the output names, which must be set by subclass constructors.

        See :meth:`fc.simulations.AbstractModel.get_outputs()`.
        """

        # Get parameters as sundials realtype numpy array
        cdef np.ndarray[Sundials.realtype, ndim=1] parameters = self.parameters

        # Get current free variable
        cdef double {{ free_variable }} = self.free_variable

        # Unpack state variables
        {%- for state in states %}
        cdef double {{state.var_name}} = self.state[{{state.index}}]
        {%- endfor %}

        # Mathematics
        {%- for eq in output_equations %}
        {%- if eq.parameter_index is none %}
        cdef double {{ eq.lhs }} = {{ eq.rhs }}
        {%- else %}
        cdef double {{ eq.lhs }} = parameters[{{ eq.parameter_index }}]
        {%- endif %}
        {%- endfor %}

        # Update output vector and return
        outputs = self._outputs
        {%- for output in outputs %}
        {%- if output.parameter_index is none %}
        {%-   if output.length is none %}
        outputs[{{ output.index }}][()] = {{ output.var_name }}
        {%-   else %}
        {%-     for sub_output in output.var_name %}
        outputs[{{ output.index }}][{{ sub_output.index }}] = {{ sub_output.var_name }}
        {%-     endfor %}
        {%-   endif %}
        {%- else %}
        outputs[{{ output.index }}][()] = parameters[{{ output.parameter_index }}]
        {%- endif %}
        {%- endfor %}
        return outputs

    cpdef reset_state(self, name=None):
        """
        Reset the model to the given named saved state, or to initial
        conditions if no name given.

        See :meth:`fc.simulations.AbstractOdeModel.reset_state()`.
        """
        if name is None:
            CvodeSolver.reset_solver(self, self.initial_state)
        else:
            CvodeSolver.reset_solver(self, self.saved_states[name])

    def save_state(self, name):
        """
        Save a copy of the current model state associated with the given name,
        to be restored using :meth:`reset_state()`.

        See :meth:`fc.simulations.AbstractOdeModel.save_state()`.
        """
        self.saved_states[name] = self.state.copy()

    cpdef set_free_variable(self, double t):
        """
        Set the value of the free variable (typically time), but retain the
        model's current state.

        See :meth:`fc.simulations.AbstractOdeModel.set_free_variable()`.
        """
        self.free_variable = t
        CvodeSolver.set_free_variable(self, t)

    def set_indent_level(self, indent_level):
        """
        Set the level of indentation to use for progress output.

        See :meth:`fc.simulations.AbstractModel.set_indent_level()`.
        """
        self.indent_level = indent_level

    def set_output_folder(self, path):
        # TODO This is undocumented in fc
        if os.path.isdir(path) and path.startswith('/tmp'):
            shutil.rmtree(path)
        os.mkdir(path)
        self.output_path = path

    def set_rhs_wrapper(self):
        flag = Sundials.CVodeInit(
            self.cvode_mem, _evaluate_rhs, 0.0, self._state)
        self.check_flag(flag, 'CVodeInit')

    def set_solver(self, solver):
        """
        Specify the ODE solver to use for this model.

        See :meth:`fc.simulations.AbstractOdeModel.set_solver()`.
        """
        # TODO Update this (and rest of fc) to Python3
        # TODO Use logging here, or raise an exception
        print >>sys.stderr, '  ' * self.indent_level, 'set_solver: Models implemented using Cython contain a built-in ODE solver, so ignoring setting.'

