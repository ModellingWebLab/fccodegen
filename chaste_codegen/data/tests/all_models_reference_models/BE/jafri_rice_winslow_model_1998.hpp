#ifndef CELLJAFRI_RICE_WINSLOW_MODEL_1998FROMCELLMLBACKWARDEULERNOLUT_HPP_
#define CELLJAFRI_RICE_WINSLOW_MODEL_1998FROMCELLMLBACKWARDEULERNOLUT_HPP_

//! @file
//!
//! This source file was generated from CellML by chaste_codegen version (version omitted as unimportant)
//!
//! Model: jafri_rice_winslow_1998
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

class Celljafri_rice_winslow_model_1998FromCellMLBackwardEulerNoLut : public AbstractBackwardEulerCardiacCell<25>
{
    friend class boost::serialization::access;
    template<class Archive>
    void serialize(Archive & archive, const unsigned int version)
    {
        archive & boost::serialization::base_object<AbstractBackwardEulerCardiacCell<25> >(*this);
        
    }

    //
    // Settable parameters and readable variables
    //

public:

    boost::shared_ptr<RegularStimulus> UseCellMLDefaultStimulus();
    double GetIntracellularCalciumConcentration();
    Celljafri_rice_winslow_model_1998FromCellMLBackwardEulerNoLut(boost::shared_ptr<AbstractIvpOdeSolver> /* unused; should be empty */, boost::shared_ptr<AbstractStimulusFunction> pIntracellularStimulus);
    ~Celljafri_rice_winslow_model_1998FromCellMLBackwardEulerNoLut();
    double GetIIonic(const std::vector<double>* pStateVariables=NULL);void ComputeResidual(double var_chaste_interface__environment__time, const double rCurrentGuess[25], double rResidual[25]);
    void ComputeJacobian(double var_chaste_interface__environment__time, const double rCurrentGuess[25], double rJacobian[25][25]);protected:
    void UpdateTransmembranePotential(double var_chaste_interface__environment__time);
    void ComputeOneStepExceptVoltage(double var_chaste_interface__environment__time);

    std::vector<double> ComputeDerivedQuantities(double var_chaste_interface__environment__time, const std::vector<double> & rY);
};

// Needs to be included last
#include "SerializationExportWrapper.hpp"
CHASTE_CLASS_EXPORT(Celljafri_rice_winslow_model_1998FromCellMLBackwardEulerNoLut)

namespace boost
{
    namespace serialization
    {
        template<class Archive>
        inline void save_construct_data(
            Archive & ar, const Celljafri_rice_winslow_model_1998FromCellMLBackwardEulerNoLut * t, const unsigned int fileVersion)
        {
            const boost::shared_ptr<AbstractIvpOdeSolver> p_solver = t->GetSolver();
            const boost::shared_ptr<AbstractStimulusFunction> p_stimulus = t->GetStimulusFunction();
            ar << p_solver;
            ar << p_stimulus;
        }

        template<class Archive>
        inline void load_construct_data(
            Archive & ar, Celljafri_rice_winslow_model_1998FromCellMLBackwardEulerNoLut * t, const unsigned int fileVersion)
        {
            boost::shared_ptr<AbstractIvpOdeSolver> p_solver;
            boost::shared_ptr<AbstractStimulusFunction> p_stimulus;
            ar >> p_solver;
            ar >> p_stimulus;
            ::new(t)Celljafri_rice_winslow_model_1998FromCellMLBackwardEulerNoLut(p_solver, p_stimulus);
        }

    }

}

#endif // CELLJAFRI_RICE_WINSLOW_MODEL_1998FROMCELLMLBACKWARDEULERNOLUT_HPP_