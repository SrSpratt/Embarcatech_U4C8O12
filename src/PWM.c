#include <PWM_U4C8.h>

void InitPWM(uint8_t pins[], uint8_t slice[]){
    for (uint8_t i = 0; i < 2; i++){
        gpio_set_function(pins[i], GPIO_FUNC_PWM);
        slice[i] = pwm_gpio_to_slice_num(pins[i]);
    }
}

void ConfigPWM(uint8_t slices[]){
    for (uint8_t i = 0; i < 2; i++){
        pwm_set_wrap(slices[i], PWM_WRAP);
        pwm_set_clkdiv(slices[i], PWM_CLKDIV);
        pwm_set_enabled(slices[i], true);
    }
}

void SetPWMPulseWidth(uint8_t pin, uint16_t pulseWidth){
    pwm_set_gpio_level(pin, pulseWidth);
}