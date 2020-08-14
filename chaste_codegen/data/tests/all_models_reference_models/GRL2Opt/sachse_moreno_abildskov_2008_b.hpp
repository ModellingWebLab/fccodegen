#ifndef CELLSACHSE_MORENO_ABILDSKOV_2008_BFROMCELLMLGRL2OPT_HPP_
#define CELLSACHSE_MORENO_ABILDSKOV_2008_BFROMCELLMLGRL2OPT_HPP_

//! @file
//!
//! This source file was generated from CellML by chaste_codegen version (version omitted as unimportant)
//!
//! Model: sachse_model_2007
//!
//! Processed by chaste_codegen: https://github.com/ModellingWebLab/chaste-codegen
//!     (translator: chaste_codegen, model type: GeneralizedRushLarsenSecondOrderOpt)
//! on (date omitted as unimportant)
//!
//! <autogenerated>

#include "ChasteSerialization.hpp"
#include <boost/serialization/base_object.hpp>
#include "AbstractStimulusFunction.hpp"
#include "AbstractGeneralizedRushLarsenCardiacCell.hpp"

class Cellsachse_moreno_abildskov_2008_bFromCellMLGRL2Opt : public AbstractGeneralizedRushLarsenCardiacCell
{
    friend class boost::serialization::access;
    template<class Archive>
    void serialize(Archive & archive, const unsigned int version)
    {
        archive & boost::serialization::base_object<AbstractGeneralizedRushLarsenCardiacCell >(*this);
        
    }

    //
    // Settable parameters and readable variables
    //

public:

    boost::shared_ptr<RegularStimulus> UseCellMLDefaultStimulus();
    Cellsachse_moreno_abildskov_2008_bFromCellMLGRL2Opt(boost::shared_ptr<AbstractIvpOdeSolver> /* unused; should be empty */, boost::shared_ptr<AbstractStimulusFunction> pIntracellularStimulus);
    ~Cellsachse_moreno_abildskov_2008_bFromCellMLGRL2Opt();
    double GetIIonic(const std::vector<double>* pStateVariables=NULL);
    void UpdateTransmembranePotential(double var_chaste_interface__environment__time_converted);
    void ComputeOneStepExceptVoltage(double var_chaste_interface__environment__time_converted);
    
    double EvaluateYDerivative0(double var_chaste_interface__environment__time_converted, std::vector<double>& rY);
    double EvaluatePartialDerivative0(double var_chaste_interface__environment__time_converted, std::vector<double>& rY, double delta, bool forceNumerical=false);
    double EvaluateYDerivative1(double var_chaste_interface__environment__time_converted, std::vector<double>& rY);
    double EvaluatePartialDerivative1(double var_chaste_interface__environment__time_converted, std::vector<double>& rY, double delta, bool forceNumerical=false);
    double EvaluateYDerivative2(double var_chaste_interface__environment__time_converted, std::vector<double>& rY);
    double EvaluatePartialDerivative2(double var_chaste_interface__environment__time_converted, std::vector<double>& rY, double delta, bool forceNumerical=false);
    double EvaluateYDerivative3(double var_chaste_interface__environment__time_converted, std::vector<double>& rY);
    double EvaluatePartialDerivative3(double var_chaste_interface__environment__time_converted, std::vector<double>& rY, double delta, bool forceNumerical=false);
    double EvaluateYDerivative4(double var_chaste_interface__environment__time_converted, std::vector<double>& rY);
    double EvaluatePartialDerivative4(double var_chaste_interface__environment__time_converted, std::vector<double>& rY, double delta, bool forceNumerical=false);
    double EvaluateYDerivative5(double var_chaste_interface__environment__time_converted, std::vector<double>& rY);
    double EvaluatePartialDerivative5(double var_chaste_interface__environment__time_converted, std::vector<double>& rY, double delta, bool forceNumerical=false);
    double EvaluateYDerivative6(double var_chaste_interface__environment__time_converted, std::vector<double>& rY);
    double EvaluatePartialDerivative6(double var_chaste_interface__environment__time_converted, std::vector<double>& rY, double delta, bool forceNumerical=false);

    std::vector<double> ComputeDerivedQuantities(double var_chaste_interface__environment__time_converted, const std::vector<double> & rY);
};

// Needs to be included last
#include "SerializationExportWrapper.hpp"
CHASTE_CLASS_EXPORT(Cellsachse_moreno_abildskov_2008_bFromCellMLGRL2Opt)

namespace boost
{
    namespace serialization
    {
        template<class Archive>
        inline void save_construct_data(
            Archive & ar, const Cellsachse_moreno_abildskov_2008_bFromCellMLGRL2Opt * t, const unsigned int fileVersion)
        {
            const boost::shared_ptr<AbstractIvpOdeSolver> p_solver = t->GetSolver();
            const boost::shared_ptr<AbstractStimulusFunction> p_stimulus = t->GetStimulusFunction();
            ar << p_solver;
            ar << p_stimulus;
        }

        template<class Archive>
        inline void load_construct_data(
            Archive & ar, Cellsachse_moreno_abildskov_2008_bFromCellMLGRL2Opt * t, const unsigned int fileVersion)
        {
            boost::shared_ptr<AbstractIvpOdeSolver> p_solver;
            boost::shared_ptr<AbstractStimulusFunction> p_stimulus;
            ar >> p_solver;
            ar >> p_stimulus;
            ::new(t)Cellsachse_moreno_abildskov_2008_bFromCellMLGRL2Opt(p_solver, p_stimulus);
        }

    }

}

#endif // CELLSACHSE_MORENO_ABILDSKOV_2008_BFROMCELLMLGRL2OPT_HPP_