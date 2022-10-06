/**
Q2
Recebendo via teclado um número romano converter em número decimal e printar o resultado.
Números validos: I = 1, V = 5 , X = 10, L = 50, C = 100, D = 500, M = 1000
Exemplos : IV = 4 , VI = 6 , XII = 12 , IX =9 , VIII = 8, MDCDLXXIV = 1974
*/

#include <stdio.h>
#include <stdlib.h>

enum eRomanValIndex {
    I=0,
    V,
    X,
    L,
    C,
    D,
    M,
    NUM_VAL
};

const int ROMAN_VALUES_TO_DEC[NUM_VAL] = {
    1, // I,
    5, // V,
    10, // X,
    50, // L,
    100, // C,
    500, // D,
    1000, // M,
};

int main()
{
    char input[4096];
    int indexed[4096];

    sscanf("%s", input);

    int len = strlen(input);
    for (int i = 0; i < len; i++)
    {
        switch (input[i])
        {
            case 'I': indexed[i] = I; break;
            case 'V': indexed[i] = V; break;
            case 'X': indexed[i] = X; break;
            case 'L': indexed[i] = L; break;
            case 'C': indexed[i] = C; break;
            case 'D': indexed[i] = D; break;
            case 'M': indexed[i] = M; break;
            default:
                perror("INVALID INPUT");
                break;
        }
    }

    int temp = 0;
    int total = 0;
    int last = -1;
    for (int i = 0; i < len; i++)
    {
        int r = indexed[i];
        if (last != -1) {
            if (r > last) {
                total += temp;
                temp = 0;
            } else if (r < last) {
                total -= temp;
                temp = 0;
            } else {
                total += temp;
                temp = 0;
            }
        }
        temp += ROMAN_VALUES_TO_DEC[r];
        last = r;
    }

    total += temp;

    printf("%d\n", total);

    // TODO: finish me

    return 0;
}
