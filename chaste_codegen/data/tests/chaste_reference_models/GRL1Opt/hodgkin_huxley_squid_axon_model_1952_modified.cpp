//! @file
//!
//! This source file was generated from CellML by chaste_codegen version 0.1.0
//!
//! Model: hodgkin_huxley_squid_axon_model_1952_modified
//!
//! Processed by chaste_codegen: https://github.com/ModellingWebLab/chaste-codegen
//!     (translator: chaste_codegen, model type: normal)
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


    Cellhodgkin_huxley_squid_axon_model_1952_modifiedFromCellMLGRL1Opt::Cellhodgkin_huxley_squid_axon_model_1952_modifiedFromCellMLGRL1Opt(boost::shared_ptr<AbstractIvpOdeSolver> /* unused; should be empty */, boost::shared_ptr<AbstractStimulusFunction> pIntracellularStimulus)
        : AbstractGeneralizedRushLarsenCardiacCell(
                4,
                0,
                pIntracellularStimulus)
    {
        // Time units: millisecond
        //
        this->mpSystemInfo = OdeSystemInformation<Cellhodgkin_huxley_squid_axon_model_1952_modifiedFromCellMLGRL1Opt>::Instance();
        Init();
        
    }

    Cellhodgkin_huxley_squid_axon_model_1952_modifiedFromCellMLGRL1Opt::~Cellhodgkin_huxley_squid_axon_model_1952_modifiedFromCellMLGRL1Opt()
    {
    }
    
    double Cellhodgkin_huxley_squid_axon_model_1952_modifiedFromCellMLGRL1Opt::GetIIonic(const std::vector<double>* pStateVariables)
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
        
        const double var_leakage_current__i_L = 19.316099999999999 + 0.29999999999999999 * var_chaste_interface__membrane__V; // microA_per_cm2
        const double var_potassium_channel__i_K = 36.0 * pow(var_chaste_interface__potassium_channel_n_gate__n, 4) * (87.0 + var_chaste_interface__membrane__V); // microA_per_cm2
        const double var_sodium_channel__i_Na = 120.0 * pow(var_chaste_interface__sodium_channel_m_gate__m, 3) * (-40.0 + var_chaste_interface__membrane__V) * var_chaste_interface__sodium_channel_h_gate__h; // microA_per_cm2
        const double var_chaste_interface__i_ionic = var_leakage_current__i_L + var_potassium_channel__i_K + var_sodium_channel__i_Na; // uA_per_cm2

        const double i_ionic = var_chaste_interface__i_ionic;
        EXCEPT_IF_NOT(!std::isnan(i_ionic));
        return i_ionic;
    }

    void Cellhodgkin_huxley_squid_axon_model_1952_modifiedFromCellMLGRL1Opt::UpdateTransmembranePotential(double var_chaste_interface__environment__time)
    {
        std::vector<double>& rY = rGetStateVariables();
        unsigned v_index = GetVoltageIndex();
        const double delta = 1e-8;

        double d_dt_chaste_interface_var_membrane__V;
        double var_chaste_interface__membrane__V = (mSetVoltageDerivativeToZero ? this->mFixedVoltage : rY[0]);
        // Units: millivolt; Initial value: -75.0
        double var_chaste_interface__sodium_channel_m_gate__m = rY[1];
        // Units: dimensionless; Initial value: 0.05
        double var_chaste_interface__sodium_channel_h_gate__h = rY[2];
        // Units: dimensionless; Initial value: 0.6
        double var_chaste_interface__potassium_channel_n_gate__n = rY[3];
        // Units: dimensionless; Initial value: 0.325
        

        // Mathematics
        d_dt_chaste_interface_var_membrane__V = -19.316099999999999 - 1.0 * GetIntracellularAreaStimulus(var_chaste_interface__environment__time) - 0.29999999999999999 * var_chaste_interface__membrane__V - 36.0 * pow(var_chaste_interface__potassium_channel_n_gate__n, 4) * (87.0 + var_chaste_interface__membrane__V) - 120.0 * pow(var_chaste_interface__sodium_channel_m_gate__m, 3) * (-40.0 + var_chaste_interface__membrane__V) * var_chaste_interface__sodium_channel_h_gate__h; // millivolt / millisecond

        double evalF = d_dt_chaste_interface_var_membrane__V;
        mEvalF[0] = d_dt_chaste_interface_var_membrane__V;
        double partialF = EvaluatePartialDerivative0(var_chaste_interface__environment__time, rY, delta, true);
        if (fabs(partialF) < delta)
        {
            rY[v_index] += evalF*mDt;
        }
        else
        {
            rY[v_index] += (evalF/partialF)*(exp(partialF*mDt)-1.0);
        }
    }

    void Cellhodgkin_huxley_squid_axon_model_1952_modifiedFromCellMLGRL1Opt::ComputeOneStepExceptVoltage(double var_chaste_interface__environment__time)
    {
        std::vector<double>& rY = rGetStateVariables();
        const double delta = 1e-8;

        double var_chaste_interface__membrane__V = (mSetVoltageDerivativeToZero ? this->mFixedVoltage : rY[0]);
        // Units: millivolt; Initial value: -75.0
        double var_chaste_interface__sodium_channel_m_gate__m = rY[1];
        // Units: dimensionless; Initial value: 0.05
        double var_chaste_interface__sodium_channel_h_gate__h = rY[2];
        // Units: dimensionless; Initial value: 0.6
        double var_chaste_interface__potassium_channel_n_gate__n = rY[3];
        // Units: dimensionless; Initial value: 0.325
        
        
        // Mathematics
        const double d_dt_chaste_interface_var_potassium_channel_n_gate__n = -0.125 * var_chaste_interface__potassium_channel_n_gate__n * exp(0.9375 + 0.012500000000000001 * var_chaste_interface__membrane__V) - 0.01 * (1.0 - var_chaste_interface__potassium_channel_n_gate__n) * (65.0 + var_chaste_interface__membrane__V) / (-1.0 + exp(-6.5 - 0.10000000000000001 * var_chaste_interface__membrane__V)); // 1 / millisecond
        const double d_dt_chaste_interface_var_sodium_channel_h_gate__h = 0.070000000000000007 * (1.0 - var_chaste_interface__sodium_channel_h_gate__h) * exp(-3.75 - 0.050000000000000003 * var_chaste_interface__membrane__V) - 1.0 * var_chaste_interface__sodium_channel_h_gate__h / (1.0 + exp(-4.5 - 0.10000000000000001 * var_chaste_interface__membrane__V)); // 1 / millisecond
        const double d_dt_chaste_interface_var_sodium_channel_m_gate__m = -4.0 * var_chaste_interface__sodium_channel_m_gate__m * exp(-4.166666666666667 - 0.055555555555555552 * var_chaste_interface__membrane__V) - 0.10000000000000001 * (1.0 - var_chaste_interface__sodium_channel_m_gate__m) * (50.0 + var_chaste_interface__membrane__V) / (-1.0 + exp(-5.0 - 0.10000000000000001 * var_chaste_interface__membrane__V)); // 1 / millisecond
        
        mEvalF[1] = d_dt_chaste_interface_var_sodium_channel_m_gate__m;
        mPartialF[1] = EvaluatePartialDerivative1(var_chaste_interface__environment__time, rY, delta);
        mEvalF[2] = d_dt_chaste_interface_var_sodium_channel_h_gate__h;
        mPartialF[2] = EvaluatePartialDerivative2(var_chaste_interface__environment__time, rY, delta);
        mEvalF[3] = d_dt_chaste_interface_var_potassium_channel_n_gate__n;
        mPartialF[3] = EvaluatePartialDerivative3(var_chaste_interface__environment__time, rY, delta);
        
        {
            if (fabs(mPartialF[1]) < delta){
                rY[1] += mDt*d_dt_chaste_interface_var_sodium_channel_m_gate__m;
            }
            else
            {
                rY[1] += (d_dt_chaste_interface_var_sodium_channel_m_gate__m/mPartialF[1])*(exp(mPartialF[1]*mDt)-1.0);
            }
            
        }
        {
            if (fabs(mPartialF[2]) < delta){
                rY[2] += mDt*d_dt_chaste_interface_var_sodium_channel_h_gate__h;
            }
            else
            {
                rY[2] += (d_dt_chaste_interface_var_sodium_channel_h_gate__h/mPartialF[2])*(exp(mPartialF[2]*mDt)-1.0);
            }
            
        }
        {
            if (fabs(mPartialF[3]) < delta){
                rY[3] += mDt*d_dt_chaste_interface_var_potassium_channel_n_gate__n;
            }
            else
            {
                rY[3] += (d_dt_chaste_interface_var_potassium_channel_n_gate__n/mPartialF[3])*(exp(mPartialF[3]*mDt)-1.0);
            }
            
        }        
        
    }
   
    
    double Cellhodgkin_huxley_squid_axon_model_1952_modifiedFromCellMLGRL1Opt::EvaluateYDerivative0(double var_chaste_interface__environment__time, std::vector<double>& rY)
    {
        double d_dt_chaste_interface_var_membrane__V;
        double var_chaste_interface__membrane__V = (mSetVoltageDerivativeToZero ? this->mFixedVoltage : rY[0]);
        // Units: millivolt; Initial value: -75.0
        double var_chaste_interface__sodium_channel_m_gate__m = rY[1];
        // Units: dimensionless; Initial value: 0.05
        double var_chaste_interface__sodium_channel_h_gate__h = rY[2];
        // Units: dimensionless; Initial value: 0.6
        double var_chaste_interface__potassium_channel_n_gate__n = rY[3];
        // Units: dimensionless; Initial value: 0.325
        
        
        // Mathematics
        d_dt_chaste_interface_var_membrane__V = -19.316099999999999 - 1.0 * GetIntracellularAreaStimulus(var_chaste_interface__environment__time) - 0.29999999999999999 * var_chaste_interface__membrane__V - 36.0 * pow(var_chaste_interface__potassium_channel_n_gate__n, 4) * (87.0 + var_chaste_interface__membrane__V) - 120.0 * pow(var_chaste_interface__sodium_channel_m_gate__m, 3) * (-40.0 + var_chaste_interface__membrane__V) * var_chaste_interface__sodium_channel_h_gate__h; // millivolt / millisecond

        return d_dt_chaste_interface_var_membrane__V;
    }

    double Cellhodgkin_huxley_squid_axon_model_1952_modifiedFromCellMLGRL1Opt::EvaluatePartialDerivative0(double var_chaste_interface__environment__time, std::vector<double>& rY, double delta, bool forceNumerical)
    {
        double partialF;
        if (!forceNumerical && this->mUseAnalyticJacobian)
        {
            double var_chaste_interface__sodium_channel_m_gate__m = rY[1];
            // Units: dimensionless; Initial value: 0.05
            double var_chaste_interface__sodium_channel_h_gate__h = rY[2];
            // Units: dimensionless; Initial value: 0.6
            double var_chaste_interface__potassium_channel_n_gate__n = rY[3];
            // Units: dimensionless; Initial value: 0.325
            
            const double var_x0 = 120.0 * pow(var_chaste_interface__sodium_channel_m_gate__m, 3);
            
            partialF = -0.29999999999999999 - 36.0 * pow(var_chaste_interface__potassium_channel_n_gate__n, 4) - var_x0 * var_chaste_interface__sodium_channel_h_gate__h;
        }
        else
        {
            const double y_save = rY[0];
            rY[0] += delta;
            const double temp = EvaluateYDerivative0(var_chaste_interface__environment__time, rY);
            partialF = (temp-mEvalF[0])/delta;
            rY[0] = y_save;
        }
        return partialF;
    }
    double Cellhodgkin_huxley_squid_axon_model_1952_modifiedFromCellMLGRL1Opt::EvaluateYDerivative1(double var_chaste_interface__environment__time, std::vector<double>& rY)
    {
        
        double var_chaste_interface__membrane__V = (mSetVoltageDerivativeToZero ? this->mFixedVoltage : rY[0]);
        // Units: millivolt; Initial value: -75.0
        double var_chaste_interface__sodium_channel_m_gate__m = rY[1];
        // Units: dimensionless; Initial value: 0.05
        
        
        // Mathematics
        const double d_dt_chaste_interface_var_sodium_channel_m_gate__m = -4.0 * var_chaste_interface__sodium_channel_m_gate__m * exp(-4.166666666666667 - 0.055555555555555552 * var_chaste_interface__membrane__V) - 0.10000000000000001 * (1.0 - var_chaste_interface__sodium_channel_m_gate__m) * (50.0 + var_chaste_interface__membrane__V) / (-1.0 + exp(-5.0 - 0.10000000000000001 * var_chaste_interface__membrane__V)); // 1 / millisecond

        return d_dt_chaste_interface_var_sodium_channel_m_gate__m;
    }

    double Cellhodgkin_huxley_squid_axon_model_1952_modifiedFromCellMLGRL1Opt::EvaluatePartialDerivative1(double var_chaste_interface__environment__time, std::vector<double>& rY, double delta, bool forceNumerical)
    {
        double partialF;
        if (!forceNumerical && this->mUseAnalyticJacobian)
        {
            double var_chaste_interface__membrane__V = (mSetVoltageDerivativeToZero ? this->mFixedVoltage : rY[0]);
            // Units: millivolt; Initial value: -75.0
            
            const double var_x2 = exp(-4.166666666666667 - 0.055555555555555552 * var_chaste_interface__membrane__V);
            const double var_x4 = -0.10000000000000001 * var_chaste_interface__membrane__V;
            const double var_x5 = exp(-5.0 + var_x4);
            const double var_x6 = -1.0 + var_x5;
            const double var_x7 = 0.10000000000000001 / var_x6;
            const double var_x8 = 50.0 + var_chaste_interface__membrane__V;
            
            partialF = -4.0 * var_x2 + var_x7 * var_x8;
        }
        else
        {
            const double y_save = rY[1];
            rY[1] += delta;
            const double temp = EvaluateYDerivative1(var_chaste_interface__environment__time, rY);
            partialF = (temp-mEvalF[1])/delta;
            rY[1] = y_save;
        }
        return partialF;
    }
    double Cellhodgkin_huxley_squid_axon_model_1952_modifiedFromCellMLGRL1Opt::EvaluateYDerivative2(double var_chaste_interface__environment__time, std::vector<double>& rY)
    {
        
        double var_chaste_interface__membrane__V = (mSetVoltageDerivativeToZero ? this->mFixedVoltage : rY[0]);
        // Units: millivolt; Initial value: -75.0
        double var_chaste_interface__sodium_channel_h_gate__h = rY[2];
        // Units: dimensionless; Initial value: 0.6
        
        
        // Mathematics
        const double d_dt_chaste_interface_var_sodium_channel_h_gate__h = 0.070000000000000007 * (1.0 - var_chaste_interface__sodium_channel_h_gate__h) * exp(-3.75 - 0.050000000000000003 * var_chaste_interface__membrane__V) - 1.0 * var_chaste_interface__sodium_channel_h_gate__h / (1.0 + exp(-4.5 - 0.10000000000000001 * var_chaste_interface__membrane__V)); // 1 / millisecond

        return d_dt_chaste_interface_var_sodium_channel_h_gate__h;
    }

    double Cellhodgkin_huxley_squid_axon_model_1952_modifiedFromCellMLGRL1Opt::EvaluatePartialDerivative2(double var_chaste_interface__environment__time, std::vector<double>& rY, double delta, bool forceNumerical)
    {
        double partialF;
        if (!forceNumerical && this->mUseAnalyticJacobian)
        {
            double var_chaste_interface__membrane__V = (mSetVoltageDerivativeToZero ? this->mFixedVoltage : rY[0]);
            // Units: millivolt; Initial value: -75.0
            
            const double var_x4 = -0.10000000000000001 * var_chaste_interface__membrane__V;
            const double var_x9 = exp(-3.75 - 0.050000000000000003 * var_chaste_interface__membrane__V);
            const double var_x10 = exp(-4.5 + var_x4);
            const double var_x11 = 1.0 + var_x10;
            
            partialF = -1.0 / var_x11 - 0.070000000000000007 * var_x9;
        }
        else
        {
            const double y_save = rY[2];
            rY[2] += delta;
            const double temp = EvaluateYDerivative2(var_chaste_interface__environment__time, rY);
            partialF = (temp-mEvalF[2])/delta;
            rY[2] = y_save;
        }
        return partialF;
    }
    double Cellhodgkin_huxley_squid_axon_model_1952_modifiedFromCellMLGRL1Opt::EvaluateYDerivative3(double var_chaste_interface__environment__time, std::vector<double>& rY)
    {
        
        double var_chaste_interface__membrane__V = (mSetVoltageDerivativeToZero ? this->mFixedVoltage : rY[0]);
        // Units: millivolt; Initial value: -75.0
        double var_chaste_interface__potassium_channel_n_gate__n = rY[3];
        // Units: dimensionless; Initial value: 0.325
        
        
        // Mathematics
        const double d_dt_chaste_interface_var_potassium_channel_n_gate__n = -0.125 * var_chaste_interface__potassium_channel_n_gate__n * exp(0.9375 + 0.012500000000000001 * var_chaste_interface__membrane__V) - 0.01 * (1.0 - var_chaste_interface__potassium_channel_n_gate__n) * (65.0 + var_chaste_interface__membrane__V) / (-1.0 + exp(-6.5 - 0.10000000000000001 * var_chaste_interface__membrane__V)); // 1 / millisecond

        return d_dt_chaste_interface_var_potassium_channel_n_gate__n;
    }

    double Cellhodgkin_huxley_squid_axon_model_1952_modifiedFromCellMLGRL1Opt::EvaluatePartialDerivative3(double var_chaste_interface__environment__time, std::vector<double>& rY, double delta, bool forceNumerical)
    {
        double partialF;
        if (!forceNumerical && this->mUseAnalyticJacobian)
        {
            double var_chaste_interface__membrane__V = (mSetVoltageDerivativeToZero ? this->mFixedVoltage : rY[0]);
            // Units: millivolt; Initial value: -75.0
            
            const double var_x4 = -0.10000000000000001 * var_chaste_interface__membrane__V;
            const double var_x13 = exp(-6.5 + var_x4);
            const double var_x14 = -1.0 + var_x13;
            const double var_x15 = 0.01 / var_x14;
            const double var_x16 = exp(0.9375 + 0.012500000000000001 * var_chaste_interface__membrane__V);
            const double var_x17 = 65.0 + var_chaste_interface__membrane__V;
            
            partialF = -0.125 * var_x16 + var_x15 * var_x17;
        }
        else
        {
            const double y_save = rY[3];
            rY[3] += delta;
            const double temp = EvaluateYDerivative3(var_chaste_interface__environment__time, rY);
            partialF = (temp-mEvalF[3])/delta;
            rY[3] = y_save;
        }
        return partialF;
    }

    std::vector<double> Cellhodgkin_huxley_squid_axon_model_1952_modifiedFromCellMLGRL1Opt::ComputeDerivedQuantities(double var_chaste_interface__environment__time, const std::vector<double> & rY)
    {
        // Inputs:
        // Time units: millisecond
        

        // Mathematics
        const double var_membrane__i_Stim = GetIntracellularAreaStimulus(var_chaste_interface__environment__time); // microA_per_cm2

        std::vector<double> dqs(2);
        dqs[0] = var_membrane__i_Stim;
        dqs[1] = var_chaste_interface__environment__time;
        return dqs;
    }

template<>
void OdeSystemInformation<Cellhodgkin_huxley_squid_axon_model_1952_modifiedFromCellMLGRL1Opt>::Initialise(void)
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

    // Derived Quantity index [0]:
    this->mDerivedQuantityNames.push_back("membrane_stimulus_current");
    this->mDerivedQuantityUnits.push_back("microA_per_cm2");

    // Derived Quantity index [1]:
    this->mDerivedQuantityNames.push_back("time");
    this->mDerivedQuantityUnits.push_back("millisecond");

    this->mInitialised = true;
}

// Serialization for Boost >= 1.36
#include "SerializationExportWrapperForCpp.hpp"
CHASTE_CLASS_EXPORT(Cellhodgkin_huxley_squid_axon_model_1952_modifiedFromCellMLGRL1Opt)
