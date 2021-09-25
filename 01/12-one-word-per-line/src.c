#include <stdio.h>

#define IN 1
#define OUT 0

int main()
{
    int c, st;

    while ((c = getchar()) != EOF)
    {
        if (c == ' ' || c == '\n' || c == '\t')
        {
            if (st == IN)
                putchar('\n');
            st = OUT;
        }
        else
        {
            st = IN;
            putchar(c);
        }
    }
}
