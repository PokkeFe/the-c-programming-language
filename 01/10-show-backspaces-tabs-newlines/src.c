#include <stdio.h>

int main()
{
    int c;

    while((c = getchar()) != EOF)
    {
        if (c == '\n')
        {
            putchar('\\');
            putchar('n');
        }
        else if (c == '\b')
        {
            putchar('\\');
            putchar('b');
        }
        else if (c == '\t')
        {
            putchar('\\');
            putchar('t');
        }
        else
        {
            putchar(c);
        }
    }

    putchar('\n');
}
