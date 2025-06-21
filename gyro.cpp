// gyro_esp32.cpp

#include <Wire.h>
#include <MPU6050.h>
#include "gyro_esp32.h"

MPU6050 mpu;
float currentYaw = 0;

void MPU_Init() {
    Wire.begin();
    mpu.initialize();
    if (!mpu.testConnection()) {
        Serial.println("MPU6050 connection failed");
    } else {
        Serial.println("MPU6050 ready");
    }
}

void GetZAngle() {
    mpu.getRotation();
    mpu.getYawPitchRoll(ypr);
    currentYaw = ypr[0] * 180.0 / PI;
    if (currentYaw < 0) currentYaw += 360;
}

void TurnRight90() {
    GetZAngle();
    float target = fmod(currentYaw + 90.0, 360.0);
    while (true) {
        GetZAngle();
        if (abs(currentYaw - target) < 2) break;
        Run_Both_Motors(100, -100);
        delay(10);
    }
    Stop_Motors();
}

void TurnLeft90() {
    GetZAngle();
    float target = fmod(currentYaw + 270.0, 360.0);
    while (true) {
        GetZAngle();
        if (abs(currentYaw - target) < 2) break;
        Run_Both_Motors(-100, 100);
        delay(10);
    }
    Stop_Motors();
}

void TurnRight180() {
    GetZAngle();
    float target = fmod(currentYaw + 180.0, 360.0);
    while (true) {
        GetZAngle();
        if (abs(currentYaw - target) < 2) break;
        Run_Both_Motors(100, -100);
        delay(10);
    }
    Stop_Motors();
}
