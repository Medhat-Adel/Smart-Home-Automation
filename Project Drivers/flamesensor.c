 /******************************************************************************
 *
 * Module: Flame Sensor
 *
 * File Name: flamesensor.c
 *
 * Description: Source file for the ATmega16 Flame Sensor driver
 *
 * Author: Medhat Adel Tawfik
 *
 *******************************************************************************/

#include "GPIO.h"
#include "avr/io.h"


void FlameSensor_init(void) {
    GPIO_setupPinDirection(PORTD_ID, PIN2, PIN_INPUT);
}

uint8 FlameSensor_getValue(void) {
    return GPIO_readPin(PORTD_ID, PIN2);
}

