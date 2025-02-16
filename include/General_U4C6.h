#ifndef GENERALU6C_H
#define GENERALU6C_H

#include "pico/stdlib.h"
#include "hardware/pio.h"
#include <Interfaces_U4C6.h>
#include <stdio.h>


/**
 * @brief Estrutura para representar a configuração de um pino GPIO.
 * 
 * Esta estrutura armazena as informações necessárias para configurar um pino GPIO como 
 * entrada ou saída.
 */
typedef struct PinSet {
    int Pin;   /** Número do pino GPIO. */
    bool Input; /** Define se o pino será entrada (true) ou saída (false). */
} PinOut;

/**
 * @brief Estrutura para representar um ponteiro para um PIO e sua configuração.
 * 
 * Esta estrutura armazena informações sobre o endereço do PIO, a máquina de estados associada
 * e o offset do programa PIO.
 */
typedef struct PIO {
    PIO Address; /** Ponteiro para o endereço do PIO. */
    int StateMachine; /** Número da máquina de estados do PIO. */
    int Offset; /** Valor do offset do programa PIO. */
} PIORefs;

/**
 * @brief Estrutura para representar uma cor RGB com valores para Red, Green e Blue.
 * 
 * Esta estrutura armazena os valores de cor em formato RGB, variando de 0.0 a 1.0.
 */
typedef struct RGB {
    double Red;   /** Valor da componente vermelha (Red). */
    double Green; /** Valor da componente verde (Green). */
    double Blue;  /** Valor da componente azul (Blue). */
} RGB;

/**
 * @brief Imprime as informações de um pino configurado.
 * 
 * Esta função exibe as propriedades de um pino GPIO, incluindo seu número e se é uma entrada ou saída.
 * 
 * @param pin Estrutura contendo as informações do pino a ser impresso.
 */
void PrintPinOut(PinOut pin);

/**
 * @brief Imprime as informações de um PIO e sua configuração.
 * 
 * Esta função exibe as propriedades de um PIO, incluindo seu endereço, offset e máquina de estados.
 * 
 * @param pio Estrutura contendo as informações do PIO a ser impresso.
 */
void PrintPIO(PIORefs pio);

/**
 * @brief Imprime as informações de uma cor RGB.
 * 
 * Esta função exibe os valores das componentes vermelha, verde e azul de uma cor RGB.
 * 
 * @param color Estrutura contendo a cor RGB a ser impressa.
 */
void PrintRGB(RGB color);

/**
 * @brief Configura os pinos GPIO e o PIO com base nas informações fornecidas.
 * 
 * Esta função inicializa os pinos GPIO, configurando-os como entrada ou saída conforme o especificado,
 * e também configura o PIO com o programa necessário.
 * 
 * @param pins Ponteiro para um vetor de estruturas PinOut, contendo os pinos a serem configurados.
 * @param size Número de elementos no vetor de pinos.
 * @param pio Ponteiro para a estrutura PIORefs, contendo as configurações do PIO.
 */
void Config(PinOut* pins, int size, PIORefs* pio);

/**
 * @brief Inicializa o PIO com o programa e pino fornecidos.
 * 
 * Esta função configura o PIO, carregando o programa e inicializando o estado da máquina de estados
 * para o pino fornecido.
 * 
 * @param pio Ponteiro para a estrutura PIORefs.
 * @param pin Número do pino a ser configurado no PIO.
 */
void InitPIO(PIORefs* pio, int pin);

/**
 * @brief Inicializa um pino GPIO como entrada ou saída.
 * 
 * Esta função configura um pino GPIO como entrada ou saída com base no parâmetro fornecido.
 * 
 * @param PIN Número do pino GPIO a ser configurado.
 * @param input Valor booleano que define se o pino será configurado como entrada (true) ou saída (false).
 */
void InitPin(int PIN, bool input);

/**
 * @brief Configura um pino GPIO como entrada.
 * 
 * Esta função configura um pino GPIO como entrada e ativa o resistor de pull-up.
 * 
 * @param PIN Número do pino GPIO a ser configurado como entrada.
 */
void SetInput(int PIN);

/**
 * @brief Configura um pino GPIO como saída.
 * 
 * Esta função configura um pino GPIO como saída e inicializa o valor do pino como 0.
 * 
 * @param PIN Número do pino GPIO a ser configurado como saída.
 */
void SetOutput(int PIN);


#endif
