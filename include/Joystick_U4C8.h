#ifndef JOYSTICK_U4C8_H
#define JOYSTICK_U4C8_H

#include <ssd1306.h>
#include "hardware/adc.h"

#define JOYSTICKHPIN 26   /**< Pino do eixo horizontal do joystick. */
#define JOYSTICKVPIN 27   /**< Pino do eixo vertical do joystick. */
#define JOYSTICKBPIN 22   /**< Pino do botão do joystick. */
#define ADCHCHANNEL 0     /**< Canal ADC para leitura do eixo horizontal. */
#define ADCVCHANNEL 1     /**< Canal ADC para leitura do eixo vertical. */

/**
 * @brief Configura os pinos do joystick para leitura via ADC.
 * 
 * Inicializa o ADC e configura os pinos do joystick para entrada analógica.
 */
void ConfigADC();

/**
 * @brief Lê os valores do joystick.
 * 
 * Captura os valores dos eixos X e Y do joystick e os armazena no vetor fornecido.
 * 
 * @param values Vetor onde serão armazenados os valores lidos do ADC (eixo X e Y).
 */
void JoystickRead(uint16_t values[]);

/**
 * @brief Mapeia os valores do joystick para coordenadas do display.
 * 
 * Converte os valores lidos do joystick em coordenadas adequadas para exibição na tela OLED.
 * 
 * @param values Vetor contendo os valores normalizados do joystick.
 */
void MapToDisplay(float values[]);

/**
 * @brief Desenha um ponto na tela com base na posição do joystick.
 * 
 * Atualiza a posição do ponto na tela OLED e pode ativar o PWM baseado na inclinação do joystick.
 * 
 * @param ssd Ponteiro para a estrutura do display OLED.
 * @param cor Cor do ponto a ser desenhado.
 * @param pins Vetor contendo os pinos PWM a serem controlados.
 * @param dBorder Indica se uma borda adicional deve ser desenhada na tela.
 * @param pwm Indica se o PWM deve ser ativado para indicar a inclinação do joystick.
 */
void TraceDot(ssd1306_t* ssd, bool cor, uint8_t pins[], int dBorder, bool pwm);

#endif
