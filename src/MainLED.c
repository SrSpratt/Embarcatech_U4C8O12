#include <General_U4C6.h>
#include <MainLED_U4C6.h>


void TogglePinNoTime(uint8_t pin){
    int pinLevel = gpio_get(pin);
    gpio_put(pin, !pinLevel);
    pinLevel = gpio_get(pin);
    printf("Pino %s %s!\n", pin == 11 ? "verde" : "azul", pinLevel == 1 ? "ligado" : "desligado");
}