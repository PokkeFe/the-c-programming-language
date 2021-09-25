#include <stdio.h>

#define MAXBARLEN 20

int main()
{
    int c, maxn, index;
    int lettercount[26];

    for (int i = 0; i < 26; i++)
        lettercount[i] = 0;

    maxn = 0;

    // count the letters
    while ((c=getchar()) != EOF)
    {
        if (c >= 'a' && c <= 'z')
        {
            index = c-'a';
            ++lettercount[index];
            if(lettercount[index] > maxn)
                maxn = lettercount[index];
        }
        else if (c >= 'A' && c <= 'Z')
        {

            index = c-'A';
            ++lettercount[index];
            if(lettercount[index] > maxn)
                maxn = lettercount[index];
        }    
    }

    // print out the histogram
    for (int i = 0; i < 26; i++)
    {
        printf("%c: ", 'a'+i);
        for (int j = 0; lettercount[i] > 0 && j < ((float)lettercount[i] / maxn) * MAXBARLEN; j++)
            printf("#");
        printf("\n");
    }
}
