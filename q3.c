#include <stdio.h>
#include <stdlib.h>

typedef struct {
    unsigned char b,g,r,a; 
} ColorBGRA;

typedef struct {
    union {
        ColorBGRA color;
        unsigned int integer;
        unsigned char byte[4];
    };
} Color;

int main()
{
    Color corInicial;
    Color corFinal; 

    corInicial.integer = 0x00001A;
    corFinal.integer = 0xFF001A;

    int steps = 3;
    int incPerStep = (corFinal.color.r - corInicial.color.r) / (steps);

    Color cor = corInicial;
    for (int i = 0; i < steps; i++) {
        cor.color.r += incPerStep;
        //printf("A=%X R=%X G=%X B=%X (0x%08X)\n", cor.color.a, cor.color.r, cor.color.g, cor.color.b, cor.integer);
        printf("0x%06X\n", cor.integer);
    }

    return 0;
}
