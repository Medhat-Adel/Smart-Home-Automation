 /******************************************************************************
 *
 * Module: DCmotor
 *
 * File Name: dcmotor.c
 *
 * Description: Source file for the ATmega16 DCmotor driver
 *
 * Author: Medhat Adel Tawfik
 *
 *******************************************************************************/

#include "DCMotor.h"
#include "avr/io.h"
#include "gpio.h"

void DcMotor_Init(void) {
    GPIO_setupPinDirection(PORTB_ID, PIN0_ID, PIN_OUTPUT);
    GPIO_setupPinDirection(PORTB_ID, PIN1_ID, PIN_OUTPUT);
    GPIO_writePin(PORTB_ID, PIN0_ID, LOGIC_LOW);
    GPIO_writePin(PORTB_ID, PIN1_ID, LOGIC_LOW);
}

void DcMotor_Rotate(DcMotor_State state, uint8 speed) {
    if(state == CW) {
        GPIO_writePin(PORTB_ID, PIN0_ID, LOGIC_HIGH);
        GPIO_writePin(PORTB_ID, PIN1_ID, LOGIC_LOW);
    } else if(state == A_CW) {
        GPIO_writePin(PORTB_ID, PIN0_ID, LOGIC_LOW);
        GPIO_writePin(PORTB_ID, PIN1_ID, LOGIC_HIGH);
    } else {
        GPIO_writePin(PORTB_ID, PIN0_ID, LOGIC_LOW);
        GPIO_writePin(PORTB_ID, PIN1_ID, LOGIC_LOW);
    }
    PWM_Timer0_Start(speed);
}
