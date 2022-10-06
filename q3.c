// OK
#include <stdio.h>
#include <stdlib.h>
#define LINHAS 3
#define COLUNAS 5
int **cria_slot(int **slot)
{
    int col;
    int line;
    line = 0;
    slot = malloc (sizeof(int *) * 3);
    while (line < 3)
        slot[line++] = malloc (sizeof (int));
    line = 0;
    col = 0;
    while (line < 3)
    {
        printf("Insira os valores da linha %d:\n", (line + 1));
        while (col < 5)
        {
            scanf("%d", &slot[line][col]);
            col++;
        }
        col = 0;
        line++;
    }
    return (slot);
}
int main (void)
{
    int premio[LINHAS][COLUNAS] = {{1,0,0,0,1}, {0,1,0,1,0}, {0,0,1,0,0}};
    int **slot = 0;
    int lines = 0;
    int cols = 0;
    slot = cria_slot(slot);
    int comp = slot[0][0];
    int count_prize = 0;
    while (lines < 3 && count_prize != 5)
    {
        while (cols < 5)
        {
            if (comp == slot[lines][cols] && premio[lines][cols])
            {
                count_prize++;
            }
            cols++;
        }
        cols = 0;
        lines ++;
        if (lines == 3 && count_prize != 5)
        {
            lines = 0;
            while (lines < 3)
                free (slot[lines++]);
            free(slot);
            lines = 0;
            cols = 0;
            count_prize = 0;
            slot = cria_slot(slot);
            comp = slot[0][0];
        }
    }
    printf ("Gahnou!\n");
    return (0);
}

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
