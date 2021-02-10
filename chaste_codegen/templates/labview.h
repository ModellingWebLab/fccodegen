//==============================================================================
// CellML file:   Z:\fusion\COR\Models\ten_tusscher_model_2006_epi.cellml
// CellML model:  tentusscher_model_2006_epi
// Date and time: 9-4-2019 at 14:08:36
//------------------------------------------------------------------------------
// Conversion from CellML 1.0 to C (header) was done using COR (0.9.31.1409)
//    Copyright 2002-2019 Dr Alan Garny
//    http://cor.physiol.ox.ac.uk/ - cor@physiol.ox.ac.uk
//------------------------------------------------------------------------------
// http://www.cellml.org/
//==============================================================================

#ifndef __TEN_TUSSCHER_MODEL_2006_EPI_H__
#define __TEN_TUSSCHER_MODEL_2006_EPI_H__

//------------------------------------------------------------------------------
// State variables
//------------------------------------------------------------------------------

#define _NB_OF_STATE_VARIABLES_ 19

extern double Y[_NB_OF_STATE_VARIABLES_];
extern double dY[_NB_OF_STATE_VARIABLES_];
// 0: d (dimensionless) (in L_type_Ca_current_d_gate)
// 1: f2 (dimensionless) (in L_type_Ca_current_f2_gate)
// 2: fCass (dimensionless) (in L_type_Ca_current_fCass_gate)
// 3: f (dimensionless) (in L_type_Ca_current_f_gate)
// 4: Ca_SR (millimolar) (in calcium_dynamics)
// 5: Ca_i (millimolar) (in calcium_dynamics)
// 6: Ca_ss (millimolar) (in calcium_dynamics)
// 7: R_prime (dimensionless) (in calcium_dynamics)
// 8: h (dimensionless) (in fast_sodium_current_h_gate)
// 9: j (dimensionless) (in fast_sodium_current_j_gate)
// 10: m (dimensionless) (in fast_sodium_current_m_gate)
// 11: V (millivolt) (in membrane)
// 12: K_i (millimolar) (in potassium_dynamics)
// 13: Xr1 (dimensionless) (in rapid_time_dependent_potassium_current_Xr1_gate)
// 14: Xr2 (dimensionless) (in rapid_time_dependent_potassium_current_Xr2_gate)
// 15: Xs (dimensionless) (in slow_time_dependent_potassium_current_Xs_gate)
// 16: Na_i (millimolar) (in sodium_dynamics)
// 17: r (dimensionless) (in transient_outward_current_r_gate)
// 18: s (dimensionless) (in transient_outward_current_s_gate)

extern char YNames[_NB_OF_STATE_VARIABLES_][8];
extern char YUnits[_NB_OF_STATE_VARIABLES_][14];
extern char YComponents[_NB_OF_STATE_VARIABLES_][48];

//------------------------------------------------------------------------------
// Constants
//------------------------------------------------------------------------------

extern double g_CaL;   // litre_per_farad_second (in L_type_Ca_current)
extern double g_bca;   // nanoS_per_picoF (in calcium_background_current)
extern double Buf_c;   // millimolar (in calcium_dynamics)
extern double Buf_sr;   // millimolar (in calcium_dynamics)
extern double Buf_ss;   // millimolar (in calcium_dynamics)
extern double Ca_o;   // millimolar (in calcium_dynamics)
extern double EC;   // millimolar (in calcium_dynamics)
extern double K_buf_c;   // millimolar (in calcium_dynamics)
extern double K_buf_sr;   // millimolar (in calcium_dynamics)
extern double K_buf_ss;   // millimolar (in calcium_dynamics)
extern double K_up;   // millimolar (in calcium_dynamics)
extern double V_leak;   // per_millisecond (in calcium_dynamics)
extern double V_rel;   // per_millisecond (in calcium_dynamics)
extern double V_sr;   // micrometre3 (in calcium_dynamics)
extern double V_ss;   // micrometre3 (in calcium_dynamics)
extern double V_xfer;   // per_millisecond (in calcium_dynamics)
extern double Vmax_up;   // millimolar_per_millisecond (in calcium_dynamics)
extern double k1_prime;   // per_millimolar2_per_millisecond (in calcium_dynamics)
extern double k2_prime;   // per_millimolar_per_millisecond (in calcium_dynamics)
extern double k3;   // per_millisecond (in calcium_dynamics)
extern double k4;   // per_millisecond (in calcium_dynamics)
extern double max_sr;   // dimensionless (in calcium_dynamics)
extern double min_sr;   // dimensionless (in calcium_dynamics)
extern double K_pCa;   // millimolar (in calcium_pump_current)
extern double g_pCa;   // picoA_per_picoF (in calcium_pump_current)
extern double g_Na;   // nanoS_per_picoF (in fast_sodium_current)
extern double g_K1;   // nanoS_per_picoF (in inward_rectifier_potassium_current)
extern double Cm;   // microF (in membrane)
extern double F;   // coulomb_per_millimole (in membrane)
extern double R;   // joule_per_mole_kelvin (in membrane)
extern double T;   // kelvin (in membrane)
extern double V_c;   // micrometre3 (in membrane)
extern double K_o;   // millimolar (in potassium_dynamics)
extern double g_pK;   // nanoS_per_picoF (in potassium_pump_current)
extern double g_Kr;   // nanoS_per_picoF (in rapid_time_dependent_potassium_current)
extern double P_kna;   // dimensionless (in reversal_potentials)
extern double g_Ks;   // nanoS_per_picoF (in slow_time_dependent_potassium_current)
extern double g_bna;   // nanoS_per_picoF (in sodium_background_current)
extern double K_NaCa;   // picoA_per_picoF (in sodium_calcium_exchanger_current)
extern double K_sat;   // dimensionless (in sodium_calcium_exchanger_current)
extern double Km_Ca;   // millimolar (in sodium_calcium_exchanger_current)
extern double Km_Nai;   // millimolar (in sodium_calcium_exchanger_current)
extern double alpha;   // dimensionless (in sodium_calcium_exchanger_current)
extern double gamma;   // dimensionless (in sodium_calcium_exchanger_current)
extern double Na_o;   // millimolar (in sodium_dynamics)
extern double K_mNa;   // millimolar (in sodium_potassium_pump_current)
extern double K_mk;   // millimolar (in sodium_potassium_pump_current)
extern double P_NaK;   // picoA_per_picoF (in sodium_potassium_pump_current)
extern double g_to;   // nanoS_per_picoF (in transient_outward_current)

//------------------------------------------------------------------------------
// Computed variables
//------------------------------------------------------------------------------

extern double alpha_d;   // dimensionless (in L_type_Ca_current_d_gate)
extern double beta_d;   // dimensionless (in L_type_Ca_current_d_gate)
extern double d_inf;   // dimensionless (in L_type_Ca_current_d_gate)
extern double gamma_d;   // millisecond (in L_type_Ca_current_d_gate)
extern double tau_d;   // millisecond (in L_type_Ca_current_d_gate)
extern double f2_inf;   // dimensionless (in L_type_Ca_current_f2_gate)
extern double tau_f2;   // millisecond (in L_type_Ca_current_f2_gate)
extern double fCass_inf;   // dimensionless (in L_type_Ca_current_fCass_gate)
extern double tau_fCass;   // millisecond (in L_type_Ca_current_fCass_gate)
extern double f_inf;   // dimensionless (in L_type_Ca_current_f_gate)
extern double tau_f;   // millisecond (in L_type_Ca_current_f_gate)
extern double i_CaL;   // picoA_per_picoF (in L_type_Ca_current)
extern double i_b_Ca;   // picoA_per_picoF (in calcium_background_current)
extern double Ca_i_bufc;   // dimensionless (in calcium_dynamics)
extern double Ca_sr_bufsr;   // dimensionless (in calcium_dynamics)
extern double Ca_ss_bufss;   // dimensionless (in calcium_dynamics)
extern double O;   // dimensionless (in calcium_dynamics)
extern double i_leak;   // millimolar_per_millisecond (in calcium_dynamics)
extern double i_rel;   // millimolar_per_millisecond (in calcium_dynamics)
extern double i_up;   // millimolar_per_millisecond (in calcium_dynamics)
extern double i_xfer;   // millimolar_per_millisecond (in calcium_dynamics)
extern double k1;   // per_millimolar2_per_millisecond (in calcium_dynamics)
extern double k2;   // per_millimolar_per_millisecond (in calcium_dynamics)
extern double kcasr;   // dimensionless (in calcium_dynamics)
extern double i_p_Ca;   // picoA_per_picoF (in calcium_pump_current)
extern double alpha_h;   // per_millisecond (in fast_sodium_current_h_gate)
extern double beta_h;   // per_millisecond (in fast_sodium_current_h_gate)
extern double h_inf;   // dimensionless (in fast_sodium_current_h_gate)
extern double tau_h;   // millisecond (in fast_sodium_current_h_gate)
extern double alpha_j;   // per_millisecond (in fast_sodium_current_j_gate)
extern double beta_j;   // per_millisecond (in fast_sodium_current_j_gate)
extern double j_inf;   // dimensionless (in fast_sodium_current_j_gate)
extern double tau_j;   // millisecond (in fast_sodium_current_j_gate)
extern double alpha_m;   // dimensionless (in fast_sodium_current_m_gate)
extern double beta_m;   // dimensionless (in fast_sodium_current_m_gate)
extern double m_inf;   // dimensionless (in fast_sodium_current_m_gate)
extern double tau_m;   // millisecond (in fast_sodium_current_m_gate)
extern double i_Na;   // picoA_per_picoF (in fast_sodium_current)
extern double alpha_K1;   // dimensionless (in inward_rectifier_potassium_current)
extern double beta_K1;   // dimensionless (in inward_rectifier_potassium_current)
extern double i_K1;   // picoA_per_picoF (in inward_rectifier_potassium_current)
extern double xK1_inf;   // dimensionless (in inward_rectifier_potassium_current)
extern double i_Stim;   // picoA_per_picoF (in membrane)
extern double i_p_K;   // picoA_per_picoF (in potassium_pump_current)
extern double alpha_xr1;   // dimensionless (in rapid_time_dependent_potassium_current_Xr1_gate)
extern double beta_xr1;   // dimensionless (in rapid_time_dependent_potassium_current_Xr1_gate)
extern double tau_xr1;   // millisecond (in rapid_time_dependent_potassium_current_Xr1_gate)
extern double xr1_inf;   // dimensionless (in rapid_time_dependent_potassium_current_Xr1_gate)
extern double alpha_xr2;   // dimensionless (in rapid_time_dependent_potassium_current_Xr2_gate)
extern double beta_xr2;   // dimensionless (in rapid_time_dependent_potassium_current_Xr2_gate)
extern double tau_xr2;   // millisecond (in rapid_time_dependent_potassium_current_Xr2_gate)
extern double xr2_inf;   // dimensionless (in rapid_time_dependent_potassium_current_Xr2_gate)
extern double i_Kr;   // picoA_per_picoF (in rapid_time_dependent_potassium_current)
extern double E_Ca;   // millivolt (in reversal_potentials)
extern double E_K;   // millivolt (in reversal_potentials)
extern double E_Ks;   // millivolt (in reversal_potentials)
extern double E_Na;   // millivolt (in reversal_potentials)
extern double alpha_xs;   // dimensionless (in slow_time_dependent_potassium_current_Xs_gate)
extern double beta_xs;   // dimensionless (in slow_time_dependent_potassium_current_Xs_gate)
extern double tau_xs;   // millisecond (in slow_time_dependent_potassium_current_Xs_gate)
extern double xs_inf;   // dimensionless (in slow_time_dependent_potassium_current_Xs_gate)
extern double i_Ks;   // picoA_per_picoF (in slow_time_dependent_potassium_current)
extern double i_b_Na;   // picoA_per_picoF (in sodium_background_current)
extern double i_NaCa;   // picoA_per_picoF (in sodium_calcium_exchanger_current)
extern double i_NaK;   // picoA_per_picoF (in sodium_potassium_pump_current)
extern double r_inf;   // dimensionless (in transient_outward_current_r_gate)
extern double tau_r;   // millisecond (in transient_outward_current_r_gate)
extern double s_inf;   // dimensionless (in transient_outward_current_s_gate)
extern double tau_s;   // millisecond (in transient_outward_current_s_gate)
extern double i_to;   // picoA_per_picoF (in transient_outward_current)

//------------------------------------------------------------------------------
// Procedures
//------------------------------------------------------------------------------

extern void init();
extern void compute(double time);

//------------------------------------------------------------------------------

#endif

//==============================================================================
// End of file
//==============================================================================
