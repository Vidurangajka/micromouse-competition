// ir_sensor_esp32.cpp

#include <Arduino.h>
#include "ir_sensor_esp32.h"

#define IR_LEFT_PIN   36
#define IR_FRONT_PIN  39
#define IR_RIGHT_PIN  34

void InitSharpSensors() {
    pinMode(IR_LEFT_PIN, INPUT);
    pinMode(IR_FRONT_PIN, INPUT);
    pinMode(IR_RIGHT_PIN, INPUT);
}

void UpdateSharpSensors() {
    ir_left_val = analogRead(IR_LEFT_PIN);
    ir_front_val = analogRead(IR_FRONT_PIN);
    ir_right_val = analogRead(IR_RIGHT_PIN);
}

float GetLeftDist() {
    return ConvertToDistance(ir_left_val);
}

float GetRightDist() {
    return ConvertToDistance(ir_right_val);
}

float GetFrontDist() {
    return ConvertToDistance(ir_front_val);
}

float ConvertToDistance(int raw) {
    float dist = 22.5324 - 0.028196 * raw + 0.000014268 * raw * raw - 0.0000000025487 * raw * raw * raw;
    return constrain(dist, 5, 80);
}
