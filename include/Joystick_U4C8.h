#ifndef JOYSTICK_U4C8_H
#define JOYSTICK_U4C8_H

#include <ssd1306.h>
#include "hardware/adc.h"

#define JOYSTICKHPIN 26
#define JOYSTICKVPIN 27
#define JOYSTICKBPIN 22
#define ADCHCHANNEL 0
#define ADCVCHANNEL 1


void ConfigADC();

void JoystickRead(uint16_t[]);
void MapToDisplay(float[]);
void TraceDot(ssd1306_t*, bool cor);

#endif