#include <stdio.h>

#define MAXLINE 256
#define TABSTOP 8

#define IN 1
#define OUT 0

int getinputline(char s[], int lim);
void entab(char in[], char out[], int lim, int tabstop);

int main()
{
    char linein[MAXLINE];
    char lineout[MAXLINE];

    while(getinputline(linein, MAXLINE) > 0)
    {
        entab(linein, lineout, MAXLINE, TABSTOP);
        printf("%s", lineout);
    }

}

int getinputline(char s[], int lim)
{
    int c, i;

    for (i = 0; i < lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
        s[i] = c;
    if (c == '\n')
    {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

void entab(char in[], char out[], int lim, int tabstop)
{
    // i - index of in
    // j - index of out
    // d - distance from start of spaces
    // st - state
    int i, j, d, st;
    
    i = j = d = 0;
    st = OUT;

    while (i < lim && in[i] != '\0')
    {
        if(st == OUT)
        {
            if (in[i] == ' ')
            {
                st = IN;
                d = 0;
            }
            else
            {
                out[j] = in[i];
                ++i;
                ++j; 
            }
        }
        else
        {
            if (in[i] == ' ')
            {
                ++i;
                ++d;
                
                if (i % tabstop == 0)
                {
                    out[j] = '\t';
                    ++j;
                    d = 0;
                }
            }
            else
            {
                st = OUT;
                for( ;d > 0; --d)
                {
                    out[j] = ' ';
                    ++j;
                }
            }
        }
    }
    if (st == IN)
    {
        for( ;d > 0; --d)
        {
            out[j] = ' ';
            ++j;
        }
    }
    out[j] = '\0';
}
