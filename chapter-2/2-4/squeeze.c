#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void squeeze(char s1[], char s2[])
{
    int s2_len = strlen(s2);
    int s1_len = strlen(s1);
    char new_string[s1_len];
    int new_string_len = 0;

    // check if character from first array is present
    // in the second array
    // if it's not, copy the character to new_string
    for (int i = 0; s1[i] != '\0'; i++)
    {
        bool is_present = false;
        for (int j = 0; j < s2_len; j++)
        {
            if (s1[i] == s2[j])
            {
                is_present = true;
            }
        }
        if (!is_present)
        {
            new_string[new_string_len] = s1[i];
            new_string_len++;
        }
    }

    // copy new array to s1
    for (int i = 0; i <= new_string_len; i++)
    {
        s1[i] = new_string[i];
    }
    s1[new_string_len] = '\0';

}
