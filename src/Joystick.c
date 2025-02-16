#include <Joystick_U4C8.h>

void ConfigADC(){
    adc_init();
    adc_gpio_init(JOYSTICKHPIN);
    adc_gpio_init(JOYSTICKVPIN);
}

void JoystickRead(uint16_t values[]){
    adc_select_input(ADCHCHANNEL);
    values[1] = adc_read();
    adc_select_input(ADCVCHANNEL);
    values[0] = adc_read();
}

void MapToDisplay(float values[]){
    float normalizeJoystick[2];
    normalizeJoystick[0] = values[0]/4095.0f;
    normalizeJoystick[1] = values[1]/4095.0f;
    printf("normalizedX:%lf\n", normalizeJoystick[0]);
    printf("normalizedY:%lf\n", normalizeJoystick[1]);

    values[0] = (uint16_t) (normalizeJoystick[0] * 127.0f);
    values[1] = (uint16_t) (normalizeJoystick[1] * 63.0f);

    printf("normalizedDisplayX:%d\n", values[0]);
    printf("normalizedDisplayY:%d\n", values[1]);
}

void TraceDot(ssd1306_t* ssd, bool cor){
        uint16_t previousValues[2];
        uint16_t values[2];
        JoystickRead(values);
        if (values[0] != previousValues[0] || values[1] != previousValues[1]){
            printf("new X: %d\nnew Y: %d\n", values[0], values[1]);
            previousValues[0] = values[0];
            previousValues[1] = values[1];
            float mapValues[2];
            mapValues[0] = values[0];
            mapValues[1] = values[1];
            MapToDisplay(mapValues);
            ssd1306_fill(ssd, !cor);
            ssd1306_rect(ssd, 63 - mapValues[1]-1, mapValues[0]-1, 2, 2, cor, cor);
            ssd1306_send_data(ssd);
        }
}
