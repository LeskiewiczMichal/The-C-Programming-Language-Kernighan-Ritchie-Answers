#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(char s[]);

// takes: number, string to put into, minimal padding on printf
void itoa(int n, char s[], int p)
{
    int i, sign;
    
    if ((sign = n) < 0)
    {
        n = -n;
    }

    i = 0;

    do
    {
        s[i++] = n % 10 + '0';
    } while ((n /= 10) > 0);
    
    if (sign < 0)
    {
        s[i++] = '-';
    }

    // check if string has enough characters to match minimal padding
    // if not, add spaces in front
    int s_len = strlen(s);
    while (s_len < p)
    {
        s[s_len] = ' ';
        s_len++;
    }
    s[s_len] = '\0';
    reverse(s);
}

// reverse string in place, taken from the book
void reverse(char s[])
{
    int c, i, j;

    for (i = 0, j = strlen(s) - 1; i < j; i++, j--)
    {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

int main()
{
    char string[500] = { '\0' };

    itoa(512, string, 4);

    printf("%s\n", string);
}