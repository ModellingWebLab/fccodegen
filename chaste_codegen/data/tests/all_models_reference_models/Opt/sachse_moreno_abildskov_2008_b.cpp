//! @file
//!
//! This source file was generated from CellML by chaste_codegen version (version omitted as unimportant)
//!
//! Model: sachse_model_2007
//!
//! Processed by chaste_codegen: https://github.com/ModellingWebLab/chaste-codegen
//!     (translator: chaste_codegen, model type: NormalOpt)
//! on (date omitted as unimportant)
//!
//! <autogenerated>

#include "sachse_moreno_abildskov_2008_b.hpp"
#include <cmath>
#include <cassert>
#include <memory>
#include "Exception.hpp"
#include "OdeSystemInformation.hpp"
#include "RegularStimulus.hpp"
#include "HeartConfig.hpp"
#include "IsNan.hpp"
#include "MathsCustomFunctions.hpp"

class Cellsachse_moreno_abildskov_2008_bFromCellMLOpt_LookupTables : public AbstractLookupTableCollection
{
public:
    static Cellsachse_moreno_abildskov_2008_bFromCellMLOpt_LookupTables* Instance()
    {
        if (mpInstance.get() == NULL)
        {
            mpInstance.reset(new Cellsachse_moreno_abildskov_2008_bFromCellMLOpt_LookupTables);
        }
        return mpInstance.get();
    }

    void FreeMemory()
    {

        mNeedsRegeneration.assign(mNeedsRegeneration.size(), true);
    }

    // Row lookup methods
    // using linear-interpolation



    ~Cellsachse_moreno_abildskov_2008_bFromCellMLOpt_LookupTables()
    {

    }

protected:
    Cellsachse_moreno_abildskov_2008_bFromCellMLOpt_LookupTables(const Cellsachse_moreno_abildskov_2008_bFromCellMLOpt_LookupTables&);
    Cellsachse_moreno_abildskov_2008_bFromCellMLOpt_LookupTables& operator= (const Cellsachse_moreno_abildskov_2008_bFromCellMLOpt_LookupTables&);
    Cellsachse_moreno_abildskov_2008_bFromCellMLOpt_LookupTables()
    {
        assert(mpInstance.get() == NULL);
        mKeyingVariableNames.resize(0);
        mNumberOfTables.resize(0);
        mTableMins.resize(0);
        mTableSteps.resize(0);
        mTableStepInverses.resize(0);
        mTableMaxs.resize(0);
        mNeedsRegeneration.resize(0);

        Cellsachse_moreno_abildskov_2008_bFromCellMLOpt_LookupTables::RegenerateTables();
    }

    void RegenerateTables()
    {
        AbstractLookupTableCollection::EventHandler::BeginEvent(AbstractLookupTableCollection::EventHandler::GENERATE_TABLES);

        AbstractLookupTableCollection::EventHandler::EndEvent(AbstractLookupTableCollection::EventHandler::GENERATE_TABLES);
    }

private:
    /** The single instance of the class */
    static std::shared_ptr<Cellsachse_moreno_abildskov_2008_bFromCellMLOpt_LookupTables> mpInstance;

};

std::shared_ptr<Cellsachse_moreno_abildskov_2008_bFromCellMLOpt_LookupTables> Cellsachse_moreno_abildskov_2008_bFromCellMLOpt_LookupTables::mpInstance;


    boost::shared_ptr<RegularStimulus> Cellsachse_moreno_abildskov_2008_bFromCellMLOpt::UseCellMLDefaultStimulus()
    {
        // Use the default stimulus specified by CellML metadata
        const double var_chaste_interface__I_stim__stim_duration_converted = 1.0; // millisecond
        const double var_chaste_interface__I_stim__stim_period_converted = 1000.0; // millisecond
        const double var_chaste_interface__I_stim__stim_start_converted = 100.0; // millisecond
        const double var_chaste_interface__I_stim__stim_amplitude_converted = 0.0001 * HeartConfig::Instance()->GetCapacitance() / mParameters[2]; // uA_per_cm2
        boost::shared_ptr<RegularStimulus> p_cellml_stim(new RegularStimulus(
                -fabs(var_chaste_interface__I_stim__stim_amplitude_converted),
                var_chaste_interface__I_stim__stim_duration_converted,
                var_chaste_interface__I_stim__stim_period_converted,
                var_chaste_interface__I_stim__stim_start_converted
                ));
        mpIntracellularStimulus = p_cellml_stim;
        return p_cellml_stim;
    }

    Cellsachse_moreno_abildskov_2008_bFromCellMLOpt::Cellsachse_moreno_abildskov_2008_bFromCellMLOpt(boost::shared_ptr<AbstractIvpOdeSolver> pSolver, boost::shared_ptr<AbstractStimulusFunction> pIntracellularStimulus)
        : AbstractCardiacCell(
                pSolver,
                7,
                0,
                pIntracellularStimulus)
    {
        // Time units: millisecond
        //
        this->mpSystemInfo = OdeSystemInformation<Cellsachse_moreno_abildskov_2008_bFromCellMLOpt>::Instance();
        Init();

        // We have a default stimulus specified in the CellML file metadata
        this->mHasDefaultStimulusFromCellML = true;
        
        this->mParameters[0] = 140.0; // (var_model_parameters__Ki) [millimolar]
        this->mParameters[1] = 5.0; // (var_model_parameters__Ko) [millimolar]
        this->mParameters[2] = 4.5000000000000001e-6; // (var_membrane__Cm) [microfarad]
        this->mParameters[3] = 5.4000000000000004e-9; // (var_I_Shkr__PShkr) [microlitre_per_second]
        this->mParameters[4] = 0.001; // (var_I_Kir__GKir) [microsiemens]
        this->mParameters[5] = 6.9e-6; // (var_I_b__Gb) [microsiemens]
        this->mParameters[6] = 295.0; // (var_model_parameters__T) [kelvin]
    }

    Cellsachse_moreno_abildskov_2008_bFromCellMLOpt::~Cellsachse_moreno_abildskov_2008_bFromCellMLOpt()
    {
    }

    AbstractLookupTableCollection* Cellsachse_moreno_abildskov_2008_bFromCellMLOpt::GetLookupTableCollection()
    {
        return Cellsachse_moreno_abildskov_2008_bFromCellMLOpt_LookupTables::Instance();
    }
    
    double Cellsachse_moreno_abildskov_2008_bFromCellMLOpt::GetIIonic(const std::vector<double>* pStateVariables)
    {
        // For state variable interpolation (SVI) we read in interpolated state variables,
        // otherwise for ionic current interpolation (ICI) we use the state variables of this model (node).
        if (!pStateVariables) pStateVariables = &rGetStateVariables();
        const std::vector<double>& rY = *pStateVariables;
        double var_chaste_interface__membrane__Vm = (mSetVoltageDerivativeToZero ? this->mFixedVoltage : rY[0]);
        // Units: millivolt; Initial value: -58.0
        double var_chaste_interface__I_Shkr__OShkr = rY[6];
        // Units: dimensionless; Initial value: 0.0
        
        const double var_I_b__I_b_converted = 0.001 * HeartConfig::Instance()->GetCapacitance() * mParameters[5] * var_chaste_interface__membrane__Vm / mParameters[2]; // uA_per_cm2
        const double var_I_Kir__EK = 0.086113989637305696 * mParameters[6] * log(mParameters[1] / mParameters[0]); // millivolt
        const double var_I_Kir__I_Kir_converted = 3.1622776601683795e-5 * sqrt(mParameters[1]) * (-var_I_Kir__EK + var_chaste_interface__membrane__Vm) * HeartConfig::Instance()->GetCapacitance() * mParameters[4] / ((0.93999999999999995 + exp(14.631768953068592 * (-var_I_Kir__EK + var_chaste_interface__membrane__Vm) / mParameters[6])) * mParameters[2]); // uA_per_cm2
        const double var_I_Shkr__I_Shkr_converted = 0.001 * HeartConfig::Instance()->GetCapacitance() * ((fabs(var_chaste_interface__membrane__Vm) < 8.6113989637305703e-9 * fabs(mParameters[6])) ? (58062575.210589647 * (8.6113989637305703e-9 * mParameters[6] + var_chaste_interface__membrane__Vm) * (0.0096500000000000006 * (-mParameters[1] * exp(1.0000000000000001e-7) + mParameters[0]) * var_chaste_interface__I_Shkr__OShkr * mParameters[3] / (1.0 - exp(1.0000000000000001e-7)) + 0.0096500000000000006 * (-mParameters[1] * exp(-1.0000000000000001e-7) + mParameters[0]) * var_chaste_interface__I_Shkr__OShkr * mParameters[3] / (1.0 - exp(-1.0000000000000001e-7))) / mParameters[6] - 0.0096500000000000006 * (-mParameters[1] * exp(1.0000000000000001e-7) + mParameters[0]) * var_chaste_interface__I_Shkr__OShkr * mParameters[3] / (1.0 - exp(1.0000000000000001e-7))) : (1120607.7015643802 * (-mParameters[1] * exp(-11.612515042117931 * var_chaste_interface__membrane__Vm / mParameters[6]) + mParameters[0]) * var_chaste_interface__I_Shkr__OShkr * mParameters[3] * var_chaste_interface__membrane__Vm / ((1.0 - exp(-11.612515042117931 * var_chaste_interface__membrane__Vm / mParameters[6])) * mParameters[6]))) / mParameters[2]; // uA_per_cm2
        const double var_chaste_interface__i_ionic = var_I_Kir__I_Kir_converted + var_I_Shkr__I_Shkr_converted + var_I_b__I_b_converted; // uA_per_cm2

        const double i_ionic = var_chaste_interface__i_ionic;
        EXCEPT_IF_NOT(!std::isnan(i_ionic));
        return i_ionic;
    }

    void Cellsachse_moreno_abildskov_2008_bFromCellMLOpt::EvaluateYDerivatives(double var_chaste_interface__environment__time_converted, const std::vector<double>& rY, std::vector<double>& rDY)
    {
        // Inputs:
        // Time units: millisecond
        double var_chaste_interface__membrane__Vm = (mSetVoltageDerivativeToZero ? this->mFixedVoltage : rY[0]);
        // Units: millivolt; Initial value: -58.0
        double var_chaste_interface__I_Shkr__C0Shkr = rY[1];
        // Units: dimensionless; Initial value: 0.911
        double var_chaste_interface__I_Shkr__C1Shkr = rY[2];
        // Units: dimensionless; Initial value: 0.0857
        double var_chaste_interface__I_Shkr__C2Shkr = rY[3];
        // Units: dimensionless; Initial value: 0.00302
        double var_chaste_interface__I_Shkr__C3Shkr = rY[4];
        // Units: dimensionless; Initial value: 4.74e-05
        double var_chaste_interface__I_Shkr__C4Shkr = rY[5];
        // Units: dimensionless; Initial value: 2.79e-07
        double var_chaste_interface__I_Shkr__OShkr = rY[6];
        // Units: dimensionless; Initial value: 0.0

        // Mathematics
        double d_dt_chaste_interface_var_membrane__Vm;
        const double d_dt_chaste_interface_var_I_Shkr__OShkr = 0.076999999999999999 * var_chaste_interface__I_Shkr__C4Shkr - 0.017999999999999999 * var_chaste_interface__I_Shkr__OShkr; // 1 / millisecond
        const double var_I_Shkr__k_v = 2.0 * exp(-17.767148014440433 * var_chaste_interface__membrane__Vm / mParameters[6]); // first_order_rate_constant
        const double var_I_Shkr__kv = 30.0 * exp(14.864019253910952 * var_chaste_interface__membrane__Vm / mParameters[6]); // first_order_rate_constant
        const double d_dt_chaste_interface_var_I_Shkr__C0Shkr = 0.001 * var_chaste_interface__I_Shkr__C1Shkr * var_I_Shkr__k_v - 0.0040000000000000001 * var_chaste_interface__I_Shkr__C0Shkr * var_I_Shkr__kv; // 1 / millisecond
        const double d_dt_chaste_interface_var_I_Shkr__C1Shkr = 0.002 * var_chaste_interface__I_Shkr__C2Shkr * var_I_Shkr__k_v + 0.0040000000000000001 * var_chaste_interface__I_Shkr__C0Shkr * var_I_Shkr__kv - 0.001 * (3.0 * var_I_Shkr__kv + var_I_Shkr__k_v) * var_chaste_interface__I_Shkr__C1Shkr; // 1 / millisecond
        const double d_dt_chaste_interface_var_I_Shkr__C2Shkr = 0.0030000000000000001 * var_chaste_interface__I_Shkr__C1Shkr * var_I_Shkr__kv + 0.0030000000000000001 * var_chaste_interface__I_Shkr__C3Shkr * var_I_Shkr__k_v - 0.001 * (2.0 * var_I_Shkr__k_v + 2.0 * var_I_Shkr__kv) * var_chaste_interface__I_Shkr__C2Shkr; // 1 / millisecond
        const double d_dt_chaste_interface_var_I_Shkr__C3Shkr = 0.002 * var_chaste_interface__I_Shkr__C2Shkr * var_I_Shkr__kv + 0.0040000000000000001 * var_chaste_interface__I_Shkr__C4Shkr * var_I_Shkr__k_v - 0.001 * (3.0 * var_I_Shkr__k_v + var_I_Shkr__kv) * var_chaste_interface__I_Shkr__C3Shkr; // 1 / millisecond
        const double d_dt_chaste_interface_var_I_Shkr__C4Shkr = 0.017999999999999999 * var_chaste_interface__I_Shkr__OShkr + 0.001 * var_chaste_interface__I_Shkr__C3Shkr * var_I_Shkr__kv - 0.001 * (77.0 + 4.0 * var_I_Shkr__k_v) * var_chaste_interface__I_Shkr__C4Shkr; // 1 / millisecond

        if (mSetVoltageDerivativeToZero)
        {
            d_dt_chaste_interface_var_membrane__Vm = 0.0;
        }
        else
        {
            const double var_I_Kir__EK = 0.086113989637305696 * mParameters[6] * log(mParameters[1] / mParameters[0]); // millivolt
            d_dt_chaste_interface_var_membrane__Vm = 0.001 * (-((fabs(var_chaste_interface__membrane__Vm) < 8.6113989637305703e-9 * fabs(mParameters[6])) ? (58062575.210589647 * (8.6113989637305703e-9 * mParameters[6] + var_chaste_interface__membrane__Vm) * (0.0096500000000000006 * (-mParameters[1] * exp(1.0000000000000001e-7) + mParameters[0]) * var_chaste_interface__I_Shkr__OShkr * mParameters[3] / (1.0 - exp(1.0000000000000001e-7)) + 0.0096500000000000006 * (-mParameters[1] * exp(-1.0000000000000001e-7) + mParameters[0]) * var_chaste_interface__I_Shkr__OShkr * mParameters[3] / (1.0 - exp(-1.0000000000000001e-7))) / mParameters[6] - 0.0096500000000000006 * (-mParameters[1] * exp(1.0000000000000001e-7) + mParameters[0]) * var_chaste_interface__I_Shkr__OShkr * mParameters[3] / (1.0 - exp(1.0000000000000001e-7))) : (1120607.7015643802 * (-mParameters[1] * exp(-11.612515042117931 * var_chaste_interface__membrane__Vm / mParameters[6]) + mParameters[0]) * var_chaste_interface__I_Shkr__OShkr * mParameters[3] * var_chaste_interface__membrane__Vm / ((1.0 - exp(-11.612515042117931 * var_chaste_interface__membrane__Vm / mParameters[6])) * mParameters[6]))) - mParameters[5] * var_chaste_interface__membrane__Vm - 1000.0 * GetIntracellularAreaStimulus(var_chaste_interface__environment__time_converted) * mParameters[2] / HeartConfig::Instance()->GetCapacitance() - 0.031622776601683791 * sqrt(mParameters[1]) * (-var_I_Kir__EK + var_chaste_interface__membrane__Vm) * mParameters[4] / (0.93999999999999995 + exp(14.631768953068592 * (-var_I_Kir__EK + var_chaste_interface__membrane__Vm) / mParameters[6]))) / mParameters[2]; // millivolt / millisecond
        }
        
        rDY[0] = d_dt_chaste_interface_var_membrane__Vm;
        rDY[1] = d_dt_chaste_interface_var_I_Shkr__C0Shkr;
        rDY[2] = d_dt_chaste_interface_var_I_Shkr__C1Shkr;
        rDY[3] = d_dt_chaste_interface_var_I_Shkr__C2Shkr;
        rDY[4] = d_dt_chaste_interface_var_I_Shkr__C3Shkr;
        rDY[5] = d_dt_chaste_interface_var_I_Shkr__C4Shkr;
        rDY[6] = d_dt_chaste_interface_var_I_Shkr__OShkr;
    }

    std::vector<double> Cellsachse_moreno_abildskov_2008_bFromCellMLOpt::ComputeDerivedQuantities(double var_chaste_interface__environment__time_converted, const std::vector<double> & rY)
    {
        // Inputs:
        // Time units: millisecond
        double var_chaste_interface__membrane__Vm = (mSetVoltageDerivativeToZero ? this->mFixedVoltage : rY[0]);
        // Units: millivolt; Initial value: -58.0
        double var_chaste_interface__I_Shkr__OShkr = rY[6];
        // Units: dimensionless; Initial value: 0.0
        
        // Mathematics
        const double var_I_Kir__aKir = 0.93999999999999995; // dimensionless
        const double var_I_Kir__bKir = 1.26; // dimensionless
        const double var_I_b__Eb = 0; // millivolt
        const double var_I_stim__I_stim_converted = -GetIntracellularAreaStimulus(var_chaste_interface__environment__time_converted); // uA_per_cm2
        const double var_I_b__I_b = (-var_I_b__Eb + var_chaste_interface__membrane__Vm) * mParameters[5]; // nanoampere
        const double var_I_b__I_b_converted = 0.001 * HeartConfig::Instance()->GetCapacitance() * var_I_b__I_b / mParameters[2]; // uA_per_cm2
        const double var_model_parameters__F = 96500.0; // coulomb_per_mole
        const double var_model_parameters__R = 8310.0; // millijoule_per_kelvin_mole
        const double var_I_Kir__EK = var_model_parameters__R * mParameters[6] * log(mParameters[1] / mParameters[0]) / var_model_parameters__F; // millivolt
        const double var_I_Kir__OKir = 1 / (var_I_Kir__aKir + exp((-var_I_Kir__EK + var_chaste_interface__membrane__Vm) * var_I_Kir__bKir * var_model_parameters__F / (var_model_parameters__R * mParameters[6]))); // dimensionless
        const double var_I_Kir__I_Kir = 0.031622776601683791 * sqrt(mParameters[1]) * (-var_I_Kir__EK + var_chaste_interface__membrane__Vm) * mParameters[4] * var_I_Kir__OKir; // nanoampere
        const double var_I_Kir__I_Kir_converted = 0.001 * HeartConfig::Instance()->GetCapacitance() * var_I_Kir__I_Kir / mParameters[2]; // uA_per_cm2
        const double var_I_Shkr__I_Shkr = ((fabs(var_chaste_interface__membrane__Vm) < 8.6113989637305703e-9 * fabs(mParameters[6])) ? (58062575.210589647 * (8.6113989637305703e-9 * mParameters[6] + var_chaste_interface__membrane__Vm) * (0.0096500000000000006 * (-mParameters[1] * exp(1.0000000000000001e-7) + mParameters[0]) * var_chaste_interface__I_Shkr__OShkr * mParameters[3] / (1.0 - exp(1.0000000000000001e-7)) + 0.0096500000000000006 * (-mParameters[1] * exp(-1.0000000000000001e-7) + mParameters[0]) * var_chaste_interface__I_Shkr__OShkr * mParameters[3] / (1.0 - exp(-1.0000000000000001e-7))) / mParameters[6] - 0.0096500000000000006 * (-mParameters[1] * exp(1.0000000000000001e-7) + mParameters[0]) * var_chaste_interface__I_Shkr__OShkr * mParameters[3] / (1.0 - exp(1.0000000000000001e-7))) : (1120607.7015643802 * (-mParameters[1] * exp(-11.612515042117931 * var_chaste_interface__membrane__Vm / mParameters[6]) + mParameters[0]) * var_chaste_interface__I_Shkr__OShkr * mParameters[3] * var_chaste_interface__membrane__Vm / ((1.0 - exp(-11.612515042117931 * var_chaste_interface__membrane__Vm / mParameters[6])) * mParameters[6]))); // nanoampere
        const double var_I_Shkr__I_Shkr_converted = 0.001 * HeartConfig::Instance()->GetCapacitance() * var_I_Shkr__I_Shkr / mParameters[2]; // uA_per_cm2

        std::vector<double> dqs(5);
        dqs[0] = var_I_Shkr__I_Shkr_converted;
        dqs[1] = var_I_Kir__I_Kir_converted;
        dqs[2] = var_I_b__I_b_converted;
        dqs[3] = var_I_stim__I_stim_converted;
        dqs[4] = var_chaste_interface__environment__time_converted;
        return dqs;
    }

template<>
void OdeSystemInformation<Cellsachse_moreno_abildskov_2008_bFromCellMLOpt>::Initialise(void)
{
    this->mSystemName = "sachse_model_2007";
    this->mFreeVariableName = "time";
    this->mFreeVariableUnits = "millisecond";

    // rY[0]:
    this->mVariableNames.push_back("membrane_voltage");
    this->mVariableUnits.push_back("millivolt");
    this->mInitialConditions.push_back(-58.0);

    // rY[1]:
    this->mVariableNames.push_back("I_Shkr__C0Shkr");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(0.911);

    // rY[2]:
    this->mVariableNames.push_back("I_Shkr__C1Shkr");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(0.0857);

    // rY[3]:
    this->mVariableNames.push_back("I_Shkr__C2Shkr");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(0.00302);

    // rY[4]:
    this->mVariableNames.push_back("I_Shkr__C3Shkr");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(4.74e-05);

    // rY[5]:
    this->mVariableNames.push_back("I_Shkr__C4Shkr");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(2.79e-07);

    // rY[6]:
    this->mVariableNames.push_back("I_Shkr__OShkr");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(0.0);

    // mParameters[0]:
    this->mParameterNames.push_back("cytosolic_potassium_concentration");
    this->mParameterUnits.push_back("millimolar");

    // mParameters[1]:
    this->mParameterNames.push_back("extracellular_potassium_concentration");
    this->mParameterUnits.push_back("millimolar");

    // mParameters[2]:
    this->mParameterNames.push_back("membrane_capacitance");
    this->mParameterUnits.push_back("microfarad");

    // mParameters[3]:
    this->mParameterNames.push_back("membrane_delayed_rectifier_potassium_current_conductance");
    this->mParameterUnits.push_back("microlitre_per_second");

    // mParameters[4]:
    this->mParameterNames.push_back("membrane_inward_rectifier_potassium_current_conductance");
    this->mParameterUnits.push_back("microsiemens");

    // mParameters[5]:
    this->mParameterNames.push_back("membrane_leakage_current_conductance");
    this->mParameterUnits.push_back("microsiemens");

    // mParameters[6]:
    this->mParameterNames.push_back("temperature");
    this->mParameterUnits.push_back("kelvin");

    // Derived Quantity index [0]:
    this->mDerivedQuantityNames.push_back("membrane_delayed_rectifier_potassium_current");
    this->mDerivedQuantityUnits.push_back("uA_per_cm2");

    // Derived Quantity index [1]:
    this->mDerivedQuantityNames.push_back("membrane_inward_rectifier_potassium_current");
    this->mDerivedQuantityUnits.push_back("uA_per_cm2");

    // Derived Quantity index [2]:
    this->mDerivedQuantityNames.push_back("membrane_leakage_current");
    this->mDerivedQuantityUnits.push_back("uA_per_cm2");

    // Derived Quantity index [3]:
    this->mDerivedQuantityNames.push_back("membrane_stimulus_current");
    this->mDerivedQuantityUnits.push_back("uA_per_cm2");

    // Derived Quantity index [4]:
    this->mDerivedQuantityNames.push_back("time");
    this->mDerivedQuantityUnits.push_back("millisecond");

    this->mInitialised = true;
}

// Serialization for Boost >= 1.36
#include "SerializationExportWrapperForCpp.hpp"
CHASTE_CLASS_EXPORT(Cellsachse_moreno_abildskov_2008_bFromCellMLOpt)

