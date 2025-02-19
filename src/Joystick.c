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

void TraceDot(ssd1306_t* ssd, bool cor, uint8_t pins[], int dBorder, bool pwm){
        uint16_t previousValues[2];
        uint16_t values[2];
        JoystickRead(values);
        if (values[0] != previousValues[0] || values[1] != previousValues[1]){

            // coloca o centro na coordenada 2048 para calcular a intensidade do pwm
            int valueA = (values[1] - 2048);
            int valueB = (values[0] - 2048);
            if (pwm){ // verifica se a interrupção do botão A foi acionada
                SetPWMPulseWidth(pins[0],  valueA > 0 ? valueA * 9.76 : (-valueA) * 9.76); // 9.76 = 20000/2048
                SetPWMPulseWidth(pins[1], valueB > 0 ? valueB * 9.76 : (-valueB) * 9.76);
            } else {
                SetPWMPulseWidth(pins[0],  0);
                SetPWMPulseWidth(pins[1], 0);
            }

            printf("new X: %d\nnew Y: %d\n", valueA, valueB);

            // variáveis para armazenar os valores passados da posição do joystick para comparação na próxima iteração
            previousValues[0] = values[0];
            previousValues[1] = values[1];

            // normaliza as posições do joystick para fazer o mapeamento no display
            float mapValues[2];
            mapValues[0] = values[0];
            mapValues[1] = values[1];
            MapToDisplay(mapValues);
            ssd1306_fill(ssd, !cor);
            ssd1306_rect(ssd, 0, 0, 127, 63, cor, !cor);

            if (dBorder){ //alterna uma nova borda de acordo com a interrupção
                ssd1306_rect(ssd, 2, 2, 123, 59, cor, !cor);
                ssd1306_rect(ssd, 4, 4, 119, 55, cor, !cor);
            }
            // desenha o quadrado
            ssd1306_rect(ssd, 56 - mapValues[1], mapValues[0], 8, 8, cor, cor);
            ssd1306_send_data(ssd);
        }
}
