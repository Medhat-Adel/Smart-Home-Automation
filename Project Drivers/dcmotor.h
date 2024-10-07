 /******************************************************************************
 *
 * Module: DCmotor
 *
 * File Name: dcmotor.h
 *
 * Description: Header file for the ATmega16 DCmotor driver
 *
 * Author: Medhat Adel Tawfik
 *
 *******************************************************************************/

#ifndef DCMOTOR_H_
#define DCMOTOR_H_

#include "std_types.h"

// Define motor rotation states
typedef enum {
    CW,     // Clockwise rotation
    A_CW,   // Anti-clockwise rotation
    STOP    // Stop the motor
} DcMotor_State;

// Function to initialize the DC motor
void DcMotor_Init(void);

// Function to rotate the DC motor with a specific state and speed
void DcMotor_Rotate(DcMotor_State state, uint8 speed);

#endif /* DCMOTOR_H_ */
