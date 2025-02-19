#ifndef PWM_U4C8_H
#define PWM_U4C8_H

#include "hardware/pwm.h"
#include "pico/stdlib.h"

#define PWM_WRAP 20000      /**< Valor máximo do contador PWM antes de reiniciar. */
#define PWM_CLKDIV 125.0f   /**< Fator de divisão do clock para o PWM. */

/**
 * @brief Inicializa os pinos para uso com PWM.
 * 
 * Esta função configura os pinos fornecidos para a função PWM e obtém os números de slice correspondentes.
 * 
 * @param pins Vetor contendo os números dos pinos GPIO a serem configurados como saída PWM.
 * @param slices Vetor onde serão armazenados os números de slice correspondentes a cada pino.
 */
void InitPWM(uint8_t pins[], uint8_t slices[]);

/**
 * @brief Configura os slices PWM especificados.
 * 
 * Esta função define o valor máximo do contador PWM (`PWM_WRAP`), a divisão do clock (`PWM_CLKDIV`)
 * e ativa o PWM nos slices fornecidos.
 * 
 * @param slices Vetor contendo os números dos slices PWM a serem configurados.
 */
void ConfigPWM(uint8_t slices[]);

/**
 * @brief Define a largura do pulso PWM para um pino específico.
 * 
 * Esta função ajusta o nível PWM de um pino, alterando o ciclo de trabalho do sinal PWM.
 * 
 * @param pin Número do pino GPIO configurado como saída PWM.
 * @param pulseWidth Valor do nível PWM (entre 0 e `PWM_WRAP`).
 */
void SetPWMPulseWidth(uint8_t pin, uint16_t pulseWidth);

#endif
