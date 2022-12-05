#include <stdio.h>
#include <stdbool.h>

int any(char s1[], char s2[])
{
    int location = -1;
    bool found = false;

    for (int i = 0; s1[i] != '\0'; i++)
    {
        for (int j = 0; s2[j] != '\0'; j++)
        {
            if ((s1[i] == s2[j]) && (found == false))
            {
                location = i + 1;
                found = true;
            }
        }
    }

    return location;
}