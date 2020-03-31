//! @file
//! 
//! This source file was generated from CellML.
//! 
//! Model: hodgkin_huxley_squid_axon_model_1952_modified
//! 
//! Processed by pycml - CellML Tools in Python
//!     (translators: , pycml: , optimize: )
//! on (date omitted as unimportant)
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

    Dynamichodgkin_huxley_squid_axon_model_1952_modifiedFromCellMLRushLarsen::Dynamichodgkin_huxley_squid_axon_model_1952_modifiedFromCellMLRushLarsen(boost::shared_ptr<AbstractIvpOdeSolver> /* unused; should be empty */, boost::shared_ptr<AbstractStimulusFunction> pIntracellularStimulus)
        : AbstractRushLarsenCardiacCell(
                4,
                0,
                pIntracellularStimulus)
    {
        // Time units: millisecond
        // 
        this->mpSystemInfo = OdeSystemInformation<Dynamichodgkin_huxley_squid_axon_model_1952_modifiedFromCellMLRushLarsen>::Instance();
        Init();

    }
    
    Dynamichodgkin_huxley_squid_axon_model_1952_modifiedFromCellMLRushLarsen::~Dynamichodgkin_huxley_squid_axon_model_1952_modifiedFromCellMLRushLarsen()
    {
    }
    
    double Dynamichodgkin_huxley_squid_axon_model_1952_modifiedFromCellMLRushLarsen::GetIIonic(const std::vector<double>* pStateVariables)
    {
        // For state variable interpolation (SVI) we read in interpolated state variables,
        // otherwise for ionic current interpolation (ICI) we use the state variables of this model (node).
        if (!pStateVariables) pStateVariables = &rGetStateVariables();
        const std::vector<double>& rY = *pStateVariables;
        double var_chaste_interface__membrane__V = (mSetVoltageDerivativeToZero ? this->mFixedVoltage : rY[0]);
        // Units: millivolt; Initial value: -75
        double var_chaste_interface__sodium_channel_m_gate__m = rY[1];
        // Units: dimensionless; Initial value: 0.05
        double var_chaste_interface__sodium_channel_h_gate__h = rY[2];
        // Units: dimensionless; Initial value: 0.6
        double var_chaste_interface__potassium_channel_n_gate__n = rY[3];
        // Units: dimensionless; Initial value: 0.325
        
        const double var_sodium_channel__i_Na = 120.0 * pow(var_chaste_interface__sodium_channel_m_gate__m, 3.0) * var_chaste_interface__sodium_channel_h_gate__h * (var_chaste_interface__membrane__V - 40.0); // microA_per_cm2
        const double var_potassium_channel__i_K = 36.0 * pow(var_chaste_interface__potassium_channel_n_gate__n, 4.0) * (var_chaste_interface__membrane__V -  -87.0); // microA_per_cm2
        const double var_leakage_current__i_L = 0.29999999999999999 * (var_chaste_interface__membrane__V -  -64.387); // microA_per_cm2
        const double var_chaste_interface__i_ionic = var_sodium_channel__i_Na + var_potassium_channel__i_K + var_leakage_current__i_L; // uA_per_cm2
        
        const double i_ionic = var_chaste_interface__i_ionic;
        EXCEPT_IF_NOT(!std::isnan(i_ionic));
        return i_ionic;
    }
    
    void Dynamichodgkin_huxley_squid_axon_model_1952_modifiedFromCellMLRushLarsen::EvaluateEquations(double var_chaste_interface__environment__time, std::vector<double> &rDY, std::vector<double> &rAlphaOrTau, std::vector<double> &rBetaOrInf)
    {
        std::vector<double>& rY = rGetStateVariables();
        double var_chaste_interface__membrane__V = (mSetVoltageDerivativeToZero ? this->mFixedVoltage : rY[0]);
        // Units: millivolt; Initial value: -75
        double var_chaste_interface__sodium_channel_m_gate__m = rY[1];
        // Units: dimensionless; Initial value: 0.05
        double var_chaste_interface__sodium_channel_h_gate__h = rY[2];
        // Units: dimensionless; Initial value: 0.6
        double var_chaste_interface__potassium_channel_n_gate__n = rY[3];
        // Units: dimensionless; Initial value: 0.325
        
        
        // Mathematics
        double d_dt_chaste_interface__membrane__V;
        
        if (mSetVoltageDerivativeToZero)
        {
            d_dt_chaste_interface__membrane__V = 0.0;
        }
        else
        {
            const double var_membrane__Cm = 1.0; // microF_per_cm2
            const double var_sodium_channel__i_Na = 120.0 * pow(var_chaste_interface__sodium_channel_m_gate__m, 3.0) * var_chaste_interface__sodium_channel_h_gate__h * (var_chaste_interface__membrane__V - 40.0); // microA_per_cm2
            const double var_potassium_channel__i_K = 36.0 * pow(var_chaste_interface__potassium_channel_n_gate__n, 4.0) * (var_chaste_interface__membrane__V -  -87.0); // microA_per_cm2
            const double var_leakage_current__i_L = 0.29999999999999999 * (var_chaste_interface__membrane__V -  -64.387); // microA_per_cm2
            const double var_chaste_interface__membrane__i_Stim = GetIntracellularAreaStimulus(var_chaste_interface__environment__time);
            d_dt_chaste_interface__membrane__V = (-(var_chaste_interface__membrane__i_Stim + var_sodium_channel__i_Na + var_potassium_channel__i_K + var_leakage_current__i_L)) / var_membrane__Cm; // 'millivolt per millisecond'
        }
        
        rDY[0] = d_dt_chaste_interface__membrane__V;
        rAlphaOrTau[1] = ( -0.10000000000000001 * (var_chaste_interface__membrane__V + 50.0)) / (exp((-(var_chaste_interface__membrane__V + 50.0)) * 0.10000000000000001) - 1.0);
        rBetaOrInf[1] = 4.0 * exp((-(var_chaste_interface__membrane__V + 75.0)) * 0.055555555555555552);
        rAlphaOrTau[2] = 0.070000000000000007 * exp((-(var_chaste_interface__membrane__V + 75.0)) * 0.050000000000000003);
        rBetaOrInf[2] = 1.0 / (exp((-(var_chaste_interface__membrane__V + 45.0)) * 0.10000000000000001) + 1.0);
        rAlphaOrTau[3] = ( -0.01 * (var_chaste_interface__membrane__V + 65.0)) / (exp((-(var_chaste_interface__membrane__V + 65.0)) * 0.10000000000000001) - 1.0);
        rBetaOrInf[3] = 0.125 * exp((var_chaste_interface__membrane__V + 75.0) * 0.012500000000000001);
    }
    
    void Dynamichodgkin_huxley_squid_axon_model_1952_modifiedFromCellMLRushLarsen::ComputeOneStepExceptVoltage(const std::vector<double> &rDY, const std::vector<double> &rAlphaOrTau, const std::vector<double> &rBetaOrInf)
    {
        std::vector<double>& rY = rGetStateVariables();
        {
            const double tau_inv = rAlphaOrTau[1] + rBetaOrInf[1];
            const double y_inf = rAlphaOrTau[1] / tau_inv;
            rY[1] = y_inf + (rY[1] - y_inf)*exp(-mDt*tau_inv);
        }
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
    }
    
template<>
void OdeSystemInformation<Dynamichodgkin_huxley_squid_axon_model_1952_modifiedFromCellMLRushLarsen>::Initialise(void)
{
    this->mSystemName = "hodgkin_huxley_squid_axon_model_1952_modified";
    this->mFreeVariableName = "environment__time";
    this->mFreeVariableUnits = "millisecond";
    
    // rY[0]:
    this->mVariableNames.push_back("membrane_voltage");
    this->mVariableUnits.push_back("millivolt");
    this->mInitialConditions.push_back(-75);

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
CHASTE_CLASS_EXPORT(Dynamichodgkin_huxley_squid_axon_model_1952_modifiedFromCellMLRushLarsen)
extern "C"
{
    AbstractCardiacCellInterface* MakeCardiacCell(
            boost::shared_ptr<AbstractIvpOdeSolver> pSolver,
            boost::shared_ptr<AbstractStimulusFunction> pStimulus)
    {
        return new Dynamichodgkin_huxley_squid_axon_model_1952_modifiedFromCellMLRushLarsen(pSolver, pStimulus);
    }
    
}

