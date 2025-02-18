#include <Joystick_U4C8.h>
#include <PWM_U4C8.h>

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
    normalizeJoystick[0] = (values[0])/(4095.0f);
    normalizeJoystick[1] = (values[1])/(4095.0f);
    //printf("normalizedX:%lf\n", normalizeJoystick[0]);
    //printf("normalizedY:%lf\n", normalizeJoystick[1]);

    values[0] = (uint16_t) (normalizeJoystick[0] * 120.0f);
    values[1] = (uint16_t) (normalizeJoystick[1] * 56.0f);

    //printf("normalizedDisplayX:%d\n", values[0]);
    //printf("normalizedDisplayY:%d\n", values[1]);
}

void TraceDot(ssd1306_t* ssd, bool cor, uint8_t pins[]){
        uint16_t previousValues[2];
        uint16_t values[2];
        JoystickRead(values);
        if (values[0] != previousValues[0] || values[1] != previousValues[1]){
            int valueA = (values[1] - 2047);
            int valueB = (values[0] - 2047);
            SetPWMPulseWidth(pins[0],  valueA > 0 ? valueA : (-valueA) * 4.88);
            SetPWMPulseWidth(pins[1], valueB > 0 ? valueB : (-valueB) * 4.88 );
            printf("new X: %d\nnew Y: %d\n", valueA, valueB);
            //sleep_ms(1000);
            //printf("new X: %d\nnew Y: %d\n", values[0], values[1]);
            previousValues[0] = values[0];
            previousValues[1] = values[1];
            float mapValues[2];
            mapValues[0] = values[0];
            mapValues[1] = values[1];
            MapToDisplay(mapValues);
            ssd1306_fill(ssd, !cor);
            ssd1306_rect(ssd, 1, 1, 125, 62, cor, !cor);
            //ssd1306_rect(ssd, 2, 2, 124, 61, cor, !cor);
            ssd1306_rect(ssd, 56 - mapValues[1], mapValues[0], 8, 8, cor, cor);
            ssd1306_send_data(ssd);
        }
}
