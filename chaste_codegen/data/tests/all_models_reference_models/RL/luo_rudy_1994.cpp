//! @file
//! 
//! This source file was generated from CellML.
//! 
//! Model: luo_rudy_1994
//! 
//! Processed by pycml - CellML Tools in Python
//!     (translators: , pycml: , optimize: )
//! on (date omitted as unimportant)
//! 
//! <autogenerated>

#include "luo_rudy_1994.hpp"
#include <cmath>
#include <cassert>
#include <memory>
#include "Exception.hpp"
#include "OdeSystemInformation.hpp"
#include "RegularStimulus.hpp"
#include "HeartConfig.hpp"
#include "IsNan.hpp"
#include "MathsCustomFunctions.hpp"

    boost::shared_ptr<RegularStimulus> Dynamicluo_rudy_1994FromCellMLRushLarsen::UseCellMLDefaultStimulus()
    {
        // Use the default stimulus specified by CellML metadata
        const double var_chaste_interface__membrane__stimPeriod = 1000.0; // millisecond
        const double var_chaste_interface__membrane__stimDuration = 0.5; // millisecond
        const double var_chaste_interface__membrane__stimCurrent = 50.0; // uA_per_cm2
        boost::shared_ptr<RegularStimulus> p_cellml_stim(new RegularStimulus(
                -fabs(var_chaste_interface__membrane__stimCurrent),
                var_chaste_interface__membrane__stimDuration,
                var_chaste_interface__membrane__stimPeriod,
                0.0
                ));
        mpIntracellularStimulus = p_cellml_stim;
        return p_cellml_stim;
    }
    
    double Dynamicluo_rudy_1994FromCellMLRushLarsen::GetIntracellularCalciumConcentration()
    {
        return mStateVariables[1];
    }
    
    Dynamicluo_rudy_1994FromCellMLRushLarsen::Dynamicluo_rudy_1994FromCellMLRushLarsen(boost::shared_ptr<AbstractIvpOdeSolver> /* unused; should be empty */, boost::shared_ptr<AbstractStimulusFunction> pIntracellularStimulus)
        : AbstractRushLarsenCardiacCell(
                12,
                0,
                pIntracellularStimulus)
    {
        // Time units: millisecond
        // 
        this->mpSystemInfo = OdeSystemInformation<Dynamicluo_rudy_1994FromCellMLRushLarsen>::Instance();
        Init();

        // We have a default stimulus specified in the CellML file metadata
        this->mHasDefaultStimulusFromCellML = true;
    }
    
    Dynamicluo_rudy_1994FromCellMLRushLarsen::~Dynamicluo_rudy_1994FromCellMLRushLarsen()
    {
    }
    
    double Dynamicluo_rudy_1994FromCellMLRushLarsen::GetIIonic(const std::vector<double>* pStateVariables)
    {
        // For state variable interpolation (SVI) we read in interpolated state variables,
        // otherwise for ionic current interpolation (ICI) we use the state variables of this model (node).
        if (!pStateVariables) pStateVariables = &rGetStateVariables();
        const std::vector<double>& rY = *pStateVariables;
        double var_chaste_interface__membrane__V = (mSetVoltageDerivativeToZero ? this->mFixedVoltage : rY[0]);
        // Units: millivolt; Initial value: -84.624
        double var_chaste_interface__ionic_concentrations__Cai = rY[1];
        // Units: millimolar; Initial value: 0.12e-3
        double var_chaste_interface__fast_sodium_current_m_gate__m = rY[2];
        // Units: dimensionless; Initial value: 0.0
        double var_chaste_interface__fast_sodium_current_h_gate__h = rY[3];
        // Units: dimensionless; Initial value: 1.0
        double var_chaste_interface__fast_sodium_current_j_gate__j = rY[4];
        // Units: dimensionless; Initial value: 1.0
        double var_chaste_interface__L_type_Ca_channel_d_gate__d = rY[5];
        // Units: dimensionless; Initial value: 0.0
        double var_chaste_interface__L_type_Ca_channel_f_gate__f = rY[6];
        // Units: dimensionless; Initial value: 1.0
        double var_chaste_interface__time_dependent_potassium_current_X_gate__X = rY[7];
        // Units: dimensionless; Initial value: 0.0
        double var_chaste_interface__ionic_concentrations__Nai = rY[8];
        // Units: mM; Initial value: 10.0
        double var_chaste_interface__ionic_concentrations__Ki = rY[9];
        // Units: mM; Initial value: 145.0
        
        const double var_fast_sodium_current__g_Na = 0.16; // mS_per_mm2
        const double var_ionic_concentrations__Nao = 140.0; // mM
        const double var_fast_sodium_current__E_Na = 26.614641953637257 * log(var_ionic_concentrations__Nao / var_chaste_interface__ionic_concentrations__Nai); // mV
        const double var_fast_sodium_current__i_Na = var_fast_sodium_current__g_Na * pow(var_chaste_interface__fast_sodium_current_m_gate__m, 3.0) * var_chaste_interface__fast_sodium_current_h_gate__h * var_chaste_interface__fast_sodium_current_j_gate__j * (var_chaste_interface__membrane__V - var_fast_sodium_current__E_Na); // uA_per_mm2
        const double var_L_type_Ca_channel_f_Ca_gate__f_Ca = 1.0 / (1.0 + pow(var_chaste_interface__ionic_concentrations__Cai * 1666.6666666666667, 2.0)); // dimensionless
        const double var_ionic_concentrations__Cao = 1.8; // mM
        const double var_L_type_Ca_channel__i_CaCa = var_chaste_interface__L_type_Ca_channel_d_gate__d * var_chaste_interface__L_type_Ca_channel_f_gate__f * var_L_type_Ca_channel_f_Ca_gate__f_Ca * (((var_chaste_interface__membrane__V * 9378954025.0) * 3.8797359451715714e-07) * (((1.0 * var_chaste_interface__ionic_concentrations__Cai * exp((var_chaste_interface__membrane__V * 193690.0) * 3.8797359451715714e-07)) - (0.34000000000000002 * var_ionic_concentrations__Cao)) / (exp((var_chaste_interface__membrane__V * 193690.0) * 3.8797359451715714e-07) - 1.0)) * 2.16e-05); // uA_per_mm2
        const double var_L_type_Ca_channel__i_CaNa = var_chaste_interface__L_type_Ca_channel_d_gate__d * var_chaste_interface__L_type_Ca_channel_f_gate__f * var_L_type_Ca_channel_f_Ca_gate__f_Ca * (((var_chaste_interface__membrane__V * 9378954025.0) * 3.8797359451715714e-07) * (((0.75 * var_chaste_interface__ionic_concentrations__Nai * exp((var_chaste_interface__membrane__V * 96845.0) * 3.8797359451715714e-07)) - (0.75 * var_ionic_concentrations__Nao)) / (exp((var_chaste_interface__membrane__V * 96845.0) * 3.8797359451715714e-07) - 1.0)) * 6.7500000000000001e-09); // uA_per_mm2
        const double var_ionic_concentrations__Ko = 5.4000000000000004; // mM
        const double var_L_type_Ca_channel__i_CaK = var_chaste_interface__L_type_Ca_channel_d_gate__d * var_chaste_interface__L_type_Ca_channel_f_gate__f * var_L_type_Ca_channel_f_Ca_gate__f_Ca * (((var_chaste_interface__membrane__V * 9378954025.0) * 3.8797359451715714e-07) * (((0.75 * var_chaste_interface__ionic_concentrations__Ki * exp((var_chaste_interface__membrane__V * 96845.0) * 3.8797359451715714e-07)) - (0.75 * var_ionic_concentrations__Ko)) / (exp((var_chaste_interface__membrane__V * 96845.0) * 3.8797359451715714e-07) - 1.0)) * 1.9300000000000002e-09); // uA_per_mm2
        const double var_L_type_Ca_channel__i_Ca_L = var_L_type_Ca_channel__i_CaCa + var_L_type_Ca_channel__i_CaK + var_L_type_Ca_channel__i_CaNa; // uA_per_mm2
        const double var_sarcolemmal_calcium_pump__i_p_Ca = 0.0115 * (var_chaste_interface__ionic_concentrations__Cai / (0.00050000000000000001 + var_chaste_interface__ionic_concentrations__Cai)); // uA_per_mm2
        const double var_sodium_background_current__i_Na_b = 1.4100000000000001e-05 * (var_chaste_interface__membrane__V - var_fast_sodium_current__E_Na); // uA_per_mm2
        const double var_sodium_potassium_pump__i_NaK = 0.014999999999999999 * (1.0 / ((1.0 + (0.1245 * exp( -0.10000000000000001 * ((var_chaste_interface__membrane__V * 96845.0) * 3.8797359451715714e-07)))) + (0.036499999999999998 * (0.14285714285714285 * (exp(var_ionic_concentrations__Nao * 0.01485884101040119) - 1.0)) * exp(-((var_chaste_interface__membrane__V * 96845.0) * 3.8797359451715714e-07))))) * (1.0 / (1.0 + pow(10.0 / var_chaste_interface__ionic_concentrations__Nai, 1.5))) * (var_ionic_concentrations__Ko / (var_ionic_concentrations__Ko + 1.5)); // uA_per_mm2
        const double var_time_dependent_potassium_current__i_K = (0.00282 * sqrt(var_ionic_concentrations__Ko * 0.18518518518518517)) * pow(var_chaste_interface__time_dependent_potassium_current_X_gate__X, 2.0) * (1.0 / (1.0 + exp((var_chaste_interface__membrane__V - 56.259999999999998) * 0.031152647975077882))) * (var_chaste_interface__membrane__V - (26.614641953637257 * log((var_ionic_concentrations__Ko + (0.018329999999999999 * var_ionic_concentrations__Nao)) / (var_chaste_interface__ionic_concentrations__Ki + (0.018329999999999999 * var_chaste_interface__ionic_concentrations__Nai))))); // uA_per_mm2
        const double var_calcium_background_current__i_Ca_b = 3.0159999999999999e-05 * (var_chaste_interface__membrane__V - (13.307320976818628 * log(var_ionic_concentrations__Cao / var_chaste_interface__ionic_concentrations__Cai))); // uA_per_mm2
        const double var_non_specific_calcium_activated_current__Vns = var_chaste_interface__membrane__V - (26.614641953637257 * log((var_ionic_concentrations__Ko + var_ionic_concentrations__Nao) / (var_chaste_interface__ionic_concentrations__Ki + var_chaste_interface__ionic_concentrations__Nai))); // mV
        const double var_non_specific_calcium_activated_current__i_ns_Na = (((var_non_specific_calcium_activated_current__Vns * 9378954025.0) * 3.8797359451715714e-07) * (((0.75 * var_chaste_interface__ionic_concentrations__Nai * exp((var_non_specific_calcium_activated_current__Vns * 96845.0) * 3.8797359451715714e-07)) - (0.75 * var_ionic_concentrations__Nao)) / (exp((var_non_specific_calcium_activated_current__Vns * 96845.0) * 3.8797359451715714e-07) - 1.0)) * 1.75e-09) * (1.0 / (1.0 + pow(0.0011999999999999999 / var_chaste_interface__ionic_concentrations__Cai, 3.0))); // uA_per_mm2
        const double var_non_specific_calcium_activated_current__i_ns_K = (((var_non_specific_calcium_activated_current__Vns * 9378954025.0) * 3.8797359451715714e-07) * (((0.75 * var_chaste_interface__ionic_concentrations__Ki * exp((var_non_specific_calcium_activated_current__Vns * 96845.0) * 3.8797359451715714e-07)) - (0.75 * var_ionic_concentrations__Ko)) / (exp((var_non_specific_calcium_activated_current__Vns * 96845.0) * 3.8797359451715714e-07) - 1.0)) * 1.75e-09) * (1.0 / (1.0 + pow(0.0011999999999999999 / var_chaste_interface__ionic_concentrations__Cai, 3.0))); // uA_per_mm2
        const double var_non_specific_calcium_activated_current__i_ns_Ca = var_non_specific_calcium_activated_current__i_ns_Na + var_non_specific_calcium_activated_current__i_ns_K; // uA_per_mm2
        const double var_Na_Ca_exchanger__i_NaCa = 20.0 * (1.0 / (669921.875 + pow(var_ionic_concentrations__Nao, 3.0))) * (1.0 / (1.3799999999999999 + var_ionic_concentrations__Cao)) * (1.0 / (1.0 + (0.10000000000000001 * exp(var_chaste_interface__membrane__V *  -0.024422646794659157)))) * ((exp(var_chaste_interface__membrane__V * 0.013150655966354931) * pow(var_chaste_interface__ionic_concentrations__Nai, 3.0) * var_ionic_concentrations__Cao) - (exp(var_chaste_interface__membrane__V *  -0.024422646794659157) * pow(var_ionic_concentrations__Nao, 3.0) * var_chaste_interface__ionic_concentrations__Cai)); // uA_per_mm2
        const double var_time_independent_potassium_current__E_K1 = 26.614641953637257 * log(var_ionic_concentrations__Ko / var_chaste_interface__ionic_concentrations__Ki); // mV
        const double var_plateau_potassium_current__i_Kp = 0.000183 * (1.0 / (1.0 + exp((7.4880000000000004 - var_chaste_interface__membrane__V) * 0.16722408026755853))) * (var_chaste_interface__membrane__V - var_time_independent_potassium_current__E_K1); // uA_per_mm2
        const double var_time_independent_potassium_current_K1_gate__alpha_K1 = 1.02 / (1.0 + exp(0.23849999999999999 * ((var_chaste_interface__membrane__V - var_time_independent_potassium_current__E_K1) - 59.215000000000003))); // per_ms
        const double var_time_independent_potassium_current__g_K1_max = 0.0074999999999999997; // mS_per_mm2
        const double var_time_independent_potassium_current__i_K1 = (var_time_independent_potassium_current__g_K1_max * sqrt(var_ionic_concentrations__Ko * 0.18518518518518517)) * (var_time_independent_potassium_current_K1_gate__alpha_K1 / (var_time_independent_potassium_current_K1_gate__alpha_K1 + (((0.49124000000000001 * exp(0.080320000000000003 * ((var_chaste_interface__membrane__V + 5.476) - var_time_independent_potassium_current__E_K1))) + exp(0.061749999999999999 * (var_chaste_interface__membrane__V - (var_time_independent_potassium_current__E_K1 + 594.30999999999995)))) / (1.0 + exp( -0.51429999999999998 * ((var_chaste_interface__membrane__V - var_time_independent_potassium_current__E_K1) + 4.7530000000000001)))))) * (var_chaste_interface__membrane__V - var_time_independent_potassium_current__E_K1); // uA_per_mm2
        const double var_chaste_interface__time_independent_potassium_current__i_K1 = var_time_independent_potassium_current__i_K1; // uA_per_mm2
        const double var_chaste_interface__fast_sodium_current__i_Na = var_fast_sodium_current__i_Na; // uA_per_mm2
        const double var_chaste_interface__i_ionic = (100.0 * var_chaste_interface__fast_sodium_current__i_Na) + (100.0 * var_L_type_Ca_channel__i_Ca_L) + (100.0 * var_time_dependent_potassium_current__i_K) + (100.0 * var_chaste_interface__time_independent_potassium_current__i_K1) + (100.0 * var_plateau_potassium_current__i_Kp) + (100.0 * var_Na_Ca_exchanger__i_NaCa) + (100.0 * var_sarcolemmal_calcium_pump__i_p_Ca) + (100.0 * var_sodium_background_current__i_Na_b) + (100.0 * var_calcium_background_current__i_Ca_b) + (100.0 * var_sodium_potassium_pump__i_NaK) + (100.0 * var_non_specific_calcium_activated_current__i_ns_Ca); // uA_per_cm2
        
        const double i_ionic = var_chaste_interface__i_ionic;
        EXCEPT_IF_NOT(!std::isnan(i_ionic));
        return i_ionic;
    }
    
    void Dynamicluo_rudy_1994FromCellMLRushLarsen::EvaluateEquations(double var_chaste_interface__environment__time, std::vector<double> &rDY, std::vector<double> &rAlphaOrTau, std::vector<double> &rBetaOrInf)
    {
        std::vector<double>& rY = rGetStateVariables();
        double var_chaste_interface__membrane__V = (mSetVoltageDerivativeToZero ? this->mFixedVoltage : rY[0]);
        // Units: millivolt; Initial value: -84.624
        double var_chaste_interface__ionic_concentrations__Cai = rY[1];
        // Units: millimolar; Initial value: 0.12e-3
        double var_chaste_interface__fast_sodium_current_m_gate__m = rY[2];
        // Units: dimensionless; Initial value: 0.0
        double var_chaste_interface__fast_sodium_current_h_gate__h = rY[3];
        // Units: dimensionless; Initial value: 1.0
        double var_chaste_interface__fast_sodium_current_j_gate__j = rY[4];
        // Units: dimensionless; Initial value: 1.0
        double var_chaste_interface__L_type_Ca_channel_d_gate__d = rY[5];
        // Units: dimensionless; Initial value: 0.0
        double var_chaste_interface__L_type_Ca_channel_f_gate__f = rY[6];
        // Units: dimensionless; Initial value: 1.0
        double var_chaste_interface__time_dependent_potassium_current_X_gate__X = rY[7];
        // Units: dimensionless; Initial value: 0.0
        double var_chaste_interface__ionic_concentrations__Nai = rY[8];
        // Units: mM; Initial value: 10.0
        double var_chaste_interface__ionic_concentrations__Ki = rY[9];
        // Units: mM; Initial value: 145.0
        double var_chaste_interface__ionic_concentrations__Ca_JSR = rY[10];
        // Units: mM; Initial value: 1.8
        double var_chaste_interface__ionic_concentrations__Ca_NSR = rY[11];
        // Units: mM; Initial value: 1.8
        
        
        // Mathematics
        double d_dt_chaste_interface__membrane__V;
        const double var_fast_sodium_current__g_Na = 0.16; // mS_per_mm2
        const double var_ionic_concentrations__Nao = 140.0; // mM
        const double var_fast_sodium_current__E_Na = 26.614641953637257 * log(var_ionic_concentrations__Nao / var_chaste_interface__ionic_concentrations__Nai); // mV
        const double var_fast_sodium_current__i_Na = var_fast_sodium_current__g_Na * pow(var_chaste_interface__fast_sodium_current_m_gate__m, 3.0) * var_chaste_interface__fast_sodium_current_h_gate__h * var_chaste_interface__fast_sodium_current_j_gate__j * (var_chaste_interface__membrane__V - var_fast_sodium_current__E_Na); // uA_per_mm2
        const double var_L_type_Ca_channel_f_Ca_gate__f_Ca = 1.0 / (1.0 + pow(var_chaste_interface__ionic_concentrations__Cai * 1666.6666666666667, 2.0)); // dimensionless
        const double var_ionic_concentrations__Cao = 1.8; // mM
        const double var_L_type_Ca_channel__i_CaCa = var_chaste_interface__L_type_Ca_channel_d_gate__d * var_chaste_interface__L_type_Ca_channel_f_gate__f * var_L_type_Ca_channel_f_Ca_gate__f_Ca * (((var_chaste_interface__membrane__V * 9378954025.0) * 3.8797359451715714e-07) * (((1.0 * var_chaste_interface__ionic_concentrations__Cai * exp((var_chaste_interface__membrane__V * 193690.0) * 3.8797359451715714e-07)) - (0.34000000000000002 * var_ionic_concentrations__Cao)) / (exp((var_chaste_interface__membrane__V * 193690.0) * 3.8797359451715714e-07) - 1.0)) * 2.16e-05); // uA_per_mm2
        const double var_L_type_Ca_channel__i_CaNa = var_chaste_interface__L_type_Ca_channel_d_gate__d * var_chaste_interface__L_type_Ca_channel_f_gate__f * var_L_type_Ca_channel_f_Ca_gate__f_Ca * (((var_chaste_interface__membrane__V * 9378954025.0) * 3.8797359451715714e-07) * (((0.75 * var_chaste_interface__ionic_concentrations__Nai * exp((var_chaste_interface__membrane__V * 96845.0) * 3.8797359451715714e-07)) - (0.75 * var_ionic_concentrations__Nao)) / (exp((var_chaste_interface__membrane__V * 96845.0) * 3.8797359451715714e-07) - 1.0)) * 6.7500000000000001e-09); // uA_per_mm2
        const double var_ionic_concentrations__Ko = 5.4000000000000004; // mM
        const double var_L_type_Ca_channel__i_CaK = var_chaste_interface__L_type_Ca_channel_d_gate__d * var_chaste_interface__L_type_Ca_channel_f_gate__f * var_L_type_Ca_channel_f_Ca_gate__f_Ca * (((var_chaste_interface__membrane__V * 9378954025.0) * 3.8797359451715714e-07) * (((0.75 * var_chaste_interface__ionic_concentrations__Ki * exp((var_chaste_interface__membrane__V * 96845.0) * 3.8797359451715714e-07)) - (0.75 * var_ionic_concentrations__Ko)) / (exp((var_chaste_interface__membrane__V * 96845.0) * 3.8797359451715714e-07) - 1.0)) * 1.9300000000000002e-09); // uA_per_mm2
        const double var_sarcolemmal_calcium_pump__i_p_Ca = 0.0115 * (var_chaste_interface__ionic_concentrations__Cai / (0.00050000000000000001 + var_chaste_interface__ionic_concentrations__Cai)); // uA_per_mm2
        const double var_sodium_background_current__i_Na_b = 1.4100000000000001e-05 * (var_chaste_interface__membrane__V - var_fast_sodium_current__E_Na); // uA_per_mm2
        const double var_sodium_potassium_pump__i_NaK = 0.014999999999999999 * (1.0 / ((1.0 + (0.1245 * exp( -0.10000000000000001 * ((var_chaste_interface__membrane__V * 96845.0) * 3.8797359451715714e-07)))) + (0.036499999999999998 * (0.14285714285714285 * (exp(var_ionic_concentrations__Nao * 0.01485884101040119) - 1.0)) * exp(-((var_chaste_interface__membrane__V * 96845.0) * 3.8797359451715714e-07))))) * (1.0 / (1.0 + pow(10.0 / var_chaste_interface__ionic_concentrations__Nai, 1.5))) * (var_ionic_concentrations__Ko / (var_ionic_concentrations__Ko + 1.5)); // uA_per_mm2
        const double var_time_dependent_potassium_current__i_K = (0.00282 * sqrt(var_ionic_concentrations__Ko * 0.18518518518518517)) * pow(var_chaste_interface__time_dependent_potassium_current_X_gate__X, 2.0) * (1.0 / (1.0 + exp((var_chaste_interface__membrane__V - 56.259999999999998) * 0.031152647975077882))) * (var_chaste_interface__membrane__V - (26.614641953637257 * log((var_ionic_concentrations__Ko + (0.018329999999999999 * var_ionic_concentrations__Nao)) / (var_chaste_interface__ionic_concentrations__Ki + (0.018329999999999999 * var_chaste_interface__ionic_concentrations__Nai))))); // uA_per_mm2
        const double var_calcium_background_current__i_Ca_b = 3.0159999999999999e-05 * (var_chaste_interface__membrane__V - (13.307320976818628 * log(var_ionic_concentrations__Cao / var_chaste_interface__ionic_concentrations__Cai))); // uA_per_mm2
        const double var_non_specific_calcium_activated_current__Vns = var_chaste_interface__membrane__V - (26.614641953637257 * log((var_ionic_concentrations__Ko + var_ionic_concentrations__Nao) / (var_chaste_interface__ionic_concentrations__Ki + var_chaste_interface__ionic_concentrations__Nai))); // mV
        const double var_non_specific_calcium_activated_current__i_ns_Na = (((var_non_specific_calcium_activated_current__Vns * 9378954025.0) * 3.8797359451715714e-07) * (((0.75 * var_chaste_interface__ionic_concentrations__Nai * exp((var_non_specific_calcium_activated_current__Vns * 96845.0) * 3.8797359451715714e-07)) - (0.75 * var_ionic_concentrations__Nao)) / (exp((var_non_specific_calcium_activated_current__Vns * 96845.0) * 3.8797359451715714e-07) - 1.0)) * 1.75e-09) * (1.0 / (1.0 + pow(0.0011999999999999999 / var_chaste_interface__ionic_concentrations__Cai, 3.0))); // uA_per_mm2
        const double var_non_specific_calcium_activated_current__i_ns_K = (((var_non_specific_calcium_activated_current__Vns * 9378954025.0) * 3.8797359451715714e-07) * (((0.75 * var_chaste_interface__ionic_concentrations__Ki * exp((var_non_specific_calcium_activated_current__Vns * 96845.0) * 3.8797359451715714e-07)) - (0.75 * var_ionic_concentrations__Ko)) / (exp((var_non_specific_calcium_activated_current__Vns * 96845.0) * 3.8797359451715714e-07) - 1.0)) * 1.75e-09) * (1.0 / (1.0 + pow(0.0011999999999999999 / var_chaste_interface__ionic_concentrations__Cai, 3.0))); // uA_per_mm2
        const double var_Na_Ca_exchanger__i_NaCa = 20.0 * (1.0 / (669921.875 + pow(var_ionic_concentrations__Nao, 3.0))) * (1.0 / (1.3799999999999999 + var_ionic_concentrations__Cao)) * (1.0 / (1.0 + (0.10000000000000001 * exp(var_chaste_interface__membrane__V *  -0.024422646794659157)))) * ((exp(var_chaste_interface__membrane__V * 0.013150655966354931) * pow(var_chaste_interface__ionic_concentrations__Nai, 3.0) * var_ionic_concentrations__Cao) - (exp(var_chaste_interface__membrane__V *  -0.024422646794659157) * pow(var_ionic_concentrations__Nao, 3.0) * var_chaste_interface__ionic_concentrations__Cai)); // uA_per_mm2
        const double var_time_independent_potassium_current__E_K1 = 26.614641953637257 * log(var_ionic_concentrations__Ko / var_chaste_interface__ionic_concentrations__Ki); // mV
        const double var_plateau_potassium_current__i_Kp = 0.000183 * (1.0 / (1.0 + exp((7.4880000000000004 - var_chaste_interface__membrane__V) * 0.16722408026755853))) * (var_chaste_interface__membrane__V - var_time_independent_potassium_current__E_K1); // uA_per_mm2
        const double var_time_independent_potassium_current_K1_gate__alpha_K1 = 1.02 / (1.0 + exp(0.23849999999999999 * ((var_chaste_interface__membrane__V - var_time_independent_potassium_current__E_K1) - 59.215000000000003))); // per_ms
        const double var_time_independent_potassium_current__g_K1_max = 0.0074999999999999997; // mS_per_mm2
        const double var_time_independent_potassium_current__i_K1 = (var_time_independent_potassium_current__g_K1_max * sqrt(var_ionic_concentrations__Ko * 0.18518518518518517)) * (var_time_independent_potassium_current_K1_gate__alpha_K1 / (var_time_independent_potassium_current_K1_gate__alpha_K1 + (((0.49124000000000001 * exp(0.080320000000000003 * ((var_chaste_interface__membrane__V + 5.476) - var_time_independent_potassium_current__E_K1))) + exp(0.061749999999999999 * (var_chaste_interface__membrane__V - (var_time_independent_potassium_current__E_K1 + 594.30999999999995)))) / (1.0 + exp( -0.51429999999999998 * ((var_chaste_interface__membrane__V - var_time_independent_potassium_current__E_K1) + 4.7530000000000001)))))) * (var_chaste_interface__membrane__V - var_time_independent_potassium_current__E_K1); // uA_per_mm2
        const double var_L_type_Ca_channel_d_gate__d_infinity = 1.0 / (1.0 + exp(-((var_chaste_interface__membrane__V + 10.0) * 0.16025641025641024))); // dimensionless
        const double var_L_type_Ca_channel_d_gate__tau_d = var_L_type_Ca_channel_d_gate__d_infinity * ((1.0 - exp(-((var_chaste_interface__membrane__V + 10.0) * 0.16025641025641024))) / (0.035000000000000003 * (var_chaste_interface__membrane__V + 10.0))); // ms
        const double var_L_type_Ca_channel_f_gate__f_infinity = (1.0 / (1.0 + exp((var_chaste_interface__membrane__V + 35.060000000000002) * 0.11627906976744186))) + (0.59999999999999998 / (1.0 + exp((50.0 - var_chaste_interface__membrane__V) * 0.050000000000000003))); // dimensionless
        const double var_L_type_Ca_channel_f_gate__tau_f = 1.0 / ((0.019699999999999999 * exp(-pow(0.033700000000000001 * (var_chaste_interface__membrane__V + 10.0), 2.0))) + 0.02); // ms
        const double var_calcium_fluxes_in_the_SR__i_rel =  -0.0 * (var_chaste_interface__ionic_concentrations__Ca_JSR - var_chaste_interface__ionic_concentrations__Cai); // mM_per_ms
        const double var_calcium_fluxes_in_the_SR__i_up = 0.0050000000000000001 * (var_chaste_interface__ionic_concentrations__Cai / (var_chaste_interface__ionic_concentrations__Cai + 0.00092000000000000003)); // mM_per_ms
        const double var_calcium_fluxes_in_the_SR__i_leak = 0.00033333333333333332 * var_chaste_interface__ionic_concentrations__Ca_NSR; // mM_per_ms
        const double var_calcium_fluxes_in_the_SR__i_tr = (var_chaste_interface__ionic_concentrations__Ca_NSR - var_chaste_interface__ionic_concentrations__Ca_JSR) * 0.0055555555555555558; // mM_per_ms
        const double d_dt_chaste_interface__ionic_concentrations__Cai = ((-((var_L_type_Ca_channel__i_CaCa + var_sarcolemmal_calcium_pump__i_p_Ca + var_calcium_background_current__i_Ca_b) - var_Na_Ca_exchanger__i_NaCa)) * 0.0015184968096382029) + (var_calcium_fluxes_in_the_SR__i_rel * 0.0070588235294117632) + ((var_calcium_fluxes_in_the_SR__i_leak - var_calcium_fluxes_in_the_SR__i_up) * 0.081176470588235281); // 'millimole per litre per millisecond'
        const double d_dt_chaste_interface__ionic_concentrations__Nai = (-(var_fast_sodium_current__i_Na + var_L_type_Ca_channel__i_CaNa + var_sodium_background_current__i_Na_b + var_non_specific_calcium_activated_current__i_ns_Na + (var_Na_Ca_exchanger__i_NaCa * 3.0) + (var_sodium_potassium_pump__i_NaK * 3.0))) * 0.0030369936192764057; // 'nanomole per millimetre^3 per millisecond'
        const double d_dt_chaste_interface__ionic_concentrations__Ki = (-(var_L_type_Ca_channel__i_CaK + var_time_dependent_potassium_current__i_K + var_time_independent_potassium_current__i_K1 + var_plateau_potassium_current__i_Kp + var_non_specific_calcium_activated_current__i_ns_K + (-(var_sodium_potassium_pump__i_NaK * 2.0)))) * 0.0030369936192764057; // 'nanomole per millimetre^3 per millisecond'
        const double d_dt_chaste_interface__ionic_concentrations__Ca_JSR = -(var_calcium_fluxes_in_the_SR__i_rel - (var_calcium_fluxes_in_the_SR__i_tr * 11.5)); // 'nanomole per millimetre^3 per millisecond'
        const double d_dt_chaste_interface__ionic_concentrations__Ca_NSR = -((var_calcium_fluxes_in_the_SR__i_leak + var_calcium_fluxes_in_the_SR__i_tr) - var_calcium_fluxes_in_the_SR__i_up); // 'nanomole per millimetre^3 per millisecond'
        
        if (mSetVoltageDerivativeToZero)
        {
            d_dt_chaste_interface__membrane__V = 0.0;
        }
        else
        {
            const double var_L_type_Ca_channel__i_Ca_L = var_L_type_Ca_channel__i_CaCa + var_L_type_Ca_channel__i_CaK + var_L_type_Ca_channel__i_CaNa; // uA_per_mm2
            const double var_chaste_interface__membrane__I_st = -GetIntracellularAreaStimulus(var_chaste_interface__environment__time);
            const double var_non_specific_calcium_activated_current__i_ns_Ca = var_non_specific_calcium_activated_current__i_ns_Na + var_non_specific_calcium_activated_current__i_ns_K; // uA_per_mm2
            const double var_membrane__Cm = 0.01; // uF_per_mm2
            d_dt_chaste_interface__membrane__V = ((0.01 * var_chaste_interface__membrane__I_st) - (var_fast_sodium_current__i_Na + var_L_type_Ca_channel__i_Ca_L + var_time_dependent_potassium_current__i_K + var_time_independent_potassium_current__i_K1 + var_plateau_potassium_current__i_Kp + var_Na_Ca_exchanger__i_NaCa + var_sarcolemmal_calcium_pump__i_p_Ca + var_sodium_background_current__i_Na_b + var_calcium_background_current__i_Ca_b + var_sodium_potassium_pump__i_NaK + var_non_specific_calcium_activated_current__i_ns_Ca)) / var_membrane__Cm; // 'millivolt per millisecond'
        }
        
        rDY[0] = d_dt_chaste_interface__membrane__V;
        rDY[1] = d_dt_chaste_interface__ionic_concentrations__Cai;
        rAlphaOrTau[2] = (0.32000000000000001 * (var_chaste_interface__membrane__V + 47.130000000000003)) / (1.0 - exp( -0.10000000000000001 * (var_chaste_interface__membrane__V + 47.130000000000003)));
        rBetaOrInf[2] = 0.080000000000000002 * exp((-var_chaste_interface__membrane__V) * 0.090909090909090912);
        rAlphaOrTau[3] = (var_chaste_interface__membrane__V <  -40.0) ? (0.13500000000000001 * exp((80.0 + var_chaste_interface__membrane__V) *  -0.14705882352941177)) : 0.0;
        rBetaOrInf[3] = (var_chaste_interface__membrane__V <  -40.0) ? ((3.5600000000000001 * exp(0.079000000000000001 * var_chaste_interface__membrane__V)) + (310000.0 * exp(0.34999999999999998 * var_chaste_interface__membrane__V))) : (1.0 / (0.13 * (1.0 + exp((var_chaste_interface__membrane__V + 10.66) *  -0.0900900900900901))));
        rAlphaOrTau[4] = (var_chaste_interface__membrane__V <  -40.0) ? ((( -127140.0 * exp(0.24440000000000001 * var_chaste_interface__membrane__V)) - (3.4740000000000003e-05 * exp( -0.043909999999999998 * var_chaste_interface__membrane__V))) * ((var_chaste_interface__membrane__V + 37.780000000000001) / (1.0 + exp(0.311 * (var_chaste_interface__membrane__V + 79.230000000000004))))) : 0.0;
        rBetaOrInf[4] = (var_chaste_interface__membrane__V <  -40.0) ? ((0.1212 * exp( -0.01052 * var_chaste_interface__membrane__V)) / (1.0 + exp( -0.13780000000000001 * (var_chaste_interface__membrane__V + 40.140000000000001)))) : ((0.29999999999999999 * exp( -2.5349999999999999e-07 * var_chaste_interface__membrane__V)) / (1.0 + exp( -0.10000000000000001 * (var_chaste_interface__membrane__V + 32.0))));
        rAlphaOrTau[5] = var_L_type_Ca_channel_d_gate__d_infinity / var_L_type_Ca_channel_d_gate__tau_d;
        rBetaOrInf[5] = (1.0 - var_L_type_Ca_channel_d_gate__d_infinity) / var_L_type_Ca_channel_d_gate__tau_d;
        rAlphaOrTau[6] = var_L_type_Ca_channel_f_gate__f_infinity / var_L_type_Ca_channel_f_gate__tau_f;
        rBetaOrInf[6] = (1.0 - var_L_type_Ca_channel_f_gate__f_infinity) / var_L_type_Ca_channel_f_gate__tau_f;
        rAlphaOrTau[7] = (7.1899999999999999e-05 * (var_chaste_interface__membrane__V + 30.0)) / (1.0 - exp( -0.14799999999999999 * (var_chaste_interface__membrane__V + 30.0)));
        rBetaOrInf[7] = (0.00013100000000000001 * (var_chaste_interface__membrane__V + 30.0)) / ( -1.0 + exp(0.068699999999999997 * (var_chaste_interface__membrane__V + 30.0)));
        rDY[8] = d_dt_chaste_interface__ionic_concentrations__Nai;
        rDY[9] = d_dt_chaste_interface__ionic_concentrations__Ki;
        rDY[10] = d_dt_chaste_interface__ionic_concentrations__Ca_JSR;
        rDY[11] = d_dt_chaste_interface__ionic_concentrations__Ca_NSR;
    }
    
    void Dynamicluo_rudy_1994FromCellMLRushLarsen::ComputeOneStepExceptVoltage(const std::vector<double> &rDY, const std::vector<double> &rAlphaOrTau, const std::vector<double> &rBetaOrInf)
    {
        std::vector<double>& rY = rGetStateVariables();
        rY[1] += mDt * rDY[1];
        {
            const double tau_inv = rAlphaOrTau[2] + rBetaOrInf[2];
            const double y_inf = rAlphaOrTau[2] / tau_inv;
            rY[2] = y_inf + (rY[2] - y_inf)*exp(-mDt*tau_inv);
        }
        {
            const double tau_inv = rAlphaOrTau[3] + rBetaOrInf[3];
            const double y_inf = rAlphaOrTau[3] / tau_inv;
            rY[3] = y_inf + (rY[3] - y_inf)*exp(-mDt*tau_inv);
        }
        {
            const double tau_inv = rAlphaOrTau[4] + rBetaOrInf[4];
            const double y_inf = rAlphaOrTau[4] / tau_inv;
            rY[4] = y_inf + (rY[4] - y_inf)*exp(-mDt*tau_inv);
        }
        {
            const double tau_inv = rAlphaOrTau[5] + rBetaOrInf[5];
            const double y_inf = rAlphaOrTau[5] / tau_inv;
            rY[5] = y_inf + (rY[5] - y_inf)*exp(-mDt*tau_inv);
        }
        {
            const double tau_inv = rAlphaOrTau[6] + rBetaOrInf[6];
            const double y_inf = rAlphaOrTau[6] / tau_inv;
            rY[6] = y_inf + (rY[6] - y_inf)*exp(-mDt*tau_inv);
        }
        {
            const double tau_inv = rAlphaOrTau[7] + rBetaOrInf[7];
            const double y_inf = rAlphaOrTau[7] / tau_inv;
            rY[7] = y_inf + (rY[7] - y_inf)*exp(-mDt*tau_inv);
        }
        rY[8] += mDt * rDY[8];
        rY[9] += mDt * rDY[9];
        rY[10] += mDt * rDY[10];
        rY[11] += mDt * rDY[11];
    }
    
template<>
void OdeSystemInformation<Dynamicluo_rudy_1994FromCellMLRushLarsen>::Initialise(void)
{
    this->mSystemName = "luo_rudy_1994";
    this->mFreeVariableName = "time";
    this->mFreeVariableUnits = "millisecond";
    
    // rY[0]:
    this->mVariableNames.push_back("membrane_voltage");
    this->mVariableUnits.push_back("millivolt");
    this->mInitialConditions.push_back(-84.624);

    // rY[1]:
    this->mVariableNames.push_back("cytosolic_calcium_concentration");
    this->mVariableUnits.push_back("millimolar");
    this->mInitialConditions.push_back(0.12e-3);

    // rY[2]:
    this->mVariableNames.push_back("fast_sodium_current_m_gate__m");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(0.0);

    // rY[3]:
    this->mVariableNames.push_back("fast_sodium_current_h_gate__h");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(1.0);

    // rY[4]:
    this->mVariableNames.push_back("fast_sodium_current_j_gate__j");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(1.0);

    // rY[5]:
    this->mVariableNames.push_back("L_type_Ca_channel_d_gate__d");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(0.0);

    // rY[6]:
    this->mVariableNames.push_back("L_type_Ca_channel_f_gate__f");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(1.0);

    // rY[7]:
    this->mVariableNames.push_back("time_dependent_potassium_current_X_gate__X");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(0.0);

    // rY[8]:
    this->mVariableNames.push_back("cytosolic_sodium_concentration");
    this->mVariableUnits.push_back("mM");
    this->mInitialConditions.push_back(10.0);

    // rY[9]:
    this->mVariableNames.push_back("cytosolic_potassium_concentration");
    this->mVariableUnits.push_back("mM");
    this->mInitialConditions.push_back(145.0);

    // rY[10]:
    this->mVariableNames.push_back("JSR_calcium_concentration");
    this->mVariableUnits.push_back("mM");
    this->mInitialConditions.push_back(1.8);

    // rY[11]:
    this->mVariableNames.push_back("NSR_calcium_concentration");
    this->mVariableUnits.push_back("mM");
    this->mInitialConditions.push_back(1.8);

    this->mInitialised = true;
}


// Serialization for Boost >= 1.36
#include "SerializationExportWrapperForCpp.hpp"
CHASTE_CLASS_EXPORT(Dynamicluo_rudy_1994FromCellMLRushLarsen)
extern "C"
{
    AbstractCardiacCellInterface* MakeCardiacCell(
            boost::shared_ptr<AbstractIvpOdeSolver> pSolver,
            boost::shared_ptr<AbstractStimulusFunction> pStimulus)
    {
        return new Dynamicluo_rudy_1994FromCellMLRushLarsen(pSolver, pStimulus);
    }
    
}

