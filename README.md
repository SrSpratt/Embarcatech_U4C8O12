# Embarcatech_U4C6O12  
### TAREFA U4C6O12 - Unidade 4 - Capítulo 6
#### Autor:
* Roberto Vítor Lima Gomes Rodrigues

#### Vídeo de funcionamento
* https://youtu.be/U6oxTWKkKCs
    * Obs.: foram implementadas todas as características pedidas na atividade -> Protocolos UART e I2C, verificáveis pelo monitor serial e o display OLED; Interrupções e Debouncing, verificáveis pelos botões e pela ausências de missclicks; controle dos LEDs RGBs e controle da matriz de LEDs.

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
Ao executar o programa, todos os leds serão ligados com a cor azul, indicando o início do programa:
* A lógica do programa é que ao apertar o botão A, será ligado o LED RGB verde com a indicação no display 1306 respectiva e também via UART.
    * Ao clicar novamente no botão, o LED será desligado.
* A lógica do programa é que ao apertar o botão B, será ligado o LED RGB azul com a indicação no display 1306 respectiva e também via UART.
    * Ao clicar novamente no botão, o LED será desligado.
* Ao inserir caracteres alfanuméricos no monitor serial:
    * Se for número de 0 a 9 -> aparecerão as indicações do número digitado no display, na matriz de LEDs e também no monitor serial via UART.
    * Se for letra -> aparecerão as indicações da letra digitada no display, e também no monitor serial via UART.
* Obs. I: o debounce foi implementado nos botões, de forma que não houvesse missclick (conforme estabelecido na questão).
* Obs. II: os LEDs da matriz estão configurados com o brilho mais baixo do que 100%, pois são muito fortes.
* Obs. III: documentei todo o código com doxygen, então ao passar o cursos do mouse em cima de qualquer uma das funções, será mostrada uma pequena descrição da implementação.
