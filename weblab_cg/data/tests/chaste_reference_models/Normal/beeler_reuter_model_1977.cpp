//! @file
//! 
//! This source file was generated from CellML.
//! 
//! Model: beeler_reuter_model_1977
//! 
//! Processed by pycml - CellML Tools in Python
//!     (translators: , pycml: , optimize: )
//! on Wed Sep 11 11:14:43 2019
//! 
//! <autogenerated>

#include "beeler_reuter_model_1977.hpp"
#include <cmath>
#include <cassert>
#include <memory>
#include "Exception.hpp"
#include "OdeSystemInformation.hpp"
#include "RegularStimulus.hpp"
#include "HeartConfig.hpp"
#include "IsNan.hpp"
#include "MathsCustomFunctions.hpp"

    boost::shared_ptr<RegularStimulus> Dynamicbeeler_reuter_model_1977FromCellML::UseCellMLDefaultStimulus()
    {
        // Use the default stimulus specified by CellML metadata
        const double var_chaste_interface__stimulus_protocol__IstimStart = 10.0; // millisecond
        const double var_stimulus_protocol__IstimAmplitude = 0.5; // uA_per_mm2
        const double var_chaste_interface__stimulus_protocol__IstimPeriod = 1000.0; // millisecond
        const double var_chaste_interface__stimulus_protocol__IstimPulseDuration = 1.0; // millisecond
        const double var_chaste_interface__stimulus_protocol__IstimAmplitude_converter = var_stimulus_protocol__IstimAmplitude; // uA_per_mm2
        const double var_chaste_interface__stimulus_protocol__IstimAmplitude = 100.0 * var_chaste_interface__stimulus_protocol__IstimAmplitude_converter; // uA_per_cm2
        boost::shared_ptr<RegularStimulus> p_cellml_stim(new RegularStimulus(
                -fabs(var_chaste_interface__stimulus_protocol__IstimAmplitude),
                var_chaste_interface__stimulus_protocol__IstimPulseDuration,
                var_chaste_interface__stimulus_protocol__IstimPeriod,
                var_chaste_interface__stimulus_protocol__IstimStart
                ));
        mpIntracellularStimulus = p_cellml_stim;
        return p_cellml_stim;
    }
    
    double Dynamicbeeler_reuter_model_1977FromCellML::GetIntracellularCalciumConcentration()
    {
        return mStateVariables[1];
    }
    
    Dynamicbeeler_reuter_model_1977FromCellML::Dynamicbeeler_reuter_model_1977FromCellML(boost::shared_ptr<AbstractIvpOdeSolver> pSolver, boost::shared_ptr<AbstractStimulusFunction> pIntracellularStimulus)
        : AbstractCardiacCell(
                pSolver,
                8,
                0,
                pIntracellularStimulus)
    {
        // Time units: millisecond
        // 
        this->mpSystemInfo = OdeSystemInformation<Dynamicbeeler_reuter_model_1977FromCellML>::Instance();
        Init();

        // We have a default stimulus specified in the CellML file metadata
        this->mHasDefaultStimulusFromCellML = true;
    }
    
    Dynamicbeeler_reuter_model_1977FromCellML::~Dynamicbeeler_reuter_model_1977FromCellML()
    {
    }
    
    double Dynamicbeeler_reuter_model_1977FromCellML::GetIIonic(const std::vector<double>* pStateVariables)
    {
        // For state variable interpolation (SVI) we read in interpolated state variables,
        // otherwise for ionic current interpolation (ICI) we use the state variables of this model (node).
        if (!pStateVariables) pStateVariables = &rGetStateVariables();
        const std::vector<double>& rY = *pStateVariables;
        double var_chaste_interface__membrane__V = (mSetVoltageDerivativeToZero ? this->mFixedVoltage : rY[0]);
        // Units: millivolt; Initial value: -84.624
        double var_chaste_interface__slow_inward_current__Cai = rY[1];
        // Units: millimolar; Initial value: 1e-4
        double var_chaste_interface__sodium_current_m_gate__m = rY[2];
        // Units: dimensionless; Initial value: 0.011
        double var_chaste_interface__sodium_current_h_gate__h = rY[3];
        // Units: dimensionless; Initial value: 0.988
        double var_chaste_interface__sodium_current_j_gate__j = rY[4];
        // Units: dimensionless; Initial value: 0.975
        double var_chaste_interface__slow_inward_current_d_gate__d = rY[5];
        // Units: dimensionless; Initial value: 0.003
        double var_chaste_interface__slow_inward_current_f_gate__f = rY[6];
        // Units: dimensionless; Initial value: 0.994
        double var_chaste_interface__time_dependent_outward_current_x1_gate__x1 = rY[7];
        // Units: dimensionless; Initial value: 0.0001
        
        const double var_sodium_current__E_Na = 50.0; // mV
        const double var_sodium_current__m = var_chaste_interface__sodium_current_m_gate__m; // dimensionless
        const double var_sodium_current__j = var_chaste_interface__sodium_current_j_gate__j; // dimensionless
        const double var_sodium_current__h = var_chaste_interface__sodium_current_h_gate__h; // dimensionless
        const double var_sodium_current__g_Nac = 3.0000000000000001e-05; // mS_per_mm2
        const double var_sodium_current__V = var_chaste_interface__membrane__V; // mV
        const double var_sodium_current__g_Na = 0.040000000000000001; // mS_per_mm2
        const double var_sodium_current__i_Na = ((var_sodium_current__g_Na * pow(var_sodium_current__m, 3.0) * var_sodium_current__h * var_sodium_current__j) + var_sodium_current__g_Nac) * (var_sodium_current__V - var_sodium_current__E_Na); // uA_per_mm2
        const double var_slow_inward_current__d = var_chaste_interface__slow_inward_current_d_gate__d; // dimensionless
        const double var_slow_inward_current__g_s = 0.00089999999999999998; // mS_per_mm2
        const double var_slow_inward_current__f = var_chaste_interface__slow_inward_current_f_gate__f; // dimensionless
        const double var_slow_inward_current__V = var_chaste_interface__membrane__V; // mV
        const double var_slow_inward_current__Cai = var_chaste_interface__slow_inward_current__Cai; // concentration_units
        const double var_slow_inward_current__E_s = (-82.299999999999997) - (13.028700000000001 * log(var_slow_inward_current__Cai * 0.001)); // mV
        const double var_slow_inward_current__i_s = var_slow_inward_current__g_s * var_slow_inward_current__d * var_slow_inward_current__f * (var_slow_inward_current__V - var_slow_inward_current__E_s); // uA_per_mm2
        const double var_time_dependent_outward_current__x1 = var_chaste_interface__time_dependent_outward_current_x1_gate__x1; // dimensionless
        const double var_time_dependent_outward_current__V = var_chaste_interface__membrane__V; // mV
        const double var_time_dependent_outward_current__i_x1 = (var_time_dependent_outward_current__x1 * 0.0080000000000000002 * (exp(0.040000000000000001 * (var_time_dependent_outward_current__V + 77.0)) - 1.0)) / exp(0.040000000000000001 * (var_time_dependent_outward_current__V + 35.0)); // uA_per_mm2
        const double var_time_independent_outward_current__V = var_chaste_interface__membrane__V; // mV
        const double var_time_independent_outward_current__i_K1 = 0.0035000000000000001 * (((4.0 * (exp(0.040000000000000001 * (var_time_independent_outward_current__V + 85.0)) - 1.0)) / (exp(0.080000000000000002 * (var_time_independent_outward_current__V + 53.0)) + exp(0.040000000000000001 * (var_time_independent_outward_current__V + 53.0)))) + ((0.20000000000000001 * (var_time_independent_outward_current__V + 23.0)) / (1.0 - exp((-0.040000000000000001) * (var_time_independent_outward_current__V + 23.0))))); // uA_per_mm2
        const double var_chaste_interface__time_dependent_outward_current__i_x1 = var_time_dependent_outward_current__i_x1; // uA_per_mm2
        const double var_chaste_interface__sodium_current__i_Na = var_sodium_current__i_Na; // uA_per_mm2
        const double var_chaste_interface__slow_inward_current__i_s = var_slow_inward_current__i_s; // uA_per_mm2
        const double var_chaste_interface__time_independent_outward_current__i_K1 = var_time_independent_outward_current__i_K1; // uA_per_mm2
        const double var_chaste_interface__i_ionic = (100.0 * var_chaste_interface__sodium_current__i_Na) + (100.0 * var_chaste_interface__slow_inward_current__i_s) + (100.0 * var_chaste_interface__time_dependent_outward_current__i_x1) + (100.0 * var_chaste_interface__time_independent_outward_current__i_K1); // uA_per_cm2
        
        const double i_ionic = var_chaste_interface__i_ionic;
        EXCEPT_IF_NOT(!std::isnan(i_ionic));
        return i_ionic;
    }
    
    void Dynamicbeeler_reuter_model_1977FromCellML::EvaluateYDerivatives(double var_chaste_interface__environment__time, const std::vector<double>& rY, std::vector<double>& rDY)
    {
        // Inputs:
        // Time units: millisecond
        double var_chaste_interface__membrane__V = (mSetVoltageDerivativeToZero ? this->mFixedVoltage : rY[0]);
        // Units: millivolt; Initial value: -84.624
        double var_chaste_interface__slow_inward_current__Cai = rY[1];
        // Units: millimolar; Initial value: 1e-4
        double var_chaste_interface__sodium_current_m_gate__m = rY[2];
        // Units: dimensionless; Initial value: 0.011
        double var_chaste_interface__sodium_current_h_gate__h = rY[3];
        // Units: dimensionless; Initial value: 0.988
        double var_chaste_interface__sodium_current_j_gate__j = rY[4];
        // Units: dimensionless; Initial value: 0.975
        double var_chaste_interface__slow_inward_current_d_gate__d = rY[5];
        // Units: dimensionless; Initial value: 0.003
        double var_chaste_interface__slow_inward_current_f_gate__f = rY[6];
        // Units: dimensionless; Initial value: 0.994
        double var_chaste_interface__time_dependent_outward_current_x1_gate__x1 = rY[7];
        // Units: dimensionless; Initial value: 0.0001
        
        
        // Mathematics
        double d_dt_chaste_interface__membrane__V;
        const double var_sodium_current__m = var_chaste_interface__sodium_current_m_gate__m; // dimensionless
        const double var_sodium_current__j = var_chaste_interface__sodium_current_j_gate__j; // dimensionless
        const double var_sodium_current__h = var_chaste_interface__sodium_current_h_gate__h; // dimensionless
        const double var_sodium_current__V = var_chaste_interface__membrane__V; // mV
        const double var_slow_inward_current__d = var_chaste_interface__slow_inward_current_d_gate__d; // dimensionless
        const double var_slow_inward_current__g_s = 0.00089999999999999998; // mS_per_mm2
        const double var_slow_inward_current__f = var_chaste_interface__slow_inward_current_f_gate__f; // dimensionless
        const double var_slow_inward_current__V = var_chaste_interface__membrane__V; // mV
        const double var_slow_inward_current__Cai = var_chaste_interface__slow_inward_current__Cai; // concentration_units
        const double var_slow_inward_current__E_s = (-82.299999999999997) - (13.028700000000001 * log(var_slow_inward_current__Cai * 0.001)); // mV
        const double var_slow_inward_current__i_s = var_slow_inward_current__g_s * var_slow_inward_current__d * var_slow_inward_current__f * (var_slow_inward_current__V - var_slow_inward_current__E_s); // uA_per_mm2
        const double var_time_dependent_outward_current__x1 = var_chaste_interface__time_dependent_outward_current_x1_gate__x1; // dimensionless
        const double var_time_dependent_outward_current__V = var_chaste_interface__membrane__V; // mV
        const double var_sodium_current_m_gate__V = var_sodium_current__V; // mV
        const double var_sodium_current_m_gate__alpha_m = ((-1.0) * (var_sodium_current_m_gate__V + 47.0)) / (exp((-0.10000000000000001) * (var_sodium_current_m_gate__V + 47.0)) - 1.0); // per_ms
        const double var_sodium_current_m_gate__m = var_sodium_current__m; // dimensionless
        const double var_sodium_current_m_gate__beta_m = 40.0 * exp((-0.056000000000000001) * (var_sodium_current_m_gate__V + 72.0)); // per_ms
        const double var_sodium_current_m_gate__d_m_d_environment__time = (var_sodium_current_m_gate__alpha_m * (1.0 - var_sodium_current_m_gate__m)) - (var_sodium_current_m_gate__beta_m * var_sodium_current_m_gate__m); // 'per millisecond'
        const double var_sodium_current__sodium_current_m_gate__d_m_d_environment__time = var_sodium_current_m_gate__d_m_d_environment__time; // ___units_11
        const double var_sodium_current_h_gate__V = var_sodium_current__V; // mV
        const double var_sodium_current_h_gate__beta_h = 1.7 / (exp((-0.082000000000000003) * (var_sodium_current_h_gate__V + 22.5)) + 1.0); // per_ms
        const double var_sodium_current_h_gate__alpha_h = 0.126 * exp((-0.25) * (var_sodium_current_h_gate__V + 77.0)); // per_ms
        const double var_sodium_current_h_gate__h = var_sodium_current__h; // dimensionless
        const double var_sodium_current_h_gate__d_h_d_environment__time = (var_sodium_current_h_gate__alpha_h * (1.0 - var_sodium_current_h_gate__h)) - (var_sodium_current_h_gate__beta_h * var_sodium_current_h_gate__h); // 'per millisecond'
        const double var_sodium_current__sodium_current_h_gate__d_h_d_environment__time = var_sodium_current_h_gate__d_h_d_environment__time; // ___units_11
        const double var_sodium_current_j_gate__V = var_sodium_current__V; // mV
        const double var_sodium_current_j_gate__beta_j = 0.29999999999999999 / (exp((-0.10000000000000001) * (var_sodium_current_j_gate__V + 32.0)) + 1.0); // per_ms
        const double var_sodium_current_j_gate__j = var_sodium_current__j; // dimensionless
        const double var_sodium_current_j_gate__alpha_j = (0.055 * exp((-0.25) * (var_sodium_current_j_gate__V + 78.0))) / (exp((-0.20000000000000001) * (var_sodium_current_j_gate__V + 78.0)) + 1.0); // per_ms
        const double var_sodium_current_j_gate__d_j_d_environment__time = (var_sodium_current_j_gate__alpha_j * (1.0 - var_sodium_current_j_gate__j)) - (var_sodium_current_j_gate__beta_j * var_sodium_current_j_gate__j); // 'per millisecond'
        const double var_sodium_current__sodium_current_j_gate__d_j_d_environment__time = var_sodium_current_j_gate__d_j_d_environment__time; // ___units_11
        const double var_slow_inward_current__d_Cai_d_environment__time = (((-0.01) * var_slow_inward_current__i_s) / 1.0) + (0.070000000000000007 * (0.0001 - var_slow_inward_current__Cai)); // 'nanomole per millimetre^3 per millisecond'
        const double var_slow_inward_current_d_gate__V = var_slow_inward_current__V; // mV
        const double var_slow_inward_current_d_gate__alpha_d = (0.095000000000000001 * exp((-(var_slow_inward_current_d_gate__V - 5.0)) / 100.0)) / (1.0 + exp((-(var_slow_inward_current_d_gate__V - 5.0)) / 13.890000000000001)); // per_ms
        const double var_slow_inward_current_d_gate__d = var_slow_inward_current__d; // dimensionless
        const double var_slow_inward_current_d_gate__beta_d = (0.070000000000000007 * exp((-(var_slow_inward_current_d_gate__V + 44.0)) / 59.0)) / (1.0 + exp((var_slow_inward_current_d_gate__V + 44.0) / 20.0)); // per_ms
        const double var_slow_inward_current_d_gate__d_d_d_environment__time = (var_slow_inward_current_d_gate__alpha_d * (1.0 - var_slow_inward_current_d_gate__d)) - (var_slow_inward_current_d_gate__beta_d * var_slow_inward_current_d_gate__d); // 'per millisecond'
        const double var_slow_inward_current__slow_inward_current_d_gate__d_d_d_environment__time = var_slow_inward_current_d_gate__d_d_d_environment__time; // ___units_11
        const double var_slow_inward_current_f_gate__f = var_slow_inward_current__f; // dimensionless
        const double var_slow_inward_current_f_gate__V = var_slow_inward_current__V; // mV
        const double var_slow_inward_current_f_gate__alpha_f = (0.012 * exp((-(var_slow_inward_current_f_gate__V + 28.0)) / 125.0)) / (1.0 + exp((var_slow_inward_current_f_gate__V + 28.0) / 6.6699999999999999)); // per_ms
        const double var_slow_inward_current_f_gate__beta_f = (0.0064999999999999997 * exp((-(var_slow_inward_current_f_gate__V + 30.0)) / 50.0)) / (1.0 + exp((-(var_slow_inward_current_f_gate__V + 30.0)) / 5.0)); // per_ms
        const double var_slow_inward_current_f_gate__d_f_d_environment__time = (var_slow_inward_current_f_gate__alpha_f * (1.0 - var_slow_inward_current_f_gate__f)) - (var_slow_inward_current_f_gate__beta_f * var_slow_inward_current_f_gate__f); // 'per millisecond'
        const double var_slow_inward_current__slow_inward_current_f_gate__d_f_d_environment__time = var_slow_inward_current_f_gate__d_f_d_environment__time; // ___units_11
        const double var_time_dependent_outward_current_x1_gate__x1 = var_time_dependent_outward_current__x1; // dimensionless
        const double var_time_dependent_outward_current_x1_gate__V = var_time_dependent_outward_current__V; // mV
        const double var_time_dependent_outward_current_x1_gate__alpha_x1 = (0.00050000000000000001 * exp((var_time_dependent_outward_current_x1_gate__V + 50.0) / 12.1)) / (1.0 + exp((var_time_dependent_outward_current_x1_gate__V + 50.0) / 17.5)); // per_ms
        const double var_time_dependent_outward_current_x1_gate__beta_x1 = (0.0012999999999999999 * exp((-(var_time_dependent_outward_current_x1_gate__V + 20.0)) / 16.670000000000002)) / (1.0 + exp((-(var_time_dependent_outward_current_x1_gate__V + 20.0)) / 25.0)); // per_ms
        const double var_time_dependent_outward_current_x1_gate__d_x1_d_environment__time = (var_time_dependent_outward_current_x1_gate__alpha_x1 * (1.0 - var_time_dependent_outward_current_x1_gate__x1)) - (var_time_dependent_outward_current_x1_gate__beta_x1 * var_time_dependent_outward_current_x1_gate__x1); // 'per millisecond'
        const double var_time_dependent_outward_current__time_dependent_outward_current_x1_gate__d_x1_d_environment__time = var_time_dependent_outward_current_x1_gate__d_x1_d_environment__time; // ___units_11
        const double var_chaste_interface__slow_inward_current__d_Cai_d_environment__time = var_slow_inward_current__d_Cai_d_environment__time; // ___units_21
        const double var_chaste_interface__sodium_current_m_gate__d_m_d_environment__time = var_sodium_current__sodium_current_m_gate__d_m_d_environment__time; // ___units_11
        const double var_chaste_interface__sodium_current_h_gate__d_h_d_environment__time = var_sodium_current__sodium_current_h_gate__d_h_d_environment__time; // ___units_11
        const double var_chaste_interface__sodium_current_j_gate__d_j_d_environment__time = var_sodium_current__sodium_current_j_gate__d_j_d_environment__time; // ___units_11
        const double var_chaste_interface__slow_inward_current_d_gate__d_d_d_environment__time = var_slow_inward_current__slow_inward_current_d_gate__d_d_d_environment__time; // ___units_11
        const double var_chaste_interface__slow_inward_current_f_gate__d_f_d_environment__time = var_slow_inward_current__slow_inward_current_f_gate__d_f_d_environment__time; // ___units_11
        const double var_chaste_interface__time_dependent_outward_current_x1_gate__d_x1_d_environment__time = var_time_dependent_outward_current__time_dependent_outward_current_x1_gate__d_x1_d_environment__time; // ___units_11
        const double d_dt_chaste_interface__slow_inward_current__Cai = var_chaste_interface__slow_inward_current__d_Cai_d_environment__time; // 'millimole per litre per millisecond'
        const double d_dt_chaste_interface__sodium_current_m_gate__m = var_chaste_interface__sodium_current_m_gate__d_m_d_environment__time; // 'per millisecond'
        const double d_dt_chaste_interface__sodium_current_h_gate__h = var_chaste_interface__sodium_current_h_gate__d_h_d_environment__time; // 'per millisecond'
        const double d_dt_chaste_interface__sodium_current_j_gate__j = var_chaste_interface__sodium_current_j_gate__d_j_d_environment__time; // 'per millisecond'
        const double d_dt_chaste_interface__slow_inward_current_d_gate__d = var_chaste_interface__slow_inward_current_d_gate__d_d_d_environment__time; // 'per millisecond'
        const double d_dt_chaste_interface__slow_inward_current_f_gate__f = var_chaste_interface__slow_inward_current_f_gate__d_f_d_environment__time; // 'per millisecond'
        const double d_dt_chaste_interface__time_dependent_outward_current_x1_gate__x1 = var_chaste_interface__time_dependent_outward_current_x1_gate__d_x1_d_environment__time; // 'per millisecond'
        
        if (mSetVoltageDerivativeToZero)
        {
            d_dt_chaste_interface__membrane__V = 0.0;
        }
        else
        {
            const double var_membrane__C = 0.01; // uF_per_mm2
            const double var_sodium_current__E_Na = 50.0; // mV
            const double var_sodium_current__g_Nac = 3.0000000000000001e-05; // mS_per_mm2
            const double var_sodium_current__g_Na = 0.040000000000000001; // mS_per_mm2
            const double var_sodium_current__i_Na = ((var_sodium_current__g_Na * pow(var_sodium_current__m, 3.0) * var_sodium_current__h * var_sodium_current__j) + var_sodium_current__g_Nac) * (var_sodium_current__V - var_sodium_current__E_Na); // uA_per_mm2
            const double var_membrane__i_Na = var_sodium_current__i_Na; // uA_per_mm2
            const double var_membrane__i_s = var_slow_inward_current__i_s; // uA_per_mm2
            const double var_time_dependent_outward_current__i_x1 = (var_time_dependent_outward_current__x1 * 0.0080000000000000002 * (exp(0.040000000000000001 * (var_time_dependent_outward_current__V + 77.0)) - 1.0)) / exp(0.040000000000000001 * (var_time_dependent_outward_current__V + 35.0)); // uA_per_mm2
            const double var_membrane__i_x1 = var_time_dependent_outward_current__i_x1; // uA_per_mm2
            const double var_time_independent_outward_current__V = var_chaste_interface__membrane__V; // mV
            const double var_time_independent_outward_current__i_K1 = 0.0035000000000000001 * (((4.0 * (exp(0.040000000000000001 * (var_time_independent_outward_current__V + 85.0)) - 1.0)) / (exp(0.080000000000000002 * (var_time_independent_outward_current__V + 53.0)) + exp(0.040000000000000001 * (var_time_independent_outward_current__V + 53.0)))) + ((0.20000000000000001 * (var_time_independent_outward_current__V + 23.0)) / (1.0 - exp((-0.040000000000000001) * (var_time_independent_outward_current__V + 23.0))))); // uA_per_mm2
            const double var_membrane__i_K1 = var_time_independent_outward_current__i_K1; // uA_per_mm2
            const double var_chaste_interface__stimulus_protocol__Istim = -GetIntracellularAreaStimulus(var_chaste_interface__environment__time);
            const double var_membrane__Istim_converter = var_chaste_interface__stimulus_protocol__Istim; // uA_per_cm2
            const double var_membrane__Istim = 0.01 * var_membrane__Istim_converter; // uA_per_mm2
            const double var_membrane__d_V_d_environment__time = (var_membrane__Istim - (var_membrane__i_Na + var_membrane__i_s + var_membrane__i_x1 + var_membrane__i_K1)) / var_membrane__C; // 'millivolt per millisecond'
            const double var_chaste_interface__membrane__d_V_d_environment__time = var_membrane__d_V_d_environment__time; // ___units_1
            d_dt_chaste_interface__membrane__V = var_chaste_interface__membrane__d_V_d_environment__time; // 'millivolt per millisecond'
        }
        
        rDY[0] = d_dt_chaste_interface__membrane__V;
        rDY[1] = d_dt_chaste_interface__slow_inward_current__Cai;
        rDY[2] = d_dt_chaste_interface__sodium_current_m_gate__m;
        rDY[3] = d_dt_chaste_interface__sodium_current_h_gate__h;
        rDY[4] = d_dt_chaste_interface__sodium_current_j_gate__j;
        rDY[5] = d_dt_chaste_interface__slow_inward_current_d_gate__d;
        rDY[6] = d_dt_chaste_interface__slow_inward_current_f_gate__f;
        rDY[7] = d_dt_chaste_interface__time_dependent_outward_current_x1_gate__x1;
    }
    
template<>
void OdeSystemInformation<Dynamicbeeler_reuter_model_1977FromCellML>::Initialise(void)
{
    this->mSystemName = "beeler_reuter_model_1977";
    this->mFreeVariableName = "environment__time";
    this->mFreeVariableUnits = "millisecond";
    
    // rY[0]:
    this->mVariableNames.push_back("membrane_voltage");
    this->mVariableUnits.push_back("millivolt");
    this->mInitialConditions.push_back(-84.624);

    // rY[1]:
    this->mVariableNames.push_back("cytosolic_calcium_concentration");
    this->mVariableUnits.push_back("millimolar");
    this->mInitialConditions.push_back(1e-4);

    // rY[2]:
    this->mVariableNames.push_back("sodium_current_m_gate__m");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(0.011);

    // rY[3]:
    this->mVariableNames.push_back("sodium_current_h_gate__h");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(0.988);

    // rY[4]:
    this->mVariableNames.push_back("sodium_current_j_gate__j");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(0.975);

    // rY[5]:
    this->mVariableNames.push_back("slow_inward_current_d_gate__d");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(0.003);

    // rY[6]:
    this->mVariableNames.push_back("slow_inward_current_f_gate__f");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(0.994);

    // rY[7]:
    this->mVariableNames.push_back("time_dependent_outward_current_x1_gate__x1");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(0.0001);

    this->mInitialised = true;
}


// Serialization for Boost >= 1.36
#include "SerializationExportWrapperForCpp.hpp"
CHASTE_CLASS_EXPORT(Dynamicbeeler_reuter_model_1977FromCellML)
extern "C"
{
    AbstractCardiacCellInterface* MakeCardiacCell(
            boost::shared_ptr<AbstractIvpOdeSolver> pSolver,
            boost::shared_ptr<AbstractStimulusFunction> pStimulus)
    {
        return new Dynamicbeeler_reuter_model_1977FromCellML(pSolver, pStimulus);
    }
    
}
