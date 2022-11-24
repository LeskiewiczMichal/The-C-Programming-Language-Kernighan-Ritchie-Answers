#include <stdio.h>

int main()
{
    char c;
    int count = 0;
    while ((c = getchar()) != EOF)
    {
        if (c == ' ')
        {
            count++;
            if (count > 16)
            {
                printf("\n");
                count = 0;
            }
            else
            {
                printf(" ");
            }
        }
        else if (c == '\t')
        {
            count += 4;
            if (count > 16)
            {
                printf("\n");
                count = 0;
            }
            else
            {
                printf("\t");
            }
        }
        else
        {
            if (count > 16)
            {
                printf("-\n");
                putchar(c);
                count = 0;
            }
            else
            {
                putchar(c);
                count++;
            }
        }
    }
}