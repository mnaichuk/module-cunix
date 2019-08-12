#include "../include/test.h"

char *my_strcpy(char *dest, const char *src)
{
    char* str = dest;
    while ((*str = *src) != '\0') 
    {
        str++;
        src++;
    }
    return dest;
}
