#include <stdio.h>
#define MAXLINE 10

int getinputline(char line[], int maxline);
void copy(char to[], char from[]);

/* print longest input line */
int main()
{
    int len;
    int max;
    char line[MAXLINE];
    char longest[MAXLINE];

    max = 0;
    while ((len = getinputline(line, MAXLINE)) > 0)
    {
        if (len > max)
        {
            max = len;
            copy(longest, line);
        }
    }
    if (max > 0)
    {
        printf("%s\n", longest);
    }
    return 0;
}

/* renamed the function to avoid conflict with stdio.h */
int getinputline(char s[], int lim)
{
    int c, i;

    for (i = 0; i < lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
        s[i] = c;
    if (c == '\n')
    {
        s[i] = c;
        ++i;
        s[i] = '\0';
    }
    // this section is modified from the original program for this exercise
    else
    {
        s[i] = '\0';
        while ((c=getchar()) != EOF && c!='\n')
            ++i;
    }
    return i;
}

void copy(char to[], char from[])
{
    int i;

    i = 0;
    while((to[i] = from[i]) != '\0')
        i++;
}
