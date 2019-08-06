#include "test.h"


int my_strcmp(char *str1, char *str2)
{
  int a;
  while (*str1==*str2)
  {
    if (*str1=='\0')
    {
      return(0);
    }
    str1++;
    str2++;
  }
  a=*str1-*str2;
  return (a);
}