#include <General_U4C8.h>
#include <stdio.h>
#include "hardware/clocks.h"
#include "hardware/adc.h"

void PrintPinOut(PinOut pin){
    printf("---- Pin ----\n");
    printf("Pin: %d\n", pin.Pin);
    printf("Input: %d\n", pin.Input);
    printf("---- Pin ----\n");
}

void Config(PinOut* pins, int size){
    stdio_init_all();

    for(int i = 0; i < size; i++)
        InitPin(pins[i].Pin, pins[i].Input);
}

void InitPin(int PIN, bool input){
    gpio_init(PIN);
    if (input)
        SetInput(PIN);
    else
        SetOutput(PIN);
}

void SetInput(int PIN){
    gpio_set_dir(PIN, GPIO_IN);
    gpio_pull_up(PIN);
}

void SetOutput(int PIN){
    gpio_set_dir(PIN, GPIO_OUT);
    gpio_put(PIN, 0);
}