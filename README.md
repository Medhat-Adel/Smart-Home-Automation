![Smart Home - Proteus 8 Professional - Schematic Capture 10_7_2024 9_49_42 PM](https://github.com/user-attachments/assets/54ce852d-ebe4-4613-b69c-350eae7d754b)

# Smart Home Automation Using ATmega32, LCD, Temperature Sensor, LDR Sensor, Flame Sensor, and Motor Control

## Project Overview
This project implements a smart home automation system that automates lighting, fan speed, and fire detection using sensors and a microcontroller. The system is designed to adjust the lighting and fan speed based on environmental conditions such as room temperature and ambient light, while also providing fire detection and real-time feedback via an LCD.

## Objectives
The primary objectives of this project are:
- **Lighting Control**: Adjust LED lighting based on ambient light intensity using an LDR.
- **Fan Speed Control**: Control the fan speed using PWM based on room temperature measured by the LM35 temperature sensor.
- **Fire Detection**: Trigger a fire alarm and alert when the flame sensor detects fire.
- **Real-Time Feedback**: Display system status, temperature, and light intensity on a 16x2 LCD.

## Features
### 1. Automatic Lighting Control
The LDR sensor monitors light intensity and adjusts three LEDs based on the following thresholds:
- **< 15%**: All LEDs (Red, Green, and Blue) turn ON.
- **16% - 50%**: Red and Green LEDs turn ON.
- **51% - 70%**: Only Red LED turns ON.
- **> 70%**: All LEDs turn OFF.

### 2. Automatic Fan Speed Control
The fan speed is adjusted based on the temperature readings from the LM35 sensor using PWM:
- **≥ 40°C**: Fan ON at 100% speed.
- **35°C ≤ Temp < 40°C**: Fan ON at 75% speed.
- **30°C ≤ Temp < 35°C**: Fan ON at 50% speed.
- **25°C ≤ Temp < 30°C**: Fan ON at 25% speed.
- **< 25°C**: Fan OFF.

### 3. Fire Detection and Alert
- The flame sensor detects fire and triggers a "Critical Alert!" message on the LCD.
- The buzzer is activated to provide an audible alert.
- The system remains in alert mode until the flame is no longer detected.

### 4. Real-Time LCD Display
The 16x2 LCD provides real-time feedback on the system status:
- **First Row**: Displays "FAN is ON" or "FAN is OFF" depending on the fan status.
- **Second Row**: Displays the temperature (`Temp= xxC`) and light intensity (`LDR= xxx%`).

## Hardware Components
- **Microcontroller**: ATmega32
- **Temperature Sensor**: LM35 (connected to ADC Channel 1)
- **Light Sensor**: LDR (connected to ADC Channel 0)
- **Display**: 16x2 LCD (in 8-bit mode)
- **Motor**: Controlled via H-Bridge (PWM-based speed control)
- **Flame Sensor**: Connected to detect fire
- **Buzzer**: Used for fire alerts
- **LEDs**: Red, Green, Blue for light intensity indication

## Pin Configuration
| Component      | Pin Configuration               |
|----------------|----------------------------------|
| LCD            | RS: PD0, Enable: PD1, Data: PORTC (8-bit mode) |
| LDR            | PA0 (ADC Channel 0)             |
| LM35           | PA1 (ADC Channel 1)             |
| Motor Control  | IN1: PB0, IN2: PB1, Enable1: PB3/OC0 |
| Flame Sensor   | PD2                             |
| Buzzer         | PD3                             |
| Red LED        | PB5                             |
| Green LED      | PB6                             |
| Blue LED       | PB7                             |

## System Requirements
- **Microcontroller**: ATmega32
- **System Frequency**: 16 MHz

## Drivers Overview
The project utilizes the following drivers for each component:
1. **ADC Driver**: Converts analog sensor data (LM35, LDR) to digital.
2. **GPIO Driver**: Handles basic pin configurations.
3. **PWM Driver**: Controls fan speed using Timer0.
4. **LCD Driver**: Displays system information in 8-bit mode.
5. **Temperature Sensor Driver**: Reads data from the LM35 sensor.
6. **LDR Driver**: Reads light intensity data from the LDR sensor.
7. **LED Driver**: Controls the LEDs based on light intensity.
8. **DC Motor Driver**: Controls the motor speed using PWM.
9. **Flame Sensor Driver**: Detects fire and triggers alerts.
10. **Buzzer Driver**: Sounds the alarm when a fire is detected.

## Circuit Schematic
(Insert the circuit schematic here if available)


## Project Structure
- **/src**: Contains the source code files for the project.
- **/drivers**: Contains the driver implementations for each hardware component.
- **/schematic**: Contains the circuit schematic and connection diagrams.

## Future Enhancements
- Add remote control features using Bluetooth or Wi-Fi modules for controlling the system wirelessly.
- Implement additional safety features like gas leak detection.

## Acknowledgments
- Special thanks to **Engineer Mohamed Tarek** for his incredible support and guidance throughout the development of this project.
