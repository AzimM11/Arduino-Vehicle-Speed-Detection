# Arduino-Vehicle-Speed-Detection
Arduino-based vehicle speed detection system using IR sensors and LCD
# 🚗 Arduino-Based Vehicle Speed Detection System

## 📌 Project Overview

This project is an Arduino-based Vehicle Speed Detection System designed to measure the speed of a moving vehicle using two IR sensors.

The system detects the vehicle at two different points, calculates the time taken between the sensors, and determines the vehicle speed. The speed is displayed on a 16×2 I2C LCD, and a buzzer provides an alert when the speed exceeds the set limit.

## ⚙️ Components Used

- Arduino UNO
- 2 × IR Sensors
- 16×2 I2C LCD
- Buzzer
- Breadboard
- Jumper Wires

## 🔌 Circuit Connections

| Component | Arduino Pin |
|---|---|
| IR Sensor 1 OUT | D2 |
| IR Sensor 2 OUT | D3 |
| Buzzer | D11 |
| LCD SDA | A4 |
| LCD SCL | A5 |
| LCD VCC | 5V |
| LCD GND | GND |
| IR Sensors VCC | 5V |
| IR Sensors GND | GND |

## 🔄 Working

1. IR Sensor 1 detects the vehicle.
2. The timer starts.
3. IR Sensor 2 detects the vehicle.
4. The timer stops.
5. Arduino calculates the time taken between the sensors.
6. Vehicle speed is calculated.
7. Speed is displayed on the LCD.
8. The buzzer alerts when the speed exceeds the set limit.

## ✨ Features

- Real-time speed measurement
- Two IR sensor detection
- LCD speed display
- Overspeed alert
- Simple and low-cost design
- Arduino-based system

## 🎯 Applications

- Road speed monitoring
- Smart traffic systems
- Speed-limit alert systems
- Road safety projects
- Academic and engineering projects

## 🛠️ Technologies Used

- Arduino UNO
- Embedded C/C++
- IR Sensors
- I2C LCD
- Arduino IDE

## 👨‍💻 Made By

**Mohamed Azim. M**

Aalim Muhammed Salegh College of Engineering

## 📂 Project Files

- `Vehicle_Speed_Detection.ino` — Arduino source code
- `README.md` — Project documentation
