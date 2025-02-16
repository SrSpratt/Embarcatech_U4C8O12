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
            .Pin = BUTTONB, 
            .Input = true
        }
    };
    Sketch sketch = { //Struct para armazenar os desenhos da matriz de LEDs (para o controle via PIO)
        .Figure = {
            0.0, 0.0, 0.0, 0.0, 0.0,
            0.0, 0.0, 0.0, 0.0, 0.0,
            0.0, 0.0, 0.0, 0.0, 0.0,
            0.0, 0.0, 0.0, 0.0, 0.0,
            0.0, 0.0, 0.0, 0.0, 0.0
        },
        .Index = -1,
        .MainColor = {
            .Red = 0.01,
            .Green = 0.0,
            .Blue = 0.0
        },
        .BackgroundColor = {
            .Red = 0.0,
            .Green = 0.0,
            .Blue = 0.01
        }
    };
    uint32_t ledConf = 0;

    Config(pins, PINS, &pio); // Configuração da UART e da PIO

    InitPIO(&pio, MATRIXPIN); // Inizialização da PIO

    Draw(sketch, ledConf, pio); //Desenha um quadrado azul

    I2CInit(&ssd); //Inicia a I2C


    interruptContext.pinToCompare[1] = BUTTONB; // Armazena o pino do botão B para no contexto global da interrupção
    interruptContext.pinToCompare[0] = BUTTONA; // Armazena o pino do botão A para no contexto global da interrupção
    interruptContext.SSD = &ssd; // Armazena o endereço da struct de manipulação do display no contexto global da interrupção

    int LEDPins[3] = {REDPIN, BLUEPIN, GREENPIN}; // Inicializa um vetor com  os três valores de pinos de LEDs RGB

    SetRGBInterrupt(&TogglePinNoTime, BUTTONA, LEDPins, &HandleDisplayInterruptI2C); // Configura a interrupção no botão A
    SetRGBInterrupt(&TogglePinNoTime, BUTTONB, LEDPins, &HandleDisplayInterruptI2C); // Configura a interrupção no botão B

    char a;
    while(1){

        a = getchar(); // "Escuta" o caractere inserido via uart/serial
        if (a >= '0' && a <= 'z'){
            char string[13] = {'C', 'a', 'r', 'a', 'c', 't', 'e', 'r', 'e', ':', ' ', a, '\0'};
            I2CDraw(&ssd, cor, string); // desenha no display via I2C
            printf("Caractere enviado: %c!\n", a); //escreve na saída serial via uart
        }
        
        switch(a){
            case '0':
                ArrayCopySameSize(sketch.Figure, SketchArray(0), VECTORSIZE); //copia o vetor do número no vetor de LEDs da matriz
                Draw(sketch, ledConf, pio); //desenha o vetor copiado com o número
                break;
            case '1':
                ArrayCopySameSize(sketch.Figure, SketchArray(1), VECTORSIZE);
                Draw(sketch, ledConf, pio);
                break;
            case '2':
                ArrayCopySameSize(sketch.Figure, SketchArray(2), VECTORSIZE);
                Draw(sketch, ledConf, pio);
                break;
            case '3':
                ArrayCopySameSize(sketch.Figure, SketchArray(3), VECTORSIZE);
                Draw(sketch, ledConf, pio);
                break;
            case '4':
                ArrayCopySameSize(sketch.Figure, SketchArray(4), VECTORSIZE);
                Draw(sketch, ledConf, pio);
                break;
            case '5':
                ArrayCopySameSize(sketch.Figure, SketchArray(5), VECTORSIZE);
                Draw(sketch, ledConf, pio);
                break;
            case '6':
                ArrayCopySameSize(sketch.Figure, SketchArray(6), VECTORSIZE);
                Draw(sketch, ledConf, pio);
                break;
            case '7':
                ArrayCopySameSize(sketch.Figure, SketchArray(7), VECTORSIZE);
                Draw(sketch, ledConf, pio);
                break;
            case '8':
                ArrayCopySameSize(sketch.Figure, SketchArray(8), VECTORSIZE);
                Draw(sketch, ledConf, pio);
                break;
            case '9':
                ArrayCopySameSize(sketch.Figure, SketchArray(9), VECTORSIZE);
                Draw(sketch, ledConf, pio);
                break;

        }
        sleep_ms(1);
    }


}


