#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum eRomanValIndex {
    I=0,
    V,
    X,
    L,
    C,
    D,
    M,
    NUM_VALS
};

const int ROMAN_VALUES_TO_DEC[NUM_VALS] = {
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

    scanf("%s", input);

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
            if (r < last) {
                total += temp;
                temp = 0;
            } else if (r > last) {
                total -= temp;
                temp = 0;
            }
        }
        temp += ROMAN_VALUES_TO_DEC[r];
        last = r;
    }

    total += temp;

    printf("%d\n", total);

    return 0;
}
