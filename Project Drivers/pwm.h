 /******************************************************************************
 *
 * Module: PWM
 *
 * File Name: pwm.h
 *
 * Description: Header file for the ATmega16 PWM driver
 *
 * Author: Medhat Adel Tawfik
 *
 *******************************************************************************/

#ifndef PWM_H_
#define PWM_H_

#include "std_types.h"

// Function to start PWM with a specific duty cycle
void PWM_Timer0_Start(uint8 duty_cycle);

#endif /* PWM_H_ */
