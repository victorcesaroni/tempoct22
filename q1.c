#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int pal(char *word, int len)
{
    if (len < 2) {
        return 1;
    }
    for (int i = 0; i < len; i++) {
        if (word[i] != word[(len-1) - i]) {
            return 0;
        }
    }
    return 1;
}

int main()
{
    /*Q1 Encontrar o maior palíndromo (trecho que lido da esquerda pra direita e vice-versa mantem a
    mesma sequência em ambos os lados).
    A sequência deve ser lida de uma arquivo.txt e devem conter os seguintes exemplos: “daomod" ,
    "asdoromametemamorfdf" , "cadasdsam", "jvvmfbsd".
    O código deve apresentar a quantidade de letras do maior palíndromo dentro de cada string e zero
    caso não encontre.*/

    char str[4096];
    char dbg[4096];
    memset(str, 0, sizeof(str));
    memset(dbg, 0, sizeof(dbg));
    int len = strlen(str);
        int maxLen = 0;

    FILE *fp = fopen("q1tests.txt", "r");

    while (fgets(str, sizeof(str), fp))
    {
        printf("%s", str);
        int len = strlen(str);
        for (int i = 0; i < len; i++) {
            for (int j = i; j < len; j++) {   
                int len = (j-i) + 1;
                if (pal(str + i, len)) {
                    if (len > maxLen) {
                        maxLen = len;
                        memset(dbg, 0, sizeof(dbg));
                        memcpy(dbg, str + i, len);
                    }
                }
            }
        }     
    }

    pritnf("%s = %d\n", dbg, maxLen);

    fclose(fp);

    return 0;
}
