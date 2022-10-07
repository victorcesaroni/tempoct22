#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int isPal(char *word, int len)
{
    if (len < 2) {
        return 0;
    }
    for (int i = 0; i < len / 2 + 1; i++) {
        if (word[i] != word[(len-1) - i]) {
            return 0;
        }
    }
    return 1;
}

int main()
{
    char str[4096];
    char dbg[4096];
    memset(str, 0, sizeof(str));
    memset(dbg, 0, sizeof(dbg));

    FILE *fp = fopen("q1tests.txt", "r");

    while (fgets(str, sizeof(str), fp))
    {
        int len = strlen(str);
        int maxLen = 0;

        if (str[len-1] == '\r') str[--len] = '\0';
        if (str[len-1] == '\n') str[--len] = '\0';
        
        for (int i = 0; i < len; i++)
        {
            for (int j = i; j < len; j++)
            {   
                int sublen = (j-i) + 1;
                if (sublen > 1 && isPal(str + i, sublen) )
                {
                    if (sublen > maxLen) {
                        maxLen = sublen;
                        memcpy(dbg, str + i, sublen);
                        dbg[sublen] = '\0';
                        //printf("%s = %d\n", dbg, maxLen);
                    }
                }
            }
        }

        printf("%s, %s, %d\n", str, dbg, maxLen);
    }

    fclose(fp);

    return 0;
}
