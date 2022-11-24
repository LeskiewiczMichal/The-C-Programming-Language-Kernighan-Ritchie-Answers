#include <stdio.h>
#include <stdbool.h>

#define MAXLINE 1000

int main(void)
{
    char c;
    int brackets, parentheses, braces, single_quote, dobule_quote; 

    // initialize to zero
    brackets = parentheses = braces = single_quote = dobule_quote = 0;

    while ((c = getchar()) != EOF)
    {
        if (c == '{')
        {
            braces++;
        }
        else if (c == '}')
        {
            braces--;
        }
        else if (c == '[')
        {
            brackets++;
        }
        else if (c == '}')
        {
            brackets--;
        }
        else if (c == '(')
        {
            parentheses++;
        }
        else if (c == ')')
        {
            parentheses--;
        }
        else if (c == '\'')
        {
            if (single_quote == 0)
            {
                single_quote = 1;
            }
            else
            {
                single_quote = 0;
            }
        }
        else if (c == '\"')
        {
            if (dobule_quote == 0)
            {
                dobule_quote = 1;
            }
            else
            {
                dobule_quote = 0;
            }
        }
    }

    printf("\n");
    
    if (brackets != 0)
    {
        printf("Curly brackets missing\n");
    }
    else if (braces != 0)
    {
        printf("Braces missing\n");
    }
    else if (parentheses != 0)
    {
        printf("Parentheses missing\n");
    }
    else if (single_quote != 0)
    {
        printf("Single quotes missing\n");
    }
    else if (dobule_quote != 0)
    {
        printf("Double quotes missing\n");
    }
}