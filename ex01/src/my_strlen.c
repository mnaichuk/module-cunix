#include "test.h"
#include <stdio.h>
unsigned int  my_strlen(char *str)
{
  int a=0;
	while (*str!='\0')
  {
    a+=1;
	  str++;
  }
	return (a);
}

