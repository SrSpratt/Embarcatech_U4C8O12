#include <General_U4C6.h>
#include <stdio.h>
#include "hardware/clocks.h"
#include "pio_u4c6.pio.h"
#include "hardware/adc.h"

void PrintPinOut(PinOut pin){
    printf("---- Pin ----\n");
    printf("Pin: %d\n", pin.Pin);
    printf("Input: %d\n", pin.Input);
    printf("---- Pin ----\n");
}

void PrintPIO(PIORefs pio){
    printf("---- PIO ----\n");
    printf("Address: %d\n", pio.Address);
    printf("Offset: %d\n", pio.Offset);
    printf("State Machine: %d\n", pio.StateMachine);
    printf("---- PIO ----\n");
}

void PrintRGB(RGB color){
    printf("---- RGB ----\n");
    printf("Red: %lf\n", color.Red);
    printf("Green: %lf\n", color.Green);
    printf("Blue: %lf\n", color.Blue);
    printf("---- RGB ----\n");
}

void Config(PinOut* pins, int size, PIORefs* pio){
    stdio_init_all();

    for(int i = 0; i < size; i++)
        InitPin(pins[i].Pin, pins[i].Input);

    pio->Address = pio0;
    if(!set_sys_clock_khz(128000, false))
        printf("clock errado!");
    pio->Offset = pio_add_program(pio->Address, &pio_u4c4_program);
    pio->StateMachine = pio_claim_unused_sm(pio->Address, true);
}

void InitPIO(PIORefs* pio, int pin){
    pio_u4c4_program_init(pio->Address, pio->StateMachine, pio->Offset, pin);
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