#ifndef INTERFACES_U4C8_H
#define INTERFACES_U4C8_H

#include "hardware/i2c.h"
#include "ssd1306.h"

#define I2C_PORT i2c1
#define I2C_SDA 14
#define I2C_SCL 15
#define endereco 0x3C

#define BAUD_RATE 115200
#define TX 0
#define RX 1

/**
 * @brief Inicializa a comunicação I2C e o display SSD1306.
 * 
 * Esta função configura a interface I2C, define as funções de GPIO para os pinos SDA e SCL, e configura o display SSD1306.
 * Além disso, a função envia os dados iniciais para o display e limpa o conteúdo da tela.
 * 
 * @param ssd Ponteiro para a estrutura SSD1306 que representa o display.
 * 
 * @note A comunicação I2C é configurada com uma taxa de 400 kHz. O display é inicializado com a resolução especificada (WIDTH x HEIGHT) e o endereço de I2C configurado.
 */
void I2CInit(ssd1306_t* ssd);

#endif