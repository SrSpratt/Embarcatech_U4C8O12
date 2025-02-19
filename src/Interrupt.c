#include <Interrupt_U4C8.h>

InterruptContext interruptContext = {NULL, 0, {0,0}, {0,0,0}, (ssd1306_t*)NULL, 1, true};
volatile uint32_t intervalButtonA = 0;
volatile uint32_t intervalButtonJoy = 0;

void SetRGBInterrupt(InterruptNewCallback callback, int inputPin, int pins[3]) {
    printf("RGB INTERRUPT\n");
    interruptContext.Callback = callback;
    interruptContext.inputPin = inputPin;
    interruptContext.RGBPin[2] = pins[2];
    interruptContext.RGBPin[1] = pins[1];
    interruptContext.RGBPin[0] = pins[0];
    gpio_set_irq_enabled_with_callback(inputPin, GPIO_IRQ_EDGE_RISE, true, &HandleInterruptRGB);
}

void HandleInterruptRGB(uint gpio, uint32_t events) {
    uint32_t interval = gpio == 5 ? intervalButtonA : intervalButtonJoy; 
    uint32_t currentTime = to_us_since_boot(get_absolute_time());
    uint8_t pin = 0;
    if(currentTime - interval > 250000){
        if (interruptContext.Callback != NULL) {
            if (gpio == interruptContext.pinToCompare[0]){ // se for A
                intervalButtonA = currentTime;
                //alterna o estado do pwm
                interruptContext.pwm = !interruptContext.pwm;
            } else { // se for Joystick
                intervalButtonJoy = currentTime;
                pin = interruptContext.RGBPin[2];
                interruptContext.Callback(pin);
                interruptContext.dBorder = !interruptContext.dBorder;
            }
                  
        }
    }
}