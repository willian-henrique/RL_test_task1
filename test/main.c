#include <stdio.h>
#include "../src/adc_convert.h"

int main() {

    uint_16 scalar, fractional;
    uint_16 conversion_ret = 0;

    scalar = 0;
    fractional = 0;

    conversion_ret = convert_adc_to_kPa(2500, &scalar, &fractional);
    printf("basic test 2500 ADC: %d, %d, %d\n\n", conversion_ret, scalar, fractional);
    conversion_ret = convert_adc_to_kPa(13000, &scalar, &fractional);
    printf("basic test 13000 ADC: %d, %d, %d\n\n", conversion_ret, scalar, fractional);
    conversion_ret = convert_adc_to_kPa(14073, &scalar, &fractional);
    printf("basic test 14073 ADC: %d, %d, %d\n", conversion_ret, scalar, fractional);
    conversion_ret = convert_adc_to_kPa(1696, &scalar, &fractional);
    printf("basic test 1696 ADC: %d, %d, %d\n\n", conversion_ret, scalar, fractional);
    conversion_ret = convert_adc_to_kPa(1697, &scalar, &fractional);
    printf("basic test 1697 ADC: %d, %d, %d\n\n", conversion_ret, scalar, fractional);
    conversion_ret = convert_adc_to_kPa(4444, &scalar, &fractional);
    printf("basic test 4444 ADC: %d, %d, %d\n\n", conversion_ret, scalar, fractional);
    conversion_ret = convert_adc_to_kPa(63666, &scalar, &fractional);
    printf("basic test 63666 ADC: %d, %d, %d\n\n", conversion_ret, scalar, fractional);
    conversion_ret = convert_adc_to_kPa(66, &scalar, &fractional);
    printf("basic test 66 ADC: %d, %d, %d\n\n", conversion_ret, scalar, fractional);
   return 0;
}
