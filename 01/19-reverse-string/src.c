#include <stdio.h>

#define MAXLINE 1000

int getinputline(char s[], int lim);
void reverse(char string[]);

// reverse input line by line
int main()
{
    char line[MAXLINE];

    while(getinputline(line, MAXLINE) > 0)
    {
        reverse(line);
        printf("%s", line);
    }

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
    }
    s[i] = '\0';
    return i;
}

void reverse(char s[])
{
    int size, i, lim, temp;

    size = i = 0;
    while (s[size]!='\0')
        ++size;
    for(lim=size/2; i<lim; ++i)
    {
        temp=s[size-1-i];
        s[size-1-i] = s[i];
        s[i]=temp;
    }
}
