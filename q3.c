/**
Q3
 o espaço de cor RGB pode ser representada por um uint32,
 onde os 8 primeiros bits menos significantes representam o canal azul,
 seguidos por 8 bits que representam a claridade de verde, que por
 sua vez são seguidos de 8 bits que nos dizem a intensidade do vermelho.
 Os 8 bits mais significantes são interpretados como o canal Alpha, ou seja,
 a transparência.
 Podemos, portanto, representar cada canal de cor por um par hexadecimal, de 00 a FF.
 Conseguimos definir então que:
 - 0x0 é equivalente a preto, já que a luminosidade de todos os canais está em 0;
 - 0xFF (255) nos daria o azul mais brilhante.
 - 0xFF00 (65280) nos daria o máximo de verde possivel;
 - 0xFF0000 (16711680) nos daria o vermelho mais vivo.
 Crie uma função que gradativamente mude e printe a cor vermelha de r_inicial para r_final em um
certo numero de passos;
 ie:
 cor_inicial = 0x00001A;
 cor_final = 0xFF001A;
 steps = 3;
 output esperado:
 0x55001A\n
 0xAA001A\n
 0XFF001A\n
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    unsigned char r;
    unsigned char g;
    unsigned char b;
    unsigned char a;
} ColorRGBA;

typedef struct {
    union {
        ColorRGBA color;
        unsigned int rgba;
    };
} Color;

int main()
{
    Color corInicial;
    Color corFinal; 

    corInicial.rgba = 0x0000001A;
    corFinal.rgba = 0x00FF001A;

    int steps = 3;
    int incPerStep = (corFinal.color.r - corInicial.color.r) / (steps);

    Color cor = corInicial;
    for (int i = 0; i < steps; i++) {
        cor.color.r += incPerStep;
        printf("0x%2X%2X%2X\n", cor.color.r, cor.color.g, cor.color.b);
    }

    return 0;
}


