#ifndef INTERRUPTU4C8_H
#define INTERRUPTU4C8_H

#include <General_U4C8.h>

/**
 * @brief Tipo de função de callback para interrupções baseadas em novos eventos.
 * 
 * Esta função de callback é chamada quando um novo evento de interrupção é gerado, 
 * com o parâmetro `uint8_t` representando o pino associado.
 */
typedef void (*InterruptNewCallback)(uint8_t);

/**
 * @brief Tipo de função de callback para interrupções relacionadas ao display.
 * 
 * Esta função de callback é chamada quando ocorre um evento de interrupção e 
 * é responsável por atualizar o display. O parâmetro `ssd1306_t*` é o ponteiro 
 * para a estrutura do display, e o parâmetro `uint8_t` é o pino que gerou a interrupção.
 */
typedef void (*InterruptDisplayCallback)(ssd1306_t*, uint8_t);

/**
 * @brief Estrutura que armazena o contexto de uma interrupção.
 * 
 * Esta estrutura contém os dados necessários para processar interrupções associadas a um display,
 * incluindo as funções de callback e os pinos relevantes.
 */
typedef struct {
    InterruptNewCallback Callback;        /**< Função de callback chamada quando uma interrupção é gerada. */
    int inputPin;                         /**< Pino de entrada que ativa a interrupção. */
    int pinToCompare[2];                  /**< Pinos que serão comparados para disparar a interrupção. */
    int RGBPin[3];                        /**< Pinos RGB associados aos LEDs para controle. */
    ssd1306_t* SSD;                       /**< Ponteiro para o display SSD1306. */
    bool dBorder;                         /**< Indicador de estado da borda de detecção. */
    bool pwm;                             /**< Indicador de controle PWM para LEDs. */
} InterruptContext;

/**
 * @brief Contexto global de interrupção, contendo o estado atual da interrupção.
 */
extern InterruptContext interruptContext;

/**
 * @brief Configura as interrupções associadas ao controle de LEDs RGB.
 * 
 * Esta função configura a interrupção para o pino de entrada especificado e associa as funções de callback
 * para o evento de interrupção e a atualização do display. Ela também configura os pinos RGB a serem usados.
 * 
 * @param callback Função de callback a ser chamada quando uma interrupção é gerada.
 * @param inputPin Pino de entrada que ativa a interrupção.
 * @param pins Array contendo os pinos RGB a serem usados.
 */
void SetRGBInterrupt(InterruptNewCallback callback, int inputPin, int pins[3]);

/**
 * @brief Manipulador de interrupção para controle de LEDs RGB.
 * 
 * Esta função é chamada quando uma interrupção é gerada e processa o evento de interrupção. 
 * Ela verifica o tempo entre interrupções e chama as funções de callback correspondentes para 
 * atualizar o estado dos LEDs e do display.
 * 
 * @param gpio Pino de interrupção que gerou o evento.
 * @param events Eventos associados à interrupção (por exemplo, borda de subida).
 */
void HandleInterruptRGB(uint gpio, uint32_t events);

#endif
