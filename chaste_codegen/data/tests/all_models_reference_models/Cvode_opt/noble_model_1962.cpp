#ifdef CHASTE_CVODE
//! @file
//!
//! This source file was generated from CellML by chaste_codegen version (version omitted as unimportant)
//!
//! Model: noble_model_1962
//!
//! Processed by chaste_codegen: https://github.com/ModellingWebLab/chaste-codegen
//!     (translator: chaste_codegen, model type: NumericCvodeOpt)
//! on (date omitted as unimportant)
//!
//! <autogenerated>

#include "noble_model_1962.hpp"
#include <cmath>
#include <cassert>
#include <memory>
#include "Exception.hpp"
#include "OdeSystemInformation.hpp"
#include "RegularStimulus.hpp"
#include "HeartConfig.hpp"
#include "IsNan.hpp"
#include "MathsCustomFunctions.hpp"

class Cellnoble_model_1962FromCellMLCvodeOpt_LookupTables : public AbstractLookupTableCollection
{
public:
    static Cellnoble_model_1962FromCellMLCvodeOpt_LookupTables* Instance()
    {
        if (mpInstance.get() == NULL)
        {
            mpInstance.reset(new Cellnoble_model_1962FromCellMLCvodeOpt_LookupTables);
        }
        return mpInstance.get();
    }

    void FreeMemory()
    {

        if (_lookup_table_0)
        {
            delete[] _lookup_table_0;
            _lookup_table_0 = NULL;
        }

        mNeedsRegeneration.assign(mNeedsRegeneration.size(), true);
    }

    // Row lookup methods
    // using linear-interpolation

    double* _lookup_0_row(unsigned i, double _factor_)
    {
        for (unsigned j=0; j<6; j++)
        {
            const double y1 = _lookup_table_0[i][j];
            const double y2 = _lookup_table_0[i+1][j];
            _lookup_table_0_row[j] = y1 + (y2-y1)*_factor_;
        }
        return _lookup_table_0_row;
    }


    const double * IndexTable0(double var_chaste_interface__membrane__V)
    {
        const double _offset_0 = var_chaste_interface__membrane__V - mTableMins[0];
        const double _offset_0_over_table_step = _offset_0 * mTableStepInverses[0];
        const unsigned _table_index_0 = (unsigned)(_offset_0_over_table_step);
        const double _factor_0 = _offset_0_over_table_step - _table_index_0;
        const double* const _lt_0_row = Cellnoble_model_1962FromCellMLCvodeOpt_LookupTables::Instance()->_lookup_0_row(_table_index_0, _factor_0);
        return _lt_0_row;
    }


// LCOV_EXCL_START
    bool CheckIndex0(double& var_chaste_interface__membrane__V)
    {
        bool _oob_0 = false;
        if (var_chaste_interface__membrane__V>mTableMaxs[0] || var_chaste_interface__membrane__V<mTableMins[0])
        {
// LCOV_EXCL_START
            _oob_0 = true;
// LCOV_EXCL_STOP
        }
        return _oob_0;
    }
// LCOV_EXCL_STOP

    ~Cellnoble_model_1962FromCellMLCvodeOpt_LookupTables()
    {

        if (_lookup_table_0)
        {
            delete[] _lookup_table_0;
            _lookup_table_0 = NULL;
        }

    }

protected:
    Cellnoble_model_1962FromCellMLCvodeOpt_LookupTables(const Cellnoble_model_1962FromCellMLCvodeOpt_LookupTables&);
    Cellnoble_model_1962FromCellMLCvodeOpt_LookupTables& operator= (const Cellnoble_model_1962FromCellMLCvodeOpt_LookupTables&);
    Cellnoble_model_1962FromCellMLCvodeOpt_LookupTables()
    {
        assert(mpInstance.get() == NULL);
        mKeyingVariableNames.resize(1);
        mNumberOfTables.resize(1);
        mTableMins.resize(1);
        mTableSteps.resize(1);
        mTableStepInverses.resize(1);
        mTableMaxs.resize(1);
        mNeedsRegeneration.resize(1);

        mKeyingVariableNames[0] = "membrane_voltage";
        mNumberOfTables[0] = 6;
        mTableMins[0] = -250.0;
        mTableMaxs[0] = 550.0;
        mTableSteps[0] = 0.001;
        mTableStepInverses[0] = 1000.0;
        mNeedsRegeneration[0] = true;
        _lookup_table_0 = NULL;

        Cellnoble_model_1962FromCellMLCvodeOpt_LookupTables::RegenerateTables();
    }

    void RegenerateTables()
    {
        AbstractLookupTableCollection::EventHandler::BeginEvent(AbstractLookupTableCollection::EventHandler::GENERATE_TABLES);


        if (mNeedsRegeneration[0])
        {
            if (_lookup_table_0)
            {
                delete[] _lookup_table_0;
                _lookup_table_0 = NULL;
            }
            const unsigned _table_size_0 = 1 + (unsigned)((mTableMaxs[0]-mTableMins[0])/mTableSteps[0]+0.5);
            _lookup_table_0 = new double[_table_size_0][6];

            for (unsigned i=0 ; i<_table_size_0; i++)
            {
                auto f = [](double var_chaste_interface__membrane__V) {
                    return exp(1.5 + 0.016666666666666666 * var_chaste_interface__membrane__V);
                };
                const double var_chaste_interface__membrane__V = mTableMins[0] + i*mTableSteps[0];
                double val = f(var_chaste_interface__membrane__V);

                _lookup_table_0[i][0] = val;
            }

            for (unsigned i=0 ; i<_table_size_0; i++)
            {
                auto f = [](double var_chaste_interface__membrane__V) {
                    return exp(-1.8 - 0.02 * var_chaste_interface__membrane__V);
                };
                const double var_chaste_interface__membrane__V = mTableMins[0] + i*mTableSteps[0];
                double val = f(var_chaste_interface__membrane__V);

                _lookup_table_0[i][1] = val;
            }

            for (unsigned i=0 ; i<_table_size_0; i++)
            {
                auto f = [](double var_chaste_interface__membrane__V) {
                    return exp(-1.125 - 0.012500000000000001 * var_chaste_interface__membrane__V);
                };
                const double var_chaste_interface__membrane__V = mTableMins[0] + i*mTableSteps[0];
                double val = f(var_chaste_interface__membrane__V);

                _lookup_table_0[i][2] = val;
            }

            for (unsigned i=0 ; i<_table_size_0; i++)
            {
                auto f = [](double var_chaste_interface__membrane__V) {
                    return -1.0 + exp(-5.0 - 0.10000000000000001 * var_chaste_interface__membrane__V);
                };
                const double var_chaste_interface__membrane__V = mTableMins[0] + i*mTableSteps[0];
                double val = f(var_chaste_interface__membrane__V);

                _lookup_table_0[i][3] = val;
            }

            for (unsigned i=0 ; i<_table_size_0; i++)
            {
                auto f = [](double var_chaste_interface__membrane__V) {
                    return ((fabs(48.0 + var_chaste_interface__membrane__V) < 1.5000000033182914e-6) ? (1.5000000033182915e-7 / (-1.0 + exp(1.0000000022121943e-7)) + 333333.33259593527 * (48.000001500000003 + var_chaste_interface__membrane__V) * (-1.5000000033182915e-7 / (-1.0 + exp(1.0000000022121943e-7)) - 1.5000000033182915e-7 / (-1.0 + exp(-1.0000000022121943e-7)))) : (0.10000000000000001 * (-48.0 - var_chaste_interface__membrane__V) / (-1.0 + exp(-3.2000000000000002 - 0.066666666666666666 * var_chaste_interface__membrane__V))));
                };
                const double var_chaste_interface__membrane__V = mTableMins[0] + i*mTableSteps[0];
                double val = f(var_chaste_interface__membrane__V);
                //Expressions which are part of a piecewise could be inf / nan, this is generally accptable, due to the piecewise, however occasionally interpolation of the lookup table from a nan/inf version can give problems.
                //To avoid this values stored in the table are intrpolated. Occurances of this to at most 2 per expression.
                if (!std::isfinite(val) && _lookup_table_0_num_misshit_piecewise[4] < 2){
                    double left = f(var_chaste_interface__membrane__V - mTableSteps[0]);
                    double right = f(var_chaste_interface__membrane__V + mTableSteps[0]);
                    val = (left + right) / 2.0;
                   // count and limit number of misshits
                  _lookup_table_0_num_misshit_piecewise[4] +=1;
                }
                else if (!std::isfinite(val) && _lookup_table_0_num_misshit_piecewise[4] >= 2){
                    EXCEPTION("Lookup table 4 at ["<<i<<"][4] has non-finite value: " << val);
                }
                _lookup_table_0[i][4] = val;
            }

            for (unsigned i=0 ; i<_table_size_0; i++)
            {
                auto f = [](double var_chaste_interface__membrane__V) {
                    return ((fabs(8.0 + var_chaste_interface__membrane__V) < 5.0000000006988898e-7) ? (5.9999999955095972e-8 / (-1.0 + exp(9.9999999925159949e-8)) - 999999.99986022199 * (7.9999995000000004 + var_chaste_interface__membrane__V) * (-5.9999999955095972e-8 / (-1.0 + exp(9.9999999925159949e-8)) - 6.0000000061677387e-8 / (-1.0 + exp(-1.0000000010279564e-7)))) : (0.12 * (8.0 + var_chaste_interface__membrane__V) / (-1.0 + exp(1.6000000000000001 + 0.20000000000000001 * var_chaste_interface__membrane__V))));
                };
                const double var_chaste_interface__membrane__V = mTableMins[0] + i*mTableSteps[0];
                double val = f(var_chaste_interface__membrane__V);
                //Expressions which are part of a piecewise could be inf / nan, this is generally accptable, due to the piecewise, however occasionally interpolation of the lookup table from a nan/inf version can give problems.
                //To avoid this values stored in the table are intrpolated. Occurances of this to at most 2 per expression.
                if (!std::isfinite(val) && _lookup_table_0_num_misshit_piecewise[5] < 2){
                    double left = f(var_chaste_interface__membrane__V - mTableSteps[0]);
                    double right = f(var_chaste_interface__membrane__V + mTableSteps[0]);
                    val = (left + right) / 2.0;
                   // count and limit number of misshits
                  _lookup_table_0_num_misshit_piecewise[5] +=1;
                }
                else if (!std::isfinite(val) && _lookup_table_0_num_misshit_piecewise[5] >= 2){
                    EXCEPTION("Lookup table 5 at ["<<i<<"][5] has non-finite value: " << val);
                }
                _lookup_table_0[i][5] = val;
            }

            mNeedsRegeneration[0] = false;
        }

        AbstractLookupTableCollection::EventHandler::EndEvent(AbstractLookupTableCollection::EventHandler::GENERATE_TABLES);
    }

private:
    /** The single instance of the class */
    static std::shared_ptr<Cellnoble_model_1962FromCellMLCvodeOpt_LookupTables> mpInstance;

    // Row lookup methods memory
    double _lookup_table_0_row[6];

    // Lookup tables
    double (*_lookup_table_0)[6];
    int _lookup_table_0_num_misshit_piecewise[6] = {0};

};

std::shared_ptr<Cellnoble_model_1962FromCellMLCvodeOpt_LookupTables> Cellnoble_model_1962FromCellMLCvodeOpt_LookupTables::mpInstance;



    Cellnoble_model_1962FromCellMLCvodeOpt::Cellnoble_model_1962FromCellMLCvodeOpt(boost::shared_ptr<AbstractIvpOdeSolver> pOdeSolver /* unused; should be empty */, boost::shared_ptr<AbstractStimulusFunction> pIntracellularStimulus)
        : AbstractCvodeCell(
                pOdeSolver,
                4,
                0,
                pIntracellularStimulus)
    {
        // Time units: millisecond
        //
        this->mpSystemInfo = OdeSystemInformation<Cellnoble_model_1962FromCellMLCvodeOpt>::Instance();
        Init();
        
        NV_Ith_S(this->mParameters, 0) = 12.0; // (var_membrane__Cm) [microF_per_cm2]
        NV_Ith_S(this->mParameters, 1) = 1.2; // (var_potassium_channel__G_K_max) [milliS_per_cm2]
        NV_Ith_S(this->mParameters, 2) = 400.0; // (var_sodium_channel__g_Na_max) [milliS_per_cm2]
        NV_Ith_S(this->mParameters, 3) = 0; // (var_sodium_channel__perc_reduced_inact_for_IpNa) [dimensionless]
        NV_Ith_S(this->mParameters, 4) = 0; // (var_sodium_channel__shift_INa_inact) [millivolt]
        NV_Ith_S(this->mParameters, 5) = 0.014999999999999999; // (var_potassium_channel__G_K1_max) [milliS_per_cm2]
        NV_Ith_S(this->mParameters, 6) = 0.074999999999999997; // (var_leakage_current__g_L) [milliS_per_cm2]
    }

    Cellnoble_model_1962FromCellMLCvodeOpt::~Cellnoble_model_1962FromCellMLCvodeOpt()
    {
    }

    AbstractLookupTableCollection* Cellnoble_model_1962FromCellMLCvodeOpt::GetLookupTableCollection()
    {
        return Cellnoble_model_1962FromCellMLCvodeOpt_LookupTables::Instance();
    }
    
    double Cellnoble_model_1962FromCellMLCvodeOpt::GetIIonic(const std::vector<double>* pStateVariables)
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
        // Units: millivolt; Initial value: -81.4147357
        double var_chaste_interface__sodium_channel_m_gate__m = NV_Ith_S(rY, 1);
        // Units: dimensionless; Initial value: 0.0438066719
        double var_chaste_interface__sodium_channel_h_gate__h = NV_Ith_S(rY, 2);
        // Units: dimensionless; Initial value: 0.854216896
        double var_chaste_interface__potassium_channel_n_gate__n = NV_Ith_S(rY, 3);
        // Units: dimensionless; Initial value: 0.593071543
        
        // Lookup table indexing
        const bool _oob_0 = Cellnoble_model_1962FromCellMLCvodeOpt_LookupTables::Instance()->CheckIndex0(var_chaste_interface__membrane__V);
// LCOV_EXCL_START
        if (_oob_0)
            EXCEPTION(DumpState("membrane_voltage outside lookup table range", rY));
// LCOV_EXCL_STOP
        const double* const _lt_0_row = Cellnoble_model_1962FromCellMLCvodeOpt_LookupTables::Instance()->IndexTable0(var_chaste_interface__membrane__V);

        const double var_leakage_current__i_Leak = (60.0 + var_chaste_interface__membrane__V) * NV_Ith_S(mParameters, 6); // microA_per_cm2
        const double var_potassium_channel__i_K = (100.0 + var_chaste_interface__membrane__V) * (pow(var_chaste_interface__potassium_channel_n_gate__n, 4) * NV_Ith_S(mParameters, 1) + NV_Ith_S(mParameters, 5) * _lt_0_row[0] + NV_Ith_S(mParameters, 1) * _lt_0_row[1]); // microA_per_cm2
        const double var_sodium_channel__i_Na = (0.14000000000000001 + pow(var_chaste_interface__sodium_channel_m_gate__m, 3) * NV_Ith_S(mParameters, 2) * var_chaste_interface__sodium_channel_h_gate__h) * (-40.0 + var_chaste_interface__membrane__V); // microA_per_cm2
        const double var_chaste_interface__i_ionic = var_leakage_current__i_Leak + var_potassium_channel__i_K + var_sodium_channel__i_Na; // uA_per_cm2

        const double i_ionic = var_chaste_interface__i_ionic;
        if (made_new_cvode_vector)
        {
            DeleteVector(rY);
        }
        EXCEPT_IF_NOT(!std::isnan(i_ionic));
        return i_ionic;
    }

    void Cellnoble_model_1962FromCellMLCvodeOpt::EvaluateYDerivatives(double var_chaste_interface__environment__time, const N_Vector rY, N_Vector rDY)
    {
        // Inputs:
        // Time units: millisecond
        double var_chaste_interface__membrane__V = (mSetVoltageDerivativeToZero ? this->mFixedVoltage : NV_Ith_S(rY, 0));
        // Units: millivolt; Initial value: -81.4147357
        double var_chaste_interface__sodium_channel_m_gate__m = NV_Ith_S(rY, 1);
        // Units: dimensionless; Initial value: 0.0438066719
        double var_chaste_interface__sodium_channel_h_gate__h = NV_Ith_S(rY, 2);
        // Units: dimensionless; Initial value: 0.854216896
        double var_chaste_interface__potassium_channel_n_gate__n = NV_Ith_S(rY, 3);
        // Units: dimensionless; Initial value: 0.593071543

        // Lookup table indexing
        const bool _oob_0 = Cellnoble_model_1962FromCellMLCvodeOpt_LookupTables::Instance()->CheckIndex0(var_chaste_interface__membrane__V);
// LCOV_EXCL_START
        if (_oob_0)
            EXCEPTION(DumpState("membrane_voltage outside lookup table range", rY , var_chaste_interface__environment__time));
// LCOV_EXCL_STOP
        const double* const _lt_0_row = Cellnoble_model_1962FromCellMLCvodeOpt_LookupTables::Instance()->IndexTable0(var_chaste_interface__membrane__V);

        // Mathematics
        double d_dt_chaste_interface_var_membrane__V;
        const double d_dt_chaste_interface_var_potassium_channel_n_gate__n = -0.002 * var_chaste_interface__potassium_channel_n_gate__n * _lt_0_row[2] + 0.0001 * (1.0 - var_chaste_interface__potassium_channel_n_gate__n) * (-50.0 - var_chaste_interface__membrane__V) / (_lt_0_row[3]); // 1 / millisecond
        const double var_sodium_channel_h_gate__alpha_h = 0.17000000000000001 * exp(-4.5 + 0.050000000000000003 * NV_Ith_S(mParameters, 4) - 0.050000000000000003 * var_chaste_interface__membrane__V); // per_millisecond
        const double var_sodium_channel_h_gate__beta_h = 1 / (1.0 + exp(-4.2000000000000002 + 0.10000000000000001 * NV_Ith_S(mParameters, 4) - 0.10000000000000001 * var_chaste_interface__membrane__V)); // per_millisecond
        const double d_dt_chaste_interface_var_sodium_channel_h_gate__h = (var_sodium_channel_h_gate__alpha_h + var_sodium_channel_h_gate__beta_h) * (-var_chaste_interface__sodium_channel_h_gate__h + 0.01 * NV_Ith_S(mParameters, 3) + (1.0 - 0.01 * NV_Ith_S(mParameters, 3)) * var_sodium_channel_h_gate__alpha_h / (var_sodium_channel_h_gate__alpha_h + var_sodium_channel_h_gate__beta_h)); // 1 / millisecond
        const double d_dt_chaste_interface_var_sodium_channel_m_gate__m = (1.0 - var_chaste_interface__sodium_channel_m_gate__m) * _lt_0_row[4] - _lt_0_row[5] * var_chaste_interface__sodium_channel_m_gate__m; // 1 / millisecond

        if (mSetVoltageDerivativeToZero)
        {
            d_dt_chaste_interface_var_membrane__V = 0.0;
        }
        else
        {
            d_dt_chaste_interface_var_membrane__V = (-(60.0 + var_chaste_interface__membrane__V) * NV_Ith_S(mParameters, 6) - (100.0 + var_chaste_interface__membrane__V) * (pow(var_chaste_interface__potassium_channel_n_gate__n, 4) * NV_Ith_S(mParameters, 1) + NV_Ith_S(mParameters, 5) * _lt_0_row[0] + NV_Ith_S(mParameters, 1) * _lt_0_row[1]) - (0.14000000000000001 + pow(var_chaste_interface__sodium_channel_m_gate__m, 3) * NV_Ith_S(mParameters, 2) * var_chaste_interface__sodium_channel_h_gate__h) * (-40.0 + var_chaste_interface__membrane__V)) / NV_Ith_S(mParameters, 0); // millivolt / millisecond
        }
        
        NV_Ith_S(rDY,0) = d_dt_chaste_interface_var_membrane__V;
        NV_Ith_S(rDY,1) = d_dt_chaste_interface_var_sodium_channel_m_gate__m;
        NV_Ith_S(rDY,2) = d_dt_chaste_interface_var_sodium_channel_h_gate__h;
        NV_Ith_S(rDY,3) = d_dt_chaste_interface_var_potassium_channel_n_gate__n;
    }

    N_Vector Cellnoble_model_1962FromCellMLCvodeOpt::ComputeDerivedQuantities(double var_chaste_interface__environment__time, const N_Vector & rY)
    {
        // Inputs:
        // Time units: millisecond
        double var_chaste_interface__membrane__V = (mSetVoltageDerivativeToZero ? this->mFixedVoltage : NV_Ith_S(rY, 0));
        // Units: millivolt; Initial value: -81.4147357
        double var_chaste_interface__sodium_channel_m_gate__m = NV_Ith_S(rY, 1);
        // Units: dimensionless; Initial value: 0.0438066719
        double var_chaste_interface__sodium_channel_h_gate__h = NV_Ith_S(rY, 2);
        // Units: dimensionless; Initial value: 0.854216896
        double var_chaste_interface__potassium_channel_n_gate__n = NV_Ith_S(rY, 3);
        // Units: dimensionless; Initial value: 0.593071543
        
        // Lookup table indexing
        const bool _oob_0 = Cellnoble_model_1962FromCellMLCvodeOpt_LookupTables::Instance()->CheckIndex0(var_chaste_interface__membrane__V);
// LCOV_EXCL_START
        if (_oob_0)
            EXCEPTION(DumpState("membrane_voltage outside lookup table range", rY , var_chaste_interface__environment__time));
// LCOV_EXCL_STOP
        const double* const _lt_0_row = Cellnoble_model_1962FromCellMLCvodeOpt_LookupTables::Instance()->IndexTable0(var_chaste_interface__membrane__V);

        // Mathematics
        const double var_leakage_current__E_L = -60.0; // millivolt
        const double var_leakage_current__i_Leak = (-var_leakage_current__E_L + var_chaste_interface__membrane__V) * NV_Ith_S(mParameters, 6); // microA_per_cm2
        const double var_potassium_channel__g_K1 = NV_Ith_S(mParameters, 5) * _lt_0_row[0] + NV_Ith_S(mParameters, 1) * _lt_0_row[1]; // milliS_per_cm2
        const double var_potassium_channel__g_K2 = pow(var_chaste_interface__potassium_channel_n_gate__n, 4) * NV_Ith_S(mParameters, 1); // milliS_per_cm2
        const double var_potassium_channel__i_K = (100.0 + var_chaste_interface__membrane__V) * (var_potassium_channel__g_K1 + var_potassium_channel__g_K2); // microA_per_cm2
        const double var_sodium_channel__E_Na = 40.0; // millivolt
        const double var_sodium_channel_h_gate__alpha_h = 0.17000000000000001 * exp(-4.5 + 0.050000000000000003 * NV_Ith_S(mParameters, 4) - 0.050000000000000003 * var_chaste_interface__membrane__V); // per_millisecond
        const double var_sodium_channel_h_gate__beta_h = 1 / (1.0 + exp(-4.2000000000000002 + 0.10000000000000001 * NV_Ith_S(mParameters, 4) - 0.10000000000000001 * var_chaste_interface__membrane__V)); // per_millisecond
        const double var_sodium_channel_h_gate__tau_h = 1 / (var_sodium_channel_h_gate__alpha_h + var_sodium_channel_h_gate__beta_h); // millisecond
        const double var_sodium_channel__g_Na = pow(var_chaste_interface__sodium_channel_m_gate__m, 3) * NV_Ith_S(mParameters, 2) * var_chaste_interface__sodium_channel_h_gate__h; // milliS_per_cm2
        const double var_sodium_channel__i_Na = (0.14000000000000001 + var_sodium_channel__g_Na) * (-var_sodium_channel__E_Na + var_chaste_interface__membrane__V); // microA_per_cm2

        N_Vector dqs = N_VNew_Serial(5);
        NV_Ith_S(dqs, 0) = var_potassium_channel__i_K;
        NV_Ith_S(dqs, 1) = var_sodium_channel__i_Na;
        NV_Ith_S(dqs, 2) = var_sodium_channel_h_gate__tau_h;
        NV_Ith_S(dqs, 3) = var_leakage_current__i_Leak;
        NV_Ith_S(dqs, 4) = var_chaste_interface__environment__time;
        return dqs;
    }

template<>
void OdeSystemInformation<Cellnoble_model_1962FromCellMLCvodeOpt>::Initialise(void)
{
    this->mSystemName = "noble_model_1962";
    this->mFreeVariableName = "time";
    this->mFreeVariableUnits = "millisecond";

    // NV_Ith_S(rY, 0):
    this->mVariableNames.push_back("membrane_voltage");
    this->mVariableUnits.push_back("millivolt");
    this->mInitialConditions.push_back(-81.4147357);

    // NV_Ith_S(rY, 1):
    this->mVariableNames.push_back("membrane_fast_sodium_current_m_gate");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(0.0438066719);

    // NV_Ith_S(rY, 2):
    this->mVariableNames.push_back("membrane_fast_sodium_current_h_gate");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(0.854216896);

    // NV_Ith_S(rY, 3):
    this->mVariableNames.push_back("potassium_channel_n_gate__n");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(0.593071543);

    // mParameters[0]:
    this->mParameterNames.push_back("membrane_capacitance");
    this->mParameterUnits.push_back("microF_per_cm2");

    // mParameters[1]:
    this->mParameterNames.push_back("membrane_delayed_rectifier_potassium_current_conductance");
    this->mParameterUnits.push_back("milliS_per_cm2");

    // mParameters[2]:
    this->mParameterNames.push_back("membrane_fast_sodium_current_conductance");
    this->mParameterUnits.push_back("milliS_per_cm2");

    // mParameters[3]:
    this->mParameterNames.push_back("membrane_fast_sodium_current_reduced_inactivation");
    this->mParameterUnits.push_back("dimensionless");

    // mParameters[4]:
    this->mParameterNames.push_back("membrane_fast_sodium_current_shift_inactivation");
    this->mParameterUnits.push_back("millivolt");

    // mParameters[5]:
    this->mParameterNames.push_back("membrane_inward_rectifier_potassium_current_conductance");
    this->mParameterUnits.push_back("milliS_per_cm2");

    // mParameters[6]:
    this->mParameterNames.push_back("membrane_leakage_current_conductance");
    this->mParameterUnits.push_back("milliS_per_cm2");

    // Derived Quantity index [0]:
    this->mDerivedQuantityNames.push_back("membrane_delayed_rectifier_potassium_current");
    this->mDerivedQuantityUnits.push_back("microA_per_cm2");

    // Derived Quantity index [1]:
    this->mDerivedQuantityNames.push_back("membrane_fast_sodium_current");
    this->mDerivedQuantityUnits.push_back("microA_per_cm2");

    // Derived Quantity index [2]:
    this->mDerivedQuantityNames.push_back("membrane_fast_sodium_current_h_gate_tau");
    this->mDerivedQuantityUnits.push_back("millisecond");

    // Derived Quantity index [3]:
    this->mDerivedQuantityNames.push_back("membrane_leakage_current");
    this->mDerivedQuantityUnits.push_back("microA_per_cm2");

    // Derived Quantity index [4]:
    this->mDerivedQuantityNames.push_back("time");
    this->mDerivedQuantityUnits.push_back("millisecond");

    
    this->mAttributes["SuggestedCycleLength"] = 1000;
    this->mInitialised = true;
}

// Serialization for Boost >= 1.36
#include "SerializationExportWrapperForCpp.hpp"
CHASTE_CLASS_EXPORT(Cellnoble_model_1962FromCellMLCvodeOpt)

#endif // CHASTE_CVODE
