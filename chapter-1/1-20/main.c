#include <stdio.h>

#define TABSTOP 8
#define MAXLINE 1000
#define TAB '\t'

int line_getter(char s[], int lim);
int calculate_spaces(int char_num);

int main(void)
{
    int char_counter = 0;
    char input[MAXLINE];

    // get lines
    while (line_getter(input, MAXLINE) > 0)
    {
        // ITERATE input
        for (int i = 0; input[i] != '\0'; i++)
        {
            // if character is tab
            if (input[i] == TAB)
            {
                // find out number of spaces
                int spaces = calculate_spaces(char_counter);
                // printf("%d", spaces);
                // print number of spaces
                for (int j = 0; j < spaces; j++)
                {
                    putchar(' ');
                    char_counter++;
                }
            }
            else
            {
                putchar(input[i]);
                char_counter++;
            }
            
        }

        char_counter = 0;   
    }
}

int calculate_spaces(int char_num)
{
    return TABSTOP - (char_num % TABSTOP);
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
