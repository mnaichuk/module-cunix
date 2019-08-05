#include "test.h"
#include <stdlib.h>

extern long write(int, const char *, unsigned long);

int my_puts(const char *s)
{
    int i = 0;
    while (s[i])
    {
        if (s[i] != -1){
            write(1, &s[i], 1);
            i++;
    }
        else 
            return -1;
    }
    write (1, "\n", 1);
    return 0;
}

