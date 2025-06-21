// motor_control_esp32.h
#ifndef MOTOR_CONTROL_ESP32_H
#define MOTOR_CONTROL_ESP32_H

#include <stdint.h>

#define MOTOR_MAX_SPEED 1023

void Motors_Init();
void Stop_Motors();
void Forward_Left_Motor(uint32_t power);
void Backward_Left_Motor(uint32_t power);
void Forward_Right_Motor(uint32_t power);
void Backward_Right_Motor(uint32_t power);
void Run_Both_Motors(int32_t left_power, int32_t right_power);

#endif
