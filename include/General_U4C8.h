#ifndef GENERALU8C_H
#define GENERALU8C_H

#include "pico/stdlib.h"
#include <Interfaces_U4C8.h>
#include <stdio.h>

/**
 * @brief Estrutura para representar a configuração de um pino GPIO.
 * 
 * Esta estrutura armazena as informações necessárias para configurar um pino GPIO como 
 * entrada ou saída.
 */
typedef struct PinSet {
    int Pin;    /**< Número do pino GPIO. */
    bool Input; /**< Define se o pino será entrada (true) ou saída (false). */
} PinOut;

/**
 * @brief Imprime as informações de um pino configurado.
 * 
 * Esta função exibe as propriedades de um pino GPIO, incluindo seu número e se é uma entrada ou saída.
 * 
 * @param pin Estrutura contendo as informações do pino a ser impresso.
 */
void PrintPinOut(PinOut pin);

/**
 * @brief Configura múltiplos pinos GPIO como entrada ou saída.
 * 
 * Esta função inicializa os pinos GPIO conforme especificado no vetor de estruturas `PinOut`.
 * 
 * @param pins Ponteiro para um vetor de estruturas `PinOut`, contendo os pinos a serem configurados.
 * @param size Número de elementos no vetor de pinos.
 */
void Config(PinOut* pins, int size);

/**
 * @brief Inicializa um pino GPIO como entrada ou saída.
 * 
 * Esta função configura um pino GPIO com base no parâmetro `input`.
 * Se `input` for verdadeiro, o pino será configurado como entrada; caso contrário, será configurado como saída.
 * 
 * @param PIN Número do pino GPIO a ser configurado.
 * @param input Valor booleano que define se o pino será entrada (`true`) ou saída (`false`).
 */
void InitPin(int PIN, bool input);

/**
 * @brief Configura um pino GPIO como entrada com pull-up ativado.
 * 
 * Esta função define um pino GPIO como entrada e ativa o resistor de pull-up interno.
 * 
 * @param PIN Número do pino GPIO a ser configurado como entrada.
 */
void SetInput(int PIN);

/**
 * @brief Configura um pino GPIO como saída e inicializa-o com nível baixo.
 * 
 * Esta função define um pino GPIO como saída e define seu valor inicial como 0.
 * 
 * @param PIN Número do pino GPIO a ser configurado como saída.
 */
void SetOutput(int PIN);

#endif
