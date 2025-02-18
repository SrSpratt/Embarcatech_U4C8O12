#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "hardware/timer.h"
#include "hardware/clocks.h"
#include "hardware/i2c.h"
#include <ssd1306.h>
#include <font.h>
#include <General_U4C6.h>
#include <MainLED_U4C6.h>
#include <Interrupt_U4C6.h>
#include <Interfaces_U4C6.H>
#include <Joystick_U4C8.h>
#include <PWM_U4C8.h>

#define PINS 3
#define BUTTONA 5


int main(){

    ssd1306_t ssd; //Declaração de uma struct para a manipulação do display
    bool cor = true;  

    PIORefs pio; //declaração da struct para armazenar a PIO

    PinOut pins[PINS] = { //inicialização dos pinos de LEDs e botões
        { 
            .Pin = GREENPIN, 
            .Input = false
        },
        { 
            .Pin = BUTTONA, 
            .Input = true
        },
        {
            .Pin = JOYSTICKBPIN,
            .Input = true
        }
    };

    Config(pins, PINS, &pio); // Configuração da UART e da PIO

    I2CInit(&ssd); //Inicia a I2C

    interruptContext.pinToCompare[1] = JOYSTICKBPIN; // Armazena o pino do botão A para no contexto global da interrupção
    interruptContext.pinToCompare[0] = BUTTONA; // Armazena o pino do botão A para no contexto global da interrupção
    interruptContext.SSD = &ssd; // Armazena o endereço da struct de manipulação do display no contexto global da interrupção

    int LEDPins[3] = {REDPIN, BLUEPIN, GREENPIN}; // Inicializa um vetor com  os três valores de pinos de LEDs RGB

    SetRGBInterrupt(&TogglePinNoTime, BUTTONA, LEDPins, &HandleDisplayInterruptI2C); // Configura a interrupção no botão A
    SetRGBInterrupt(&TogglePinNoTime, JOYSTICKBPIN, LEDPins, &HandleDisplayInterruptI2C); // Configura a interrupção no botão A

    ConfigADC();

    uint8_t ledpins[2] = {12, 13}; 
    uint8_t slices[2];
    InitPWM(ledpins, slices);
    ConfigPWM(slices);

    char a;
    while(1){
        TraceDot(&ssd, cor, ledpins);
    }


}


