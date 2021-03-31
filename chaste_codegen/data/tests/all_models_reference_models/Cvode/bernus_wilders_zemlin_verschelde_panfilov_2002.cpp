#ifdef CHASTE_CVODE
//! @file
//!
//! This source file was generated from CellML by chaste_codegen version (version omitted as unimportant)
//!
//! Model: bernus_wilders_zemlin_verschelde_panfilov_2002_version01
//!
//! Processed by chaste_codegen: https://github.com/ModellingWebLab/chaste-codegen
//!     (translator: chaste_codegen, model type: NumericCvode)
//! on (date omitted as unimportant)
//!
//! <autogenerated>

#include "bernus_wilders_zemlin_verschelde_panfilov_2002.hpp"
#include <cmath>
#include <cassert>
#include <memory>
#include "Exception.hpp"
#include "OdeSystemInformation.hpp"
#include "RegularStimulus.hpp"
#include "HeartConfig.hpp"
#include "IsNan.hpp"
#include "MathsCustomFunctions.hpp"



    boost::shared_ptr<RegularStimulus> Cellbernus_wilders_zemlin_verschelde_panfilov_2002FromCellMLCvode::UseCellMLDefaultStimulus()
    {
        // Use the default stimulus specified by CellML metadata
        const double var_chaste_interface__stimulus_protocol__IstimAmplitude_converted = 0.5 * HeartConfig::Instance()->GetCapacitance(); // uA_per_cm2
        const double var_chaste_interface__stimulus_protocol__IstimPeriod = 1000.0; // millisecond
        const double var_chaste_interface__stimulus_protocol__IstimPulseDuration = 1.0; // millisecond
        const double var_chaste_interface__stimulus_protocol__IstimStart = 10.0; // millisecond
        boost::shared_ptr<RegularStimulus> p_cellml_stim(new RegularStimulus(
                -fabs(var_chaste_interface__stimulus_protocol__IstimAmplitude_converted),
                var_chaste_interface__stimulus_protocol__IstimPulseDuration,
                var_chaste_interface__stimulus_protocol__IstimPeriod,
                var_chaste_interface__stimulus_protocol__IstimStart
                ));
        mpIntracellularStimulus = p_cellml_stim;
        return p_cellml_stim;
    }

    Cellbernus_wilders_zemlin_verschelde_panfilov_2002FromCellMLCvode::Cellbernus_wilders_zemlin_verschelde_panfilov_2002FromCellMLCvode(boost::shared_ptr<AbstractIvpOdeSolver> pOdeSolver /* unused; should be empty */, boost::shared_ptr<AbstractStimulusFunction> pIntracellularStimulus)
        : AbstractCvodeCell(
                pOdeSolver,
                6,
                0,
                pIntracellularStimulus)
    {
        // Time units: millisecond
        //
        this->mpSystemInfo = OdeSystemInformation<Cellbernus_wilders_zemlin_verschelde_panfilov_2002FromCellMLCvode>::Instance();
        Init();

        // We have a default stimulus specified in the CellML file metadata
        this->mHasDefaultStimulusFromCellML = true;
        
        NV_Ith_S(this->mParameters, 0) = 0.00040000000000000002; // (var_ionic_concentrations__Ca_i) [millimolar]
        NV_Ith_S(this->mParameters, 1) = 140.0; // (var_ionic_concentrations__K_i) [millimolar]
        NV_Ith_S(this->mParameters, 2) = 10.0; // (var_ionic_concentrations__Na_i) [millimolar]
        NV_Ith_S(this->mParameters, 3) = 2.0; // (var_ionic_concentrations__Ca_e) [millimolar]
        NV_Ith_S(this->mParameters, 4) = 4.0; // (var_ionic_concentrations__K_e) [millimolar]
        NV_Ith_S(this->mParameters, 5) = 138.0; // (var_ionic_concentrations__Na_e) [millimolar]
        NV_Ith_S(this->mParameters, 6) = 0.064000000000000001; // (var_calcium_current__g_Ca) [nanoS_per_picoF]
        NV_Ith_S(this->mParameters, 7) = 153.40000000000001; // (var_membrane__Cm) [picoF]
        NV_Ith_S(this->mParameters, 8) = 16.0; // (var_sodium_current__g_Na) [nanoS_per_picoF]
        NV_Ith_S(this->mParameters, 9) = 3.8999999999999999; // (var_inward_rectifier_potassium_current__g_K1) [nanoS_per_picoF]
    }

    Cellbernus_wilders_zemlin_verschelde_panfilov_2002FromCellMLCvode::~Cellbernus_wilders_zemlin_verschelde_panfilov_2002FromCellMLCvode()
    {
    }

    
    double Cellbernus_wilders_zemlin_verschelde_panfilov_2002FromCellMLCvode::GetIIonic(const std::vector<double>* pStateVariables)
    {
        // For state variable interpolation (SVI) we read in interpolated state variables,
        // otherwise for ionic current interpolation (ICI) we use the state variables of this model (node).
        N_Vector rY;
        bool made_new_cvode_vector = false;
        if (!pStateVariables)
        {
            rY = rGetStateVariables();
        }
        else
        {
            made_new_cvode_vector = true;
            rY = MakeNVector(*pStateVariables);
        }
        double var_chaste_interface__membrane__V = (mSetVoltageDerivativeToZero ? this->mFixedVoltage : NV_Ith_S(rY, 0));
        // Units: millivolt; Initial value: -90.2
        double var_chaste_interface__sodium_current_m_gate__m = NV_Ith_S(rY, 1);
        // Units: dimensionless; Initial value: 0.0016203
        double var_chaste_interface__sodium_current_v_gate__v = NV_Ith_S(rY, 2);
        // Units: dimensionless; Initial value: 0.9944036
        double var_chaste_interface__calcium_current_f_gate__f = NV_Ith_S(rY, 3);
        // Units: dimensionless; Initial value: 1.0
        double var_chaste_interface__transient_outward_current_to_gate__to = NV_Ith_S(rY, 4);
        // Units: dimensionless; Initial value: 0.0
        double var_chaste_interface__delayed_rectifier_potassium_current_X_gate__X = NV_Ith_S(rY, 5);
        // Units: dimensionless; Initial value: 0.000928836
        
        const double var_calcium_background_current__g_b_Ca = 0.00084999999999999995; // nanoS_per_picoF
        const double var_delayed_rectifier_potassium_current__g_K = 0.019; // nanoS_per_picoF
        const double var_calcium_current_f_Ca_gate__f_Ca = 1 / (1.0 + 1666.6666666666667 * NV_Ith_S(mParameters, 0)); // dimensionless
        const double var_membrane__F = 96845.0; // coulomb_per_mole
        const double var_membrane__R = 8314.0; // millijoule_per_mole_kelvin
        const double var_membrane__T = 310.0; // kelvin
        const double var_calcium_current__E_Ca = 0.5 * var_membrane__R * var_membrane__T * log(NV_Ith_S(mParameters, 3) / NV_Ith_S(mParameters, 0)) / var_membrane__F; // millivolt
        const double var_delayed_rectifier_potassium_current__E_K = var_membrane__R * var_membrane__T * log(NV_Ith_S(mParameters, 4) / NV_Ith_S(mParameters, 1)) / var_membrane__F; // millivolt
        const double var_calcium_background_current__i_b_Ca = (-var_calcium_current__E_Ca + var_chaste_interface__membrane__V) * var_calcium_background_current__g_b_Ca; // picoA_per_picoF
        const double var_calcium_current_d_gate__alpha_d = 0.63503954329583223 * exp(-0.89850709360569092 * pow((-1 + 0.044722719141323794 * var_chaste_interface__membrane__V), 2)) / sqrt(M_PI); // per_millisecond
        const double var_calcium_current_d_gate__beta_d = 0.14710000000000001 - 0.25101580310038191 * exp(-0.088183122039937209 * pow((-1 + 0.15948963317384371 * var_chaste_interface__membrane__V), 2)) / sqrt(M_PI); // per_millisecond
        const double var_calcium_current_d_gate__d_infinity = var_calcium_current_d_gate__alpha_d / (var_calcium_current_d_gate__alpha_d + var_calcium_current_d_gate__beta_d); // dimensionless
        const double var_calcium_current__i_Ca = (-var_calcium_current__E_Ca + var_chaste_interface__membrane__V) * NV_Ith_S(mParameters, 6) * var_calcium_current_d_gate__d_infinity * var_calcium_current_f_Ca_gate__f_Ca * var_chaste_interface__calcium_current_f_gate__f; // picoA_per_picoF
        const double var_calcium_current__i_Ca_converted = HeartConfig::Instance()->GetCapacitance() * var_calcium_current__i_Ca; // uA_per_cm2
        const double var_delayed_rectifier_potassium_current__i_K = pow(var_chaste_interface__delayed_rectifier_potassium_current_X_gate__X, 2) * (-var_delayed_rectifier_potassium_current__E_K + var_chaste_interface__membrane__V) * var_delayed_rectifier_potassium_current__g_K; // picoA_per_picoF
        const double var_inward_rectifier_potassium_current_K1_gate__alpha_K1 = 0.10000000000000001 / (1.0 + exp(-12.0 + 0.059999999999999998 * var_chaste_interface__membrane__V - 0.059999999999999998 * var_delayed_rectifier_potassium_current__E_K)); // per_millisecond
        const double var_inward_rectifier_potassium_current_K1_gate__beta_K1 = (3.0 * exp(0.02 + 0.00020000000000000001 * var_chaste_interface__membrane__V - 0.00020000000000000001 * var_delayed_rectifier_potassium_current__E_K) + exp(-1.0 + 0.10000000000000001 * var_chaste_interface__membrane__V - 0.10000000000000001 * var_delayed_rectifier_potassium_current__E_K)) / (1.0 + exp(0.5 * var_delayed_rectifier_potassium_current__E_K - 0.5 * var_chaste_interface__membrane__V)); // per_millisecond
        const double var_inward_rectifier_potassium_current_K1_gate__K1_infinity = var_inward_rectifier_potassium_current_K1_gate__alpha_K1 / (var_inward_rectifier_potassium_current_K1_gate__alpha_K1 + var_inward_rectifier_potassium_current_K1_gate__beta_K1); // dimensionless
        const double var_inward_rectifier_potassium_current__i_K1 = (-var_delayed_rectifier_potassium_current__E_K + var_chaste_interface__membrane__V) * NV_Ith_S(mParameters, 9) * var_inward_rectifier_potassium_current_K1_gate__K1_infinity; // picoA_per_picoF
        const double var_inward_rectifier_potassium_current__i_K1_converted = HeartConfig::Instance()->GetCapacitance() * var_inward_rectifier_potassium_current__i_K1; // uA_per_cm2
        const double var_sodium_background_current__g_b_Na = 0.001; // nanoS_per_picoF
        const double var_sodium_calcium_pump__f_NaCa = (pow(NV_Ith_S(mParameters, 2), 3) * NV_Ith_S(mParameters, 3) * exp(0.012999999999999999 * var_chaste_interface__membrane__V) - pow(NV_Ith_S(mParameters, 5), 3) * NV_Ith_S(mParameters, 0) * exp(-0.024 * var_chaste_interface__membrane__V)) / ((1.0 + 0.10000000000000001 * exp(-0.024 * var_chaste_interface__membrane__V)) * (669921.875 + pow(NV_Ith_S(mParameters, 5), 3)) * (1.3799999999999999 + NV_Ith_S(mParameters, 3))); // dimensionless
        const double var_sodium_calcium_pump__g_NaCa = 1000.0; // nanoS_per_picoF
        const double var_sodium_calcium_pump__i_NaCa = var_sodium_calcium_pump__f_NaCa * var_sodium_calcium_pump__g_NaCa; // picoA_per_picoF
        const double var_sodium_current__E_Na = var_membrane__R * var_membrane__T * log(NV_Ith_S(mParameters, 5) / NV_Ith_S(mParameters, 2)) / var_membrane__F; // millivolt
        const double var_sodium_background_current__i_b_Na = (-var_sodium_current__E_Na + var_chaste_interface__membrane__V) * var_sodium_background_current__g_b_Na; // picoA_per_picoF
        const double var_sodium_current__i_Na = pow(var_chaste_interface__sodium_current_m_gate__m, 3) * pow(var_chaste_interface__sodium_current_v_gate__v, 2) * (-var_sodium_current__E_Na + var_chaste_interface__membrane__V) * NV_Ith_S(mParameters, 8); // picoA_per_picoF
        const double var_sodium_current__i_Na_converted = HeartConfig::Instance()->GetCapacitance() * var_sodium_current__i_Na; // uA_per_cm2
        const double var_sodium_potassium_pump__f_NaK_a = NV_Ith_S(mParameters, 4) / ((1.0 + 31.622776601683793 * pow((1 / NV_Ith_S(mParameters, 2)), 1.5)) * (1.5 + NV_Ith_S(mParameters, 4))); // dimensionless
        const double var_sodium_potassium_pump__g_NaK = 1.3; // nanoS_per_picoF
        const double var_sodium_potassium_pump__sigma = -0.14280000000000001 + 0.14280000000000001 * exp(0.01485884101040119 * NV_Ith_S(mParameters, 5)); // dimensionless
        const double var_sodium_potassium_pump__f_NaK = 1 / (1.0 + 0.1245 * exp(-0.0037000000000000002 * var_chaste_interface__membrane__V) + 0.036499999999999998 * var_sodium_potassium_pump__sigma * exp(-0.036999999999999998 * var_chaste_interface__membrane__V)); // dimensionless
        const double var_sodium_potassium_pump__i_NaK = var_sodium_potassium_pump__f_NaK * var_sodium_potassium_pump__f_NaK_a * var_sodium_potassium_pump__g_NaK; // picoA_per_picoF
        const double var_transient_outward_current__E_to = var_membrane__R * var_membrane__T * log((NV_Ith_S(mParameters, 4) + 0.042999999999999997 * NV_Ith_S(mParameters, 5)) / (NV_Ith_S(mParameters, 1) + 0.042999999999999997 * NV_Ith_S(mParameters, 2))) / var_membrane__F; // millivolt
        const double var_transient_outward_current__g_to = 0.40000000000000002; // nanoS_per_picoF
        const double var_transient_outward_current_r_gate__alpha_r = 0.52659999999999996 * exp(0.70203392000000009 - 0.0166 * var_chaste_interface__membrane__V) / (1.0 + exp(3.9880601600000003 - 0.094299999999999995 * var_chaste_interface__membrane__V)); // per_millisecond
        const double var_transient_outward_current_r_gate__beta_r = (0.51490000000000002 * exp(0.67236288 - 0.13439999999999999 * var_chaste_interface__membrane__V) + 5.1860000000000002e-5 * var_chaste_interface__membrane__V) / (1.0 + exp(6.9907280000000006e-6 - 0.1348 * var_chaste_interface__membrane__V)); // per_millisecond
        const double var_transient_outward_current_r_gate__r_infinity = var_transient_outward_current_r_gate__alpha_r / (var_transient_outward_current_r_gate__alpha_r + var_transient_outward_current_r_gate__beta_r); // dimensionless
        const double var_transient_outward_current__i_to = (-var_transient_outward_current__E_to + var_chaste_interface__membrane__V) * var_transient_outward_current__g_to * var_transient_outward_current_r_gate__r_infinity * var_chaste_interface__transient_outward_current_to_gate__to; // picoA_per_picoF
        const double var_chaste_interface__i_ionic = HeartConfig::Instance()->GetCapacitance() * var_calcium_background_current__i_b_Ca + HeartConfig::Instance()->GetCapacitance() * var_delayed_rectifier_potassium_current__i_K + HeartConfig::Instance()->GetCapacitance() * var_sodium_background_current__i_b_Na + HeartConfig::Instance()->GetCapacitance() * var_sodium_calcium_pump__i_NaCa + HeartConfig::Instance()->GetCapacitance() * var_sodium_potassium_pump__i_NaK + HeartConfig::Instance()->GetCapacitance() * var_transient_outward_current__i_to + var_calcium_current__i_Ca_converted + var_inward_rectifier_potassium_current__i_K1_converted + var_sodium_current__i_Na_converted; // uA_per_cm2

        const double i_ionic = var_chaste_interface__i_ionic;
        if (made_new_cvode_vector)
        {
            DeleteVector(rY);
        }
        EXCEPT_IF_NOT(!std::isnan(i_ionic));
        return i_ionic;
    }

    void Cellbernus_wilders_zemlin_verschelde_panfilov_2002FromCellMLCvode::EvaluateYDerivatives(double var_chaste_interface__environment__time, const N_Vector rY, N_Vector rDY)
    {
        // Inputs:
        // Time units: millisecond
        double var_chaste_interface__membrane__V = (mSetVoltageDerivativeToZero ? this->mFixedVoltage : NV_Ith_S(rY, 0));
        // Units: millivolt; Initial value: -90.2
        double var_chaste_interface__sodium_current_m_gate__m = NV_Ith_S(rY, 1);
        // Units: dimensionless; Initial value: 0.0016203
        double var_chaste_interface__sodium_current_v_gate__v = NV_Ith_S(rY, 2);
        // Units: dimensionless; Initial value: 0.9944036
        double var_chaste_interface__calcium_current_f_gate__f = NV_Ith_S(rY, 3);
        // Units: dimensionless; Initial value: 1.0
        double var_chaste_interface__transient_outward_current_to_gate__to = NV_Ith_S(rY, 4);
        // Units: dimensionless; Initial value: 0.0
        double var_chaste_interface__delayed_rectifier_potassium_current_X_gate__X = NV_Ith_S(rY, 5);
        // Units: dimensionless; Initial value: 0.000928836

        // Mathematics
        double d_dt_chaste_interface_var_membrane__V;
        const double var_calcium_current_f_gate__alpha_f = 0.0068700000000000002 / (1.0 + exp(-1.0056535947712419 + 0.16339869281045752 * var_chaste_interface__membrane__V)); // per_millisecond
        const double var_calcium_current_f_gate__beta_f = 0.00057499999999999999 + (0.010999999999999999 + 0.069000000000000006 * exp(-108.07499999999999 - 11.0 * var_chaste_interface__membrane__V)) / (1.0 + exp(-2.7313499999999999 - 0.27800000000000002 * var_chaste_interface__membrane__V)); // per_millisecond
        const double d_dt_chaste_interface_var_calcium_current_f_gate__f = (1.0 - var_chaste_interface__calcium_current_f_gate__f) * var_calcium_current_f_gate__alpha_f - var_calcium_current_f_gate__beta_f * var_chaste_interface__calcium_current_f_gate__f; // 1 / millisecond
        const double var_delayed_rectifier_potassium_current_X_gate__X_infinity = 0.98799999999999999 / (1.0 + exp(-0.86099999999999999 - 0.062 * var_chaste_interface__membrane__V)); // dimensionless
        const double var_delayed_rectifier_potassium_current_X_gate__tau_X_a = 40.0 - 40.0 * tanh(160.0 + 2.0 * var_chaste_interface__membrane__V); // millisecond
        const double var_delayed_rectifier_potassium_current_X_gate__tau_X = 182.0 + 240.0 * exp(-4.1682692307692308 * pow((1 + 0.039215686274509803 * var_chaste_interface__membrane__V), 2)) + 182.0 * tanh(0.154 + 0.011599999999999999 * var_chaste_interface__membrane__V) + var_delayed_rectifier_potassium_current_X_gate__tau_X_a; // millisecond
        const double d_dt_chaste_interface_var_delayed_rectifier_potassium_current_X_gate__X = (-var_chaste_interface__delayed_rectifier_potassium_current_X_gate__X + var_delayed_rectifier_potassium_current_X_gate__X_infinity) / var_delayed_rectifier_potassium_current_X_gate__tau_X; // 1 / millisecond
        const double var_sodium_current_m_gate__alpha_m = ((fabs(47.130000000000003 + var_chaste_interface__membrane__V) < 1.0000000010279564e-6) ? (-3.2000000146581445e-7 / (1.0 - exp(1.0000000045806701e-7)) + 499999.99948602181 * (47.130001000000007 + var_chaste_interface__membrane__V) * (3.2000000146581445e-7 / (1.0 - exp(1.0000000045806701e-7)) + 3.1999999919207769e-7 / (1.0 - exp(-9.9999999747524276e-8)))) : (0.32000000000000001 * (47.130000000000003 + var_chaste_interface__membrane__V) / (1.0 - exp(-4.7130000000000001 - 0.10000000000000001 * var_chaste_interface__membrane__V)))); // per_millisecond
        const double var_sodium_current_m_gate__beta_m = 0.080000000000000002 * exp(-0.090909090909090912 * var_chaste_interface__membrane__V); // per_millisecond
        const double d_dt_chaste_interface_var_sodium_current_m_gate__m = (1.0 - var_chaste_interface__sodium_current_m_gate__m) * var_sodium_current_m_gate__alpha_m - var_sodium_current_m_gate__beta_m * var_chaste_interface__sodium_current_m_gate__m; // 1 / millisecond
        const double var_sodium_current_v_gate__tau_v = 0.25 + 2.2400000000000002 * (1.0 - tanh(7.7400000000000002 + 0.12 * var_chaste_interface__membrane__V)) / (1.0 - tanh(6.4680000000000009 + 0.070000000000000007 * var_chaste_interface__membrane__V)); // millisecond
        const double var_sodium_current_v_gate__v_infinity = 0.5 - 0.5 * tanh(7.7400000000000002 + 0.12 * var_chaste_interface__membrane__V); // dimensionless
        const double d_dt_chaste_interface_var_sodium_current_v_gate__v = (-var_chaste_interface__sodium_current_v_gate__v + var_sodium_current_v_gate__v_infinity) / var_sodium_current_v_gate__tau_v; // 1 / millisecond
        const double var_transient_outward_current_to_gate__alpha_to = (5.6119999999999998e-5 * var_chaste_interface__membrane__V + 0.072099999999999997 * exp(-5.9257863000000004 - 0.17299999999999999 * var_chaste_interface__membrane__V)) / (1.0 + exp(-5.9326369200000002 - 0.17319999999999999 * var_chaste_interface__membrane__V)); // per_millisecond
        const double var_transient_outward_current_to_gate__beta_to = (0.0001215 * var_chaste_interface__membrane__V + 0.076700000000000004 * exp(-5.6479010000000002e-8 - 1.6600000000000001e-9 * var_chaste_interface__membrane__V)) / (1.0 + exp(-5.4573693999999993 - 0.16039999999999999 * var_chaste_interface__membrane__V)); // per_millisecond
        const double d_dt_chaste_interface_var_transient_outward_current_to_gate__to = (1.0 - var_chaste_interface__transient_outward_current_to_gate__to) * var_transient_outward_current_to_gate__alpha_to - var_transient_outward_current_to_gate__beta_to * var_chaste_interface__transient_outward_current_to_gate__to; // 1 / millisecond

        if (mSetVoltageDerivativeToZero)
        {
            d_dt_chaste_interface_var_membrane__V = 0.0;
        }
        else
        {
            const double var_calcium_background_current__g_b_Ca = 0.00084999999999999995; // nanoS_per_picoF
            const double var_delayed_rectifier_potassium_current__g_K = 0.019; // nanoS_per_picoF
            const double var_calcium_current_f_Ca_gate__f_Ca = 1 / (1.0 + 1666.6666666666667 * NV_Ith_S(mParameters, 0)); // dimensionless
            const double var_membrane__F = 96845.0; // coulomb_per_mole
            const double var_membrane__R = 8314.0; // millijoule_per_mole_kelvin
            const double var_membrane__T = 310.0; // kelvin
            const double var_calcium_current__E_Ca = 0.5 * var_membrane__R * var_membrane__T * log(NV_Ith_S(mParameters, 3) / NV_Ith_S(mParameters, 0)) / var_membrane__F; // millivolt
            const double var_delayed_rectifier_potassium_current__E_K = var_membrane__R * var_membrane__T * log(NV_Ith_S(mParameters, 4) / NV_Ith_S(mParameters, 1)) / var_membrane__F; // millivolt
            const double var_calcium_background_current__i_b_Ca = (-var_calcium_current__E_Ca + var_chaste_interface__membrane__V) * var_calcium_background_current__g_b_Ca; // picoA_per_picoF
            const double var_calcium_current_d_gate__alpha_d = 0.63503954329583223 * exp(-0.89850709360569092 * pow((-1 + 0.044722719141323794 * var_chaste_interface__membrane__V), 2)) / sqrt(M_PI); // per_millisecond
            const double var_calcium_current_d_gate__beta_d = 0.14710000000000001 - 0.25101580310038191 * exp(-0.088183122039937209 * pow((-1 + 0.15948963317384371 * var_chaste_interface__membrane__V), 2)) / sqrt(M_PI); // per_millisecond
            const double var_calcium_current_d_gate__d_infinity = var_calcium_current_d_gate__alpha_d / (var_calcium_current_d_gate__alpha_d + var_calcium_current_d_gate__beta_d); // dimensionless
            const double var_calcium_current__i_Ca = (-var_calcium_current__E_Ca + var_chaste_interface__membrane__V) * NV_Ith_S(mParameters, 6) * var_calcium_current_d_gate__d_infinity * var_calcium_current_f_Ca_gate__f_Ca * var_chaste_interface__calcium_current_f_gate__f; // picoA_per_picoF
            const double var_delayed_rectifier_potassium_current__i_K = pow(var_chaste_interface__delayed_rectifier_potassium_current_X_gate__X, 2) * (-var_delayed_rectifier_potassium_current__E_K + var_chaste_interface__membrane__V) * var_delayed_rectifier_potassium_current__g_K; // picoA_per_picoF
            const double var_inward_rectifier_potassium_current_K1_gate__alpha_K1 = 0.10000000000000001 / (1.0 + exp(-12.0 + 0.059999999999999998 * var_chaste_interface__membrane__V - 0.059999999999999998 * var_delayed_rectifier_potassium_current__E_K)); // per_millisecond
            const double var_inward_rectifier_potassium_current_K1_gate__beta_K1 = (3.0 * exp(0.02 + 0.00020000000000000001 * var_chaste_interface__membrane__V - 0.00020000000000000001 * var_delayed_rectifier_potassium_current__E_K) + exp(-1.0 + 0.10000000000000001 * var_chaste_interface__membrane__V - 0.10000000000000001 * var_delayed_rectifier_potassium_current__E_K)) / (1.0 + exp(0.5 * var_delayed_rectifier_potassium_current__E_K - 0.5 * var_chaste_interface__membrane__V)); // per_millisecond
            const double var_inward_rectifier_potassium_current_K1_gate__K1_infinity = var_inward_rectifier_potassium_current_K1_gate__alpha_K1 / (var_inward_rectifier_potassium_current_K1_gate__alpha_K1 + var_inward_rectifier_potassium_current_K1_gate__beta_K1); // dimensionless
            const double var_inward_rectifier_potassium_current__i_K1 = (-var_delayed_rectifier_potassium_current__E_K + var_chaste_interface__membrane__V) * NV_Ith_S(mParameters, 9) * var_inward_rectifier_potassium_current_K1_gate__K1_infinity; // picoA_per_picoF
            const double var_sodium_background_current__g_b_Na = 0.001; // nanoS_per_picoF
            const double var_sodium_calcium_pump__f_NaCa = (pow(NV_Ith_S(mParameters, 2), 3) * NV_Ith_S(mParameters, 3) * exp(0.012999999999999999 * var_chaste_interface__membrane__V) - pow(NV_Ith_S(mParameters, 5), 3) * NV_Ith_S(mParameters, 0) * exp(-0.024 * var_chaste_interface__membrane__V)) / ((1.0 + 0.10000000000000001 * exp(-0.024 * var_chaste_interface__membrane__V)) * (669921.875 + pow(NV_Ith_S(mParameters, 5), 3)) * (1.3799999999999999 + NV_Ith_S(mParameters, 3))); // dimensionless
            const double var_sodium_calcium_pump__g_NaCa = 1000.0; // nanoS_per_picoF
            const double var_sodium_calcium_pump__i_NaCa = var_sodium_calcium_pump__f_NaCa * var_sodium_calcium_pump__g_NaCa; // picoA_per_picoF
            const double var_sodium_current__E_Na = var_membrane__R * var_membrane__T * log(NV_Ith_S(mParameters, 5) / NV_Ith_S(mParameters, 2)) / var_membrane__F; // millivolt
            const double var_sodium_background_current__i_b_Na = (-var_sodium_current__E_Na + var_chaste_interface__membrane__V) * var_sodium_background_current__g_b_Na; // picoA_per_picoF
            const double var_sodium_current__i_Na = pow(var_chaste_interface__sodium_current_m_gate__m, 3) * pow(var_chaste_interface__sodium_current_v_gate__v, 2) * (-var_sodium_current__E_Na + var_chaste_interface__membrane__V) * NV_Ith_S(mParameters, 8); // picoA_per_picoF
            const double var_sodium_potassium_pump__f_NaK_a = NV_Ith_S(mParameters, 4) / ((1.0 + 31.622776601683793 * pow((1 / NV_Ith_S(mParameters, 2)), 1.5)) * (1.5 + NV_Ith_S(mParameters, 4))); // dimensionless
            const double var_sodium_potassium_pump__g_NaK = 1.3; // nanoS_per_picoF
            const double var_sodium_potassium_pump__sigma = -0.14280000000000001 + 0.14280000000000001 * exp(0.01485884101040119 * NV_Ith_S(mParameters, 5)); // dimensionless
            const double var_sodium_potassium_pump__f_NaK = 1 / (1.0 + 0.1245 * exp(-0.0037000000000000002 * var_chaste_interface__membrane__V) + 0.036499999999999998 * var_sodium_potassium_pump__sigma * exp(-0.036999999999999998 * var_chaste_interface__membrane__V)); // dimensionless
            const double var_sodium_potassium_pump__i_NaK = var_sodium_potassium_pump__f_NaK * var_sodium_potassium_pump__f_NaK_a * var_sodium_potassium_pump__g_NaK; // picoA_per_picoF
            const double var_stimulus_protocol__i_stim_converted = GetIntracellularAreaStimulus(var_chaste_interface__environment__time); // uA_per_cm2
            const double var_stimulus_protocol__i_stim = var_stimulus_protocol__i_stim_converted / HeartConfig::Instance()->GetCapacitance(); // picoA_per_picoF
            const double var_transient_outward_current__E_to = var_membrane__R * var_membrane__T * log((NV_Ith_S(mParameters, 4) + 0.042999999999999997 * NV_Ith_S(mParameters, 5)) / (NV_Ith_S(mParameters, 1) + 0.042999999999999997 * NV_Ith_S(mParameters, 2))) / var_membrane__F; // millivolt
            const double var_transient_outward_current__g_to = 0.40000000000000002; // nanoS_per_picoF
            const double var_transient_outward_current_r_gate__alpha_r = 0.52659999999999996 * exp(0.70203392000000009 - 0.0166 * var_chaste_interface__membrane__V) / (1.0 + exp(3.9880601600000003 - 0.094299999999999995 * var_chaste_interface__membrane__V)); // per_millisecond
            const double var_transient_outward_current_r_gate__beta_r = (0.51490000000000002 * exp(0.67236288 - 0.13439999999999999 * var_chaste_interface__membrane__V) + 5.1860000000000002e-5 * var_chaste_interface__membrane__V) / (1.0 + exp(6.9907280000000006e-6 - 0.1348 * var_chaste_interface__membrane__V)); // per_millisecond
            const double var_transient_outward_current_r_gate__r_infinity = var_transient_outward_current_r_gate__alpha_r / (var_transient_outward_current_r_gate__alpha_r + var_transient_outward_current_r_gate__beta_r); // dimensionless
            const double var_transient_outward_current__i_to = (-var_transient_outward_current__E_to + var_chaste_interface__membrane__V) * var_transient_outward_current__g_to * var_transient_outward_current_r_gate__r_infinity * var_chaste_interface__transient_outward_current_to_gate__to; // picoA_per_picoF
            d_dt_chaste_interface_var_membrane__V = (-var_calcium_background_current__i_b_Ca - var_calcium_current__i_Ca - var_delayed_rectifier_potassium_current__i_K - var_inward_rectifier_potassium_current__i_K1 - var_sodium_background_current__i_b_Na - var_sodium_calcium_pump__i_NaCa - var_sodium_current__i_Na - var_sodium_potassium_pump__i_NaK - var_stimulus_protocol__i_stim - var_transient_outward_current__i_to) / NV_Ith_S(mParameters, 7); // millivolt / millisecond
        }
        
        NV_Ith_S(rDY,0) = d_dt_chaste_interface_var_membrane__V;
        NV_Ith_S(rDY,1) = d_dt_chaste_interface_var_sodium_current_m_gate__m;
        NV_Ith_S(rDY,2) = d_dt_chaste_interface_var_sodium_current_v_gate__v;
        NV_Ith_S(rDY,3) = d_dt_chaste_interface_var_calcium_current_f_gate__f;
        NV_Ith_S(rDY,4) = d_dt_chaste_interface_var_transient_outward_current_to_gate__to;
        NV_Ith_S(rDY,5) = d_dt_chaste_interface_var_delayed_rectifier_potassium_current_X_gate__X;
    }

    N_Vector Cellbernus_wilders_zemlin_verschelde_panfilov_2002FromCellMLCvode::ComputeDerivedQuantities(double var_chaste_interface__environment__time, const N_Vector & rY)
    {
        // Inputs:
        // Time units: millisecond
        double var_chaste_interface__membrane__V = (mSetVoltageDerivativeToZero ? this->mFixedVoltage : NV_Ith_S(rY, 0));
        // Units: millivolt; Initial value: -90.2
        double var_chaste_interface__sodium_current_m_gate__m = NV_Ith_S(rY, 1);
        // Units: dimensionless; Initial value: 0.0016203
        double var_chaste_interface__sodium_current_v_gate__v = NV_Ith_S(rY, 2);
        // Units: dimensionless; Initial value: 0.9944036
        double var_chaste_interface__calcium_current_f_gate__f = NV_Ith_S(rY, 3);
        // Units: dimensionless; Initial value: 1.0
        
        // Mathematics
        const double var_calcium_current_f_Ca_gate__f_Ca = 1 / (1.0 + 1666.6666666666667 * NV_Ith_S(mParameters, 0)); // dimensionless
        const double var_membrane__Cm_converted = 9.9999999999999995e-7 * NV_Ith_S(mParameters, 7); // uF
        const double var_membrane__F = 96845.0; // coulomb_per_mole
        const double var_membrane__R = 8314.0; // millijoule_per_mole_kelvin
        const double var_membrane__T = 310.0; // kelvin
        const double var_calcium_current__E_Ca = 0.5 * var_membrane__R * var_membrane__T * log(NV_Ith_S(mParameters, 3) / NV_Ith_S(mParameters, 0)) / var_membrane__F; // millivolt
        const double var_delayed_rectifier_potassium_current__E_K = var_membrane__R * var_membrane__T * log(NV_Ith_S(mParameters, 4) / NV_Ith_S(mParameters, 1)) / var_membrane__F; // millivolt
        const double var_calcium_current_d_gate__alpha_d = 0.63503954329583223 * exp(-0.89850709360569092 * pow((-1 + 0.044722719141323794 * var_chaste_interface__membrane__V), 2)) / sqrt(M_PI); // per_millisecond
        const double var_calcium_current_d_gate__beta_d = 0.14710000000000001 - 0.25101580310038191 * exp(-0.088183122039937209 * pow((-1 + 0.15948963317384371 * var_chaste_interface__membrane__V), 2)) / sqrt(M_PI); // per_millisecond
        const double var_calcium_current_d_gate__d_infinity = var_calcium_current_d_gate__alpha_d / (var_calcium_current_d_gate__alpha_d + var_calcium_current_d_gate__beta_d); // dimensionless
        const double var_calcium_current__i_Ca = (-var_calcium_current__E_Ca + var_chaste_interface__membrane__V) * NV_Ith_S(mParameters, 6) * var_calcium_current_d_gate__d_infinity * var_calcium_current_f_Ca_gate__f_Ca * var_chaste_interface__calcium_current_f_gate__f; // picoA_per_picoF
        const double var_calcium_current__i_Ca_converted = HeartConfig::Instance()->GetCapacitance() * var_calcium_current__i_Ca; // uA_per_cm2
        const double var_inward_rectifier_potassium_current_K1_gate__alpha_K1 = 0.10000000000000001 / (1.0 + exp(-12.0 + 0.059999999999999998 * var_chaste_interface__membrane__V - 0.059999999999999998 * var_delayed_rectifier_potassium_current__E_K)); // per_millisecond
        const double var_inward_rectifier_potassium_current_K1_gate__beta_K1 = (3.0 * exp(0.02 + 0.00020000000000000001 * var_chaste_interface__membrane__V - 0.00020000000000000001 * var_delayed_rectifier_potassium_current__E_K) + exp(-1.0 + 0.10000000000000001 * var_chaste_interface__membrane__V - 0.10000000000000001 * var_delayed_rectifier_potassium_current__E_K)) / (1.0 + exp(0.5 * var_delayed_rectifier_potassium_current__E_K - 0.5 * var_chaste_interface__membrane__V)); // per_millisecond
        const double var_inward_rectifier_potassium_current_K1_gate__K1_infinity = var_inward_rectifier_potassium_current_K1_gate__alpha_K1 / (var_inward_rectifier_potassium_current_K1_gate__alpha_K1 + var_inward_rectifier_potassium_current_K1_gate__beta_K1); // dimensionless
        const double var_inward_rectifier_potassium_current__i_K1 = (-var_delayed_rectifier_potassium_current__E_K + var_chaste_interface__membrane__V) * NV_Ith_S(mParameters, 9) * var_inward_rectifier_potassium_current_K1_gate__K1_infinity; // picoA_per_picoF
        const double var_inward_rectifier_potassium_current__i_K1_converted = HeartConfig::Instance()->GetCapacitance() * var_inward_rectifier_potassium_current__i_K1; // uA_per_cm2
        const double var_sodium_current__E_Na = var_membrane__R * var_membrane__T * log(NV_Ith_S(mParameters, 5) / NV_Ith_S(mParameters, 2)) / var_membrane__F; // millivolt
        const double var_sodium_current__i_Na = pow(var_chaste_interface__sodium_current_m_gate__m, 3) * pow(var_chaste_interface__sodium_current_v_gate__v, 2) * (-var_sodium_current__E_Na + var_chaste_interface__membrane__V) * NV_Ith_S(mParameters, 8); // picoA_per_picoF
        const double var_sodium_current__i_Na_converted = HeartConfig::Instance()->GetCapacitance() * var_sodium_current__i_Na; // uA_per_cm2
        const double var_stimulus_protocol__i_stim_converted = GetIntracellularAreaStimulus(var_chaste_interface__environment__time); // uA_per_cm2

        N_Vector dqs = N_VNew_Serial(6);
        NV_Ith_S(dqs, 0) = var_calcium_current__i_Ca_converted;
        NV_Ith_S(dqs, 1) = var_membrane__Cm_converted;
        NV_Ith_S(dqs, 2) = var_sodium_current__i_Na_converted;
        NV_Ith_S(dqs, 3) = var_inward_rectifier_potassium_current__i_K1_converted;
        NV_Ith_S(dqs, 4) = var_stimulus_protocol__i_stim_converted;
        NV_Ith_S(dqs, 5) = var_chaste_interface__environment__time;
        return dqs;
    }

template<>
void OdeSystemInformation<Cellbernus_wilders_zemlin_verschelde_panfilov_2002FromCellMLCvode>::Initialise(void)
{
    this->mSystemName = "bernus_wilders_zemlin_verschelde_panfilov_2002_version01";
    this->mFreeVariableName = "time";
    this->mFreeVariableUnits = "millisecond";

    // NV_Ith_S(rY, 0):
    this->mVariableNames.push_back("membrane_voltage");
    this->mVariableUnits.push_back("millivolt");
    this->mInitialConditions.push_back(-90.2);

    // NV_Ith_S(rY, 1):
    this->mVariableNames.push_back("sodium_current_m_gate__m");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(0.0016203);

    // NV_Ith_S(rY, 2):
    this->mVariableNames.push_back("sodium_current_v_gate__v");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(0.9944036);

    // NV_Ith_S(rY, 3):
    this->mVariableNames.push_back("membrane_L_type_calcium_current_f_gate");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(1.0);

    // NV_Ith_S(rY, 4):
    this->mVariableNames.push_back("transient_outward_current_to_gate__to");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(0.0);

    // NV_Ith_S(rY, 5):
    this->mVariableNames.push_back("delayed_rectifier_potassium_current_X_gate__X");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(0.000928836);

    // mParameters[0]:
    this->mParameterNames.push_back("cytosolic_calcium_concentration");
    this->mParameterUnits.push_back("millimolar");

    // mParameters[1]:
    this->mParameterNames.push_back("cytosolic_potassium_concentration");
    this->mParameterUnits.push_back("millimolar");

    // mParameters[2]:
    this->mParameterNames.push_back("cytosolic_sodium_concentration");
    this->mParameterUnits.push_back("millimolar");

    // mParameters[3]:
    this->mParameterNames.push_back("extracellular_calcium_concentration");
    this->mParameterUnits.push_back("millimolar");

    // mParameters[4]:
    this->mParameterNames.push_back("extracellular_potassium_concentration");
    this->mParameterUnits.push_back("millimolar");

    // mParameters[5]:
    this->mParameterNames.push_back("extracellular_sodium_concentration");
    this->mParameterUnits.push_back("millimolar");

    // mParameters[6]:
    this->mParameterNames.push_back("membrane_L_type_calcium_current_conductance");
    this->mParameterUnits.push_back("nanoS_per_picoF");

    // mParameters[7]:
    this->mParameterNames.push_back("membrane__Cm");
    this->mParameterUnits.push_back("picoF");

    // mParameters[8]:
    this->mParameterNames.push_back("membrane_fast_sodium_current_conductance");
    this->mParameterUnits.push_back("nanoS_per_picoF");

    // mParameters[9]:
    this->mParameterNames.push_back("membrane_inward_rectifier_potassium_current_conductance");
    this->mParameterUnits.push_back("nanoS_per_picoF");

    // Derived Quantity index [0]:
    this->mDerivedQuantityNames.push_back("membrane_L_type_calcium_current");
    this->mDerivedQuantityUnits.push_back("uA_per_cm2");

    // Derived Quantity index [1]:
    this->mDerivedQuantityNames.push_back("membrane_capacitance");
    this->mDerivedQuantityUnits.push_back("uF");

    // Derived Quantity index [2]:
    this->mDerivedQuantityNames.push_back("membrane_fast_sodium_current");
    this->mDerivedQuantityUnits.push_back("uA_per_cm2");

    // Derived Quantity index [3]:
    this->mDerivedQuantityNames.push_back("membrane_inward_rectifier_potassium_current");
    this->mDerivedQuantityUnits.push_back("uA_per_cm2");

    // Derived Quantity index [4]:
    this->mDerivedQuantityNames.push_back("membrane_stimulus_current");
    this->mDerivedQuantityUnits.push_back("uA_per_cm2");

    // Derived Quantity index [5]:
    this->mDerivedQuantityNames.push_back("time");
    this->mDerivedQuantityUnits.push_back("millisecond");

    this->mInitialised = true;
}

// Serialization for Boost >= 1.36
#include "SerializationExportWrapperForCpp.hpp"
CHASTE_CLASS_EXPORT(Cellbernus_wilders_zemlin_verschelde_panfilov_2002FromCellMLCvode)

#endif // CHASTE_CVODE
