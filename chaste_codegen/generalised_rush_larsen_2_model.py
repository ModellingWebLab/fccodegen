from chaste_codegen.generalised_rush_larsen_1_model import GeneralisedRushLarsenFirstOrderModel


class GeneralisedRushLarsenSecondOrderModel(GeneralisedRushLarsenFirstOrderModel):
    """ Holds template and information specific for the GeneralisedRushLarsen model type"""

    def __init__(self, model, file_name, **kwargs):
        super().__init__(model, file_name, **kwargs)
        self._vars_for_template['model_type'] = 'GeneralizedRushLarsenSecondOrder'
        self._templates = ['generalised_rush_larsen_model_2.cpp', 'generalised_rush_larsen_model.hpp']
