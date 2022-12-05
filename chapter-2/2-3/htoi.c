#include <stdio.h>
#include <math.h>
#include <string.h>

int htoi(char s[])
{
    int s_len = strlen(s);
    int sum = 0;
    int exponent = 0;
    //  witch each loop pass:
    //      sum += corresponding char times exponent
    //      exponent++
    for (int i = s_len - 1; i >= 0; i--, exponent++)
    {
        char c = s[i];
        int times;

        if (c >= '0' && c <= '9')
        {
            times = c - '0';
        }
        else if (c >= 'a' && c <= 'f')
        {
            times = c - 'a' + 10;
        }
        else if (c >= 'A' && c <= 'F')
        {
            times = c - 'A' + 10;
        }
        // check for optional 0x or 0X on start of string
        else if ((c == 'x' || c == 'X') && s[i - 1] == '0')
        {
            return sum;
        }
        else 
        {
            printf("Incorrect input");
            return -1;
        }
        sum += times * pow(16, exponent);
    }
    
    return sum;
}
