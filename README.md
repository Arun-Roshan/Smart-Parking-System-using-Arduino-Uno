# 🚗 Smart Parking System using Arduino Uno

This project is a simple **smart parking gate** system that uses an **IR sensor** to detect vehicles, a **servo motor** to open/close the gate, **OLED display** for status, and **LED indicators** for availability.

---

## 🎯 Features

- IR Sensor detects the presence of a vehicle
- Servo Motor controls gate movement (0° = open, 45° = closed)
- OLED displays system status
- Red & Green LEDs show availability
- Fully automatic and beginner-friendly

---

## 🧰 Components Used

| Component            | Quantity |
|----------------------|----------|
| Arduino Uno          | 1        |
| IR Sensor Module     | 1        |
| Servo Motor (SG90)   | 1        |
| 0.96" OLED Display (I2C) | 1     |
| Red LED              | 1        |
| Green LED            | 1        |
| 220Ω Resistors       | 2        |
| Breadboard + Jumper Wires | As needed |

---

## ⚙️ Circuit Connections

| Component    | Arduino Pin |
|--------------|-------------|
| IR Sensor OUT| D2          |
| Red LED      | D3          |
| Green LED    | D4          |
| Servo Signal | D9          |
| OLED SDA     | A4          |
| OLED SCL     | A5          |
| GND/VCC      | Connect accordingly (5V/GND) |

---

## 🔁 How It Works

- When **no vehicle** is detected:
  - **Red LED** glows
  - **Servo at 45°** (Gate Closed)
  - OLED shows *"Parking Available"*

- When **a vehicle** is detected:
  - **Green LED** glows
  - **Servo rotates to 0°** (Gate Opens)
  - OLED shows *"Vehicle Detected - Gate Opening..."*
  - Gate closes again after a short delay

---

## 💾 Arduino Code
Make sure you have the following libraries installed:

- `Servo.h`
- `Wire.h`
- `Adafruit_GFX.h`
- `Adafruit_SSD1306.h`

---

## 🖼️ Preview
![20250618_152112](https://github.com/user-attachments/assets/c9ae25c0-b063-4a4e-a8f3-5fa2feead23c)
![20250618_152109](https://github.com/user-attachments/assets/7d798a62-e189-4597-8ad5-d88a231ffa5c)


🔗 YouTube: [Arun Roshan Tech]https://www.youtube.com/@ArunRoshanTechOfficial  



