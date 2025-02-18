#ifndef PWM_U4C8_H
#define PWM_U4C8_H

#include "hardware/pwm.h"
#include "pico/stdlib.h"
#define PWM_WRAP 20000
#define PWM_CLKDIV 125.0f

void InitPWM(uint8_t[], uint8_t[]);
void ConfigPWM(uint8_t[]);
void SetPWMPulseWidth(uint8_t, uint16_t);

#endif