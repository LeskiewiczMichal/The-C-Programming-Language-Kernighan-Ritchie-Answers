#include <stdio.h>

#define MAXLINE 1000
#define TAB2SPACE 8

char line[MAXLINE];

int line_getter(void);

int main(void)
{
    int i, t;
    int spacecount, len;

    while ((len = line_getter()) > 0)
    {
        spacecount = 0;
        for (i = 0; i < len; i++)
        {
            if (line[i] == ' ')
            {
                spacecount++;
            }
            if (line[i] != ' ')
            {
                spacecount = 0;
            }
            if (spacecount == TAB2SPACE)
            {
                i -= 7;
                len -= 7;
                line[i] = '\t';

                for (t = i + 1; t < len; t++)
                {
                    line[t] = line[t + 7];
                }
                spacecount = 0;
                line[len] = '\0';
            }
        }
        printf("%s", line);
    }
}

int line_getter(void)
{
    int c, i;
    extern char line[];

    for (i = 0; i < MAXLINE - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        line[i] = c;
    if (c == '\n')
    {
        line[i] = c;
        ++i;
    }
    line[i] = '\0';
    return i;
}