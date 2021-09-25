#include <stdio.h>

#define MAXLINE 1000
#define TABSTOP 8

int getinputline(char s[], int lim);
void expandtab(char in[], char out[], int lim, int tabstop);

int main()
{
    char linein[MAXLINE];
    char lineout[MAXLINE];
    
    while(getinputline(linein, MAXLINE) > 0)
    {
        expandtab(linein, lineout, MAXLINE, TABSTOP);
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

void expandtab(char l[], char o[], int lim, int ts)
{
    int i, n, c;
    
    n = i = 0;

    while (n < lim-1 && l[i] != '\0')
    {
        if (l[i] == '\t')
        {
            o[n] = ' ';
            ++n;
            while (n < lim-1 && n % ts != 0)
            {
                o[n] = ' ';
                ++n;
            }
            ++i;
        }
        else
        {
            o[n] = l[i];
            ++n;
            ++i;
        }
    }
    o[n] = '\0';

}
