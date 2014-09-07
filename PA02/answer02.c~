#include <stdlib.h>
#include <stdio.h>
#include "answer02.h"

size_t my_strlen(const char *str)
{
  int len;
  len = sizeof(str);
  return len;
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
  int len = my_strlen(str);
  str = str + len;
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
  int len1 = my_strlen(haystack);
  int len2 = my_strlen(needle);
  int ind1;
  int ind2;
  int count;
  if(*needle != '\0')
  {  
    for(ind1 = 0; ind1 < len1 + 1; ind1++)
    {
      for(ind2 = 0; ind2 < len2 + 1; ind2++)
      {
	count = 0;
	while(needle[ind2] == haystack[ind1])
	{
	  ind1++;
	  ind2++;
	  count++;
	  if(count == len2)
	  {
	    haystack = haystack + ind1;
	    return (char*) haystack;
	  }
	}
      }
    }
    return NULL;
  }
  return (char*) haystack;
}

char * my_strcpy(char * dest, const char * src)
{
  int len = my_strlen(src);
  int ind = 0;
  while( ind < len + 1)
  {
    dest[ind] = src[ind];
    ind++;
  }
  dest = dest - len;
  return dest;
}

char * my_strcat(char * dest, const char * src)
{
  int len1 = my_strlen(src);
  int len2 = my_strlen(dest);
  int ind = 0;
  dest = dest + len2;
  while(ind < len1 + 1)
  {
    *dest = src[ind];
    ind++;
    dest++;
  }
  dest = dest -len1-len2;
  return dest;
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
  int len = my_strlen(str);
  int sign = 1;
  int ind;
  for(ind = 0; ind < len; ind++);
  {
    if((*str >= 9 && *str <=13) ||*str ==32)
    {
      if(*str == '-')
      {
	sign = -1;
      }
      elseif(*str >= '0' && *str <= '9')
      {
	ret =ret *10;
	ret = ret + (*str - '0');
      }
    }
    str++;
  }
  return ret*sign;
}






   
    
    
