 /******************************************************************************
 *
 * Module: LDR
 *
 * File Name: ldr.h
 *
 * Description: Header file for the ATmega16 LDR driver
 *
 * Author: Medhat Adel Tawfik
 *
 *******************************************************************************/

#ifndef LDR_H_
#define LDR_H_

#include "std_types.h"

// Function to get the light intensity from the LDR sensor
uint16 LDR_getLightIntensity(void);


#endif /* LDR_H_ */
