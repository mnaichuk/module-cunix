#include "test.h"
#include <stdarg.h>
#include <stddef.h>
#include <unistd.h>
char s[256]; 
unsigned int  my_strlen(char *str)
{
    int i;
	i = 0;
	while (str[i] != '\0')
        ++i;
	return i;
}

int my_atoi(const char *nptr)
{
    int num = 0;
    int flag = 0;
    if (*nptr == '-')
    {
        flag = 1;
        nptr++;
    }
    while (*nptr != '\0')
    {
        if ( *nptr >= '0' && *nptr <= '9' )
        {
            num *= 10;
            num += *nptr - '0';
        }
        else
            break;
        nptr++;
    }
		return (flag? -num: num);
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
	 }
    while ((nmb /= 10) > 0);
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
 
int ndigits (const char *str)
{
    int i;
    for(i = 0; *(str+i) >= '0' && *(str+i) <= '9'; i++);
    return i;
}

void printStr (const char *str)
{
    for( int i = 0; *(str + i) != '\0'; i++ ) write(1, str + i, 1);
}

void printChar (const int count, const char str)
{
    for( int i = 0; i < count; i++) write(1, &str, 1);
}

int convertation (const char* type, va_list* args)
{
    int length = 0;
    int shift = 0;
    int skip = 0;
    char *item;
    switch(*type)
    {
        case '%':
            printStr("%");
            return 1;
        case 's':
            printStr(va_arg(*args, char*));
            return 1;
        case 'd':
            printStr(my_itoa(va_arg(*args, int)));
            return 1;
        case '0':
            shift = my_atoi(type + 1);
            skip = ndigits(type + 1);
            if( type[skip + 1] == 's' )
                item = va_arg(*args, char*);
            else
                item = my_itoa(va_arg(*args, int));
            length = my_strlen(item);
            printChar(shift - length, '0');
            printStr(item);
            return skip + 2;
        default:
            shift = my_atoi(type);
            skip = ndigits(type);
            if( type[skip] == 's' )
                item = va_arg(*args, char*);
            else
                item = my_itoa(va_arg(*args, int));
            length = my_strlen(item);
            printChar(shift - length, ' '); //padding
            printStr(item);
            return ++skip;
         }
    return 0;
}

int my_printf(const char *format, ...)
{
    va_list argList;
    va_start(argList, format);
    int i = 0;
    do
    {
        if( format[i] == '%' )
        {
            i += convertation(format+i+1, &argList) + 1;
        }
        else
        {
            write(1, format+i, 1);
            i++;
        }
    }
    while (format[i] != '\0');
    va_end(argList);
    return 0;
}
