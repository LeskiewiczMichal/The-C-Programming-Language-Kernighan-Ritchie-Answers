#include <stdio.h>

int main(void)
{
    int lim = 1000;
    char c;
    char s[lim];

    for (int i = 0; i < lim - 1; i++)
    {
        if ((c = getchar()) != 'n')
        {
            if (c != EOF)
            {
                s[i] = c;
            }
        }

    }
}