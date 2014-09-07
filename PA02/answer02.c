#include <stdlib.h>
#include <stdio.h>
#include "answer02.h"

size_t my_strlen(const char *str)
{
  size_t ind = 0;
  while(*str != '\0')
  {
    str++;
    ind++;
  }
  return ind;
}

int my_countchar(const char * str, char ch)
{
  int len;
  len = my_strlen(str);
  int count = 0;
  while(*str !='\0')
  {
    if(*str == ch)
    {
      count++;
    }
    str++;
  }
  return count;
}

char * my_strchr(const char * str, int ch)
{
  int len;
  len = my_strlen(str);
  int ind;
  for(ind = 0;ind < len + 1; ind++)
  {
    if(*str == ch)
    {
      return (char *) str;
    }
    str++;
  }
  return NULL;
  }
  
char * my_strrchr(const char * str, int ch)
{
  int len; 
  len = my_strlen(str);
  str +=len;
  int ind;
  for(ind = 0; ind < len + 1; ind++)
  {
    if(*str == ch)
    {
      return (char *) str;
    }
    str--;
  }
  return NULL;
}

char * my_strstr(const char * haystack, const char * needle)
{
  int len1;
  len1= my_strlen(haystack);
  int len2;
  len2 = my_strlen(needle);
  int count= 0;
  const char * a = needle;
  if(*needle != '\0')
  {  
    while(*haystack)
    {
	while((* needle== *haystack)&&(*needle))
	{
	  haystack++;
	  needle++;
	  count++;
	}
	if(count == len2)
	{
	  return (char*) (haystack-=len2);
	}
	else
	{
	  needle = a;
	  count = 0;
	  haystack++;
	}
    }
      return NULL;
  }
  return (char*) haystack;
}

char * my_strcpy(char * dest, const char * src)
{
  int len;
  len = my_strlen(src);
  int ind = 0;
  while( ind < len + 1)
  {
    *dest = *src;
    dest++;
    src++;
    ind++;
  }
  dest -=ind;
  return (char*)dest;
}

char * my_strcat(char * dest, const char * src)
{
  int len1;
  len1 = my_strlen(src);
  int len2;
  len2 = my_strlen(dest);
  int ind = 0;
  dest = dest + len2;
  while(ind < len1 + 1)
  {
    *dest = src[ind];
    ind++;
    dest++;
  }
  dest = dest -len1-len2;
  return (char*) dest;
}

int my_isspace(int ch)
{
  if((ch >= 9 && ch <=13) ||ch ==32)
  {
    return 1;
  }
  return 0;
}

int my_atoi(const char * str)
{
  int ret = 0;
  int len;
  len = my_strlen(str);
  int sign = 1;
  int ind;
  for(ind = 0; ind < len; ind++)
  {
    if((*str >= 9 && *str <= 13) ||*str != 32)
    {
      if(*str == '-')
      {
	sign = -1;
      }
      else if(*str >= '0' && *str <= '9')
      {
	ret *=10;
	ret +=(*str - '0');
      }
    }
    str++;
  }
  return ret*sign;
}






   
    
    
