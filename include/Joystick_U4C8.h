#ifndef JOYSTICK_U4C8_H
#define JOYSTICK_U4C8_H

#include "hardware/adc.h"

#define JOYSTICKHPIN 26
#define JOYSTICKVPIN 27
#define JOYSTICKBPIN 22
#define ADCHCHANNEL 0
#define ADCVCHANNEL 1


void ConfigADC();

void JoystickRead(uint16_t[]);

#endif