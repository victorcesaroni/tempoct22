#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int pal(char *word, int len)
{
    for (int i = 0; i < len / 2 + 1; i++) {
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

    char set[4096];
    char fuzz[4096];
    memset(set, 0, sizeof(set));
    memset(fuzz, 0, sizeof(fuzz));

    FILE *fp = fopen("q1tests.txt", "r");

    while (fgets(set, sizeof(set), fp))
    {
        printf("%s", set);
        int len = strlen(fuzz);
        int maxLen = 0;

        // search for the substring with n letters
        for (int n = 0; n < len; n++)
        {
            // build all possible combinations given the set of letters
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                }
            }

            // TODO: finish me
            
            if (pal(fuzz, n)) {
                maxLen = n;
            }
        }
    }

    fclose(fp);

    return 0;
}
