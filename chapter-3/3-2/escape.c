#include <stdio.h>

void escape(char s[], char t[])
{
    int t_len = 0;

    for (int i = 0; s[i] != '\0'; i++)
    {
        char c = s[i];

        switch (c)
        {
            case '\n':
                t[t_len] = '\\'; 
                t_len++;
                t[t_len] = 'n';
                t_len++;
                break;
            case '\t':
                t[t_len] = '\\'; 
                t_len++;
                t[t_len] = 't';
                t_len++;
                break;
            default:
                t[t_len] = c;
                t_len++;
                break;
        }
    }
    t[t_len] = '\0';
}