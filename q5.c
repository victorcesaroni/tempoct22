#include <stdio.h>
#include <stdlib.h>

#define LINHAS 3
#define COLUNAS 5
#define ARRIDX(i,j) ((i*COLUNAS)+j)

void cria_slot(int **ppSlot)
{
    int* matrix = (int*)malloc(sizeof(int) * LINHAS * COLUNAS);
    for (int line = 0; line < LINHAS; line++) {
        printf("Insira os %d valores da linha %d/%d:\n", COLUNAS, (line + 1), LINHAS);
        for (int col = 0; col < COLUNAS; col++) {
            scanf("%d", &matrix[ARRIDX(line,col)]);
        }
    }
    *ppSlot = matrix;
}

int main()
{
    int premio[LINHAS * COLUNAS] = {
        1,0,0,0,1, 
        0,1,0,1,0, 
        0,0,1,0,0
    };

    int ganhou = 0;
    while (!ganhou)
    {
        int count_prize = 0;
        int *slot = NULL;
        cria_slot(&slot);
        int comp = slot[ARRIDX(0,0)];
        
        for (int i = 0; (i < LINHAS) && !ganhou; i++)
        {
            for (int j = 0; (j < COLUNAS) && !ganhou; j++)
            {
                if (comp == slot[ARRIDX(i,j)] && premio[ARRIDX(i,j)]) {
                    count_prize++;
                }
                if (count_prize == 5) {
                    ganhou = 1;
                }
            }
        }
        
        free(slot);
        slot = NULL;

        if (!ganhou) {
            printf("Nao ganhou, tente novamente!\n");
        }
    }
    
    printf("Gahnou!\n");

    return 0;
}
