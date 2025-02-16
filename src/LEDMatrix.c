#include <LEDMatrix_U4C6.h>
#include <stdio.h>

void PrintArraySketch(double* array, int size){

    for (int i = 1; i <= size; i++){
        if (i % 5 == 1)
            printf("\n");
        printf("%.1lf ", array[i-1]);
    }
}

void PrintSketch(Sketch sketch){
    printf("---- Sketch ----\n");
    printf("-Main Color-\n");
    PrintRGB(sketch.MainColor);
    printf("-Background Color-\n");
    PrintRGB(sketch.BackgroundColor);
    printf("-Array-\n");
    PrintArraySketch(sketch.Figure, VECTORSIZE);
    printf("\n---- Sketch ----\n");

}

double* SketchArray(int frame){
    static double reset[] = {
        0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0
    };
    static double figure0[] = {
        0.0, 1.0, 1.0, 1.0, 0.0,
        0.0, 1.0, 0.0, 1.0, 0.0,
        0.0, 1.0, 0.0, 1.0, 0.0,
        0.0, 1.0, 0.0, 1.0, 0.0,
        0.0, 1.0, 1.0, 1.0, 0.0
    };
    static double figure1[] = {
        0.0, 0.0, 1.0, 0.0, 0.0,
        0.0, 0.0, 1.0, 0.0, 0.0,
        0.0, 0.0, 1.0, 0.0, 0.0,
        0.0, 0.0, 1.0, 0.0, 0.0,
        0.0, 0.0, 1.0, 0.0, 0.0
    };
    static double figure2[] = {
        0.0, 1.0, 1.0, 1.0, 0.0,
        0.0, 1.0, 0.0, 0.0, 0.0,
        0.0, 1.0, 1.0, 1.0, 0.0,
        0.0, 0.0, 0.0, 1.0, 0.0,
        0.0, 1.0, 1.0, 1.0, 0.0
    };
    static double figure3[] = {
        0.0, 1.0, 1.0, 1.0, 0.0,
        0.0, 0.0, 0.0, 1.0, 0.0,
        0.0, 1.0, 1.0, 1.0, 0.0,
        0.0, 0.0, 0.0, 1.0, 0.0,
        0.0, 1.0, 1.0, 1.0, 0.0
    };
    static double figure4[] = {
        0.0, 1.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 1.0, 0.0,
        0.0, 1.0, 1.0, 1.0, 0.0,
        0.0, 1.0, 0.0, 1.0, 0.0,
        0.0, 1.0, 0.0, 1.0, 0.0
    };
    static double figure5[] = {
        0.0, 1.0, 1.0, 1.0, 0.0,
        0.0, 0.0, 0.0, 1.0, 0.0,
        0.0, 1.0, 1.0, 1.0, 0.0,
        0.0, 1.0, 0.0, 0.0, 0.0,
        0.0, 1.0, 1.0, 1.0, 0.0
    };
    static double figure6[] = {
        0.0, 1.0, 1.0, 1.0, 0.0,
        0.0, 1.0, 0.0, 1.0, 0.0,
        0.0, 1.0, 1.0, 1.0, 0.0,
        0.0, 1.0, 0.0, 0.0, 0.0,
        0.0, 1.0, 1.0, 1.0, 0.0
    };
    static double figure7[] = {
        0.0, 1.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 1.0, 0.0,
        0.0, 1.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 1.0, 0.0,
        0.0, 1.0, 1.0, 1.0, 0.0
    };
    static double figure8[] = {
        0.0, 1.0, 1.0, 1.0, 0.0,
        0.0, 1.0, 0.0, 1.0, 0.0,
        0.0, 1.0, 1.0, 1.0, 0.0,
        0.0, 1.0, 0.0, 1.0, 0.0,
        0.0, 1.0, 1.0, 1.0, 0.0
    };
    static double figure9[] = {
        0.0, 1.0, 1.0, 1.0, 0.0,
        0.0, 0.0, 0.0, 1.0, 0.0,
        0.0, 1.0, 1.0, 1.0, 0.0,
        0.0, 1.0, 0.0, 1.0, 0.0,
        0.0, 1.0, 1.0, 1.0, 0.0
    };

    switch(frame){
        case 0:
            return figure0;
        case 1:
            return figure1;
        case 2:
            return figure2;
        case 3:
            return figure3;
        case 4:
            return figure4;
        case 5:
            return figure5;
        case 6:
            return figure6;
        case 7:
            return figure7;
        case 8:
            return figure8;
        case 9:
            return figure9;
        default:
            return reset;
    }
}

void ArrayCopySameSize(double* firstVector, double* secondVector, int size){

    for(int i = 0; i < size; i++){
        firstVector[i] = 0.0;
        firstVector[i] = secondVector[i];
    }
}

uint32_t RGBMatrix(RGB color){
    unsigned char R, G, B;
    R = color.Red * 255;
    G = color.Green * 255;
    B = color.Blue * 255;
    return (G << 24) | (R << 16) | (B << 8);
}

void Draw(Sketch sketch, uint32_t ledConf, PIORefs pio){
    pio_sm_restart(pio.Address, pio.StateMachine);
    //PrintSketch(sketch);
    for (int16_t i = 0; i < VECTORSIZE; i++){
        if (sketch.Figure[i] == 1.0)
            ledConf = RGBMatrix(sketch.MainColor);
        else
            ledConf = RGBMatrix(sketch.BackgroundColor);

        pio_sm_put_blocking(pio.Address, pio.StateMachine, ledConf);
    }
}

void Count(Sketch sketch, uint32_t ledConf, PIORefs pio, int delay){

    for(int16_t i = 0; i < 10; i++){
        ArrayCopySameSize(sketch.Figure, SketchArray(i), VECTORSIZE);
        Draw(sketch, ledConf, pio);
        sleep_ms(delay);
    }
}