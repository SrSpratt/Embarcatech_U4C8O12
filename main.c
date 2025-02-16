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
#include <LEDMatrix_U4C6.h>
#include <Interrupt_U4C6.h>
#include <Interfaces_U4C6.H>
#include <Joystick_U4C8.h>

#define PINS 5
#define BUTTONA 5
#define BUTTONB 6


int main(){

    ssd1306_t ssd; //Declaração de uma struct para a manipulação do display
    bool cor = true;  

    PIORefs pio; //declaração da struct para armazenar a PIO

    PinOut pins[PINS] = { //inicialização dos pinos de LEDs e botões
        { 
            .Pin = REDPIN, 
            .Input = false
        },
        { 
            .Pin = BLUEPIN, 
            .Input = false
        },
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
    uint32_t ledConf = 0;

    Config(pins, PINS, &pio); // Configuração da UART e da PIO

    I2CInit(&ssd); //Inicia a I2C


    interruptContext.pinToCompare[1] = BUTTONB; // Armazena o pino do botão B para no contexto global da interrupção
    interruptContext.pinToCompare[0] = BUTTONA; // Armazena o pino do botão A para no contexto global da interrupção
    interruptContext.SSD = &ssd; // Armazena o endereço da struct de manipulação do display no contexto global da interrupção

    int LEDPins[3] = {REDPIN, BLUEPIN, GREENPIN}; // Inicializa um vetor com  os três valores de pinos de LEDs RGB

    SetRGBInterrupt(&TogglePinNoTime, BUTTONA, LEDPins, &HandleDisplayInterruptI2C); // Configura a interrupção no botão A
    SetRGBInterrupt(&TogglePinNoTime, JOYSTICKBPIN, LEDPins, &HandleDisplayInterruptI2C); // Configura a interrupção no botão A

    ConfigADC();

    char a;
    while(1){
        TraceDot(&ssd, cor);
    }


}


