 /******************************************************************************
 *
 * Module: Buzzer
 *
 * File Name: buzzer.c
 *
 * Description: Source file for the ATmega16 Buzzer driver
 *
 * Author: Medhat Adel Tawfik
 *
 *******************************************************************************/

#include "GPIO.h"
#include "avr/io.h"
#include "buzzer.h"
//
void Buzzer_init(void) {
    GPIO_setupPinDirection(PORTD_ID, PIN3_ID, PIN_OUTPUT);
    Buzzer_off();
}

void Buzzer_on(void) {
    GPIO_writePin(PORTD_ID, PIN3_ID, LOGIC_HIGH);
}

void Buzzer_off(void) {
    GPIO_writePin(PORTD_ID, PIN3_ID, LOGIC_LOW);
}
