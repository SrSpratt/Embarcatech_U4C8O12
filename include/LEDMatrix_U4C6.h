#ifndef LEDMATRIXU4C6_H
#define LEDMATRIXU4C6_H

#include "General_U4C6.h"

#define MATRIXPIN 7 // Número do pino para a matriz de LEDs.
#define VECTORSIZE 25 // Tamanho do vetor que representa a matriz de LEDs (5x5).

/**
 * @struct Sketch
 * @brief Representa um desenho a ser exibido em uma matriz de LEDs.
 * 
 * Contém os dados da figura (matriz de 25 elementos), as cores de fundo e principal, e o índice do desenho.
 */
typedef struct Drawing {
    double Figure[25];           // Vetor de 25 valores representando a figura a ser exibida na matriz.
    int Index;                   // Índice do desenho, utilizado para referenciar o desenho na animação.
    RGB MainColor;               // Cor principal do desenho (para os pontos '1.0' na figura).
    RGB BackgroundColor;         // Cor de fundo do desenho (para os pontos '0.0' na figura).
} Sketch;

/**
 * @brief Imprime o conteúdo de um vetor de desenhos.
 * 
 * @param array Vetor de valores representando uma figura a ser desenhada.
 * @param size Tamanho do vetor.
 */
void PrintArraySketch(double* array, int size);

/**
 * @brief Imprime os detalhes de um desenho.
 * 
 * Exibe as cores principal e de fundo, bem como o vetor da figura.
 * 
 * @param sketch Estrutura contendo o desenho a ser impresso.
 */
void PrintSketch(Sketch sketch);

/**
 * @brief Retorna um vetor representando uma figura específica com base no índice fornecido.
 * 
 * @param frame Índice do desenho (0-9). Cada índice corresponde a uma figura específica.
 * @return Vetor de 25 valores representando a figura.
 */
double* SketchArray(int frame);

/**
 * @brief Copia os valores de um vetor para outro com o mesmo tamanho.
 * 
 * @param firstVector Vetor de destino, que será preenchido com os dados de secondVector.
 * @param secondVector Vetor de origem, cujos dados serão copiados.
 * @param size Tamanho dos vetores.
 */
void ArrayCopySameSize(double* firstVector, double* secondVector, int size);

/**
 * @brief Converte uma cor RGB para um valor de 32 bits (usado para configuração do LED).
 * 
 * A cor é representada no formato RGB, onde cada componente é multiplicado por 255.
 * O valor final é retornado como um valor de 32 bits.
 * 
 * @param color A cor a ser convertida para o formato RGB de 32 bits.
 * @return O valor de 32 bits representando a cor.
 */
uint32_t RGBMatrix(RGB color);

/**
 * @brief Desenha uma figura na matriz de LEDs, com base na configuração fornecida.
 * 
 * A função define os LEDs para exibir os valores de `Figure` com as cores apropriadas.
 * 
 * @param sketch Desenho que será exibido.
 * @param ledConf Configuração do LED.
 * @param pio Referência ao PIO, que gerencia o controle dos LEDs.
 */
void Draw(Sketch sketch, uint32_t ledConf, PIORefs pio);

/**
 * @brief Executa a animação de desenhos em uma sequência.
 * 
 * A função percorre um conjunto de desenhos e os exibe na matriz de LEDs com um intervalo de tempo
 * entre cada quadro.
 * 
 * @param sketch Desenho atual a ser exibido.
 * @param ledConf Configuração do LED.
 * @param pio Referência ao PIO, que gerencia o controle dos LEDs.
 * @param delay Tempo de atraso entre a troca dos quadros, em milissegundos.
 */
void Count(Sketch sketch, uint32_t ledConf, PIORefs pio, int delay);


#endif
