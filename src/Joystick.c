#include <Joystick_U4C8.h>

void ConfigADC(){
    adc_init();
    adc_gpio_init(JOYSTICKHPIN);
    adc_gpio_init(JOYSTICKVPIN);
}

void JoystickRead(uint16_t values[]){
    adc_select_input(ADCHCHANNEL);
    values[0] = adc_read();
    adc_select_input(ADCVCHANNEL);
    values[1] = adc_read();
}
