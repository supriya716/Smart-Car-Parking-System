# IoT-Based Smart Car Parking System

An IoT-based smart parking system designed to monitor parking slot availability using ESP32, IR sensors, Blynk, and an I2C LCD.

## Overview

The system detects whether parking slots are occupied or available using IR sensors. The ESP32 processes the sensor data and displays the parking status on an I2C LCD. The status can also be monitored remotely through the Blynk IoT platform.

## Components Used

- ESP32
- 4 IR Sensors
- I2C LCD Display
- Li-ion Battery
- Jumper Wires
- Blynk IoT Platform

## Working

1. IR sensors detect the presence of vehicles in each parking slot.
2. ESP32 reads the sensor data.
3. The parking slot status is displayed on the I2C LCD.
4. The ESP32 sends the status to the Blynk platform.
5. Users can monitor the parking slots remotely.

## Features

- Real-time parking slot detection
- Four-slot parking monitoring
- LCD-based status display
- Remote monitoring using Blynk
- ESP32-based IoT implementation
- Simple and cost-effective design

## Project Files

### Circuit Diagram
[View Circuit Diagram](Images/Circuit_Diagram.png)

### Hardware Setup
[View Hardware Setup](Images/Hardware%20Setup.png)

### Source Code
[View Source Code](Source_Code/SmartCarParking.ino)

## Technologies Used

- Embedded C/C++
- ESP32
- Arduino IDE
- Blynk IoT
- I2C Communication
- IR Sensors

## Applications

- Smart parking areas
- College and office parking
- Residential parking
- Small-scale automated parking systems

## Future Improvements

- Mobile application integration
- Automatic entry and exit control
- Parking slot reservation
- Integration with a web-based dashboard
- Addition of more parking slots
