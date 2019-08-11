#include "test.h"
char *my_strcpy(char *dest, const char *src)
{
  int a;
  for(a=0;src[a]!='\0';a++)
  {
    dest[a]=src[a];
  }
  dest[a]=src[a];
  return dest;
}