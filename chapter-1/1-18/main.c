#include <stdio.h>

#define MINLINE 81
#define MAXLINE 10000
#define TRUE 1
#define FALSE 0

int line_getter(char line[], int maxline);
int copy(char to[], int to_size, char from[]);
int check_if_blank(char s[]);
void remove_trailing_blanks(char s[], int length);

main()
{
    int len;
    int max;
    char line[MAXLINE];
    char buffer[MAXLINE];
    char buffer_len = 0;
    //    char longest[MAXLINE];

    max = 0;
    while ((len = line_getter(line, MAXLINE)) > 0)
    {
        if (len > 0)
        {
            remove_trailing_blanks(line, len);
            int not_only_blanks = check_if_blank(line);
            if (not_only_blanks)
            {
                buffer_len = copy(buffer, buffer_len, line);
            }
        }
    }

    printf("%s", buffer);
    return 0;
}

void remove_trailing_blanks(char s[], int length)
{
    int i = length - 1;
    while (s[i] == '\n' || s[i] == ' ' || s[i] == '\t')
    {
        s[i] = '\0';
        i--;
    }
}

int check_if_blank(char s[])
{
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] != ' ' && s[i] != '\t' && s[i] != '\n')
        {
            return TRUE;
        }
    }
    return FALSE;
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

int copy(char to[], int to_size, char from[])
{
    int i;
    int size = to_size;
    i = 0;
    while (from[i] != '\0')
    {
        to[size] = from[i];
        size++;
        i++;
    }
    to[size] = ' ';
    size++;
    return size;
}
