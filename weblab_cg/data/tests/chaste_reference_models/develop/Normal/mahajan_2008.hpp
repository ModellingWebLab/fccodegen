#ifndef DYNAMICMAHAJAN_2008FROMCELLML_HPP_
#define DYNAMICMAHAJAN_2008FROMCELLML_HPP_

//! @file
//! 
//! This source file was generated from CellML.
//! 
//! Model: mahajan_shiferaw_model_2008
//! 
//! Processed by pycml - CellML Tools in Python
//!     (translators: , pycml: , optimize: )
//! on Wed Sep 11 11:22:49 2019
//! 
//! <autogenerated>

#include "ChasteSerialization.hpp"
#include <boost/serialization/base_object.hpp>
#include "AbstractCardiacCell.hpp"
#include "AbstractDynamicallyLoadableEntity.hpp"
#include "AbstractStimulusFunction.hpp"

class Dynamicmahajan_2008FromCellML : public AbstractCardiacCell, public AbstractDynamicallyLoadableEntity
{
    friend class boost::serialization::access;
    template<class Archive>
    void serialize(Archive & archive, const unsigned int version)
    {
        archive & boost::serialization::base_object<AbstractCardiacCell >(*this);
        archive & boost::serialization::base_object<AbstractDynamicallyLoadableEntity>(*this);
    }
    
    // 
    // Settable parameters and readable variables
    // 
    
public:
    boost::shared_ptr<RegularStimulus> UseCellMLDefaultStimulus();
    double GetIntracellularCalciumConcentration();
    Dynamicmahajan_2008FromCellML(boost::shared_ptr<AbstractIvpOdeSolver> pSolver, boost::shared_ptr<AbstractStimulusFunction> pIntracellularStimulus);
    ~Dynamicmahajan_2008FromCellML();
    double GetIIonic(const std::vector<double>* pStateVariables=NULL);
    void EvaluateYDerivatives(double var_chaste_interface__Environment__time, const std::vector<double>& rY, std::vector<double>& rDY);
};


// Needs to be included last
#include "SerializationExportWrapper.hpp"
CHASTE_CLASS_EXPORT(Dynamicmahajan_2008FromCellML)

namespace boost
{
    namespace serialization
    {
        template<class Archive>
        inline void save_construct_data(
            Archive & ar, const Dynamicmahajan_2008FromCellML * t, const unsigned int fileVersion)
        {
            const boost::shared_ptr<AbstractIvpOdeSolver> p_solver = t->GetSolver();
            const boost::shared_ptr<AbstractStimulusFunction> p_stimulus = t->GetStimulusFunction();
            ar << p_solver;
            ar << p_stimulus;
        }
        
        template<class Archive>
        inline void load_construct_data(
            Archive & ar, Dynamicmahajan_2008FromCellML * t, const unsigned int fileVersion)
        {
            boost::shared_ptr<AbstractIvpOdeSolver> p_solver;
            boost::shared_ptr<AbstractStimulusFunction> p_stimulus;
            ar >> p_solver;
            ar >> p_stimulus;
            ::new(t)Dynamicmahajan_2008FromCellML(p_solver, p_stimulus);
        }
        
    }
    
}

#endif // DYNAMICMAHAJAN_2008FROMCELLML_HPP_