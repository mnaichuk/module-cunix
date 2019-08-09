
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include "test.h"
char arr[256];
unsigned int  my_strlen(char *str)
{
  int a=0;
  while (*str!='\0')
  {
    ia+=1;
    str++;
  }
  return (a);
}

int miniAtoi(const char *nptr)
{
  int a=0;
  int i;
  for(i=0;nptr[i]>='0' && nptr[i]<='9';i++)
  {
    a++;
  }
  return ;
}

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

char* my_itoa(int nmb)
{
  int flag=0;
  int i=0;
  char temp;
  int a,b;
  if (nmb<0)
  {
    flag =1;
    nmb=-nmb;
  }
  do
  {
    arr[i]=nmb%10+'0';
    i++;
  }
  while(( nmb/=10)>0);
  if (flag==1)
  {
    arr[i]='-';
    i++;
  }
  arr[i]='\0';
  for (a=0, b=my_strlen(arr)-1; a<b; a++,b--)
  {
    temp=arr[a];
    arr[a]=arr[b];
    arr[b]=temp;
  }
  return arr;
}

int print_string(const char *string)
{
  for(;*string!='\0';string++)
  {
    write(1,string,1);
  }
  return 0;
}

void print_padding(const char ch, int num)
{
  for(;num>0;num--)
  {
    write(1,&ch,1);
  }
}

int determination(const char *type, va_list *argptr)
{
  int flag=0;
  char *ptrOnArg;
  int width=0;
  int pad_to_char;
  int pad_to_string;
  if (*type=='0')
  {
    type++;
    flag=1;
  }
  switch(*type)
  {
    case 's':
      print_string(va_arg(*argptr, char *));
      return 2;

    case '%':
      write(1,"%",1);
      return 2;

    case 'd':
      ptrOnArg=my_itoa(va_arg(*argptr,int ));
      print_string(ptrOnArg);
      return 2;

    default:
      width=my_atoi(type);
      pad_to_char=miniAtoi(type);
      if (*(type+pad_to_char)=='d')
      {
        ptrOnArg=my_itoa(va_arg(*argptr,int ));
        pad_to_string=width- my_strlen(ptrOnArg);
      }
      else
      {
        ptrOnArg=va_arg(*argptr,char *);
        pad_to_string=width- my_strlen(ptrOnArg);
      }
      if (flag==1)
      {
        print_padding('0',pad_to_string);
      }
      else
      {
        print_padding(' ',pad_to_string);
      }
      print_string(ptrOnArg);
      return (pad_to_char+flag+2);
  }
  return 0;
}

int my_printf(const char *format, ...)
{
  int a=0;
  va_list argptr;
  va_start(argptr,format);
  while (format[a]!='\0')
  {
    if (format[a]=='%')
    {
      a=a+determination(format+a+1, &argptr);
    }
    if (format[a]=='\n')
    {
      break;
    }
    else
    {
      write (1,format+a,1);
      a++;
    }
  }
  write(1,"\n",1);
  va_end(argptr);
  return 0;
}

