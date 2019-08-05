#include "test.h"

char s[256];

unsigned int  my_strlen(char *str)
{
    int i;
    i = 0;
    while (str[i] != '\0')
        ++i;
    return i;
}

char* my_itoa(int nmb)
{
    int i, sign;
    if ((sign = nmb) < 0) 
        nmb =  -nmb;   
    i = 0;
    do
    {      
        s[i++] = nmb % 10 + '0';

    } while ((nmb /= 10) > 0);
   
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    int k, j;
    char c;
    for (k = 0, j = my_strlen(s)-1; k<j; k++, j--)
    {
        c = s[k];
        s[k] = s[j];
        s[j] = c; 
    }
    return s;
}

