#ifndef CELLDOKOS_MODEL_1996FROMCELLML_HPP_
#define CELLDOKOS_MODEL_1996FROMCELLML_HPP_

//! @file
//! 
//! This source file was generated from CellML by chaste_codegen version 0.0.1
//! 
//! Model: dokos_model_1996
//! 
//! Processed by chaste_codegen: https://github.com/ModellingWebLab/chaste-codegen
//!     (translator: chaste_codegen, model type: normal, options: )
//! on 2020-01-29 20:21:40
//! 
//! <autogenerated>

#include "ChasteSerialization.hpp"
#include <boost/serialization/base_object.hpp>
#include "AbstractCardiacCell.hpp"

#include "AbstractStimulusFunction.hpp"

class Celldokos_model_1996FromCellML : public AbstractCardiacCell
{
    friend class boost::serialization::access;
    template<class Archive>
    void serialize(Archive & archive, const unsigned int version)
    {
        archive & boost::serialization::base_object<AbstractCardiacCell >(*this);
        
    }
    
    // 
    // Settable parameters and readable variables
    // 
    
public:
    double GetIntracellularCalciumConcentration();
    Celldokos_model_1996FromCellML(boost::shared_ptr<AbstractIvpOdeSolver> pSolver, boost::shared_ptr<AbstractStimulusFunction> pIntracellularStimulus);
    ~Celldokos_model_1996FromCellML();
    double GetIIonic(const std::vector<double>* pStateVariables=NULL);
    void EvaluateYDerivatives(double var_chaste_interface__environment__time_converted, const std::vector<double>& rY, std::vector<double>& rDY);
};


// Needs to be included last
#include "SerializationExportWrapper.hpp"
CHASTE_CLASS_EXPORT(Celldokos_model_1996FromCellML)

namespace boost
{
    namespace serialization
    {
        template<class Archive>
        inline void save_construct_data(
            Archive & ar, const Celldokos_model_1996FromCellML * t, const unsigned int fileVersion)
        {
            const boost::shared_ptr<AbstractIvpOdeSolver> p_solver = t->GetSolver();
            const boost::shared_ptr<AbstractStimulusFunction> p_stimulus = t->GetStimulusFunction();
            ar << p_solver;
            ar << p_stimulus;
        }
        
        template<class Archive>
        inline void load_construct_data(
            Archive & ar, Celldokos_model_1996FromCellML * t, const unsigned int fileVersion)
        {
            boost::shared_ptr<AbstractIvpOdeSolver> p_solver;
            boost::shared_ptr<AbstractStimulusFunction> p_stimulus;
            ar >> p_solver;
            ar >> p_stimulus;
            ::new(t)Celldokos_model_1996FromCellML(p_solver, p_stimulus);
        }
        
    }
    
}

#endif // CELLDOKOS_MODEL_1996FROMCELLML_HPP_