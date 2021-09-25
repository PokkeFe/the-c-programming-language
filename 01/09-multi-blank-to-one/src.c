#include <stdio.h>

int main() 
{
    int c, lc;

    while ((c = getchar()) != EOF)
    {
        if ((c == ' ' && lc != ' ') || c != ' ')
            putchar(c);
        lc = c;
    }
}
