# Micromouse Robot (ESP32)

A modular ESP32-based micromouse robot software written in C++ using the Arduino framework. It includes support for wheel encoders, motor control, IR distance sensors, and an MPU6050 gyroscope, enabling basic autonomous maze navigation and flood fill pathfinding.

---

## 📦 Features

* **Encoder-based movement** with tick-to-distance conversion
* **PWM motor control** with direction logic using ESP32 `ledcWrite`
* **IR Sharp sensor filtering** and analog-to-distance conversion
* **Gyro turning and yaw tracking** via MPU6050
* **Maze exploration logic** with wall detection & movement strategies

---

## 🔧 Hardware Connections

| Component     | Pin                                |
| ------------- | ---------------------------------- |
| Left Encoder  | GPIO34, GPIO35                     |
| Right Encoder | GPIO32, GPIO33                     |
| IR Sensors    | GPIO36 (L), GPIO39 (F), GPIO34 (R) |
| Motor Left    | PWM: GPIO18, DIR: GPIO25           |
| Motor Right   | PWM: GPIO19, DIR: GPIO26           |
| MPU6050       | I2C SDA: GPIO21, SCL: GPIO22       |

---

## 🚀 Getting Started

### ✅ Prerequisites

* Arduino IDE or PlatformIO
* ESP32 board definitions
* Libraries:

  * [MPU6050 by Electronic Cats](https://github.com/ElectronicCats/mpu6050)
  * [I2Cdevlib](https://github.com/jrowberg/i2cdevlib) (optional low-level driver)

### 📂 Folder Structure

```
micromouse_project/
├── micromouse_main.ino
├── encoder_esp32.{h,cpp}
├── motor_control_esp32.{h,cpp}
├── ir_sensor_esp32.{h,cpp}
├── gyro_esp32.{h,cpp}
├── config.h
└── README.md
```

---

## 🧪 Usage

1. Upload to your ESP32 board.
2. Place robot in maze cell.
3. It will detect walls and move forward, right, left, or backward accordingly.
4. Extend logic to support flood fill, speed runs, and EEPROM path memory.


