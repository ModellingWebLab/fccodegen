//! @file
//! 
//! This source file was generated from CellML by chaste_codegen version 0.0.1
//! 
//! Model: hodgkin_huxley_squid_axon_model_1952_modified
//! 
//! Processed by chaste_codegen: https://github.com/ModellingWebLab/chaste-codegen
//!     (translator: chaste_codegen, model type: normal, options: )
//! on 2020-01-29 20:12:19
//! 
//! <autogenerated>

#include "hodgkin_huxley_squid_axon_model_1952_modified.hpp"
#include <cmath>
#include <cassert>
#include <memory>
#include "Exception.hpp"
#include "OdeSystemInformation.hpp"
#include "RegularStimulus.hpp"
#include "HeartConfig.hpp"
#include "IsNan.hpp"
#include "MathsCustomFunctions.hpp"
    
    Cellhodgkin_huxley_squid_axon_model_1952_modifiedFromCellML::Cellhodgkin_huxley_squid_axon_model_1952_modifiedFromCellML(boost::shared_ptr<AbstractIvpOdeSolver> pSolver, boost::shared_ptr<AbstractStimulusFunction> pIntracellularStimulus)
        : AbstractCardiacCell(
                pSolver,
                4,
                0,
                pIntracellularStimulus)
    {
        // Time units: millisecond
        // 
        this->mpSystemInfo = OdeSystemInformation<Cellhodgkin_huxley_squid_axon_model_1952_modifiedFromCellML>::Instance();
        Init();
        
    }
    
    Cellhodgkin_huxley_squid_axon_model_1952_modifiedFromCellML::~Cellhodgkin_huxley_squid_axon_model_1952_modifiedFromCellML()
    {
    }

    double Cellhodgkin_huxley_squid_axon_model_1952_modifiedFromCellML::GetIIonic(const std::vector<double>* pStateVariables)
    {
        // For state variable interpolation (SVI) we read in interpolated state variables,
        // otherwise for ionic current interpolation (ICI) we use the state variables of this model (node).
        if (!pStateVariables) pStateVariables = &rGetStateVariables();
        const std::vector<double>& rY = *pStateVariables;
        double var_chaste_interface__membrane__V = (mSetVoltageDerivativeToZero ? this->mFixedVoltage : rY[0]);
        // Units: millivolt; Initial value: -75.0
        double var_chaste_interface__sodium_channel_m_gate__m = rY[1];
        // Units: dimensionless; Initial value: 0.05
        double var_chaste_interface__sodium_channel_h_gate__h = rY[2];
        // Units: dimensionless; Initial value: 0.6
        double var_chaste_interface__potassium_channel_n_gate__n = rY[3];
        // Units: dimensionless; Initial value: 0.325
        
        const double var_leakage_current__g_L = 0.3; // milliS_per_cm2
        const double var_membrane__E_R = -75.0; // millivolt
        const double var_leakage_current__E_L = 10.613 + var_membrane__E_R; // millivolt
        const double var_leakage_current__i_L = (-var_leakage_current__E_L + var_chaste_interface__membrane__V) * var_leakage_current__g_L; // microA_per_cm2
        const double var_potassium_channel__E_K = -12.0 + var_membrane__E_R; // millivolt
        const double var_potassium_channel__g_K = 36.0; // milliS_per_cm2
        const double var_potassium_channel__i_K = pow(var_chaste_interface__potassium_channel_n_gate__n, 4.0) * (-var_potassium_channel__E_K + var_chaste_interface__membrane__V) * var_potassium_channel__g_K; // microA_per_cm2
        const double var_sodium_channel__E_Na = 115.0 + var_membrane__E_R; // millivolt
        const double var_sodium_channel__g_Na = 120.0; // milliS_per_cm2
        const double var_sodium_channel__i_Na = pow(var_chaste_interface__sodium_channel_m_gate__m, 3.0) * (-var_sodium_channel__E_Na + var_chaste_interface__membrane__V) * var_sodium_channel__g_Na * var_chaste_interface__sodium_channel_h_gate__h; // microA_per_cm2
        const double var_chaste_interface__i_ionic = var_leakage_current__i_L + var_potassium_channel__i_K + var_sodium_channel__i_Na; // uA_per_cm2
        
        const double i_ionic = var_chaste_interface__i_ionic;
        EXCEPT_IF_NOT(!std::isnan(i_ionic));
        return i_ionic;
    }
    
    void Cellhodgkin_huxley_squid_axon_model_1952_modifiedFromCellML::EvaluateYDerivatives(double var_chaste_interface__environment__time, const std::vector<double>& rY, std::vector<double>& rDY)
    {
        // Inputs:
        // Time units: millisecond
        double var_chaste_interface__membrane__V = (mSetVoltageDerivativeToZero ? this->mFixedVoltage : rY[0]);
        // Units: millivolt; Initial value: -75.0
        double var_chaste_interface__sodium_channel_m_gate__m = rY[1];
        // Units: dimensionless; Initial value: 0.05
        double var_chaste_interface__sodium_channel_h_gate__h = rY[2];
        // Units: dimensionless; Initial value: 0.6
        double var_chaste_interface__potassium_channel_n_gate__n = rY[3];
        // Units: dimensionless; Initial value: 0.325
        
        // Mathematics
        double d_dt_chaste_interface_var_membrane__V;
        const double var_potassium_channel_n_gate__alpha_n = -0.01 * (65.0 + var_chaste_interface__membrane__V) / (-1.0 + exp(-6.5 - 0.1 * var_chaste_interface__membrane__V)); // per_millisecond
        const double var_potassium_channel_n_gate__beta_n = 0.125 * exp(0.9375 + 0.0125 * var_chaste_interface__membrane__V); // per_millisecond
        const double d_dt_chaste_interface_var_potassium_channel_n_gate__n = (1.0 - var_chaste_interface__potassium_channel_n_gate__n) * var_potassium_channel_n_gate__alpha_n - var_potassium_channel_n_gate__beta_n * var_chaste_interface__potassium_channel_n_gate__n; // 1 / millisecond
        const double var_sodium_channel_h_gate__alpha_h = 0.07 * exp(-3.75 - 0.05 * var_chaste_interface__membrane__V); // per_millisecond
        const double var_sodium_channel_h_gate__beta_h = 1.0 / (1.0 + exp(-4.5 - 0.1 * var_chaste_interface__membrane__V)); // per_millisecond
        const double d_dt_chaste_interface_var_sodium_channel_h_gate__h = (1.0 - var_chaste_interface__sodium_channel_h_gate__h) * var_sodium_channel_h_gate__alpha_h - var_sodium_channel_h_gate__beta_h * var_chaste_interface__sodium_channel_h_gate__h; // 1 / millisecond
        const double var_sodium_channel_m_gate__alpha_m = -0.1 * (50.0 + var_chaste_interface__membrane__V) / (-1.0 + exp(-5.0 - 0.1 * var_chaste_interface__membrane__V)); // per_millisecond
        const double var_sodium_channel_m_gate__beta_m = 4.0 * exp(-4.166666666666666 - 0.05555555555555555 * var_chaste_interface__membrane__V); // per_millisecond
        const double d_dt_chaste_interface_var_sodium_channel_m_gate__m = (1.0 - var_chaste_interface__sodium_channel_m_gate__m) * var_sodium_channel_m_gate__alpha_m - var_sodium_channel_m_gate__beta_m * var_chaste_interface__sodium_channel_m_gate__m; // 1 / millisecond
        
        if (mSetVoltageDerivativeToZero)
        {
            d_dt_chaste_interface_var_membrane__V = 0.0;
        }
        else
        {
            const double var_leakage_current__g_L = 0.3; // milliS_per_cm2
            const double var_membrane__Cm = 1.0; // microF_per_cm2
            const double var_membrane__E_R = -75.0; // millivolt
            const double var_leakage_current__E_L = 10.613 + var_membrane__E_R; // millivolt
            const double var_leakage_current__i_L = (-var_leakage_current__E_L + var_chaste_interface__membrane__V) * var_leakage_current__g_L; // microA_per_cm2
            const double var_membrane__i_Stim_converter = GetIntracellularAreaStimulus(var_chaste_interface__environment__time); // uA_per_cm2
            const double var_membrane__i_Stim = var_membrane__i_Stim_converter; // microA_per_cm2
            const double var_potassium_channel__E_K = -12.0 + var_membrane__E_R; // millivolt
            const double var_potassium_channel__g_K = 36.0; // milliS_per_cm2
            const double var_potassium_channel__i_K = pow(var_chaste_interface__potassium_channel_n_gate__n, 4.0) * (-var_potassium_channel__E_K + var_chaste_interface__membrane__V) * var_potassium_channel__g_K; // microA_per_cm2
            const double var_sodium_channel__E_Na = 115.0 + var_membrane__E_R; // millivolt
            const double var_sodium_channel__g_Na = 120.0; // milliS_per_cm2
            const double var_sodium_channel__i_Na = pow(var_chaste_interface__sodium_channel_m_gate__m, 3.0) * (-var_sodium_channel__E_Na + var_chaste_interface__membrane__V) * var_sodium_channel__g_Na * var_chaste_interface__sodium_channel_h_gate__h; // microA_per_cm2
            d_dt_chaste_interface_var_membrane__V = (-var_leakage_current__i_L - var_membrane__i_Stim - var_potassium_channel__i_K - var_sodium_channel__i_Na) / var_membrane__Cm; // millivolt / millisecond
        }
        
        rDY[0] = d_dt_chaste_interface_var_membrane__V;
        rDY[1] = d_dt_chaste_interface_var_sodium_channel_m_gate__m;
        rDY[2] = d_dt_chaste_interface_var_sodium_channel_h_gate__h;
        rDY[3] = d_dt_chaste_interface_var_potassium_channel_n_gate__n;
    }

template<>
void OdeSystemInformation<Cellhodgkin_huxley_squid_axon_model_1952_modifiedFromCellML>::Initialise(void)
{
    this->mSystemName = "hodgkin_huxley_squid_axon_model_1952_modified";
    this->mFreeVariableName = "time";
    this->mFreeVariableUnits = "millisecond";
    
    // rY[0]:
    this->mVariableNames.push_back("membrane_voltage");
    this->mVariableUnits.push_back("millivolt");
    this->mInitialConditions.push_back(-75.0);
    
    // rY[1]:
    this->mVariableNames.push_back("sodium_channel_m_gate__m");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(0.05);
    
    // rY[2]:
    this->mVariableNames.push_back("sodium_channel_h_gate__h");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(0.6);
    
    // rY[3]:
    this->mVariableNames.push_back("potassium_channel_n_gate__n");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(0.325);
    
    this->mInitialised = true;    
}


// Serialization for Boost >= 1.36
#include "SerializationExportWrapperForCpp.hpp"
CHASTE_CLASS_EXPORT(Cellhodgkin_huxley_squid_axon_model_1952_modifiedFromCellML)