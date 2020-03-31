//! @file
//! 
//! This source file was generated from CellML.
//! 
//! Model: LivshitzRudy2007
//! 
//! Processed by pycml - CellML Tools in Python
//!     (translators: , pycml: , optimize: )
//! on (date omitted as unimportant)
//! 
//! <autogenerated>

#include "livshitz_rudy_2007.hpp"
#include <cmath>
#include <cassert>
#include <memory>
#include "Exception.hpp"
#include "OdeSystemInformation.hpp"
#include "RegularStimulus.hpp"
#include "HeartConfig.hpp"
#include "IsNan.hpp"
#include "MathsCustomFunctions.hpp"

    boost::shared_ptr<RegularStimulus> Dynamiclivshitz_rudy_2007FromCellMLRushLarsen::UseCellMLDefaultStimulus()
    {
        // Use the default stimulus specified by CellML metadata
        const double var_chaste_interface__cell__stim_offset = 0.0; // millisecond
        const double var_chaste_interface__cell__stim_period = 400.0; // millisecond
        const double var_chaste_interface__cell__stim_duration = 3.0; // millisecond
        const double var_chaste_interface__cell__stim_amplitude =  -15.0 * HeartConfig::Instance()->GetCapacitance(); // uA_per_cm2
        boost::shared_ptr<RegularStimulus> p_cellml_stim(new RegularStimulus(
                -fabs(var_chaste_interface__cell__stim_amplitude),
                var_chaste_interface__cell__stim_duration,
                var_chaste_interface__cell__stim_period,
                var_chaste_interface__cell__stim_offset
                ));
        mpIntracellularStimulus = p_cellml_stim;
        return p_cellml_stim;
    }
    
    Dynamiclivshitz_rudy_2007FromCellMLRushLarsen::Dynamiclivshitz_rudy_2007FromCellMLRushLarsen(boost::shared_ptr<AbstractIvpOdeSolver> /* unused; should be empty */, boost::shared_ptr<AbstractStimulusFunction> pIntracellularStimulus)
        : AbstractRushLarsenCardiacCell(
                18,
                0,
                pIntracellularStimulus)
    {
        // Time units: millisecond
        // 
        this->mpSystemInfo = OdeSystemInformation<Dynamiclivshitz_rudy_2007FromCellMLRushLarsen>::Instance();
        Init();

        // We have a default stimulus specified in the CellML file metadata
        this->mHasDefaultStimulusFromCellML = true;
    }
    
    Dynamiclivshitz_rudy_2007FromCellMLRushLarsen::~Dynamiclivshitz_rudy_2007FromCellMLRushLarsen()
    {
    }
    
    double Dynamiclivshitz_rudy_2007FromCellMLRushLarsen::GetIIonic(const std::vector<double>* pStateVariables)
    {
        // For state variable interpolation (SVI) we read in interpolated state variables,
        // otherwise for ionic current interpolation (ICI) we use the state variables of this model (node).
        if (!pStateVariables) pStateVariables = &rGetStateVariables();
        const std::vector<double>& rY = *pStateVariables;
        double var_chaste_interface__cell__V = (mSetVoltageDerivativeToZero ? this->mFixedVoltage : rY[0]);
        // Units: millivolt; Initial value: -89.4356034692784
        double var_chaste_interface__INa__H = rY[1];
        // Units: dimensionless; Initial value: 0.994401369032678
        double var_chaste_interface__INa__m = rY[2];
        // Units: dimensionless; Initial value: 0.000734780346592185
        double var_chaste_interface__INa__J = rY[3];
        // Units: dimensionless; Initial value: 0.996100688673679
        double var_chaste_interface__ICaL__d = rY[4];
        // Units: dimensionless; Initial value: 3.2514786721066e-27
        double var_chaste_interface__ICaL__f = rY[5];
        // Units: dimensionless; Initial value: 0.997404948824816
        double var_chaste_interface__IKr__xr = rY[6];
        // Units: dimensionless; Initial value: 0.000162194715543637
        double var_chaste_interface__IKs__xs1 = rY[7];
        // Units: dimensionless; Initial value: 0.0285147332973946
        double var_chaste_interface__IKs__xs2 = rY[8];
        // Units: dimensionless; Initial value: 0.0764114040188678
        double var_chaste_interface__ICaT__b = rY[9];
        // Units: dimensionless; Initial value: 0.000927461915392873
        double var_chaste_interface__ICaT__g = rY[10];
        // Units: dimensionless; Initial value: 0.952834331760863
        double var_chaste_interface__Na__Na_i = rY[12];
        // Units: mM; Initial value: 16.612739313555
        double var_chaste_interface__K__K_i = rY[13];
        // Units: mM; Initial value: 139.730914103161
        double var_chaste_interface__Ca__Ca_T = rY[14];
        // Units: mM; Initial value: 0.0257059808595638
        
        const double var_ICaL__G_CaL_mult = 1.0; // dimensionless
        const double var_Ca__bmyo = (0.12000000000000001 - var_chaste_interface__Ca__Ca_T) + 0.0028800000000000002; // mM
        const double var_Ca__cmyo = (1.19e-06 - (var_chaste_interface__Ca__Ca_T * 0.0028800000000000002)) + 0.00019160000000000005; // mM2
        const double var_Ca__Ca_i = (((2.0 * sqrt((var_Ca__bmyo * var_Ca__bmyo) - (3.0 * var_Ca__cmyo))) * 0.33333333333333331) * cos(acos((((9.0 * var_Ca__bmyo * var_Ca__cmyo) - (2.0 * var_Ca__bmyo * var_Ca__bmyo * var_Ca__bmyo)) - (27.0 * (var_chaste_interface__Ca__Ca_T *  -1.19e-06))) / (2.0 * pow((var_Ca__bmyo * var_Ca__bmyo) - (3.0 * var_Ca__cmyo), 1.5))) * 0.33333333333333331)) - (var_Ca__bmyo * 0.33333333333333331); // mM
        const double var_ICaL__fca = 1.0 / (1.0 + (var_Ca__Ca_i * 1666.6666666666667)); // dimensionless
        const double var_ICaL__ilca = var_chaste_interface__ICaL__d * var_chaste_interface__ICaL__f * var_ICaL__fca * ((var_ICaL__G_CaL_mult * var_chaste_interface__cell__V * ((1.0 * var_Ca__Ca_i * exp(var_chaste_interface__cell__V * 0.074871767015605245)) - 0.61380000000000001) * 7.8019226357407261) / (exp(var_chaste_interface__cell__V * 0.074871767015605245) - 1.0)); // uA_per_uF
        const double var_INaCa__inaca = (0.00025000000000000001 * exp(var_chaste_interface__cell__V *  -0.031820500981632228) * ((exp(var_chaste_interface__cell__V * 0.037435883507802623) * pow(var_chaste_interface__Na__Na_i, 3.0) * 1.8) - (2744000.0 * var_Ca__Ca_i))) / (1.0 + (0.0001 * exp(var_chaste_interface__cell__V *  -0.031820500981632228) * ((exp(var_chaste_interface__cell__V * 0.037435883507802623) * pow(var_chaste_interface__Na__Na_i, 3.0) * 1.8) + (2744000.0 * var_Ca__Ca_i)))); // uA_per_uF
        const double var_INa__GNa = 16.0; // mS_per_uF
        const double var_reversal_potentials__ENa = log(140.0 / var_chaste_interface__Na__Na_i) * 26.712338705498262; // mV
        const double var_INaK__inak = ((2.25 * (1.0 / (1.0 + (0.1245 * exp(var_chaste_interface__cell__V *  -0.0037435883507802624)) + (exp((-var_chaste_interface__cell__V) * 0.037435883507802623) * 0.036533226130519084)))) / (1.0 + pow(10.0 / var_chaste_interface__Na__Na_i, 2.0))) * 0.75; // uA_per_uF
        const double var_reversal_potentials__EK = log(4.5 / var_chaste_interface__K__K_i) * 26.712338705498262; // mV
        const double var_IKr__gkrmax = 0.02614; // mS_per_uF
        const double var_IK1__ak1 = 1.02 / (1.0 + exp(0.23849999999999999 * ((var_chaste_interface__cell__V - var_reversal_potentials__EK) - 59.215000000000003))); // per_ms
        const double var_cell__caiont = ((var_ICaL__ilca + (0.003016 * (var_chaste_interface__cell__V - (log(1.8 / var_Ca__Ca_i) * 13.356169352749131))) + ((1.1499999999999999 * var_Ca__Ca_i) / (0.00050000000000000001 + var_Ca__Ca_i))) - (2.0 * var_INaCa__inaca)) + (0.050000000000000003 * var_chaste_interface__ICaT__b * var_chaste_interface__ICaT__b * var_chaste_interface__ICaT__g * (var_chaste_interface__cell__V - ((log(1.8 / var_Ca__Ca_i) * 0.5) * 26.712338705498262))); // uA_per_uF
        const double var_cell__naiont = (var_INa__GNa * var_chaste_interface__INa__m * var_chaste_interface__INa__m * var_chaste_interface__INa__m * var_chaste_interface__INa__H * var_chaste_interface__INa__J * (var_chaste_interface__cell__V - var_reversal_potentials__ENa)) + (0.0040000000000000001 * (var_chaste_interface__cell__V - var_reversal_potentials__ENa)) + (3.0 * var_INaCa__inaca) + (var_chaste_interface__ICaL__d * var_chaste_interface__ICaL__f * var_ICaL__fca * ((var_ICaL__G_CaL_mult * var_chaste_interface__cell__V * ((0.75 * var_chaste_interface__Na__Na_i * exp(var_chaste_interface__cell__V * 0.037435883507802623)) - 105.0) * 0.0024381008236689767) / (exp(var_chaste_interface__cell__V * 0.037435883507802623) - 1.0))) + (3.0 * var_INaK__inak); // uA_per_uF
        const double var_chaste_interface__cell__i_Stim = 0.0;
        const double var_cell__kiont = (((var_IKr__gkrmax * 0.91287092917527679 * var_chaste_interface__IKr__xr * (1.0 / (1.0 + exp((var_chaste_interface__cell__V + 9.0) * 0.044642857142857144))) * (var_chaste_interface__cell__V - var_reversal_potentials__EK)) + ((0.433 * (1.0 + (0.59999999999999998 / (1.0 + pow(3.8000000000000002e-05 / var_Ca__Ca_i, 1.3999999999999999))))) * var_chaste_interface__IKs__xs1 * var_chaste_interface__IKs__xs2 * (var_chaste_interface__cell__V - (log(7.0662000000000003 / (var_chaste_interface__K__K_i + (0.018329999999999999 * var_chaste_interface__Na__Na_i))) * 26.712338705498262))) + (((0.68465319688145754 * var_IK1__ak1) / (var_IK1__ak1 + (((0.49124000000000001 * exp(0.080320000000000003 * ((var_chaste_interface__cell__V - var_reversal_potentials__EK) + 5.476))) + (1.0 * exp(0.061749999999999999 * ((var_chaste_interface__cell__V - var_reversal_potentials__EK) - 594.30999999999995)))) / (1.0 + exp( -0.51429999999999998 * ((var_chaste_interface__cell__V - var_reversal_potentials__EK) + 4.7530000000000001)))))) * (var_chaste_interface__cell__V - var_reversal_potentials__EK)) + ((0.0055199999999999997 * (var_chaste_interface__cell__V - var_reversal_potentials__EK)) / (1.0 + exp((7.4880000000000004 - var_chaste_interface__cell__V) * 0.16722408026755853))) + (var_chaste_interface__ICaL__d * var_chaste_interface__ICaL__f * var_ICaL__fca * ((var_ICaL__G_CaL_mult * var_chaste_interface__cell__V * ((0.75 * var_chaste_interface__K__K_i * exp(var_chaste_interface__cell__V * 0.037435883507802623)) - 3.375) * 0.00069711623550831479) / (exp(var_chaste_interface__cell__V * 0.037435883507802623) - 1.0)))) - (2.0 * var_INaK__inak)) + (var_chaste_interface__cell__i_Stim / HeartConfig::Instance()->GetCapacitance()); // uA_per_uF
        const double var_chaste_interface__i_ionic = (var_cell__naiont + var_cell__kiont + var_cell__caiont) * HeartConfig::Instance()->GetCapacitance(); // uA_per_cm2
        
        const double i_ionic = var_chaste_interface__i_ionic;
        EXCEPT_IF_NOT(!std::isnan(i_ionic));
        return i_ionic;
    }
    
    void Dynamiclivshitz_rudy_2007FromCellMLRushLarsen::EvaluateEquations(double var_chaste_interface__Environment__time, std::vector<double> &rDY, std::vector<double> &rAlphaOrTau, std::vector<double> &rBetaOrInf)
    {
        std::vector<double>& rY = rGetStateVariables();
        double var_chaste_interface__cell__V = (mSetVoltageDerivativeToZero ? this->mFixedVoltage : rY[0]);
        // Units: millivolt; Initial value: -89.4356034692784
        double var_chaste_interface__INa__H = rY[1];
        // Units: dimensionless; Initial value: 0.994401369032678
        double var_chaste_interface__INa__m = rY[2];
        // Units: dimensionless; Initial value: 0.000734780346592185
        double var_chaste_interface__INa__J = rY[3];
        // Units: dimensionless; Initial value: 0.996100688673679
        double var_chaste_interface__ICaL__d = rY[4];
        // Units: dimensionless; Initial value: 3.2514786721066e-27
        double var_chaste_interface__ICaL__f = rY[5];
        // Units: dimensionless; Initial value: 0.997404948824816
        double var_chaste_interface__IKr__xr = rY[6];
        // Units: dimensionless; Initial value: 0.000162194715543637
        double var_chaste_interface__IKs__xs1 = rY[7];
        // Units: dimensionless; Initial value: 0.0285147332973946
        double var_chaste_interface__IKs__xs2 = rY[8];
        // Units: dimensionless; Initial value: 0.0764114040188678
        double var_chaste_interface__ICaT__b = rY[9];
        // Units: dimensionless; Initial value: 0.000927461915392873
        double var_chaste_interface__ICaT__g = rY[10];
        // Units: dimensionless; Initial value: 0.952834331760863
        double var_chaste_interface__Irel__Rel = rY[11];
        // Units: mM_per_ms; Initial value: 1.06874246141923e-23
        double var_chaste_interface__Na__Na_i = rY[12];
        // Units: mM; Initial value: 16.612739313555
        double var_chaste_interface__K__K_i = rY[13];
        // Units: mM; Initial value: 139.730914103161
        double var_chaste_interface__Ca__Ca_T = rY[14];
        // Units: mM; Initial value: 0.0257059808595638
        double var_chaste_interface__Ca__Ca_JSR_T = rY[15];
        // Units: mM; Initial value: 7.87371650296567
        double var_chaste_interface__Ca__Ca_NSR = rY[16];
        // Units: mM; Initial value: 2.71518235696672
        
        
        // Mathematics
        double d_dt_chaste_interface__cell__V;
        const double var_ICaL__G_CaL_mult = 1.0; // dimensionless
        const double var_Ca__bmyo = (0.12000000000000001 - var_chaste_interface__Ca__Ca_T) + 0.0028800000000000002; // mM
        const double var_Ca__cmyo = (1.19e-06 - (var_chaste_interface__Ca__Ca_T * 0.0028800000000000002)) + 0.00019160000000000005; // mM2
        const double var_Ca__Ca_i = (((2.0 * sqrt((var_Ca__bmyo * var_Ca__bmyo) - (3.0 * var_Ca__cmyo))) * 0.33333333333333331) * cos(acos((((9.0 * var_Ca__bmyo * var_Ca__cmyo) - (2.0 * var_Ca__bmyo * var_Ca__bmyo * var_Ca__bmyo)) - (27.0 * (var_chaste_interface__Ca__Ca_T *  -1.19e-06))) / (2.0 * pow((var_Ca__bmyo * var_Ca__bmyo) - (3.0 * var_Ca__cmyo), 1.5))) * 0.33333333333333331)) - (var_Ca__bmyo * 0.33333333333333331); // mM
        const double var_ICaL__fca = 1.0 / (1.0 + (var_Ca__Ca_i * 1666.6666666666667)); // dimensionless
        const double var_ICaL__ilca = var_chaste_interface__ICaL__d * var_chaste_interface__ICaL__f * var_ICaL__fca * ((var_ICaL__G_CaL_mult * var_chaste_interface__cell__V * ((1.0 * var_Ca__Ca_i * exp(var_chaste_interface__cell__V * 0.074871767015605245)) - 0.61380000000000001) * 7.8019226357407261) / (exp(var_chaste_interface__cell__V * 0.074871767015605245) - 1.0)); // uA_per_uF
        const double var_INaCa__inaca = (0.00025000000000000001 * exp(var_chaste_interface__cell__V *  -0.031820500981632228) * ((exp(var_chaste_interface__cell__V * 0.037435883507802623) * pow(var_chaste_interface__Na__Na_i, 3.0) * 1.8) - (2744000.0 * var_Ca__Ca_i))) / (1.0 + (0.0001 * exp(var_chaste_interface__cell__V *  -0.031820500981632228) * ((exp(var_chaste_interface__cell__V * 0.037435883507802623) * pow(var_chaste_interface__Na__Na_i, 3.0) * 1.8) + (2744000.0 * var_Ca__Ca_i)))); // uA_per_uF
        const double var_INa__GNa = 16.0; // mS_per_uF
        const double var_reversal_potentials__ENa = log(140.0 / var_chaste_interface__Na__Na_i) * 26.712338705498262; // mV
        const double var_INaK__inak = ((2.25 * (1.0 / (1.0 + (0.1245 * exp(var_chaste_interface__cell__V *  -0.0037435883507802624)) + (exp((-var_chaste_interface__cell__V) * 0.037435883507802623) * 0.036533226130519084)))) / (1.0 + pow(10.0 / var_chaste_interface__Na__Na_i, 2.0))) * 0.75; // uA_per_uF
        const double var_reversal_potentials__EK = log(4.5 / var_chaste_interface__K__K_i) * 26.712338705498262; // mV
        const double var_IKr__gkrmax = 0.02614; // mS_per_uF
        const double var_IK1__ak1 = 1.02 / (1.0 + exp(0.23849999999999999 * ((var_chaste_interface__cell__V - var_reversal_potentials__EK) - 59.215000000000003))); // per_ms
        const double var_cell__caiont = ((var_ICaL__ilca + (0.003016 * (var_chaste_interface__cell__V - (log(1.8 / var_Ca__Ca_i) * 13.356169352749131))) + ((1.1499999999999999 * var_Ca__Ca_i) / (0.00050000000000000001 + var_Ca__Ca_i))) - (2.0 * var_INaCa__inaca)) + (0.050000000000000003 * var_chaste_interface__ICaT__b * var_chaste_interface__ICaT__b * var_chaste_interface__ICaT__g * (var_chaste_interface__cell__V - ((log(1.8 / var_Ca__Ca_i) * 0.5) * 26.712338705498262))); // uA_per_uF
        const double var_cell__naiont = (var_INa__GNa * var_chaste_interface__INa__m * var_chaste_interface__INa__m * var_chaste_interface__INa__m * var_chaste_interface__INa__H * var_chaste_interface__INa__J * (var_chaste_interface__cell__V - var_reversal_potentials__ENa)) + (0.0040000000000000001 * (var_chaste_interface__cell__V - var_reversal_potentials__ENa)) + (3.0 * var_INaCa__inaca) + (var_chaste_interface__ICaL__d * var_chaste_interface__ICaL__f * var_ICaL__fca * ((var_ICaL__G_CaL_mult * var_chaste_interface__cell__V * ((0.75 * var_chaste_interface__Na__Na_i * exp(var_chaste_interface__cell__V * 0.037435883507802623)) - 105.0) * 0.0024381008236689767) / (exp(var_chaste_interface__cell__V * 0.037435883507802623) - 1.0))) + (3.0 * var_INaK__inak); // uA_per_uF
        const double var_chaste_interface__cell__i_Stim = GetIntracellularAreaStimulus(var_chaste_interface__Environment__time);
        const double var_cell__kiont = (((var_IKr__gkrmax * 0.91287092917527679 * var_chaste_interface__IKr__xr * (1.0 / (1.0 + exp((var_chaste_interface__cell__V + 9.0) * 0.044642857142857144))) * (var_chaste_interface__cell__V - var_reversal_potentials__EK)) + ((0.433 * (1.0 + (0.59999999999999998 / (1.0 + pow(3.8000000000000002e-05 / var_Ca__Ca_i, 1.3999999999999999))))) * var_chaste_interface__IKs__xs1 * var_chaste_interface__IKs__xs2 * (var_chaste_interface__cell__V - (log(7.0662000000000003 / (var_chaste_interface__K__K_i + (0.018329999999999999 * var_chaste_interface__Na__Na_i))) * 26.712338705498262))) + (((0.68465319688145754 * var_IK1__ak1) / (var_IK1__ak1 + (((0.49124000000000001 * exp(0.080320000000000003 * ((var_chaste_interface__cell__V - var_reversal_potentials__EK) + 5.476))) + (1.0 * exp(0.061749999999999999 * ((var_chaste_interface__cell__V - var_reversal_potentials__EK) - 594.30999999999995)))) / (1.0 + exp( -0.51429999999999998 * ((var_chaste_interface__cell__V - var_reversal_potentials__EK) + 4.7530000000000001)))))) * (var_chaste_interface__cell__V - var_reversal_potentials__EK)) + ((0.0055199999999999997 * (var_chaste_interface__cell__V - var_reversal_potentials__EK)) / (1.0 + exp((7.4880000000000004 - var_chaste_interface__cell__V) * 0.16722408026755853))) + (var_chaste_interface__ICaL__d * var_chaste_interface__ICaL__f * var_ICaL__fca * ((var_ICaL__G_CaL_mult * var_chaste_interface__cell__V * ((0.75 * var_chaste_interface__K__K_i * exp(var_chaste_interface__cell__V * 0.037435883507802623)) - 3.375) * 0.00069711623550831479) / (exp(var_chaste_interface__cell__V * 0.037435883507802623) - 1.0)))) - (2.0 * var_INaK__inak)) + (var_chaste_interface__cell__i_Stim / HeartConfig::Instance()->GetCapacitance()); // uA_per_uF
        const double var_INa__a = 1.0 - (1.0 / (1.0 + exp((-(var_chaste_interface__cell__V + 40.0)) * 41.666666666666664))); // per_ms
        const double var_ICaL__dss0 = 1.0 / (1.0 + exp((-(var_chaste_interface__cell__V + 10.0)) * 0.16025641025641024)); // dimensionless
        const double var_IKs__xss = 1.0 / (1.0 + exp((-(var_chaste_interface__cell__V - 1.5)) * 0.059880239520958084)); // dimensionless
        const double var_IKs__tauxs = 1.0 / (((7.1899999999999999e-05 * (var_chaste_interface__cell__V + 30.0)) / (1.0 - exp( -0.14799999999999999 * (var_chaste_interface__cell__V + 30.0)))) + ((0.00013100000000000001 * (var_chaste_interface__cell__V + 30.0)) / (exp(0.068699999999999997 * (var_chaste_interface__cell__V + 30.0)) - 1.0))); // ms
        const double var_ICaT__aa = 1.0 - (1.0 / (1.0 + exp((-var_chaste_interface__cell__V) * 416.66666666666669))); // dimensionless
        const double var_Irel__bbb = 10.800000000000001 - var_chaste_interface__Ca__Ca_JSR_T; // mM
        const double var_Irel__Ca_JSR_free = ((-var_Irel__bbb) * 0.5) + (sqrt(pow(var_Irel__bbb, 2.0) + (4.0 * (var_chaste_interface__Ca__Ca_JSR_T * 0.80000000000000004))) * 0.5); // mM
        const double var_Iup_Ileak__iup = (0.0087500000000000008 * var_Ca__Ca_i) / (var_Ca__Ca_i + 0.00092000000000000003); // mM_per_ms
        const double var_Iup_Ileak__ileak = (0.0087500000000000008 * var_chaste_interface__Ca__Ca_NSR) * 0.066666666666666666; // mM_per_ms
        const double var_Itr__itr = (var_chaste_interface__Ca__Ca_NSR - var_Irel__Ca_JSR_free) * 0.0083333333333333332; // mM_per_ms
        const double d_dt_chaste_interface__IKs__xs2 = ((var_IKs__xss - var_chaste_interface__IKs__xs2) / var_IKs__tauxs) * 0.25; // 'per millisecond'
        const double d_dt_chaste_interface__Irel__Rel = (-(((var_ICaL__ilca * 0.59375) / (1.0 + pow(1.0 / var_Irel__Ca_JSR_free, 9.0))) + var_chaste_interface__Irel__Rel)) / (4.75 / (1.0 + (0.0123 / var_Irel__Ca_JSR_free))); // 'mM per millisecond per ms'
        const double d_dt_chaste_interface__Na__Na_i = ((-var_cell__naiont) * 1.5902511810263306e-09) * 38686.179652867118; // 'millimole per litre per millisecond'
        const double d_dt_chaste_interface__K__K_i = ((-var_cell__kiont) * 1.5902511810263306e-09) * 38686.179652867118; // 'millimole per litre per millisecond'
        const double d_dt_chaste_interface__Ca__Ca_T = (((-var_cell__caiont) * 1.5902511810263306e-09) * 19343.089826433559) + (((var_Iup_Ileak__ileak - var_Iup_Ileak__iup) * 2.0983325651856948e-06) * 38686.179652867118) + ((var_chaste_interface__Irel__Rel * 1.8246370132049518e-07) * 38686.179652867118); // 'millimole per litre per millisecond'
        const double d_dt_chaste_interface__Ca__Ca_JSR_T = var_Itr__itr - var_chaste_interface__Irel__Rel; // 'millimole per litre per millisecond'
        const double d_dt_chaste_interface__Ca__Ca_NSR = (var_Iup_Ileak__iup - ((var_Itr__itr * 1.8246370132049518e-07) * 476568.87978169642)) - var_Iup_Ileak__ileak; // 'millimole per litre per millisecond'
        const double d_dt_chaste_interface__Ca__Over = 0.0; // 'per millisecond'
        
        if (mSetVoltageDerivativeToZero)
        {
            d_dt_chaste_interface__cell__V = 0.0;
        }
        else
        {
            d_dt_chaste_interface__cell__V = -(var_cell__naiont + var_cell__kiont + var_cell__caiont); // 'millivolt per millisecond'
        }
        
        rDY[0] = d_dt_chaste_interface__cell__V;
        rAlphaOrTau[1] = var_INa__a * 0.13500000000000001 * exp((80.0 + var_chaste_interface__cell__V) *  -0.14705882352941177);
        rBetaOrInf[1] = ((1.0 - var_INa__a) / (0.13 * (1.0 + exp((var_chaste_interface__cell__V + 10.66) *  -0.0900900900900901)))) + (var_INa__a * ((3.5600000000000001 * exp(0.079000000000000001 * var_chaste_interface__cell__V)) + (exp(0.34999999999999998 * var_chaste_interface__cell__V) * 310000.0)));
        rAlphaOrTau[2] = ((var_chaste_interface__cell__V + 47.130000000000003) * 0.32000000000000001) / (1.0 - exp( -0.10000000000000001 * (var_chaste_interface__cell__V + 47.130000000000003)));
        rBetaOrInf[2] = 0.080000000000000002 * exp((-var_chaste_interface__cell__V) * 0.090909090909090912);
        rAlphaOrTau[3] = (var_INa__a * (( -127140.0 * exp(0.24440000000000001 * var_chaste_interface__cell__V)) - (3.4740000000000003e-05 * exp( -0.043909999999999998 * var_chaste_interface__cell__V))) * 1.0 * (var_chaste_interface__cell__V + 37.780000000000001)) / (1.0 + exp(0.311 * (var_chaste_interface__cell__V + 79.230000000000004)));
        rBetaOrInf[3] = (((1.0 - var_INa__a) * 0.29999999999999999 * exp( -2.5349999999999999e-07 * var_chaste_interface__cell__V)) / (1.0 + exp( -0.10000000000000001 * (var_chaste_interface__cell__V + 32.0)))) + ((var_INa__a * 0.1212 * exp( -0.01052 * var_chaste_interface__cell__V)) / (1.0 + exp( -0.13780000000000001 * (var_chaste_interface__cell__V + 40.140000000000001))));
        rAlphaOrTau[4] = (var_ICaL__dss0 * 1.0 * (1.0 - exp((-(var_chaste_interface__cell__V + 10.0)) * 0.16025641025641024))) / (0.035000000000000003 * (var_chaste_interface__cell__V + 10.0));
        rBetaOrInf[4] = var_ICaL__dss0 * (1.0 / (1.0 + exp((-(var_chaste_interface__cell__V + 60.0)) * 41.666666666666664)));
        rAlphaOrTau[5] = 1.0 / ((0.019699999999999999 * exp(-pow(0.033700000000000001 * (var_chaste_interface__cell__V + 10.0), 2.0))) + 0.02);
        rBetaOrInf[5] = (1.0 / (1.0 + exp((var_chaste_interface__cell__V + 32.0) * 0.125))) + (0.59999999999999998 / (1.0 + exp((50.0 - var_chaste_interface__cell__V) * 0.050000000000000003)));
        rAlphaOrTau[6] = 1.0 / (((0.0013799999999999999 * (var_chaste_interface__cell__V + 14.199999999999999)) / (1.0 - exp( -0.123 * (var_chaste_interface__cell__V + 14.199999999999999)))) + ((0.00060999999999999997 * (var_chaste_interface__cell__V + 38.899999999999999)) / (exp(0.14499999999999999 * (var_chaste_interface__cell__V + 38.899999999999999)) - 1.0)));
        rBetaOrInf[6] = 1.0 / (1.0 + exp((-(var_chaste_interface__cell__V + 10.085000000000001)) * 0.23529411764705882));
        rAlphaOrTau[7] = var_IKs__tauxs;
        rBetaOrInf[7] = var_IKs__xss;
        rDY[8] = d_dt_chaste_interface__IKs__xs2;
        rAlphaOrTau[9] = 3.7000000000000002 + (6.0999999999999996 / (1.0 + exp((var_chaste_interface__cell__V + 25.0) * 0.22222222222222221)));
        rBetaOrInf[9] = 1.0 / (1.0 + exp((-(var_chaste_interface__cell__V + 14.0)) * 0.092592592592592587));
        rAlphaOrTau[10] = (var_ICaT__aa * 1.0 * (( -0.875 * var_chaste_interface__cell__V) + 12.0)) + (12.0 * (1.0 - var_ICaT__aa));
        rBetaOrInf[10] = 1.0 / (1.0 + exp((var_chaste_interface__cell__V + 60.0) * 0.17857142857142858));
        rDY[11] = d_dt_chaste_interface__Irel__Rel;
        rDY[12] = d_dt_chaste_interface__Na__Na_i;
        rDY[13] = d_dt_chaste_interface__K__K_i;
        rDY[14] = d_dt_chaste_interface__Ca__Ca_T;
        rDY[15] = d_dt_chaste_interface__Ca__Ca_JSR_T;
        rDY[16] = d_dt_chaste_interface__Ca__Ca_NSR;
        rDY[17] = d_dt_chaste_interface__Ca__Over;
    }
    
    void Dynamiclivshitz_rudy_2007FromCellMLRushLarsen::ComputeOneStepExceptVoltage(const std::vector<double> &rDY, const std::vector<double> &rAlphaOrTau, const std::vector<double> &rBetaOrInf)
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
        rY[4] = rBetaOrInf[4] + (rY[4] - rBetaOrInf[4])*exp(-mDt/rAlphaOrTau[4]);
        rY[5] = rBetaOrInf[5] + (rY[5] - rBetaOrInf[5])*exp(-mDt/rAlphaOrTau[5]);
        rY[6] = rBetaOrInf[6] + (rY[6] - rBetaOrInf[6])*exp(-mDt/rAlphaOrTau[6]);
        rY[7] = rBetaOrInf[7] + (rY[7] - rBetaOrInf[7])*exp(-mDt/rAlphaOrTau[7]);
        rY[8] += mDt * rDY[8];
        rY[9] = rBetaOrInf[9] + (rY[9] - rBetaOrInf[9])*exp(-mDt/rAlphaOrTau[9]);
        rY[10] = rBetaOrInf[10] + (rY[10] - rBetaOrInf[10])*exp(-mDt/rAlphaOrTau[10]);
        rY[11] += mDt * rDY[11];
        rY[12] += mDt * rDY[12];
        rY[13] += mDt * rDY[13];
        rY[14] += mDt * rDY[14];
        rY[15] += mDt * rDY[15];
        rY[16] += mDt * rDY[16];
        rY[17] += mDt * rDY[17];
    }
    
    std::vector<double> Dynamiclivshitz_rudy_2007FromCellMLRushLarsen::ComputeDerivedQuantities(double var_chaste_interface__Environment__time, const std::vector<double> & rY)
    {
        // Inputs:
        // Time units: millisecond
        double var_chaste_interface__Ca__Ca_T = rY[14];
        // Units: mM; Initial value: 0.0257059808595638
        
        
        // Mathematics
        const double var_Ca__bmyo = (0.12000000000000001 - var_chaste_interface__Ca__Ca_T) + 0.0028800000000000002; // mM
        const double var_Ca__cmyo = (1.19e-06 - (var_chaste_interface__Ca__Ca_T * 0.0028800000000000002)) + 0.00019160000000000005; // mM2
        const double var_Ca__Ca_i = (((2.0 * sqrt((var_Ca__bmyo * var_Ca__bmyo) - (3.0 * var_Ca__cmyo))) * 0.33333333333333331) * cos(acos((((9.0 * var_Ca__bmyo * var_Ca__cmyo) - (2.0 * var_Ca__bmyo * var_Ca__bmyo * var_Ca__bmyo)) - (27.0 * (var_chaste_interface__Ca__Ca_T *  -1.19e-06))) / (2.0 * pow((var_Ca__bmyo * var_Ca__bmyo) - (3.0 * var_Ca__cmyo), 1.5))) * 0.33333333333333331)) - (var_Ca__bmyo * 0.33333333333333331); // mM
        const double var_chaste_interface__Ca__Ca_i = var_Ca__Ca_i; // millimolar
        
        std::vector<double> dqs(1);
        dqs[0] = var_chaste_interface__Ca__Ca_i;
        return dqs;
    }
    
template<>
void OdeSystemInformation<Dynamiclivshitz_rudy_2007FromCellMLRushLarsen>::Initialise(void)
{
    this->mSystemName = "LivshitzRudy2007";
    this->mFreeVariableName = "Environment__time";
    this->mFreeVariableUnits = "millisecond";
    
    // rY[0]:
    this->mVariableNames.push_back("membrane_voltage");
    this->mVariableUnits.push_back("millivolt");
    this->mInitialConditions.push_back(-89.4356034692784);

    // rY[1]:
    this->mVariableNames.push_back("INa__H");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(0.994401369032678);

    // rY[2]:
    this->mVariableNames.push_back("INa__m");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(0.000734780346592185);

    // rY[3]:
    this->mVariableNames.push_back("INa__J");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(0.996100688673679);

    // rY[4]:
    this->mVariableNames.push_back("ICaL__d");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(3.2514786721066e-27);

    // rY[5]:
    this->mVariableNames.push_back("ICaL__f");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(0.997404948824816);

    // rY[6]:
    this->mVariableNames.push_back("IKr__xr");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(0.000162194715543637);

    // rY[7]:
    this->mVariableNames.push_back("IKs__xs1");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(0.0285147332973946);

    // rY[8]:
    this->mVariableNames.push_back("IKs__xs2");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(0.0764114040188678);

    // rY[9]:
    this->mVariableNames.push_back("ICaT__b");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(0.000927461915392873);

    // rY[10]:
    this->mVariableNames.push_back("ICaT__g");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(0.952834331760863);

    // rY[11]:
    this->mVariableNames.push_back("Irel__Rel");
    this->mVariableUnits.push_back("mM_per_ms");
    this->mInitialConditions.push_back(1.06874246141923e-23);

    // rY[12]:
    this->mVariableNames.push_back("Na__Na_i");
    this->mVariableUnits.push_back("mM");
    this->mInitialConditions.push_back(16.612739313555);

    // rY[13]:
    this->mVariableNames.push_back("K__K_i");
    this->mVariableUnits.push_back("mM");
    this->mInitialConditions.push_back(139.730914103161);

    // rY[14]:
    this->mVariableNames.push_back("Ca__Ca_T");
    this->mVariableUnits.push_back("mM");
    this->mInitialConditions.push_back(0.0257059808595638);

    // rY[15]:
    this->mVariableNames.push_back("Ca__Ca_JSR_T");
    this->mVariableUnits.push_back("mM");
    this->mInitialConditions.push_back(7.87371650296567);

    // rY[16]:
    this->mVariableNames.push_back("Ca__Ca_NSR");
    this->mVariableUnits.push_back("mM");
    this->mInitialConditions.push_back(2.71518235696672);

    // rY[17]:
    this->mVariableNames.push_back("Ca__Over");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(1e-12);

    // Derived Quantity index [0]:
    this->mDerivedQuantityNames.push_back("cytosolic_calcium_concentration");
    this->mDerivedQuantityUnits.push_back("millimolar");
    
    this->mInitialised = true;
}


// Serialization for Boost >= 1.36
#include "SerializationExportWrapperForCpp.hpp"
CHASTE_CLASS_EXPORT(Dynamiclivshitz_rudy_2007FromCellMLRushLarsen)
extern "C"
{
    AbstractCardiacCellInterface* MakeCardiacCell(
            boost::shared_ptr<AbstractIvpOdeSolver> pSolver,
            boost::shared_ptr<AbstractStimulusFunction> pStimulus)
    {
        return new Dynamiclivshitz_rudy_2007FromCellMLRushLarsen(pSolver, pStimulus);
    }
    
}

