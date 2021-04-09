#ifdef CHASTE_CVODE
//! @file
//!
//! This source file was generated from CellML by chaste_codegen version (version omitted as unimportant)
//!
//! Model: mcallister_noble_tsien_1975_modelB
//!
//! Processed by chaste_codegen: https://github.com/ModellingWebLab/chaste-codegen
//!     (translator: chaste_codegen, model type: NumericCvode)
//! on (date omitted as unimportant)
//!
//! <autogenerated>

#include "mcallister_noble_tsien_1975_b.hpp"
#include <cmath>
#include <cassert>
#include <memory>
#include "Exception.hpp"
#include "OdeSystemInformation.hpp"
#include "RegularStimulus.hpp"
#include "HeartConfig.hpp"
#include "IsNan.hpp"
#include "MathsCustomFunctions.hpp"




    Cellmcallister_noble_tsien_1975_bFromCellMLCvode::Cellmcallister_noble_tsien_1975_bFromCellMLCvode(boost::shared_ptr<AbstractIvpOdeSolver> pOdeSolver /* unused; should be empty */, boost::shared_ptr<AbstractStimulusFunction> pIntracellularStimulus)
        : AbstractCvodeCell(
                pOdeSolver,
                10,
                0,
                pIntracellularStimulus)
    {
        // Time units: millisecond
        //
        this->mpSystemInfo = OdeSystemInformation<Cellmcallister_noble_tsien_1975_bFromCellMLCvode>::Instance();
        Init();
        
        NV_Ith_S(this->mParameters, 0) = 1.0; // (var_secondary_inward_current__g_si_mult) [dimensionless]
        NV_Ith_S(this->mParameters, 1) = 10.0; // (var_membrane__C) [microF_per_cm2]
        NV_Ith_S(this->mParameters, 2) = 150.0; // (var_fast_sodium_current__g_Na) [milliS_per_cm2]
        NV_Ith_S(this->mParameters, 3) = 25.0; // (var_plateau_potassium_current2__g_x2) [microA_per_cm2]
    }

    Cellmcallister_noble_tsien_1975_bFromCellMLCvode::~Cellmcallister_noble_tsien_1975_bFromCellMLCvode()
    {
    }

    
    double Cellmcallister_noble_tsien_1975_bFromCellMLCvode::GetIIonic(const std::vector<double>* pStateVariables)
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
        // Units: millivolt; Initial value: -78.041367
        double var_chaste_interface__fast_sodium_current_m_gate__m = NV_Ith_S(rY, 1);
        // Units: dimensionless; Initial value: 0.02566853
        double var_chaste_interface__fast_sodium_current_h_gate__h = NV_Ith_S(rY, 2);
        // Units: dimensionless; Initial value: 0.78656359
        double var_chaste_interface__secondary_inward_current_d_gate__d = NV_Ith_S(rY, 3);
        // Units: dimensionless; Initial value: 0.00293135
        double var_chaste_interface__secondary_inward_current_f_gate__f = NV_Ith_S(rY, 4);
        // Units: dimensionless; Initial value: 0.80873917
        double var_chaste_interface__pacemaker_potassium_current_s_gate__s = NV_Ith_S(rY, 5);
        // Units: dimensionless; Initial value: 0.75473994
        double var_chaste_interface__plateau_potassium_current1_x1_gate__x1 = NV_Ith_S(rY, 6);
        // Units: dimensionless; Initial value: 0.02030289
        double var_chaste_interface__plateau_potassium_current2_x2_gate__x2 = NV_Ith_S(rY, 7);
        // Units: dimensionless; Initial value: 0.0176854
        double var_chaste_interface__transient_chloride_current_q_gate__q = NV_Ith_S(rY, 8);
        // Units: dimensionless; Initial value: 3.11285794
        double var_chaste_interface__transient_chloride_current_r_gate__r = NV_Ith_S(rY, 9);
        // Units: dimensionless; Initial value: 0.13500116
        
        const double var_chloride_background_current__g_Clb = 0.01; // milliS_per_cm2
        const double var_fast_sodium_current__E_Na = 40.0; // millivolt
        const double var_fast_sodium_current__i_Na = pow(var_chaste_interface__fast_sodium_current_m_gate__m, 3) * (-var_fast_sodium_current__E_Na + var_chaste_interface__membrane__V) * NV_Ith_S(mParameters, 2) * var_chaste_interface__fast_sodium_current_h_gate__h; // microA_per_cm2
        const double var_pacemaker_potassium_current__E_K = -110.0; // millivolt
        const double var_pacemaker_potassium_current__I_K2 = 2.7999999999999998 * (-1.0 + exp(0.040000000000000001 * var_chaste_interface__membrane__V - 0.040000000000000001 * var_pacemaker_potassium_current__E_K)) / (exp(2.3999999999999999 + 0.040000000000000001 * var_chaste_interface__membrane__V) + exp(4.7999999999999998 + 0.080000000000000002 * var_chaste_interface__membrane__V)); // microA_per_cm2
        const double var_pacemaker_potassium_current__i_K2 = var_pacemaker_potassium_current__I_K2 * var_chaste_interface__pacemaker_potassium_current_s_gate__s; // microA_per_cm2
        const double var_plateau_potassium_current1__I_x1 = 1.2 * (-1.0 + exp(3.7999999999999998 + 0.040000000000000001 * var_chaste_interface__membrane__V)) / exp(1.8 + 0.040000000000000001 * var_chaste_interface__membrane__V); // microA_per_cm2
        const double var_plateau_potassium_current1__i_x1 = var_plateau_potassium_current1__I_x1 * var_chaste_interface__plateau_potassium_current1_x1_gate__x1; // microA_per_cm2
        const double var_plateau_potassium_current2__I_x2 = 25.0 + 0.38500000000000001 * var_chaste_interface__membrane__V + NV_Ith_S(mParameters, 3); // microA_per_cm2
        const double var_plateau_potassium_current2__i_x2 = var_plateau_potassium_current2__I_x2 * var_chaste_interface__plateau_potassium_current2_x2_gate__x2; // microA_per_cm2
        const double var_secondary_inward_current__E_si = 70.0; // millivolt
        const double var_secondary_inward_current__g_si = 0.80000000000000004; // milliS_per_cm2
        const double var_secondary_inward_current__g_si_ = 0.040000000000000001; // milliS_per_cm2
        const double var_secondary_inward_current_d1_gate__d1 = 1 / (1.0 + exp(-6.0 - 0.14999999999999999 * var_chaste_interface__membrane__V)); // dimensionless
        const double var_secondary_inward_current__i_si = ((-var_secondary_inward_current__E_si + var_chaste_interface__membrane__V) * var_secondary_inward_current__g_si_ * var_secondary_inward_current_d1_gate__d1 + (-var_secondary_inward_current__E_si + var_chaste_interface__membrane__V) * var_secondary_inward_current__g_si * var_chaste_interface__secondary_inward_current_d_gate__d * var_chaste_interface__secondary_inward_current_f_gate__f) * NV_Ith_S(mParameters, 0); // microA_per_cm2
        const double var_sodium_background_current__g_Nab = 0.105; // milliS_per_cm2
        const double var_sodium_background_current__i_Na_b = (-var_fast_sodium_current__E_Na + var_chaste_interface__membrane__V) * var_sodium_background_current__g_Nab; // microA_per_cm2
        const double var_time_independent_outward_current__i_K1 = (-1 + exp(4.4000000000000004 + 0.040000000000000001 * var_chaste_interface__membrane__V)) / (exp(2.3999999999999999 + 0.040000000000000001 * var_chaste_interface__membrane__V) + exp(4.7999999999999998 + 0.080000000000000002 * var_chaste_interface__membrane__V)) + ((fabs(30.0 + var_chaste_interface__membrane__V) < 2.4999999999886224e-6) ? (4.9999999999772453e-7 / (1.0 - exp(-9.9999999999544901e-8)) - 200000.00000091019 * (29.999997499999999 + var_chaste_interface__membrane__V) * (-4.9999999999772453e-7 / (1.0 - exp(9.9999999999544901e-8)) - 4.9999999999772453e-7 / (1.0 - exp(-9.9999999999544901e-8)))) : (0.20000000000000001 * (30.0 + var_chaste_interface__membrane__V) / (1.0 - exp(-1.2 - 0.040000000000000001 * var_chaste_interface__membrane__V)))); // microA_per_cm2
        const double var_transient_chloride_current__E_Cl = -70.0; // millivolt
        const double var_chloride_background_current__i_Cl_b = (-var_transient_chloride_current__E_Cl + var_chaste_interface__membrane__V) * var_chloride_background_current__g_Clb; // microA_per_cm2
        const double var_transient_chloride_current__g_qr = 2.5; // milliS_per_cm2
        const double var_transient_chloride_current__i_qr = (-var_transient_chloride_current__E_Cl + var_chaste_interface__membrane__V) * var_transient_chloride_current__g_qr * var_chaste_interface__transient_chloride_current_q_gate__q * var_chaste_interface__transient_chloride_current_r_gate__r; // microA_per_cm2
        const double var_chaste_interface__i_ionic = var_chloride_background_current__i_Cl_b + var_fast_sodium_current__i_Na + var_pacemaker_potassium_current__i_K2 + var_plateau_potassium_current1__i_x1 + var_plateau_potassium_current2__i_x2 + var_secondary_inward_current__i_si + var_sodium_background_current__i_Na_b + var_time_independent_outward_current__i_K1 + var_transient_chloride_current__i_qr; // uA_per_cm2

        const double i_ionic = var_chaste_interface__i_ionic;
        if (made_new_cvode_vector)
        {
            DeleteVector(rY);
        }
        EXCEPT_IF_NOT(!std::isnan(i_ionic));
        return i_ionic;
    }

    void Cellmcallister_noble_tsien_1975_bFromCellMLCvode::EvaluateYDerivatives(double var_chaste_interface__environment__time, const N_Vector rY, N_Vector rDY)
    {
        // Inputs:
        // Time units: millisecond
        double var_chaste_interface__membrane__V = (mSetVoltageDerivativeToZero ? this->mFixedVoltage : NV_Ith_S(rY, 0));
        // Units: millivolt; Initial value: -78.041367
        double var_chaste_interface__fast_sodium_current_m_gate__m = NV_Ith_S(rY, 1);
        // Units: dimensionless; Initial value: 0.02566853
        double var_chaste_interface__fast_sodium_current_h_gate__h = NV_Ith_S(rY, 2);
        // Units: dimensionless; Initial value: 0.78656359
        double var_chaste_interface__secondary_inward_current_d_gate__d = NV_Ith_S(rY, 3);
        // Units: dimensionless; Initial value: 0.00293135
        double var_chaste_interface__secondary_inward_current_f_gate__f = NV_Ith_S(rY, 4);
        // Units: dimensionless; Initial value: 0.80873917
        double var_chaste_interface__pacemaker_potassium_current_s_gate__s = NV_Ith_S(rY, 5);
        // Units: dimensionless; Initial value: 0.75473994
        double var_chaste_interface__plateau_potassium_current1_x1_gate__x1 = NV_Ith_S(rY, 6);
        // Units: dimensionless; Initial value: 0.02030289
        double var_chaste_interface__plateau_potassium_current2_x2_gate__x2 = NV_Ith_S(rY, 7);
        // Units: dimensionless; Initial value: 0.0176854
        double var_chaste_interface__transient_chloride_current_q_gate__q = NV_Ith_S(rY, 8);
        // Units: dimensionless; Initial value: 3.11285794
        double var_chaste_interface__transient_chloride_current_r_gate__r = NV_Ith_S(rY, 9);
        // Units: dimensionless; Initial value: 0.13500116

        // Mathematics
        double d_dt_chaste_interface_var_membrane__V;
        const double var_fast_sodium_current_h_gate__alpha_h = 0.0085000000000000006 * exp(-13.064 - 0.184 * var_chaste_interface__membrane__V); // per_millisecond
        const double var_fast_sodium_current_h_gate__beta_h = 2.5 / (1.0 + exp(-0.82000000000000006 - 0.082000000000000003 * var_chaste_interface__membrane__V)); // per_millisecond
        const double d_dt_chaste_interface_var_fast_sodium_current_h_gate__h = (1.0 - var_chaste_interface__fast_sodium_current_h_gate__h) * var_fast_sodium_current_h_gate__alpha_h - var_fast_sodium_current_h_gate__beta_h * var_chaste_interface__fast_sodium_current_h_gate__h; // 1 / millisecond
        const double var_fast_sodium_current_m_gate__alpha_m = ((fabs(47.0 + var_chaste_interface__membrane__V) < 1.0000000000287557e-6) ? (9.9999999997324451e-7 / (1.0 - exp(-9.9999999997324457e-8)) - 499999.99998562218 * (46.999999000000003 + var_chaste_interface__membrane__V) * (-9.9999999997324451e-7 / (1.0 - exp(-9.9999999997324457e-8)) - 1.0000000000842668e-6 / (1.0 - exp(1.0000000000842668e-7)))) : ((47.0 + var_chaste_interface__membrane__V) / (1.0 - exp(-4.7000000000000002 - 0.10000000000000001 * var_chaste_interface__membrane__V)))); // per_millisecond
        const double var_fast_sodium_current_m_gate__beta_m = 40.0 * exp(-4.032 - 0.056000000000000001 * var_chaste_interface__membrane__V); // per_millisecond
        const double d_dt_chaste_interface_var_fast_sodium_current_m_gate__m = (1.0 - var_chaste_interface__fast_sodium_current_m_gate__m) * var_fast_sodium_current_m_gate__alpha_m - var_fast_sodium_current_m_gate__beta_m * var_chaste_interface__fast_sodium_current_m_gate__m; // 1 / millisecond
        const double var_pacemaker_potassium_current_s_gate__E_s = -52.0; // millivolt
        const double var_pacemaker_potassium_current_s_gate__alpha_s = ((fabs(52.0 + var_chaste_interface__membrane__V) < 5.0000000001437783e-7) ? (5.0000000001437788e-10 / (1.0 - exp(-1.0000000000287557e-7)) - 999999.99997124437 * (51.999999500000001 + var_chaste_interface__membrane__V) * (-5.0000000001437788e-10 / (1.0 - exp(1.0000000000287557e-7)) - 5.0000000001437788e-10 / (1.0 - exp(-1.0000000000287557e-7)))) : (0.001 * (52.0 + var_chaste_interface__membrane__V) / (1.0 - exp(-10.4 - 0.20000000000000001 * var_chaste_interface__membrane__V)))); // per_millisecond
        const double var_pacemaker_potassium_current_s_gate__beta_s = 5.0000000000000002e-5 * exp(0.067000000000000004 * var_pacemaker_potassium_current_s_gate__E_s - 0.067000000000000004 * var_chaste_interface__membrane__V); // per_millisecond
        const double d_dt_chaste_interface_var_pacemaker_potassium_current_s_gate__s = (1.0 - var_chaste_interface__pacemaker_potassium_current_s_gate__s) * var_pacemaker_potassium_current_s_gate__alpha_s - var_pacemaker_potassium_current_s_gate__beta_s * var_chaste_interface__pacemaker_potassium_current_s_gate__s; // 1 / millisecond
        const double var_plateau_potassium_current1_x1_gate__alpha_x1 = 0.00050000000000000001 * exp(4.1322314049586781 + 0.082644628099173556 * var_chaste_interface__membrane__V) / (1.0 + exp(2.8571428571428572 + 0.057142857142857141 * var_chaste_interface__membrane__V)); // per_millisecond
        const double var_plateau_potassium_current1_x1_gate__beta_x1 = 0.0012999999999999999 * exp(-1.1997600479904018 - 0.059988002399520089 * var_chaste_interface__membrane__V) / (1.0 + exp(-0.80000000000000004 - 0.040000000000000001 * var_chaste_interface__membrane__V)); // per_millisecond
        const double d_dt_chaste_interface_var_plateau_potassium_current1_x1_gate__x1 = (1.0 - var_chaste_interface__plateau_potassium_current1_x1_gate__x1) * var_plateau_potassium_current1_x1_gate__alpha_x1 - var_plateau_potassium_current1_x1_gate__beta_x1 * var_chaste_interface__plateau_potassium_current1_x1_gate__x1; // 1 / millisecond
        const double var_plateau_potassium_current2_x2_gate__alpha_x2 = 0.000127 / (1.0 + exp(-3.7999999999999998 - 0.20000000000000001 * var_chaste_interface__membrane__V)); // per_millisecond
        const double var_plateau_potassium_current2_x2_gate__beta_x2 = 0.00029999999999999997 * exp(-1.1997600479904018 - 0.059988002399520089 * var_chaste_interface__membrane__V) / (1.0 + exp(-0.80000000000000004 - 0.040000000000000001 * var_chaste_interface__membrane__V)); // per_millisecond
        const double d_dt_chaste_interface_var_plateau_potassium_current2_x2_gate__x2 = (1.0 - var_chaste_interface__plateau_potassium_current2_x2_gate__x2) * var_plateau_potassium_current2_x2_gate__alpha_x2 - var_plateau_potassium_current2_x2_gate__beta_x2 * var_chaste_interface__plateau_potassium_current2_x2_gate__x2; // 1 / millisecond
        const double var_secondary_inward_current_d_gate__alpha_d = ((fabs(40.0 + var_chaste_interface__membrane__V) < 1.0000000000010001e-6) ? (1.999999999946489e-9 / (1.0 - exp(-9.9999999997324457e-8)) - 499999.99999949994 * (39.999999000000003 + var_chaste_interface__membrane__V) * (-1.999999999946489e-9 / (1.0 - exp(-9.9999999997324457e-8)) - 2.0000000000575115e-9 / (1.0 - exp(1.0000000000287557e-7)))) : (0.002 * (40.0 + var_chaste_interface__membrane__V) / (1.0 - exp(-4.0 - 0.10000000000000001 * var_chaste_interface__membrane__V)))); // per_millisecond
        const double var_secondary_inward_current_d_gate__beta_d = 0.02 * exp(-3.552 - 0.088800000000000004 * var_chaste_interface__membrane__V); // per_millisecond
        const double d_dt_chaste_interface_var_secondary_inward_current_d_gate__d = (1.0 - var_chaste_interface__secondary_inward_current_d_gate__d) * var_secondary_inward_current_d_gate__alpha_d - var_secondary_inward_current_d_gate__beta_d * var_chaste_interface__secondary_inward_current_d_gate__d; // 1 / millisecond
        const double var_secondary_inward_current_f_gate__alpha_f = 0.00098700000000000003 * exp(-2.3999999999999999 - 0.040000000000000001 * var_chaste_interface__membrane__V); // per_millisecond
        const double var_secondary_inward_current_f_gate__beta_f = 0.02 / (1.0 + exp(-2.262 - 0.086999999999999994 * var_chaste_interface__membrane__V)); // per_millisecond
        const double d_dt_chaste_interface_var_secondary_inward_current_f_gate__f = (1.0 - var_chaste_interface__secondary_inward_current_f_gate__f) * var_secondary_inward_current_f_gate__alpha_f - var_secondary_inward_current_f_gate__beta_f * var_chaste_interface__secondary_inward_current_f_gate__f; // 1 / millisecond
        const double var_transient_chloride_current_q_gate__alpha_q = ((fabs(var_chaste_interface__membrane__V) < 9.9999999999999995e-7) ? (7.9999999999999988e-9 / (1.0 - exp(-9.9999999999999995e-8)) - 500000.00000000006 * (-9.9999999999999995e-7 + var_chaste_interface__membrane__V) * (-7.9999999999999988e-9 / (1.0 - exp(9.9999999999999995e-8)) - 7.9999999999999988e-9 / (1.0 - exp(-9.9999999999999995e-8)))) : (0.0080000000000000002 * var_chaste_interface__membrane__V / (1.0 - exp(-0.10000000000000001 * var_chaste_interface__membrane__V)))); // per_millisecond
        const double var_transient_chloride_current_q_gate__beta_q = 0.080000000000000002 * exp(-0.088800000000000004 * var_chaste_interface__membrane__V); // per_millisecond
        const double d_dt_chaste_interface_var_transient_chloride_current_q_gate__q = (1.0 - var_chaste_interface__transient_chloride_current_q_gate__q) * var_transient_chloride_current_q_gate__alpha_q - var_transient_chloride_current_q_gate__beta_q * var_chaste_interface__transient_chloride_current_q_gate__q; // 1 / millisecond
        const double var_transient_chloride_current_r_gate__alpha_r = 3.3000000000000003e-5 * exp(-0.058823529411764705 * var_chaste_interface__membrane__V); // per_millisecond
        const double var_transient_chloride_current_r_gate__beta_r = 0.033000000000000002 / (1.0 + exp(-3.75 - 0.125 * var_chaste_interface__membrane__V)); // per_millisecond
        const double d_dt_chaste_interface_var_transient_chloride_current_r_gate__r = (1.0 - var_chaste_interface__transient_chloride_current_r_gate__r) * var_transient_chloride_current_r_gate__alpha_r - var_transient_chloride_current_r_gate__beta_r * var_chaste_interface__transient_chloride_current_r_gate__r; // 1 / millisecond

        if (mSetVoltageDerivativeToZero)
        {
            d_dt_chaste_interface_var_membrane__V = 0.0;
        }
        else
        {
            const double var_chloride_background_current__g_Clb = 0.01; // milliS_per_cm2
            const double var_fast_sodium_current__E_Na = 40.0; // millivolt
            const double var_fast_sodium_current__i_Na = pow(var_chaste_interface__fast_sodium_current_m_gate__m, 3) * (-var_fast_sodium_current__E_Na + var_chaste_interface__membrane__V) * NV_Ith_S(mParameters, 2) * var_chaste_interface__fast_sodium_current_h_gate__h; // microA_per_cm2
            const double var_pacemaker_potassium_current__E_K = -110.0; // millivolt
            const double var_pacemaker_potassium_current__I_K2 = 2.7999999999999998 * (-1.0 + exp(0.040000000000000001 * var_chaste_interface__membrane__V - 0.040000000000000001 * var_pacemaker_potassium_current__E_K)) / (exp(2.3999999999999999 + 0.040000000000000001 * var_chaste_interface__membrane__V) + exp(4.7999999999999998 + 0.080000000000000002 * var_chaste_interface__membrane__V)); // microA_per_cm2
            const double var_pacemaker_potassium_current__i_K2 = var_pacemaker_potassium_current__I_K2 * var_chaste_interface__pacemaker_potassium_current_s_gate__s; // microA_per_cm2
            const double var_plateau_potassium_current1__I_x1 = 1.2 * (-1.0 + exp(3.7999999999999998 + 0.040000000000000001 * var_chaste_interface__membrane__V)) / exp(1.8 + 0.040000000000000001 * var_chaste_interface__membrane__V); // microA_per_cm2
            const double var_plateau_potassium_current1__i_x1 = var_plateau_potassium_current1__I_x1 * var_chaste_interface__plateau_potassium_current1_x1_gate__x1; // microA_per_cm2
            const double var_plateau_potassium_current2__I_x2 = 25.0 + 0.38500000000000001 * var_chaste_interface__membrane__V + NV_Ith_S(mParameters, 3); // microA_per_cm2
            const double var_plateau_potassium_current2__i_x2 = var_plateau_potassium_current2__I_x2 * var_chaste_interface__plateau_potassium_current2_x2_gate__x2; // microA_per_cm2
            const double var_secondary_inward_current__E_si = 70.0; // millivolt
            const double var_secondary_inward_current__g_si = 0.80000000000000004; // milliS_per_cm2
            const double var_secondary_inward_current__g_si_ = 0.040000000000000001; // milliS_per_cm2
            const double var_secondary_inward_current_d1_gate__d1 = 1 / (1.0 + exp(-6.0 - 0.14999999999999999 * var_chaste_interface__membrane__V)); // dimensionless
            const double var_secondary_inward_current__i_si = ((-var_secondary_inward_current__E_si + var_chaste_interface__membrane__V) * var_secondary_inward_current__g_si_ * var_secondary_inward_current_d1_gate__d1 + (-var_secondary_inward_current__E_si + var_chaste_interface__membrane__V) * var_secondary_inward_current__g_si * var_chaste_interface__secondary_inward_current_d_gate__d * var_chaste_interface__secondary_inward_current_f_gate__f) * NV_Ith_S(mParameters, 0); // microA_per_cm2
            const double var_sodium_background_current__g_Nab = 0.105; // milliS_per_cm2
            const double var_sodium_background_current__i_Na_b = (-var_fast_sodium_current__E_Na + var_chaste_interface__membrane__V) * var_sodium_background_current__g_Nab; // microA_per_cm2
            const double var_time_independent_outward_current__i_K1 = (-1 + exp(4.4000000000000004 + 0.040000000000000001 * var_chaste_interface__membrane__V)) / (exp(2.3999999999999999 + 0.040000000000000001 * var_chaste_interface__membrane__V) + exp(4.7999999999999998 + 0.080000000000000002 * var_chaste_interface__membrane__V)) + ((fabs(30.0 + var_chaste_interface__membrane__V) < 2.4999999999886224e-6) ? (4.9999999999772453e-7 / (1.0 - exp(-9.9999999999544901e-8)) - 200000.00000091019 * (29.999997499999999 + var_chaste_interface__membrane__V) * (-4.9999999999772453e-7 / (1.0 - exp(9.9999999999544901e-8)) - 4.9999999999772453e-7 / (1.0 - exp(-9.9999999999544901e-8)))) : (0.20000000000000001 * (30.0 + var_chaste_interface__membrane__V) / (1.0 - exp(-1.2 - 0.040000000000000001 * var_chaste_interface__membrane__V)))); // microA_per_cm2
            const double var_transient_chloride_current__E_Cl = -70.0; // millivolt
            const double var_chloride_background_current__i_Cl_b = (-var_transient_chloride_current__E_Cl + var_chaste_interface__membrane__V) * var_chloride_background_current__g_Clb; // microA_per_cm2
            const double var_transient_chloride_current__g_qr = 2.5; // milliS_per_cm2
            const double var_transient_chloride_current__i_qr = (-var_transient_chloride_current__E_Cl + var_chaste_interface__membrane__V) * var_transient_chloride_current__g_qr * var_chaste_interface__transient_chloride_current_q_gate__q * var_chaste_interface__transient_chloride_current_r_gate__r; // microA_per_cm2
            d_dt_chaste_interface_var_membrane__V = (-var_chloride_background_current__i_Cl_b - var_fast_sodium_current__i_Na - var_pacemaker_potassium_current__i_K2 - var_plateau_potassium_current1__i_x1 - var_plateau_potassium_current2__i_x2 - var_secondary_inward_current__i_si - var_sodium_background_current__i_Na_b - var_time_independent_outward_current__i_K1 - var_transient_chloride_current__i_qr) / NV_Ith_S(mParameters, 1); // millivolt / millisecond
        }
        
        NV_Ith_S(rDY,0) = d_dt_chaste_interface_var_membrane__V;
        NV_Ith_S(rDY,1) = d_dt_chaste_interface_var_fast_sodium_current_m_gate__m;
        NV_Ith_S(rDY,2) = d_dt_chaste_interface_var_fast_sodium_current_h_gate__h;
        NV_Ith_S(rDY,3) = d_dt_chaste_interface_var_secondary_inward_current_d_gate__d;
        NV_Ith_S(rDY,4) = d_dt_chaste_interface_var_secondary_inward_current_f_gate__f;
        NV_Ith_S(rDY,5) = d_dt_chaste_interface_var_pacemaker_potassium_current_s_gate__s;
        NV_Ith_S(rDY,6) = d_dt_chaste_interface_var_plateau_potassium_current1_x1_gate__x1;
        NV_Ith_S(rDY,7) = d_dt_chaste_interface_var_plateau_potassium_current2_x2_gate__x2;
        NV_Ith_S(rDY,8) = d_dt_chaste_interface_var_transient_chloride_current_q_gate__q;
        NV_Ith_S(rDY,9) = d_dt_chaste_interface_var_transient_chloride_current_r_gate__r;
    }

    N_Vector Cellmcallister_noble_tsien_1975_bFromCellMLCvode::ComputeDerivedQuantities(double var_chaste_interface__environment__time, const N_Vector & rY)
    {
        // Inputs:
        // Time units: millisecond
        double var_chaste_interface__membrane__V = (mSetVoltageDerivativeToZero ? this->mFixedVoltage : NV_Ith_S(rY, 0));
        // Units: millivolt; Initial value: -78.041367
        double var_chaste_interface__fast_sodium_current_m_gate__m = NV_Ith_S(rY, 1);
        // Units: dimensionless; Initial value: 0.02566853
        double var_chaste_interface__fast_sodium_current_h_gate__h = NV_Ith_S(rY, 2);
        // Units: dimensionless; Initial value: 0.78656359
        
        // Mathematics
        const double var_fast_sodium_current__E_Na = 40.0; // millivolt
        const double var_fast_sodium_current__i_Na = pow(var_chaste_interface__fast_sodium_current_m_gate__m, 3) * (-var_fast_sodium_current__E_Na + var_chaste_interface__membrane__V) * NV_Ith_S(mParameters, 2) * var_chaste_interface__fast_sodium_current_h_gate__h; // microA_per_cm2
        const double var_time_independent_outward_current__i_K1 = (-1 + exp(4.4000000000000004 + 0.040000000000000001 * var_chaste_interface__membrane__V)) / (exp(2.3999999999999999 + 0.040000000000000001 * var_chaste_interface__membrane__V) + exp(4.7999999999999998 + 0.080000000000000002 * var_chaste_interface__membrane__V)) + ((fabs(30.0 + var_chaste_interface__membrane__V) < 2.4999999999886224e-6) ? (4.9999999999772453e-7 / (1.0 - exp(-9.9999999999544901e-8)) - 200000.00000091019 * (29.999997499999999 + var_chaste_interface__membrane__V) * (-4.9999999999772453e-7 / (1.0 - exp(9.9999999999544901e-8)) - 4.9999999999772453e-7 / (1.0 - exp(-9.9999999999544901e-8)))) : (0.20000000000000001 * (30.0 + var_chaste_interface__membrane__V) / (1.0 - exp(-1.2 - 0.040000000000000001 * var_chaste_interface__membrane__V)))); // microA_per_cm2

        N_Vector dqs = N_VNew_Serial(3);
        NV_Ith_S(dqs, 0) = var_fast_sodium_current__i_Na;
        NV_Ith_S(dqs, 1) = var_time_independent_outward_current__i_K1;
        NV_Ith_S(dqs, 2) = var_chaste_interface__environment__time;
        return dqs;
    }

template<>
void OdeSystemInformation<Cellmcallister_noble_tsien_1975_bFromCellMLCvode>::Initialise(void)
{
    this->mSystemName = "mcallister_noble_tsien_1975_modelB";
    this->mFreeVariableName = "time";
    this->mFreeVariableUnits = "millisecond";

    // NV_Ith_S(rY, 0):
    this->mVariableNames.push_back("membrane_voltage");
    this->mVariableUnits.push_back("millivolt");
    this->mInitialConditions.push_back(-78.041367);

    // NV_Ith_S(rY, 1):
    this->mVariableNames.push_back("fast_sodium_current_m_gate__m");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(0.02566853);

    // NV_Ith_S(rY, 2):
    this->mVariableNames.push_back("fast_sodium_current_h_gate__h");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(0.78656359);

    // NV_Ith_S(rY, 3):
    this->mVariableNames.push_back("secondary_inward_current_d_gate__d");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(0.00293135);

    // NV_Ith_S(rY, 4):
    this->mVariableNames.push_back("secondary_inward_current_f_gate__f");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(0.80873917);

    // NV_Ith_S(rY, 5):
    this->mVariableNames.push_back("pacemaker_potassium_current_s_gate__s");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(0.75473994);

    // NV_Ith_S(rY, 6):
    this->mVariableNames.push_back("plateau_potassium_current1_x1_gate__x1");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(0.02030289);

    // NV_Ith_S(rY, 7):
    this->mVariableNames.push_back("plateau_potassium_current2_x2_gate__x2");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(0.0176854);

    // NV_Ith_S(rY, 8):
    this->mVariableNames.push_back("transient_chloride_current_q_gate__q");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(3.11285794);

    // NV_Ith_S(rY, 9):
    this->mVariableNames.push_back("transient_chloride_current_r_gate__r");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(0.13500116);

    // mParameters[0]:
    this->mParameterNames.push_back("membrane_L_type_calcium_current_conductance");
    this->mParameterUnits.push_back("dimensionless");

    // mParameters[1]:
    this->mParameterNames.push_back("membrane_capacitance");
    this->mParameterUnits.push_back("microF_per_cm2");

    // mParameters[2]:
    this->mParameterNames.push_back("membrane_fast_sodium_current_conductance");
    this->mParameterUnits.push_back("milliS_per_cm2");

    // mParameters[3]:
    this->mParameterNames.push_back("membrane_rapid_delayed_rectifier_potassium_current_conductance");
    this->mParameterUnits.push_back("microA_per_cm2");

    // Derived Quantity index [0]:
    this->mDerivedQuantityNames.push_back("membrane_fast_sodium_current");
    this->mDerivedQuantityUnits.push_back("microA_per_cm2");

    // Derived Quantity index [1]:
    this->mDerivedQuantityNames.push_back("membrane_inward_rectifier_potassium_current");
    this->mDerivedQuantityUnits.push_back("microA_per_cm2");

    // Derived Quantity index [2]:
    this->mDerivedQuantityNames.push_back("time");
    this->mDerivedQuantityUnits.push_back("millisecond");

    
    this->mAttributes["SuggestedCycleLength"] = 2000;
    this->mInitialised = true;
}

// Serialization for Boost >= 1.36
#include "SerializationExportWrapperForCpp.hpp"
CHASTE_CLASS_EXPORT(Cellmcallister_noble_tsien_1975_bFromCellMLCvode)

#endif // CHASTE_CVODE
