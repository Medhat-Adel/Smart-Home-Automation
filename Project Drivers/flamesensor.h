 /******************************************************************************
 *
 * Module: Flame Sensor
 *
 * File Name: flamesensor.h
 *
 * Description: Header file for the ATmega16 Flame Sensor driver
 *
 * Author: Medhat Adel Tawfik
 *
 *******************************************************************************/

#ifndef FLAMESENSOR_H_
#define FLAMESENSOR_H_

#include "std_types.h"

// Function to initialize the flame sensor
void FlameSensor_init(void);

// Function to get the value from the flame sensor
uint8 FlameSensor_getValue(void);

#endif /* FLAMESENSOR_H_ */
