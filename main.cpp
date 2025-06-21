#include <Arduino.h>

// Include your ported module headers
#include "encoder_esp32.h"
#include "motor_control_esp32.h"
#include "ir_sensor_esp32.h"
#include "gyro_esp32.h"

// ====== Constants ======
#define WALL_THRESHOLD_CM 15.0  // IR threshold for detecting walls

// ====== Setup Function ======
void setup() {
    Serial.begin(115200);

    // Initialize all systems
    Encoders_Init();
    Motors_Init();
    InitSharpSensors();    // Start ADC & sensor filtering
    MPU_Init();            // Initialize MPU6050

    Serial.println("Micromouse Initialized");
}

// ====== Helper Movement Functions ======

void go_forward() {
    Encoder_Forward_Cell();
}

void go_to_right() {
    TurnRight90();
    go_forward();
}

void go_to_left() {
    TurnLeft90();
    go_forward();
}

void go_backward() {
    TurnRight180();
    go_forward();
}

// ====== Wall Detection ======
bool is_wall_in_front() {
    return GetFrontDist() < WALL_THRESHOLD_CM;
}

bool is_wall_in_right() {
    return GetRightDist() < WALL_THRESHOLD_CM;
}

bool is_wall_in_left() {
    return GetLeftDist() < WALL_THRESHOLD_CM;
}

// ====== Main Loop ======
void loop() {
    UpdateSharpSensors();

    if (!is_wall_in_front()) {
        go_forward();
    } else if (!is_wall_in_right()) {
        go_to_right();
    } else if (!is_wall_in_left()) {
        go_to_left();
    } else {
        go_backward();  // Dead-end
    }

    delay(100);  // Optional stabilization delay
}
