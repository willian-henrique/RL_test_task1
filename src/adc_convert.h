#ifndef ADC_CONVERT_H
#define ADC_CONVERT_H

#include "type_def.h"


/**
 * This function convert ADC value to kPa pressure, it was optimized to work with 
 * 
 * @param ADC value
 * @param scalar pointer to calculed scalar
 * @param fractional pointer to calculed fraction 
 * @return The return value indicate the conversion state, where:
 *          0 - success.
 *          1 - ADC lower than accepted value.
 *          2 - ADC higher than accepted value.
 */
uint_16 convert_adc_to_kPa(uint_16 adc, uint_16 *scalar, uint_16 *fractional);

#endif