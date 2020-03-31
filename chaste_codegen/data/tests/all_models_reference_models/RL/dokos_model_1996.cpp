//! @file
//! 
//! This source file was generated from CellML.
//! 
//! Model: dokos_model_1996
//! 
//! Processed by pycml - CellML Tools in Python
//!     (translators: , pycml: , optimize: )
//! on (date omitted as unimportant)
//! 
//! <autogenerated>

#include "dokos_model_1996.hpp"
#include <cmath>
#include <cassert>
#include <memory>
#include "Exception.hpp"
#include "OdeSystemInformation.hpp"
#include "RegularStimulus.hpp"
#include "HeartConfig.hpp"
#include "IsNan.hpp"
#include "MathsCustomFunctions.hpp"

    Dynamicdokos_model_1996FromCellMLRushLarsen::Dynamicdokos_model_1996FromCellMLRushLarsen(boost::shared_ptr<AbstractIvpOdeSolver> /* unused; should be empty */, boost::shared_ptr<AbstractStimulusFunction> pIntracellularStimulus)
        : AbstractRushLarsenCardiacCell(
                18,
                0,
                pIntracellularStimulus)
    {
        // Time units: millisecond
        // 
        this->mpSystemInfo = OdeSystemInformation<Dynamicdokos_model_1996FromCellMLRushLarsen>::Instance();
        Init();

    }
    
    Dynamicdokos_model_1996FromCellMLRushLarsen::~Dynamicdokos_model_1996FromCellMLRushLarsen()
    {
    }
    
    double Dynamicdokos_model_1996FromCellMLRushLarsen::GetIIonic(const std::vector<double>* pStateVariables)
    {
        // For state variable interpolation (SVI) we read in interpolated state variables,
        // otherwise for ionic current interpolation (ICI) we use the state variables of this model (node).
        if (!pStateVariables) pStateVariables = &rGetStateVariables();
        const std::vector<double>& rY = *pStateVariables;
        double var_chaste_interface__membrane__E = (mSetVoltageDerivativeToZero ? this->mFixedVoltage : rY[0]);
        // Units: millivolt; Initial value: -64.9
        double var_chaste_interface__L_type_calcium_current_d_gate__dL = rY[1];
        // Units: dimensionless; Initial value: 0.0001
        double var_chaste_interface__L_type_calcium_current_f_gate__fL = rY[2];
        // Units: dimensionless; Initial value: 0.1505
        double var_chaste_interface__L_type_calcium_current_f2_gate__fL2 = rY[3];
        // Units: dimensionless; Initial value: 0.219
        double var_chaste_interface__T_type_calcium_current_d_gate__dT = rY[4];
        // Units: dimensionless; Initial value: 0.001
        double var_chaste_interface__T_type_calcium_current_f_gate__fT = rY[5];
        // Units: dimensionless; Initial value: 0.1328
        double var_chaste_interface__fast_sodium_current_m_gate__m = rY[6];
        // Units: dimensionless; Initial value: 0.0139
        double var_chaste_interface__fast_sodium_current_h_gate__h = rY[7];
        // Units: dimensionless; Initial value: 0.0087
        double var_chaste_interface__delayed_rectifying_potassium_current_x_gate__x = rY[8];
        // Units: dimensionless; Initial value: 0.5682
        double var_chaste_interface__hyperpolarising_activated_current_y_gate__y = rY[9];
        // Units: dimensionless; Initial value: 0.0287
        double var_chaste_interface__ion_concentrations__Cai = rY[10];
        // Units: millimolar; Initial value: 0.000034
        double var_chaste_interface__ion_concentrations__Cao = rY[11];
        // Units: millimolar; Initial value: 2.0004
        double var_chaste_interface__ion_concentrations__Nai = rY[14];
        // Units: millimolar; Initial value: 7.4994
        double var_chaste_interface__ion_concentrations__Nao = rY[15];
        // Units: millimolar; Initial value: 139.9929
        double var_chaste_interface__ion_concentrations__Ki = rY[16];
        // Units: millimolar; Initial value: 140.0073
        double var_chaste_interface__ion_concentrations__Ko = rY[17];
        // Units: millimolar; Initial value: 5.4243
        
        const double var_membrane__C = 3.1999999999999999e-05; // nanoF
        const double var_reversal_potentials__E_Na = 26.713760659695648 * log(var_chaste_interface__ion_concentrations__Nao / var_chaste_interface__ion_concentrations__Nai); // millivolt
        const double var_hyperpolarising_activated_current__i_fNa = ((var_chaste_interface__hyperpolarising_activated_current_y_gate__y * pow(var_chaste_interface__ion_concentrations__Ko, 1.8300000000000001)) / (pow(var_chaste_interface__ion_concentrations__Ko, 1.8300000000000001) + 71.36612580598495)) * 0.0080999999999999996 * (var_chaste_interface__membrane__E - var_reversal_potentials__E_Na); // picoA
        const double var_hyperpolarising_activated_current__i_fK = ((var_chaste_interface__hyperpolarising_activated_current_y_gate__y * pow(var_chaste_interface__ion_concentrations__Ko, 1.8300000000000001)) / (pow(var_chaste_interface__ion_concentrations__Ko, 1.8300000000000001) + 71.36612580598495)) * 0.0135 * (var_chaste_interface__membrane__E - (26.713760659695648 * log(var_chaste_interface__ion_concentrations__Ko / var_chaste_interface__ion_concentrations__Ki))); // picoA
        const double var_fast_sodium_current__i_Na = 0.25 * pow(var_chaste_interface__fast_sodium_current_m_gate__m, 3.0) * var_chaste_interface__fast_sodium_current_h_gate__h * (var_chaste_interface__membrane__E - var_reversal_potentials__E_Na); // picoA
        const double var_reversal_potentials__E_Ca = 13.356880329847824 * log(var_chaste_interface__ion_concentrations__Cao / var_chaste_interface__ion_concentrations__Cai); // millivolt
        const double var_L_type_calcium_current__i_CaL = 0.40000000000000002 * var_chaste_interface__L_type_calcium_current_d_gate__dL * var_chaste_interface__L_type_calcium_current_f_gate__fL * var_chaste_interface__L_type_calcium_current_f2_gate__fL2 * ((var_chaste_interface__membrane__E - var_reversal_potentials__E_Ca) + 75.0); // picoA
        const double var_sodium_calcium_exchange_current__do = 1.0 + (var_chaste_interface__ion_concentrations__Cao * 0.27300027300027302) + ((var_chaste_interface__ion_concentrations__Cao * 0.27300027300027302) * exp((var_chaste_interface__membrane__E * 0.0) * 3.8797490106562429e-07)) + (var_chaste_interface__ion_concentrations__Nao * 0.00061425061425061424) + (pow(var_chaste_interface__ion_concentrations__Nao, 2.0) * 1.094140745013563e-06) + (pow(var_chaste_interface__ion_concentrations__Nao, 3.0) * 2.3464309350494597e-07); // dimensionless
        const double var_sodium_calcium_exchange_current__k23 = (((pow(var_chaste_interface__ion_concentrations__Nao, 2.0) * 1.094140745013563e-06) + (pow(var_chaste_interface__ion_concentrations__Nao, 3.0) * 2.3464309350494597e-07)) * exp((var_chaste_interface__membrane__E *  -41633.42485725) * 1.9398745053281215e-07)) / var_sodium_calcium_exchange_current__do; // dimensionless
        const double var_sodium_calcium_exchange_current__k32 = exp((var_chaste_interface__membrane__E * 41633.42485725) * 1.9398745053281215e-07); // dimensionless
        const double var_sodium_calcium_exchange_current__k41 = exp((var_chaste_interface__membrane__E *  -41633.42485725) * 1.9398745053281215e-07); // dimensionless
        const double var_sodium_calcium_exchange_current__k43 = var_chaste_interface__ion_concentrations__Nai / (26.440000000000001 + var_chaste_interface__ion_concentrations__Nai); // dimensionless
        const double var_sodium_calcium_exchange_current__k34 = var_chaste_interface__ion_concentrations__Nao / (4.6630000000000003 + var_chaste_interface__ion_concentrations__Nao); // dimensionless
        const double var_sodium_calcium_exchange_current__k21 = ((var_chaste_interface__ion_concentrations__Cao * 0.27300027300027302) * exp((var_chaste_interface__membrane__E *  -0.0) * 3.8797490106562429e-07)) / var_sodium_calcium_exchange_current__do; // dimensionless
        const double var_sodium_calcium_exchange_current__x1 = (var_sodium_calcium_exchange_current__k41 * var_sodium_calcium_exchange_current__k34 * (var_sodium_calcium_exchange_current__k23 + var_sodium_calcium_exchange_current__k21)) + (var_sodium_calcium_exchange_current__k21 * var_sodium_calcium_exchange_current__k32 * (var_sodium_calcium_exchange_current__k43 + var_sodium_calcium_exchange_current__k41)); // dimensionless
        const double var_sodium_calcium_exchange_current__di = 1.0 + (var_chaste_interface__ion_concentrations__Cai * 48.309178743961354) + ((var_chaste_interface__ion_concentrations__Cai * 48.309178743961354) * exp((var_chaste_interface__membrane__E *  -13208.843251349999) * 3.8797490106562429e-07)) + ((var_chaste_interface__ion_concentrations__Cai * var_chaste_interface__ion_concentrations__Nai) * 1.8271247633873431) + (var_chaste_interface__ion_concentrations__Nai * 0.0025297242600556538) + (pow(var_chaste_interface__ion_concentrations__Nai, 2.0) * 0.0011051656880977081) + (pow(var_chaste_interface__ion_concentrations__Nai, 3.0) * 4.1799004844845232e-05); // dimensionless
        const double var_sodium_calcium_exchange_current__k14 = (((pow(var_chaste_interface__ion_concentrations__Nai, 2.0) * 0.0011051656880977081) + (pow(var_chaste_interface__ion_concentrations__Nai, 3.0) * 4.1799004844845232e-05)) * exp((var_chaste_interface__membrane__E * 41633.42485725) * 1.9398745053281215e-07)) / var_sodium_calcium_exchange_current__di; // dimensionless
        const double var_sodium_calcium_exchange_current__k12 = ((var_chaste_interface__ion_concentrations__Cai * 48.309178743961354) * exp((var_chaste_interface__membrane__E *  -13208.843251349999) * 3.8797490106562429e-07)) / var_sodium_calcium_exchange_current__di; // dimensionless
        const double var_sodium_calcium_exchange_current__x2 = (var_sodium_calcium_exchange_current__k32 * var_sodium_calcium_exchange_current__k43 * (var_sodium_calcium_exchange_current__k14 + var_sodium_calcium_exchange_current__k12)) + (var_sodium_calcium_exchange_current__k41 * var_sodium_calcium_exchange_current__k12 * (var_sodium_calcium_exchange_current__k34 + var_sodium_calcium_exchange_current__k32)); // dimensionless
        const double var_sodium_calcium_exchange_current__i_NaCa = (4.0 * ((var_sodium_calcium_exchange_current__x2 * var_sodium_calcium_exchange_current__k21) - (var_sodium_calcium_exchange_current__x1 * var_sodium_calcium_exchange_current__k12))) / (var_sodium_calcium_exchange_current__x1 + var_sodium_calcium_exchange_current__x2 + ((var_sodium_calcium_exchange_current__k14 * var_sodium_calcium_exchange_current__k43 * (var_sodium_calcium_exchange_current__k23 + var_sodium_calcium_exchange_current__k21)) + (var_sodium_calcium_exchange_current__k12 * var_sodium_calcium_exchange_current__k23 * (var_sodium_calcium_exchange_current__k43 + var_sodium_calcium_exchange_current__k41))) + ((var_sodium_calcium_exchange_current__k23 * var_sodium_calcium_exchange_current__k34 * (var_sodium_calcium_exchange_current__k14 + var_sodium_calcium_exchange_current__k12)) + (var_sodium_calcium_exchange_current__k14 * var_sodium_calcium_exchange_current__k21 * (var_sodium_calcium_exchange_current__k34 + var_sodium_calcium_exchange_current__k32)))); // picoA
        const double var_delayed_rectifying_potassium_current__i_KNa = var_chaste_interface__delayed_rectifying_potassium_current_x_gate__x * pow(var_chaste_interface__ion_concentrations__Ko * 1.0, 0.58999999999999997) * (var_chaste_interface__ion_concentrations__Nai - (var_chaste_interface__ion_concentrations__Nao * exp(((-var_chaste_interface__membrane__E) * 96485.341499999995) * 3.8797490106562429e-07))) * 9.0999999999999993e-06; // picoA
        const double var_delayed_rectifying_potassium_current__i_KK = var_chaste_interface__delayed_rectifying_potassium_current_x_gate__x * 0.00025999999999999998 * pow(var_chaste_interface__ion_concentrations__Ko * 1.0, 0.58999999999999997) * (var_chaste_interface__ion_concentrations__Ki - (var_chaste_interface__ion_concentrations__Ko * exp(((-var_chaste_interface__membrane__E) * 96485.341499999995) * 3.8797490106562429e-07))); // picoA
        const double var_T_type_calcium_current__i_CaT = 0.085000000000000006 * var_chaste_interface__T_type_calcium_current_d_gate__dT * var_chaste_interface__T_type_calcium_current_f_gate__fT * ((var_chaste_interface__membrane__E - var_reversal_potentials__E_Ca) + 75.0); // picoA
        const double var_background_sodium_current__i_bNa = 0.00024000000000000001 * (var_chaste_interface__membrane__E - var_reversal_potentials__E_Na); // picoA
        const double var_sodium_potassium_pump__i_p = ((((0.22600000000000001 * var_chaste_interface__ion_concentrations__Nai) / (var_chaste_interface__ion_concentrations__Nai + 40.0)) * var_chaste_interface__ion_concentrations__Ko) / (var_chaste_interface__ion_concentrations__Ko + 1.0)) * (1.0 - pow((var_chaste_interface__membrane__E - 40.0) * 0.0047393364928909956, 2.0)); // picoA
        const double var_background_potassium_current__i_bK = 6.9999999999999994e-05 * pow(var_chaste_interface__ion_concentrations__Ko * 1.0, 0.40999999999999998) * (var_chaste_interface__ion_concentrations__Ki - (var_chaste_interface__ion_concentrations__Ko * exp(((-var_chaste_interface__membrane__E) * 96485.341499999995) * 3.8797490106562429e-07))); // picoA
        const double var_membrane__i_tot = var_L_type_calcium_current__i_CaL + var_T_type_calcium_current__i_CaT + var_fast_sodium_current__i_Na + (var_delayed_rectifying_potassium_current__i_KK + var_delayed_rectifying_potassium_current__i_KNa) + (var_hyperpolarising_activated_current__i_fK + var_hyperpolarising_activated_current__i_fNa) + var_sodium_potassium_pump__i_p + var_sodium_calcium_exchange_current__i_NaCa + var_background_sodium_current__i_bNa + var_background_potassium_current__i_bK; // picoA
        const double var_chaste_interface__i_ionic = 0.001 * (((var_membrane__i_tot) / var_membrane__C) * HeartConfig::Instance()->GetCapacitance()); // uA_per_cm2
        
        const double i_ionic = var_chaste_interface__i_ionic;
        EXCEPT_IF_NOT(!std::isnan(i_ionic));
        return i_ionic;
    }
    
    void Dynamicdokos_model_1996FromCellMLRushLarsen::EvaluateEquations(double var_chaste_interface__environment__time, std::vector<double> &rDY, std::vector<double> &rAlphaOrTau, std::vector<double> &rBetaOrInf)
    {
        std::vector<double>& rY = rGetStateVariables();
        double var_chaste_interface__membrane__E = (mSetVoltageDerivativeToZero ? this->mFixedVoltage : rY[0]);
        // Units: millivolt; Initial value: -64.9
        double var_chaste_interface__L_type_calcium_current_d_gate__dL = rY[1];
        // Units: dimensionless; Initial value: 0.0001
        double var_chaste_interface__L_type_calcium_current_f_gate__fL = rY[2];
        // Units: dimensionless; Initial value: 0.1505
        double var_chaste_interface__L_type_calcium_current_f2_gate__fL2 = rY[3];
        // Units: dimensionless; Initial value: 0.219
        double var_chaste_interface__T_type_calcium_current_d_gate__dT = rY[4];
        // Units: dimensionless; Initial value: 0.001
        double var_chaste_interface__T_type_calcium_current_f_gate__fT = rY[5];
        // Units: dimensionless; Initial value: 0.1328
        double var_chaste_interface__fast_sodium_current_m_gate__m = rY[6];
        // Units: dimensionless; Initial value: 0.0139
        double var_chaste_interface__fast_sodium_current_h_gate__h = rY[7];
        // Units: dimensionless; Initial value: 0.0087
        double var_chaste_interface__delayed_rectifying_potassium_current_x_gate__x = rY[8];
        // Units: dimensionless; Initial value: 0.5682
        double var_chaste_interface__hyperpolarising_activated_current_y_gate__y = rY[9];
        // Units: dimensionless; Initial value: 0.0287
        double var_chaste_interface__ion_concentrations__Cai = rY[10];
        // Units: millimolar; Initial value: 0.000034
        double var_chaste_interface__ion_concentrations__Cao = rY[11];
        // Units: millimolar; Initial value: 2.0004
        double var_chaste_interface__ion_concentrations__Caup = rY[12];
        // Units: millimolar; Initial value: 0.5832
        double var_chaste_interface__ion_concentrations__Carel = rY[13];
        // Units: millimolar; Initial value: 0.1101
        double var_chaste_interface__ion_concentrations__Nai = rY[14];
        // Units: millimolar; Initial value: 7.4994
        double var_chaste_interface__ion_concentrations__Nao = rY[15];
        // Units: millimolar; Initial value: 139.9929
        double var_chaste_interface__ion_concentrations__Ki = rY[16];
        // Units: millimolar; Initial value: 140.0073
        double var_chaste_interface__ion_concentrations__Ko = rY[17];
        // Units: millimolar; Initial value: 5.4243
        
        
        // Mathematics
        double d_dt_chaste_interface__membrane__E;
        const double var_reversal_potentials__E_Na = 26.713760659695648 * log(var_chaste_interface__ion_concentrations__Nao / var_chaste_interface__ion_concentrations__Nai); // millivolt
        const double var_hyperpolarising_activated_current__i_fNa = ((var_chaste_interface__hyperpolarising_activated_current_y_gate__y * pow(var_chaste_interface__ion_concentrations__Ko, 1.8300000000000001)) / (pow(var_chaste_interface__ion_concentrations__Ko, 1.8300000000000001) + 71.36612580598495)) * 0.0080999999999999996 * (var_chaste_interface__membrane__E - var_reversal_potentials__E_Na); // picoA
        const double var_hyperpolarising_activated_current__i_fK = ((var_chaste_interface__hyperpolarising_activated_current_y_gate__y * pow(var_chaste_interface__ion_concentrations__Ko, 1.8300000000000001)) / (pow(var_chaste_interface__ion_concentrations__Ko, 1.8300000000000001) + 71.36612580598495)) * 0.0135 * (var_chaste_interface__membrane__E - (26.713760659695648 * log(var_chaste_interface__ion_concentrations__Ko / var_chaste_interface__ion_concentrations__Ki))); // picoA
        const double var_fast_sodium_current__i_Na = 0.25 * pow(var_chaste_interface__fast_sodium_current_m_gate__m, 3.0) * var_chaste_interface__fast_sodium_current_h_gate__h * (var_chaste_interface__membrane__E - var_reversal_potentials__E_Na); // picoA
        const double var_reversal_potentials__E_Ca = 13.356880329847824 * log(var_chaste_interface__ion_concentrations__Cao / var_chaste_interface__ion_concentrations__Cai); // millivolt
        const double var_L_type_calcium_current__i_CaL = 0.40000000000000002 * var_chaste_interface__L_type_calcium_current_d_gate__dL * var_chaste_interface__L_type_calcium_current_f_gate__fL * var_chaste_interface__L_type_calcium_current_f2_gate__fL2 * ((var_chaste_interface__membrane__E - var_reversal_potentials__E_Ca) + 75.0); // picoA
        const double var_sodium_calcium_exchange_current__do = 1.0 + (var_chaste_interface__ion_concentrations__Cao * 0.27300027300027302) + ((var_chaste_interface__ion_concentrations__Cao * 0.27300027300027302) * exp((var_chaste_interface__membrane__E * 0.0) * 3.8797490106562429e-07)) + (var_chaste_interface__ion_concentrations__Nao * 0.00061425061425061424) + (pow(var_chaste_interface__ion_concentrations__Nao, 2.0) * 1.094140745013563e-06) + (pow(var_chaste_interface__ion_concentrations__Nao, 3.0) * 2.3464309350494597e-07); // dimensionless
        const double var_sodium_calcium_exchange_current__k23 = (((pow(var_chaste_interface__ion_concentrations__Nao, 2.0) * 1.094140745013563e-06) + (pow(var_chaste_interface__ion_concentrations__Nao, 3.0) * 2.3464309350494597e-07)) * exp((var_chaste_interface__membrane__E *  -41633.42485725) * 1.9398745053281215e-07)) / var_sodium_calcium_exchange_current__do; // dimensionless
        const double var_sodium_calcium_exchange_current__k32 = exp((var_chaste_interface__membrane__E * 41633.42485725) * 1.9398745053281215e-07); // dimensionless
        const double var_sodium_calcium_exchange_current__k41 = exp((var_chaste_interface__membrane__E *  -41633.42485725) * 1.9398745053281215e-07); // dimensionless
        const double var_sodium_calcium_exchange_current__k43 = var_chaste_interface__ion_concentrations__Nai / (26.440000000000001 + var_chaste_interface__ion_concentrations__Nai); // dimensionless
        const double var_sodium_calcium_exchange_current__k34 = var_chaste_interface__ion_concentrations__Nao / (4.6630000000000003 + var_chaste_interface__ion_concentrations__Nao); // dimensionless
        const double var_sodium_calcium_exchange_current__k21 = ((var_chaste_interface__ion_concentrations__Cao * 0.27300027300027302) * exp((var_chaste_interface__membrane__E *  -0.0) * 3.8797490106562429e-07)) / var_sodium_calcium_exchange_current__do; // dimensionless
        const double var_sodium_calcium_exchange_current__x1 = (var_sodium_calcium_exchange_current__k41 * var_sodium_calcium_exchange_current__k34 * (var_sodium_calcium_exchange_current__k23 + var_sodium_calcium_exchange_current__k21)) + (var_sodium_calcium_exchange_current__k21 * var_sodium_calcium_exchange_current__k32 * (var_sodium_calcium_exchange_current__k43 + var_sodium_calcium_exchange_current__k41)); // dimensionless
        const double var_sodium_calcium_exchange_current__di = 1.0 + (var_chaste_interface__ion_concentrations__Cai * 48.309178743961354) + ((var_chaste_interface__ion_concentrations__Cai * 48.309178743961354) * exp((var_chaste_interface__membrane__E *  -13208.843251349999) * 3.8797490106562429e-07)) + ((var_chaste_interface__ion_concentrations__Cai * var_chaste_interface__ion_concentrations__Nai) * 1.8271247633873431) + (var_chaste_interface__ion_concentrations__Nai * 0.0025297242600556538) + (pow(var_chaste_interface__ion_concentrations__Nai, 2.0) * 0.0011051656880977081) + (pow(var_chaste_interface__ion_concentrations__Nai, 3.0) * 4.1799004844845232e-05); // dimensionless
        const double var_sodium_calcium_exchange_current__k14 = (((pow(var_chaste_interface__ion_concentrations__Nai, 2.0) * 0.0011051656880977081) + (pow(var_chaste_interface__ion_concentrations__Nai, 3.0) * 4.1799004844845232e-05)) * exp((var_chaste_interface__membrane__E * 41633.42485725) * 1.9398745053281215e-07)) / var_sodium_calcium_exchange_current__di; // dimensionless
        const double var_sodium_calcium_exchange_current__k12 = ((var_chaste_interface__ion_concentrations__Cai * 48.309178743961354) * exp((var_chaste_interface__membrane__E *  -13208.843251349999) * 3.8797490106562429e-07)) / var_sodium_calcium_exchange_current__di; // dimensionless
        const double var_sodium_calcium_exchange_current__x2 = (var_sodium_calcium_exchange_current__k32 * var_sodium_calcium_exchange_current__k43 * (var_sodium_calcium_exchange_current__k14 + var_sodium_calcium_exchange_current__k12)) + (var_sodium_calcium_exchange_current__k41 * var_sodium_calcium_exchange_current__k12 * (var_sodium_calcium_exchange_current__k34 + var_sodium_calcium_exchange_current__k32)); // dimensionless
        const double var_sodium_calcium_exchange_current__i_NaCa = (4.0 * ((var_sodium_calcium_exchange_current__x2 * var_sodium_calcium_exchange_current__k21) - (var_sodium_calcium_exchange_current__x1 * var_sodium_calcium_exchange_current__k12))) / (var_sodium_calcium_exchange_current__x1 + var_sodium_calcium_exchange_current__x2 + ((var_sodium_calcium_exchange_current__k14 * var_sodium_calcium_exchange_current__k43 * (var_sodium_calcium_exchange_current__k23 + var_sodium_calcium_exchange_current__k21)) + (var_sodium_calcium_exchange_current__k12 * var_sodium_calcium_exchange_current__k23 * (var_sodium_calcium_exchange_current__k43 + var_sodium_calcium_exchange_current__k41))) + ((var_sodium_calcium_exchange_current__k23 * var_sodium_calcium_exchange_current__k34 * (var_sodium_calcium_exchange_current__k14 + var_sodium_calcium_exchange_current__k12)) + (var_sodium_calcium_exchange_current__k14 * var_sodium_calcium_exchange_current__k21 * (var_sodium_calcium_exchange_current__k34 + var_sodium_calcium_exchange_current__k32)))); // picoA
        const double var_delayed_rectifying_potassium_current__i_KNa = var_chaste_interface__delayed_rectifying_potassium_current_x_gate__x * pow(var_chaste_interface__ion_concentrations__Ko * 1.0, 0.58999999999999997) * (var_chaste_interface__ion_concentrations__Nai - (var_chaste_interface__ion_concentrations__Nao * exp(((-var_chaste_interface__membrane__E) * 96485.341499999995) * 3.8797490106562429e-07))) * 9.0999999999999993e-06; // picoA
        const double var_delayed_rectifying_potassium_current__i_KK = var_chaste_interface__delayed_rectifying_potassium_current_x_gate__x * 0.00025999999999999998 * pow(var_chaste_interface__ion_concentrations__Ko * 1.0, 0.58999999999999997) * (var_chaste_interface__ion_concentrations__Ki - (var_chaste_interface__ion_concentrations__Ko * exp(((-var_chaste_interface__membrane__E) * 96485.341499999995) * 3.8797490106562429e-07))); // picoA
        const double var_T_type_calcium_current__i_CaT = 0.085000000000000006 * var_chaste_interface__T_type_calcium_current_d_gate__dT * var_chaste_interface__T_type_calcium_current_f_gate__fT * ((var_chaste_interface__membrane__E - var_reversal_potentials__E_Ca) + 75.0); // picoA
        const double var_background_sodium_current__i_bNa = 0.00024000000000000001 * (var_chaste_interface__membrane__E - var_reversal_potentials__E_Na); // picoA
        const double var_sodium_potassium_pump__i_p = ((((0.22600000000000001 * var_chaste_interface__ion_concentrations__Nai) / (var_chaste_interface__ion_concentrations__Nai + 40.0)) * var_chaste_interface__ion_concentrations__Ko) / (var_chaste_interface__ion_concentrations__Ko + 1.0)) * (1.0 - pow((var_chaste_interface__membrane__E - 40.0) * 0.0047393364928909956, 2.0)); // picoA
        const double var_background_potassium_current__i_bK = 6.9999999999999994e-05 * pow(var_chaste_interface__ion_concentrations__Ko * 1.0, 0.40999999999999998) * (var_chaste_interface__ion_concentrations__Ki - (var_chaste_interface__ion_concentrations__Ko * exp(((-var_chaste_interface__membrane__E) * 96485.341499999995) * 3.8797490106562429e-07))); // picoA
        const double var_sarcoplasmic_reticulum_kinetics__i_up = (0.0212 * pow(var_chaste_interface__ion_concentrations__Cai, 2.0)) / (pow(var_chaste_interface__ion_concentrations__Cai, 2.0) + 2.4999999999999999e-07); // picoA
        const double var_sarcoplasmic_reticulum_kinetics__i_tr = 0.0072364006125000008 * var_chaste_interface__ion_concentrations__Caup; // picoA
        const double var_sarcoplasmic_reticulum_kinetics__i_rel = (0.57891204900000004 * var_chaste_interface__ion_concentrations__Carel * pow(var_chaste_interface__ion_concentrations__Cai, 2.0)) / (pow(var_chaste_interface__ion_concentrations__Cai, 2.0) + 9.9999999999999995e-07); // picoA
        const double d_dt_chaste_interface__L_type_calcium_current_d_gate__dL = 0.001 * (((1.0 / (1.0 + exp((var_chaste_interface__membrane__E + 6.5999999999999996) *  -0.15151515151515152))) - var_chaste_interface__L_type_calcium_current_d_gate__dL) * 500.0); // 'per millisecond'
        const double d_dt_chaste_interface__L_type_calcium_current_f2_gate__fL2 = 0.001 * ((3.0 * (1.0 - var_chaste_interface__L_type_calcium_current_f2_gate__fL2)) - (40000.0 * var_chaste_interface__ion_concentrations__Cai * var_chaste_interface__L_type_calcium_current_f2_gate__fL2)); // 'per millisecond'
        const double d_dt_chaste_interface__ion_concentrations__Cai = 0.001 * (( -1.0 * (((var_L_type_calcium_current__i_CaL + var_T_type_calcium_current__i_CaT) - (2.0 * var_sodium_calcium_exchange_current__i_NaCa)) + var_sarcoplasmic_reticulum_kinetics__i_up + (-var_sarcoplasmic_reticulum_kinetics__i_rel))) * 2.0728537298072371); // 'millimole per litre per millisecond'
        const double d_dt_chaste_interface__ion_concentrations__Cao = 0.001 * (((1.0 * ((var_L_type_calcium_current__i_CaL + var_T_type_calcium_current__i_CaT) - (2.0 * var_sodium_calcium_exchange_current__i_NaCa))) * 10.364268649036184) + ((2.0 - var_chaste_interface__ion_concentrations__Cao) * 10.0)); // 'millimole per litre per millisecond'
        const double d_dt_chaste_interface__ion_concentrations__Caup = 0.001 * ((1.0 * (var_sarcoplasmic_reticulum_kinetics__i_up - var_sarcoplasmic_reticulum_kinetics__i_tr)) * 148.06098070051692); // 'millimole per litre per millisecond'
        const double d_dt_chaste_interface__ion_concentrations__Carel = 0.001 * ((1.0 * (var_sarcoplasmic_reticulum_kinetics__i_tr - var_sarcoplasmic_reticulum_kinetics__i_rel)) * 345.47562163453949); // 'millimole per litre per millisecond'
        const double d_dt_chaste_interface__ion_concentrations__Nai = 0.001 * (( -1.0 * (var_background_sodium_current__i_bNa + var_hyperpolarising_activated_current__i_fNa + var_fast_sodium_current__i_Na + (3.0 * var_sodium_potassium_pump__i_p) + (3.0 * var_sodium_calcium_exchange_current__i_NaCa) + var_delayed_rectifying_potassium_current__i_KNa)) * 4.1457074596144743); // 'millimole per litre per millisecond'
        const double d_dt_chaste_interface__ion_concentrations__Nao = 0.001 * (((1.0 * (var_background_sodium_current__i_bNa + var_hyperpolarising_activated_current__i_fNa + var_fast_sodium_current__i_Na + (3.0 * var_sodium_potassium_pump__i_p) + (3.0 * var_sodium_calcium_exchange_current__i_NaCa) + var_delayed_rectifying_potassium_current__i_KNa)) * 20.728537298072368) + ((140.0 - var_chaste_interface__ion_concentrations__Nao) * 10.0)); // 'millimole per litre per millisecond'
        const double d_dt_chaste_interface__ion_concentrations__Ki = 0.001 * (( -1.0 * (((var_delayed_rectifying_potassium_current__i_KK + var_hyperpolarising_activated_current__i_fK) - (2.0 * var_sodium_potassium_pump__i_p)) + var_background_potassium_current__i_bK)) * 4.1457074596144743); // 'millimole per litre per millisecond'
        const double d_dt_chaste_interface__ion_concentrations__Ko = 0.001 * (((1.0 * (((var_delayed_rectifying_potassium_current__i_KK + var_hyperpolarising_activated_current__i_fK) - (2.0 * var_sodium_potassium_pump__i_p)) + var_background_potassium_current__i_bK)) * 20.728537298072368) + ((5.4000000000000004 - var_chaste_interface__ion_concentrations__Ko) * 10.0)); // 'millimole per litre per millisecond'
        
        if (mSetVoltageDerivativeToZero)
        {
            d_dt_chaste_interface__membrane__E = 0.0;
        }
        else
        {
            const double var_membrane__C = 3.1999999999999999e-05; // nanoF
            const double var_membrane__i_tot = var_L_type_calcium_current__i_CaL + var_T_type_calcium_current__i_CaT + var_fast_sodium_current__i_Na + (var_delayed_rectifying_potassium_current__i_KK + var_delayed_rectifying_potassium_current__i_KNa) + (var_hyperpolarising_activated_current__i_fK + var_hyperpolarising_activated_current__i_fNa) + var_sodium_potassium_pump__i_p + var_sodium_calcium_exchange_current__i_NaCa + var_background_sodium_current__i_bNa + var_background_potassium_current__i_bK; // picoA
            d_dt_chaste_interface__membrane__E = 0.001 * ((-var_membrane__i_tot) / var_membrane__C); // 'millivolt per millisecond'
        }
        
        rDY[0] = d_dt_chaste_interface__membrane__E;
        rDY[1] = d_dt_chaste_interface__L_type_calcium_current_d_gate__dL;
        rAlphaOrTau[2] = 0.031 + (1.0 / (1.0 + exp((var_chaste_interface__membrane__E + 37.600000000000001) * 0.1234567901234568)));
        rBetaOrInf[2] = 1.0 / (1.0 + exp((var_chaste_interface__membrane__E + 25.0) * 0.16666666666666666));
        rDY[3] = d_dt_chaste_interface__L_type_calcium_current_f2_gate__fL2;
        rAlphaOrTau[4] = 0.00059999999999999995 + (0.0054000000000000003 / (1.0 + exp(0.029999999999999999 * (var_chaste_interface__membrane__E + 100.0))));
        rBetaOrInf[4] = 1.0 / (1.0 + exp((var_chaste_interface__membrane__E + 23.0) *  -0.16393442622950821));
        rAlphaOrTau[5] = 0.001 + (0.040000000000000001 / (1.0 + exp(0.080000000000000002 * (var_chaste_interface__membrane__E + 65.0))));
        rBetaOrInf[5] = 1.0 / (1.0 + exp((var_chaste_interface__membrane__E + 75.0) * 0.15151515151515152));
        rAlphaOrTau[6] = (200.0 * (var_chaste_interface__membrane__E + 34.299999999999997)) / (1.0 - exp( -0.089999999999999997 * (var_chaste_interface__membrane__E + 34.299999999999997)));
        rBetaOrInf[6] = 8000.0 * exp( -0.14999999999999999 * (var_chaste_interface__membrane__E + 56.200000000000003));
        rAlphaOrTau[7] = 32.399999999999999 * exp( -0.14000000000000001 * (var_chaste_interface__membrane__E + 93.400000000000006));
        rBetaOrInf[7] = 709.0 / (1.0 + (4.2000000000000002 * exp( -0.059999999999999998 * (var_chaste_interface__membrane__E + 45.399999999999999))));
        rAlphaOrTau[8] = 1.0 / ((17.0 * exp(0.039800000000000002 * var_chaste_interface__membrane__E)) + (0.21099999999999999 * exp( -0.050999999999999997 * var_chaste_interface__membrane__E)));
        rBetaOrInf[8] = 1.0 / (1.0 + exp((var_chaste_interface__membrane__E + 25.100000000000001) *  -0.13513513513513511));
        rAlphaOrTau[9] = (0.35999999999999999 * (var_chaste_interface__membrane__E + 137.80000000000001)) / (exp(0.066000000000000003 * (var_chaste_interface__membrane__E + 137.80000000000001)) - 1.0);
        rBetaOrInf[9] = (0.10000000000000001 * (var_chaste_interface__membrane__E + 76.299999999999997)) / (1.0 - exp( -0.20999999999999999 * (var_chaste_interface__membrane__E + 76.299999999999997)));
        rDY[10] = d_dt_chaste_interface__ion_concentrations__Cai;
        rDY[11] = d_dt_chaste_interface__ion_concentrations__Cao;
        rDY[12] = d_dt_chaste_interface__ion_concentrations__Caup;
        rDY[13] = d_dt_chaste_interface__ion_concentrations__Carel;
        rDY[14] = d_dt_chaste_interface__ion_concentrations__Nai;
        rDY[15] = d_dt_chaste_interface__ion_concentrations__Nao;
        rDY[16] = d_dt_chaste_interface__ion_concentrations__Ki;
        rDY[17] = d_dt_chaste_interface__ion_concentrations__Ko;
    }
    
    void Dynamicdokos_model_1996FromCellMLRushLarsen::ComputeOneStepExceptVoltage(const std::vector<double> &rDY, const std::vector<double> &rAlphaOrTau, const std::vector<double> &rBetaOrInf)
    {
        std::vector<double>& rY = rGetStateVariables();
        rY[1] += mDt * rDY[1];
        rY[2] = rBetaOrInf[2] + (rY[2] - rBetaOrInf[2])*exp(-mDt*0.001/rAlphaOrTau[2]);
        rY[3] += mDt * rDY[3];
        rY[4] = rBetaOrInf[4] + (rY[4] - rBetaOrInf[4])*exp(-mDt*0.001/rAlphaOrTau[4]);
        rY[5] = rBetaOrInf[5] + (rY[5] - rBetaOrInf[5])*exp(-mDt*0.001/rAlphaOrTau[5]);
        {
            const double tau_inv = rAlphaOrTau[6] + rBetaOrInf[6];
            const double y_inf = rAlphaOrTau[6] / tau_inv;
            rY[6] = y_inf + (rY[6] - y_inf)*exp(-mDt*0.001*tau_inv);
        }
        {
            const double tau_inv = rAlphaOrTau[7] + rBetaOrInf[7];
            const double y_inf = rAlphaOrTau[7] / tau_inv;
            rY[7] = y_inf + (rY[7] - y_inf)*exp(-mDt*0.001*tau_inv);
        }
        rY[8] = rBetaOrInf[8] + (rY[8] - rBetaOrInf[8])*exp(-mDt*0.001/rAlphaOrTau[8]);
        {
            const double tau_inv = rAlphaOrTau[9] + rBetaOrInf[9];
            const double y_inf = rAlphaOrTau[9] / tau_inv;
            rY[9] = y_inf + (rY[9] - y_inf)*exp(-mDt*0.001*tau_inv);
        }
        rY[10] += mDt * rDY[10];
        rY[11] += mDt * rDY[11];
        rY[12] += mDt * rDY[12];
        rY[13] += mDt * rDY[13];
        rY[14] += mDt * rDY[14];
        rY[15] += mDt * rDY[15];
        rY[16] += mDt * rDY[16];
        rY[17] += mDt * rDY[17];
    }
    
template<>
void OdeSystemInformation<Dynamicdokos_model_1996FromCellMLRushLarsen>::Initialise(void)
{
    this->mSystemName = "dokos_model_1996";
    this->mFreeVariableName = "environment__time";
    this->mFreeVariableUnits = "millisecond";
    
    // rY[0]:
    this->mVariableNames.push_back("membrane_voltage");
    this->mVariableUnits.push_back("millivolt");
    this->mInitialConditions.push_back(-64.9);

    // rY[1]:
    this->mVariableNames.push_back("L_type_calcium_current_d_gate__dL");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(0.0001);

    // rY[2]:
    this->mVariableNames.push_back("L_type_calcium_current_f_gate__fL");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(0.1505);

    // rY[3]:
    this->mVariableNames.push_back("L_type_calcium_current_f2_gate__fL2");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(0.219);

    // rY[4]:
    this->mVariableNames.push_back("T_type_calcium_current_d_gate__dT");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(0.001);

    // rY[5]:
    this->mVariableNames.push_back("T_type_calcium_current_f_gate__fT");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(0.1328);

    // rY[6]:
    this->mVariableNames.push_back("fast_sodium_current_m_gate__m");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(0.0139);

    // rY[7]:
    this->mVariableNames.push_back("fast_sodium_current_h_gate__h");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(0.0087);

    // rY[8]:
    this->mVariableNames.push_back("delayed_rectifying_potassium_current_x_gate__x");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(0.5682);

    // rY[9]:
    this->mVariableNames.push_back("hyperpolarising_activated_current_y_gate__y");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(0.0287);

    // rY[10]:
    this->mVariableNames.push_back("ion_concentrations__Cai");
    this->mVariableUnits.push_back("millimolar");
    this->mInitialConditions.push_back(0.000034);

    // rY[11]:
    this->mVariableNames.push_back("ion_concentrations__Cao");
    this->mVariableUnits.push_back("millimolar");
    this->mInitialConditions.push_back(2.0004);

    // rY[12]:
    this->mVariableNames.push_back("ion_concentrations__Caup");
    this->mVariableUnits.push_back("millimolar");
    this->mInitialConditions.push_back(0.5832);

    // rY[13]:
    this->mVariableNames.push_back("ion_concentrations__Carel");
    this->mVariableUnits.push_back("millimolar");
    this->mInitialConditions.push_back(0.1101);

    // rY[14]:
    this->mVariableNames.push_back("ion_concentrations__Nai");
    this->mVariableUnits.push_back("millimolar");
    this->mInitialConditions.push_back(7.4994);

    // rY[15]:
    this->mVariableNames.push_back("ion_concentrations__Nao");
    this->mVariableUnits.push_back("millimolar");
    this->mInitialConditions.push_back(139.9929);

    // rY[16]:
    this->mVariableNames.push_back("ion_concentrations__Ki");
    this->mVariableUnits.push_back("millimolar");
    this->mInitialConditions.push_back(140.0073);

    // rY[17]:
    this->mVariableNames.push_back("ion_concentrations__Ko");
    this->mVariableUnits.push_back("millimolar");
    this->mInitialConditions.push_back(5.4243);

    this->mInitialised = true;
}


// Serialization for Boost >= 1.36
#include "SerializationExportWrapperForCpp.hpp"
CHASTE_CLASS_EXPORT(Dynamicdokos_model_1996FromCellMLRushLarsen)
extern "C"
{
    AbstractCardiacCellInterface* MakeCardiacCell(
            boost::shared_ptr<AbstractIvpOdeSolver> pSolver,
            boost::shared_ptr<AbstractStimulusFunction> pStimulus)
    {
        return new Dynamicdokos_model_1996FromCellMLRushLarsen(pSolver, pStimulus);
    }
    
}

