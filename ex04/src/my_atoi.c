#include "test.h"
int my_atoi(const char *nptr)
{
  int result=0;
  int flag=0;
  int i=0;
  if (*nptr=='-')
  {
    flag=1;
    i=1;
  }
  for (;nptr[i]>='0' && nptr[i]<='9';i++) 
  {
    result=10*result + nptr[i]-'0';
  }
  if (flag==1)
  {
    result=-result;
  }
  return (result);
}