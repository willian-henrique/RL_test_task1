#ifndef ADC_CONVERT_H
#define ADC_CONVERT_H

#include "type_def.h"

uint_16 convert_adc_to_kPa(uint_16 adc, uint_16 *scalar, uint_16 *fractional);

#endif