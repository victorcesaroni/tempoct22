// OK

/*Q1 Encontrar o maior palíndromo (trecho que lido da esquerda pra direita e vice-versa mantem a
mesma sequência em ambos os lados).
A sequência deve ser lida de uma arquivo.txt e devem conter os seguintes exemplos: “daomod" ,
"asdoromametemamorfdf" , "cadasdsam", "jvvmfbsd".
O código deve apresentar a quantidade de letras do maior palíndromo dentro de cada string e zero
caso não encontre.*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

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
    char str[4096];
    //char dbg[4096];
    memset(str, 0, sizeof(str));
    //memset(dbg, 0, sizeof(dbg));

    FILE *fp = fopen("q1tests.txt", "r");

    while (fgets(str, sizeof(str), fp))
    {
        int len = strlen(str);
        if (str[len-1] == '\r') {
            str[len-1] = '\0';
            len--;
        }
        if (str[len-1] == '\n') {
            str[len-1] = '\0';
            len--;
        }

        int maxLen = 0;
        
        //printf("- %s\n", str);
        for (int i = 0; i < len; i++) {
            for (int j = i; j < len; j++) {   
                int sublen = (j-i) + 1;
                if (pal(str + i, sublen)) {
                    if (sublen > maxLen) {
                        maxLen = sublen;
                        //memset(dbg, 0, sizeof(dbg));
                        //memcpy(dbg, str + i, sublen);
                        //printf("%s = %d\n", dbg, maxLen);
                    }
                }
            }
        }

        printf("%d\n", maxLen);
    }

    fclose(fp);

    return 0;
}
