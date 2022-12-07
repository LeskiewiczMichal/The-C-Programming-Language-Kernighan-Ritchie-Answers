#include <stdio.h>

void expand(char s1[], char s2[])
{
    char last = '\0';
    int s2_len = 0;

    for (int i = 0; s1[i] != '\0'; i++)
    {
        char c = s1[i];
        // if char is '-' and last is empty or char is '-' and next is null
        if ((c == '-' && last == '\0') || (c == '-' && s1[i + 1] == '\0'))
        {
            s2[s2_len] = '-';
            s2_len++;
        }
        else if (c == '-')
        {
            continue;
        }
        // if last is empty or last is not the same type (case letter or digit) as current
        else if (
            last == '\0' ||
            ((c >= 'a' && c <= 'z') && (last < 'a' || last > 'z')) ||
            ((c >= 'A' && c <= 'Z') && (last < 'A' || last > 'Z')) ||
            ((c >= '0' && c <= '9') && (last < '0' || last > '9')))
        {
            last = c;
        }
        // iterate through last to current inclusive and add each element to s2
        else
        {
            for (int i = last; i <= c; i++)
            {
                s2[s2_len] = (char)i;
                s2_len++;
            }
        }
    }

    s2[s2_len] = '\0';
}

// test
int main()
{
    char s1[1000] = "-a-fC-E0-4";
    char s2[1000] = "\0";
    expand(s1, s2);

    printf("%s\n", s2);
}