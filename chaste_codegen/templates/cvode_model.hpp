#ifdef CHASTE_CVODE
{% include "Normal/hpp/header_comments" %}
{% include "Normal/hpp/includes" %}
{% include "Cvode/hpp/class_def" %}
{% include "Normal/hpp/DefaultStimulus_IntracellularCalciumConcentration" %}
    {{class_name}}(boost::shared_ptr<AbstractIvpOdeSolver> pOdeSolver /* unused; should be empty */, boost::shared_ptr<AbstractStimulusFunction> pIntracellularStimulus);
{% include "Normal/hpp/destructor_verify_state_variables_GetIIonic" %}
    void EvaluateYDerivatives(double {{free_variable.var_name}}, const N_Vector rY, N_Vector rDY);
    {%- if derived_quantities|length > 0 %}
    N_Vector ComputeDerivedQuantities(double {{free_variable.var_name}}, const N_Vector & rY);
    {%- endif %}
    {%- if jacobian_equations|length > 0 %}
    void EvaluateAnalyticJacobian(double {{free_variable.var_name}}, N_Vector rY, N_Vector rDY, CHASTE_CVODE_DENSE_MATRIX rJacobian, N_Vector rTmp1, N_Vector rTmp2, N_Vector rTmp3);
    {%- endif %}
};
{% include "Normal/hpp/CHASTE_CLASS_EXPORT" %}
#endif // CHASTE_CVODE
