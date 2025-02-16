#ifndef INTERFACES_U4C6_H
#define INTERFACES_U4C6_H

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

/**
 * @brief Atualiza o conteúdo do display SSD1306 com uma string personalizada.
 * 
 * Esta função atualiza o display SSD1306 com o conteúdo fornecido como uma string. 
 * Ela limpa a tela e desenha duas strings no display: uma string fixa ("Roberto Vitor") e outra fornecida como argumento.
 * O display é então atualizado com os dados desenhados.
 * 
 * @param ssd Ponteiro para a estrutura SSD1306 que representa o display.
 * @param cor Cor a ser utilizada para desenhar a string (booleano onde 'true' é uma cor e 'false' é outra).
 * @param string A string a ser desenhada no display. Deve ser uma sequência de caracteres.
 * 
 * @note O display é limpo antes de desenhar a nova string. A posição das strings desenhadas é fixa: a primeira na linha 10 e a segunda na linha 30.
 */
void I2CDraw(ssd1306_t* ssd, bool cor, char* string);

#endif