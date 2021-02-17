#ifndef CELLPASEK_SIMURDA_ORCHARD_CHRISTE_2008FROMCELLMLBACKWARDEULERNOLUT_HPP_
#define CELLPASEK_SIMURDA_ORCHARD_CHRISTE_2008FROMCELLMLBACKWARDEULERNOLUT_HPP_

//! @file
//!
//! This source file was generated from CellML by chaste_codegen version (version omitted as unimportant)
//!
//! Model: pasek_model_2008
//!
//! Processed by chaste_codegen: https://github.com/ModellingWebLab/chaste-codegen
//!     (translator: chaste_codegen, model type: BackwardEuler)
//! on (date omitted as unimportant)
//!
//! <autogenerated>

#include "ChasteSerialization.hpp"
#include <boost/serialization/base_object.hpp>
#include "AbstractStimulusFunction.hpp"
#include "AbstractBackwardEulerCardiacCell.hpp"

class Cellpasek_simurda_orchard_christe_2008FromCellMLBackwardEulerNoLut : public AbstractBackwardEulerCardiacCell<47>
{
    friend class boost::serialization::access;
    template<class Archive>
    void serialize(Archive & archive, const unsigned int version)
    {
        archive & boost::serialization::base_object<AbstractBackwardEulerCardiacCell<47> >(*this);
        
    }

    //
    // Settable parameters and readable variables
    //

public:

    boost::shared_ptr<RegularStimulus> UseCellMLDefaultStimulus();
    double GetIntracellularCalciumConcentration();
    Cellpasek_simurda_orchard_christe_2008FromCellMLBackwardEulerNoLut(boost::shared_ptr<AbstractIvpOdeSolver> /* unused; should be empty */, boost::shared_ptr<AbstractStimulusFunction> pIntracellularStimulus);
    ~Cellpasek_simurda_orchard_christe_2008FromCellMLBackwardEulerNoLut();
    double GetIIonic(const std::vector<double>* pStateVariables=NULL);void ComputeResidual(double var_chaste_interface__environment__time_converted, const double rCurrentGuess[47], double rResidual[47]);
    void ComputeJacobian(double var_chaste_interface__environment__time_converted, const double rCurrentGuess[47], double rJacobian[47][47]);protected:
    void UpdateTransmembranePotential(double var_chaste_interface__environment__time_converted);
    void ComputeOneStepExceptVoltage(double var_chaste_interface__environment__time_converted);

    std::vector<double> ComputeDerivedQuantities(double var_chaste_interface__environment__time_converted, const std::vector<double> & rY);
};

// Needs to be included last
#include "SerializationExportWrapper.hpp"
CHASTE_CLASS_EXPORT(Cellpasek_simurda_orchard_christe_2008FromCellMLBackwardEulerNoLut)

namespace boost
{
    namespace serialization
    {
        template<class Archive>
        inline void save_construct_data(
            Archive & ar, const Cellpasek_simurda_orchard_christe_2008FromCellMLBackwardEulerNoLut * t, const unsigned int fileVersion)
        {
            const boost::shared_ptr<AbstractIvpOdeSolver> p_solver = t->GetSolver();
            const boost::shared_ptr<AbstractStimulusFunction> p_stimulus = t->GetStimulusFunction();
            ar << p_solver;
            ar << p_stimulus;
        }

        template<class Archive>
        inline void load_construct_data(
            Archive & ar, Cellpasek_simurda_orchard_christe_2008FromCellMLBackwardEulerNoLut * t, const unsigned int fileVersion)
        {
            boost::shared_ptr<AbstractIvpOdeSolver> p_solver;
            boost::shared_ptr<AbstractStimulusFunction> p_stimulus;
            ar >> p_solver;
            ar >> p_stimulus;
            ::new(t)Cellpasek_simurda_orchard_christe_2008FromCellMLBackwardEulerNoLut(p_solver, p_stimulus);
        }

    }

}

#endif // CELLPASEK_SIMURDA_ORCHARD_CHRISTE_2008FROMCELLMLBACKWARDEULERNOLUT_HPP_