#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(char s[]);

void itob(int n, char s[], int b)
{
    int sign;
    int s_len = 0;

    // if sign is minus
    if ((sign = n) < 0)
    {
        n = -n;
    }

    int i = 0;
    do
    {
        //  get reminder of division
        int reminder = n % b;

        // save reminder to string, converting int to char number
        s[s_len] = (reminder + '0');
        s_len++;

        // divide number by base
        n /= b;

    } while (n > 0);
    
    // add minus if n was negative
    if (sign < 0)
    {
        s[s_len] = '-';
        s_len++;
    }

    reverse(s);

    // add null character at the end
    s[s_len] = '\0';
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

// test
int main()
{
    char string[1000] = { '\0' };

    itob(255, string, 10);

    printf("%s\n", string);
}