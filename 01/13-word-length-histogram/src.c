#include <stdio.h>

#define OUT 0
#define IN 1
#define MAXBARLEN 20
#define MAXNUM 12

int main()
{
    int c, state, n, maxn;
    int nwordlength[MAXNUM];

    maxn = n = 0;
    state = OUT;

    for (int i = 0; i < MAXNUM; i++)
        nwordlength[i] = 0;

    while ((c = getchar()) != EOF)
    {
        if (c == ' ' || c == '\n' || c == '\t')
        {
            if (state == IN)
            {
                if (n >= MAXNUM)
                    n = MAXNUM-1;
                ++nwordlength[n-1];
                if (nwordlength[n] > maxn)
                    maxn = nwordlength[n];
                n = 0;
            }
            state = OUT;
        }
        else
        {
            state = IN;
            ++n;
        }
    }

    for (int i = 0; i < MAXNUM; i++) 
    {
        printf("%3d%c| %4d ", i + 1, (i == MAXNUM - 1) ? '+' : ' ', nwordlength[i]);
        for (int j = 0; nwordlength[i] != 0 && j < ((float)nwordlength[i] / maxn) * MAXBARLEN; j++)
            printf("#");
        printf("\n");
    }
}
