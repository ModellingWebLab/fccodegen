#ifdef CHASTE_CVODE
#ifndef CELLNOBLE_SAN_MODEL_1989FROMCELLMLCVODE_HPP_
#define CELLNOBLE_SAN_MODEL_1989FROMCELLMLCVODE_HPP_

//! @file
//!
//! This source file was generated from CellML by chaste_codegen version 0.0.1
//!
//! Model: Noble_SAN_model_1989
//!
//! Processed by chaste_codegen: https://github.com/ModellingWebLab/chaste-codegen
//!     (translator: chaste_codegen)
//! on 2020-03-04 13:52:13
//!
//! <autogenerated>

#include "ChasteSerialization.hpp"
#include <boost/serialization/base_object.hpp>

#include "AbstractStimulusFunction.hpp"
#include "AbstractCvodeCell.hpp"

class Cellnoble_SAN_model_1989FromCellMLCvode : public AbstractCvodeCell
{
    friend class boost::serialization::access;
    template<class Archive>
    void serialize(Archive & archive, const unsigned int version)
    {
        archive & boost::serialization::base_object<AbstractCvodeCell >(*this);
        
    }
    
    // 
    // Settable parameters and readable variables
    // 
    
public:

    double GetIntracellularCalciumConcentration();
    Cellnoble_SAN_model_1989FromCellMLCvode(boost::shared_ptr<AbstractIvpOdeSolver> pOdeSolver /* unused; should be empty */, boost::shared_ptr<AbstractStimulusFunction> pIntracellularStimulus);
    ~Cellnoble_SAN_model_1989FromCellMLCvode();
    double GetIIonic(const std::vector<double>* pStateVariables=NULL);
    void EvaluateYDerivatives(double var_chaste_interface__environment__time_converted, const N_Vector rY, N_Vector rDY);
};

// Needs to be included last
#include "SerializationExportWrapper.hpp"
CHASTE_CLASS_EXPORT(Cellnoble_SAN_model_1989FromCellMLCvode)

namespace boost
{
    namespace serialization
    {
        template<class Archive>
        inline void save_construct_data(
            Archive & ar, const Cellnoble_SAN_model_1989FromCellMLCvode * t, const unsigned int fileVersion)
        {
            const boost::shared_ptr<AbstractIvpOdeSolver> p_solver = t->GetSolver();
            const boost::shared_ptr<AbstractStimulusFunction> p_stimulus = t->GetStimulusFunction();
            ar << p_solver;
            ar << p_stimulus;
        }

        template<class Archive>
        inline void load_construct_data(
            Archive & ar, Cellnoble_SAN_model_1989FromCellMLCvode * t, const unsigned int fileVersion)
        {
            boost::shared_ptr<AbstractIvpOdeSolver> p_solver;
            boost::shared_ptr<AbstractStimulusFunction> p_stimulus;
            ar >> p_solver;
            ar >> p_stimulus;
            ::new(t)Cellnoble_SAN_model_1989FromCellMLCvode(p_solver, p_stimulus);
        }

    }

}

#endif // CELLNOBLE_SAN_MODEL_1989FROMCELLMLCVODE_HPP_
#endif // CHASTE_CVODE
