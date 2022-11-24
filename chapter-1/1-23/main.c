// ITERATE line
            // IF line[i] = '"'
                // change in_quote from true to false or from false to true
            // IF !in_quote
                // IF line[i] is '/' and line[i + 1] is '/'
                    // i = i + 1
                    // in_comment = true
                // IF line[i] == '\n' and in_comment
                    // PRINT newline
                    // in_comment = false
                // IF line[i] == '/' and line[i + 1] == '*'
                    // in_comment = true
                    // i = i + 1
                // IF line[i] == '*' and line[i + 1] == '/'
                    // in_comment = false
                    // i = i + 1
                // IF in_comment
                    // do nothing
                // ELSE
                    // PRINT line[i]
            // ELSE
                // PRINT line[i]
                
#include <stdio.h>

#define MAXLINE 1000
#define TRUE 1
#define FALSE 0

int line_getter(char s[], int lim);

int main()
{
    char line[MAXLINE];
    int len;
    int in_quote = FALSE;
    int in_comment = FALSE;

    while ((len = line_getter(line, MAXLINE)) > 0)
    {
        for (int i = 0; i < len; i++)
        {
            if (line[i] == '"')
            {
                if (in_quote)
                {
                    in_quote = FALSE;
                }
                else
                {
                    in_quote = TRUE;
                }
            }
            if (!in_quote)
            {
                if (line[i] == '/' && line[i + 1] == '/')
                {
                    in_comment = TRUE;
                    i++;
                }
                else if (line[i] == '\n' && in_comment)
                {
                    printf("\n");
                    in_comment = FALSE;
                }
                else if (line[i] == '/' && line[i + 1] == '*')
                {
                    in_comment = TRUE;
                    i++;
                }
                else if (line[i] == '*' && line[i + 1] == '/')
                {
                    in_comment = FALSE;
                    i++;
                }
                else if (in_comment)
                {
                    ;
                }
                else
                {
                    printf("%c", line[i]);
                }
            }
        }
    }
}

int line_getter(char s[], int lim)
{
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++)
    {
        s[i] = c;
    }
    if (c == '\n')
    {
        s[i] = c;
        i++;
    }
    s[i] = '\0';
    return i;
}