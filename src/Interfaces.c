#include <Interfaces_U4C6.h>

void I2CInit(ssd1306_t* ssd){
    i2c_init(I2C_PORT, 400 * 1000);
    gpio_set_function(I2C_SDA, GPIO_FUNC_I2C);
    gpio_set_function(I2C_SCL, GPIO_FUNC_I2C);
    gpio_pull_up(I2C_SDA);
    gpio_pull_up(I2C_SCL);
    
    ssd1306_init(ssd, WIDTH, HEIGHT, false, endereco, I2C_PORT);
    ssd1306_config(ssd); // Configura o display
    ssd1306_send_data(ssd); // Envia os dados para o display

    // Limpa o display. O display inicia com todos os pixels apagados.
    ssd1306_fill(ssd, false);
    ssd1306_send_data(ssd);
}

void I2CDraw(ssd1306_t* ssd, bool cor, char* string){
    // Atualiza o conteúdo do display com animações
    ssd1306_fill(ssd, !cor); // Limpa o display
    ssd1306_rect(ssd, 1, 1, 127, 63, cor, !cor);
    ssd1306_rect(ssd, 2, 2, 126, 62, cor, !cor);
    ssd1306_send_data(ssd); // Atualiza o display

    //sleep_ms(1000);
}