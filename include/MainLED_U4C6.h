#ifndef MAINLEDU6C_H
#define MAINLEDU6C_H

#include "pico/stdlib.h"

#define REDPIN 13
#define GREENPIN 11
#define BLUEPIN 12

/**
 * @brief Alterna o estado de um pino de forma imediata, sem verificar o tempo.
 * 
 * Esta função altera o estado de um pino (liga ou desliga) e imprime o novo status do pino
 * ("ligado" ou "desligado") no terminal. Ela é usada para controlar LEDs ou dispositivos 
 * conectados a pinos específicos.
 * 
 * @param pin Pino a ser alterado (por exemplo, 11 para "verde", outro valor para "azul").
 */
void TogglePinNoTime(uint8_t pin);



#endif
