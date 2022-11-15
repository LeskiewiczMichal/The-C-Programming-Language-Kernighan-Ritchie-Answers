#include <stdio.h>

#define MINLINE 81
#define MAXLINE 10000
#define TRUE 1
#define FALSE 0

int line_getter(char line[], int maxline);
int copy(char to[], int to_size, char from[]);
void reverse(char s[], int len);

main()
{
    int len;
    int max;
    char line[MAXLINE];

    max = 0;
    while ((len = line_getter(line, MAXLINE)) > 0)
    {
        if (len > 0)
        {
            reverse(line, len);
            printf("%s", line);
        }
    }

    return 0;
}

void reverse(char s[], int len)
{
    char temp[MAXLINE] = { '\0' };
    int temp_len = 0;

    for (int i = len - 1; i >= 0; i--)
    {
        temp[temp_len] = s[i];
        temp_len++;
    }


    for (int i = 0; i < temp_len; i++)
    {
        s[i] = temp[i];
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
