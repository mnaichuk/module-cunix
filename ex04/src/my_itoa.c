 #include "../include/test.h"

char arr[256];

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

char* my_itoa(int nmb)
{
 int flag=0;
 int i=0;
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
 
 char temp;
 int a,b;
 for (a=0, b=my_strlen(arr)-1; a<b; a++,b--)
  {
    temp=arr[a];
    arr[a]=arr[b];
    arr[b]=temp;
  }
 return arr;
 }