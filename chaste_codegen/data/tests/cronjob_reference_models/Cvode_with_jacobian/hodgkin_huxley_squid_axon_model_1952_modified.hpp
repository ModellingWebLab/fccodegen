#ifdef CHASTE_CVODE
#ifndef CELLHODGKIN_HUXLEY_SQUID_AXON_MODEL_1952_MODIFIEDFROMCELLMLCVODE_HPP_
#define CELLHODGKIN_HUXLEY_SQUID_AXON_MODEL_1952_MODIFIEDFROMCELLMLCVODE_HPP_

//! @file
//!
//! This source file was generated from CellML by chaste_codegen version 0.0.1
//!
//! Model: hodgkin_huxley_squid_axon_model_1952_modified
//!
//! Processed by chaste_codegen: https://github.com/ModellingWebLab/chaste-codegen
//!     (translator: chaste_codegen, model type: CVODE )
//! on 2020-02-26 09:03:52
//!
//! <autogenerated>

#include "ChasteSerialization.hpp"
#include <boost/serialization/base_object.hpp>
#include "AbstractCvodeCell.hpp"

#include "AbstractStimulusFunction.hpp"

class Cellhodgkin_huxley_squid_axon_model_1952_modifiedFromCellMLCvode : public AbstractCvodeCell
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
    Cellhodgkin_huxley_squid_axon_model_1952_modifiedFromCellMLCvode(boost::shared_ptr<AbstractIvpOdeSolver> pOdeSolver /* unused; should be empty */, boost::shared_ptr<AbstractStimulusFunction> pIntracellularStimulus);
    ~Cellhodgkin_huxley_squid_axon_model_1952_modifiedFromCellMLCvode();
    double GetIIonic(const std::vector<double>* pStateVariables=NULL);
    void EvaluateYDerivatives(double var_chaste_interface__environment__time, const N_Vector rY, N_Vector rDY);
    void EvaluateAnalyticJacobian(double var_chaste_interface__environment__time, N_Vector rY, N_Vector rDY, CHASTE_CVODE_DENSE_MATRIX rJacobian, N_Vector rTmp1, N_Vector rTmp2, N_Vector rTmp3);
};


// Needs to be included last
#include "SerializationExportWrapper.hpp"
CHASTE_CLASS_EXPORT(Cellhodgkin_huxley_squid_axon_model_1952_modifiedFromCellMLCvode)

namespace boost
{
    namespace serialization
    {
        template<class Archive>
        inline void save_construct_data(
            Archive & ar, const Cellhodgkin_huxley_squid_axon_model_1952_modifiedFromCellMLCvode * t, const unsigned int fileVersion)
        {
            const boost::shared_ptr<AbstractIvpOdeSolver> p_solver = t->GetSolver();
            const boost::shared_ptr<AbstractStimulusFunction> p_stimulus = t->GetStimulusFunction();
            ar << p_solver;
            ar << p_stimulus;
        }
        
        template<class Archive>
        inline void load_construct_data(
            Archive & ar, Cellhodgkin_huxley_squid_axon_model_1952_modifiedFromCellMLCvode * t, const unsigned int fileVersion)
        {
            boost::shared_ptr<AbstractIvpOdeSolver> p_solver;
            boost::shared_ptr<AbstractStimulusFunction> p_stimulus;
            ar >> p_solver;
            ar >> p_stimulus;
            ::new(t)Cellhodgkin_huxley_squid_axon_model_1952_modifiedFromCellMLCvode(p_solver, p_stimulus);
        }
        
    }
    
}

#endif // CELLHODGKIN_HUXLEY_SQUID_AXON_MODEL_1952_MODIFIEDFROMCELLMLCVODE_HPP_
#endif // CHASTE_CVODE

