 /******************************************************************************
 * Welcome, I am Medhat and this is my smart home project
 *
 * File Name: main.c
 *
 * Description: The main function of the smart home project
 *
 * Author: Medhat Adel Tawfik
 *
 *******************************************************************************/

#include "ADC.h"
#include "GPIO.h"
#include "LCD.h"
#include "PWM.h"
#include "LDR.h"
#include "LED.h"
#include "DCMotor.h"
#include "FlameSensor.h"
#include "Buzzer.h"
#include <util/delay.h>

// Thresholds
#define TEMP_HIGH 40
#define TEMP_MID_HIGH 35
#define TEMP_MID_LOW 30
#define TEMP_LOW 25
#define LDR_THRESHOLD_1 15
#define LDR_THRESHOLD_2 50
#define LDR_THRESHOLD_3 70

int main(void) {
    // Initialize all modules
    ADC_init();
    LCD_init();
    LEDS_init();
    DcMotor_Init();
    FlameSensor_init();
    Buzzer_init();

    uint16 temp_value, ldr_value;
    uint8 flame_detected;
    uint8 prev_flame_detected = 0xFF; // Initialize to an invalid value to track changes

    LCD_displayStringRowColumn(0, 0, "WELCOME TO");
    LCD_displayStringRowColumn(1, 0, "SmartHomeProject");

    _delay_ms(500);
    LCD_clearScreen();

    while (1) {
        // Read temperature, light, and flame sensor values
        temp_value = LM35_getTemperature();
        ldr_value = LDR_getLightIntensity();
        flame_detected = FlameSensor_getValue();

        // Check for flame detection
        if (flame_detected && flame_detected != prev_flame_detected) {
            // Only update LCD if the flame state changes
            Buzzer_on();
            LCD_clearScreen();
            LCD_displayStringRowColumn(0, 0, "Critical Alert!");
            LCD_displayStringRowColumn(1, 0, "---------------");
            prev_flame_detected = flame_detected;
        } else if (!flame_detected && flame_detected != prev_flame_detected) {
            // Clear the alert when the flame is no longer detected and restore normal display
            Buzzer_off();
            LCD_clearScreen();
            prev_flame_detected = flame_detected;
        }

        // Only update temperature and LDR readings if no flame is detected
        if (!flame_detected) {
            // Fan control based on temperature
            LCD_moveCursor(0, 0);
            if (temp_value >= TEMP_HIGH) {
                PWM_Timer0_Start(100); // Fan at full speed
                DcMotor_Rotate(CW, 100);
                LCD_displayString("Fan is ON (100%)");
            } else if (temp_value >= TEMP_MID_HIGH) {
                PWM_Timer0_Start(75);  // Fan at 75%
                DcMotor_Rotate(CW, 75);
                LCD_displayString("Fan is ON (75%)");
            } else if (temp_value >= TEMP_MID_LOW) {
                PWM_Timer0_Start(50);  // Fan at 50%
                DcMotor_Rotate(CW, 50);
                LCD_displayString("Fan is ON (50%)");
            } else if (temp_value >= TEMP_LOW) {
                PWM_Timer0_Start(25);  // Fan at 25%
                DcMotor_Rotate(CW, 25);
                LCD_displayString("Fan is ON (25%)");
            } else {
                PWM_Timer0_Start(0);   // Fan OFF
                DcMotor_Rotate(CW, 0);
                LCD_displayString("Fan is OFF");
            }

            // LED control based on light intensity
            if (ldr_value <= LDR_THRESHOLD_1) {
                LED_on(LED_RED);
                LED_on(LED_GREEN);
                LED_on(LED_BLUE);
            } else if (ldr_value <= LDR_THRESHOLD_2) {
                LED_on(LED_RED);
                LED_on(LED_GREEN);
                LED_off(LED_BLUE);
            } else if (ldr_value <= LDR_THRESHOLD_3) {
                LED_on(LED_RED);
                LED_off(LED_GREEN);
                LED_off(LED_BLUE);
            } else {
                LED_off(LED_RED);
                LED_off(LED_GREEN);
                LED_off(LED_BLUE);
            }

            // Display temperature and LDR readings on LCD
            LCD_moveCursor(1, 0);
            LCD_displayString("Temp=");
            LCD_intgerToString(temp_value);
            LCD_displayString(" LDR=");
            LCD_intgerToString(ldr_value);
            LCD_displayString("%  ");
        }
    }
}
