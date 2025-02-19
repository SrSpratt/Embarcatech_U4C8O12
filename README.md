# Embarcatech_U4C8O12  
### TAREFA U4C8O12 - Unidade 4 - Capítulo 8
#### Autor:
* Roberto Vítor Lima Gomes Rodrigues

#### Vídeo de funcionamento
* https://youtu.be/DHrwzSz4RoQ
    * Obs.: foram implementadas todas as características -> 
       * Conversor Analógico-Digital (ADC), 
       * Modulação de Largura de Pulso (PWM); 
       * Interrupção e Debouncing (verificáveis pelos botões A e o do Joystick -- ausência de missclicks) 
       * Controle dos LEDs RGB.


#### Instruções de compilação
Certifique-se de que você tem o ambiente configurado conforme abaixo:
* Pico SDK instalado e configurado.
* VSCode com todas as extensões configuradas, CMake e Make instalados.
* Clone o repositório e abra a pasta do projeto, a extensão Pi Pico criará a pasta build
* Clique em Compile na barra inferior, do lado direito (ao lado esquerdo de RUN | PICO SDK)
* Verifique se gerou o arquivo .uf2
* Conecte a placa BitDogLab e ponha-a em modo BOOTSEL
* Arraste o arquivo até a placa, que o programa se iniciará

#### Manual do programa
Ao executar o programa, as seguintes características poderão ser verificadas:
* Ao movimentar o joystick no eixo X, o LED vermelho terá seu valor ajustado com PWM¹, e o quadrado de 8x8 no display ssd1306 seguirá o movimento.
* Ao movimentar o joystick no eixo Y, o LED azul terá seu valor ajustado com PWM¹, e o quadrado de 8x8 no display ssd1306 seguirá o movimento.
* Ao clicar no botão do joystick, as bordas da imagem no display ssd1306 mudarão e o LED verde se acenderá.
* Ao clicar no botão A, os LEDs vermelho e azul se apagarão.
* ¹Obs. I: a modulação (PWM) é feita tal que na posição central dos eixos, os LEDs sejam acesos com fraca intensidade, sendo esta aumentada ao mover o joystick para os extremos.
    * Como mostrado no vídeo, o hardware não lê exatamente "posição 2048" quando o joystick está na posição central, tal que os LEDs não são apagados na posição central
* Obs. II: o debounce foi implementado nos botões, de forma que não houvesse missclick (conforme estabelecido na questão).
* Obs. III: documentei todo o código com doxygen, então ao passar o cursos do mouse em cima de qualquer uma das funções, será mostrada uma pequena descrição da implementação.
* Obs. IV: por conta da extensão de técnicas pedidas na atividade, o vídeo ficou um pouco mais extenso do que o normal.
