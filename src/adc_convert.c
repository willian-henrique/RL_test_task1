
#include "adc_convert.h"
#include <stdio.h>

#define SIZE_OF_LOOP_UP_TABLE           91

typedef struct {
    uint_16 kPa;
    uint_16 adc;
} kpa_adc_relation;

static kpa_adc_relation adc_to_kPa_table[SIZE_OF_LOOP_UP_TABLE] = {
{ 100, 1696 },
{ 110, 1909 },
{ 120, 2118 },
{ 130, 2272 },
{ 140, 2366 },
{ 150, 2448 },
{ 160, 2570 },
{ 170, 2745 },
{ 180, 2931 },
{ 190, 3073 },
{ 200, 3151 },
{ 210, 3200 },
{ 220, 3278 },
{ 230, 3411 },
{ 240, 3573 },
{ 250, 3706 },
{ 260, 3777 },
{ 270, 3808 },
{ 280, 3853 },
{ 290, 3955 },
{ 300, 4100 },
{ 310, 4236 },
{ 320, 4316 },
{ 330, 4348 },
{ 340, 4382 },
{ 350, 4468 },
{ 360, 4610 },
{ 370, 4762 },
{ 380, 4871 },
{ 390, 4927 },
{ 400, 4971 },
{ 410, 5058 },
{ 420, 5210 },
{ 430, 5390 },
{ 440, 5541 },
{ 450, 5639 },
{ 460, 5710 },
{ 470, 5812 },
{ 480, 5979 },
{ 490, 6190 },
{ 500, 6389 },
{ 510, 6534 },
{ 520, 6641 },
{ 530, 6762 },
{ 540, 6943 },
{ 550, 7177 },
{ 560, 7414 },
{ 570, 7604 },
{ 580, 7743 },
{ 590, 7877 },
{ 600, 8060 },
{ 610, 8302 },
{ 620, 8560 },
{ 630, 8778 },
{ 640, 8938 },
{ 650, 9074 },
{ 660, 9243 },
{ 670, 9470 },
{ 680, 9726 },
{ 690, 9954 },
{ 700, 10119 },
{ 710, 10244 },
{ 720, 10383 },
{ 730, 10577 },
{ 740, 10810 },
{ 750, 11028 },
{ 760, 11187 },
{ 770, 11292 },
{ 780, 11394 },
{ 790, 11542 },
{ 800, 11739 },
{ 810, 11937 },
{ 820, 12085 },
{ 830, 12170 },
{ 840, 12237 },
{ 850, 12340 },
{ 860, 12498 },
{ 870, 12675 },
{ 880, 12815 },
{ 890, 12893 },
{ 900, 12938 },
{ 910, 13007 },
{ 920, 13135 },
{ 930, 13299 },
{ 940, 13444 },
{ 950, 13531 },
{ 960, 13575 },
{ 970, 13631 },
{ 980, 13744 },
{ 990, 13908 },
{ 1000, 14073 }
};

uint_16 convert_adc_to_kPa(uint_16 adc, uint_16 *scalar, uint_16 *fractional){

    uint_16 pos_in_vector = 0xffff;
    uint_16 diff_range_kPa = 0;
    uint_16 diff_range_adc = 0;
    uint_16 diff_adc = 0;
    uint_16 scalar_kPa;
    uint_32 fraction_part = 0;

    if(adc < 1696){
        *scalar = 0;
        *fractional = 0;
        return 1;
    }
    if(adc > 14073){
        *scalar = 0;
        *fractional = 0;
        return 2;
    }
    if(adc == 14073){
        *scalar = 1000;
        *fractional = 0;
        return 0;
    }
    for (uint_16 i = 0; i < SIZE_OF_LOOP_UP_TABLE - 1; i++){
        if(adc >= adc_to_kPa_table[i].adc && adc < adc_to_kPa_table[i + 1].adc ){
            pos_in_vector = i;
            break;
        }
    }
    diff_range_adc = adc_to_kPa_table[pos_in_vector + 1].adc - adc_to_kPa_table[pos_in_vector].adc;
    diff_range_kPa = adc_to_kPa_table[pos_in_vector + 1].kPa - adc_to_kPa_table[pos_in_vector].kPa;
    diff_adc = adc - adc_to_kPa_table[pos_in_vector].adc;
    scalar_kPa = ((uint_32)diff_adc*1000)/(((uint_32)diff_range_adc*1000)/diff_range_kPa);
    fraction_part = ((((uint_32)diff_range_kPa*100000)/diff_range_adc)*diff_adc) - (uint_32)scalar_kPa*100000 ;

    *scalar = adc_to_kPa_table[pos_in_vector].kPa + scalar_kPa;
    *fractional = (uint_16) fraction_part/100;
    return 0;
}
