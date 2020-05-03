#include "test.h"

int my_atoi(const char *nptr)
{
    int num = 0;
    int flag = 0;
    if (*nptr == '-'){
        flag = 1;
        nptr++;
}
    
    while (*nptr != '\0')
    {
        if ( *nptr >= '0' && *nptr <= '9' )
        {
        num = 10*num;
        num += *nptr - '0';
        }
       else 
           break;
       nptr++;
    }
    
return (flag? -num: num);
}
