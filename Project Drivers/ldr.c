 /******************************************************************************
 *
 * Module: LDR
 *
 * File Name: ldr.c
 *
 * Description: Source file for the ATmega16 LDR driver
 *
 * Author: Medhat Adel Tawfik
 *
 *******************************************************************************/

#include "ADC.h"
#include "gpio.h"
#define LDR_CHANNEL 0

uint16 LDR_getLightIntensity(void) {

    GPIO_setupPinDirection(PORTA_ID, PIN0_ID, PIN_INPUT);
    uint16 adc_value = ADC_readChannel(LDR_CHANNEL);
    uint16 light_intensity = ((uint32)adc_value * 100) / 1024;  // Convert to percentage
    return light_intensity;
}
