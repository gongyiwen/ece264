#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char * strcat_ex(char * * dest, int * n, const char * src)
{
  if( (*dest == NULL) )
  {
    *n = 1 + 2 * strlen(src);//it is invalid to use strlen(*dest) if dest is NULL
    char *buffer= malloc(sizeof(char) * (*n));
    *buffer = '\0';//make buffer an empty string
    strcat(buffer,src);
    free(*dest);
    *dest = buffer;//point dest to the beginning of buffer
  }
  else if((strlen(src) + strlen(*dest) + 1) > *n)
  {
    *n = 1 + 2 * (strlen(*dest) + strlen(src));
    char *buffer= malloc(sizeof(char) * (*n));
    *buffer = '\0';
    strcat(buffer,*dest);
    strcat(buffer,src);
    free(*dest);
    *dest = buffer;
  } 
  else
  {
    strcat(*dest,src);
  }
  return *dest;
}


char * * explode(const char * str, const char * delims, int * arrLen)
{  
  int ind;
  int N = 0;
  int arrInd = 0; // this is the next position where we'll create a string
  int last = 0; // 1 + the last index we saw a delimiter. Init to 0.
  for(ind = 0;ind<strlen(str);ind++)
  {
    if(strchr(delims, str[ind]) != NULL)
    {
      N++;
    }
  }
  *arrLen = N+1; //if there is one delim, there should be two arrays in the string.
  char * * strArr = malloc((*arrLen) * sizeof(char *));//create the return array
  if(N != 0)
  {
    while(arrInd < N)
    {
      for(ind = 0; ind <strlen(str) ; ind++)
      {
	if(strchr(delims, str[ind]) != NULL)
	{
	  strArr[arrInd] = malloc(sizeof(char) * (ind-last+1));
	  memcpy(strArr[arrInd],str+last,ind-last);
	  strArr[arrInd][ind-last] = '\0';
	  last = ind + 1;
	  arrInd++;
	}
      }
    }
    strArr[arrInd] = malloc(sizeof(char) * (ind-last+1));//To create the array for the last word
    memcpy(strArr[arrInd],str+last,ind-last);
    strArr[arrInd][ind-last] = '\0';
  }
  else
  {
    strArr[arrInd] = malloc(sizeof(char) * (ind-last+1));
    memcpy(strArr[arrInd],str+last,ind-last);
    strArr[arrInd][ind-last] = '\0';
  }
  return strArr;
}


char * implode(char * * strArr, int len, const char * glue)
{
  int ind;
  char * dest = NULL;
  int len1 = len;
  for(ind = 0;ind < len1-1; ind++)
  {
   strcat_ex(&dest, &len, strArr[ind]);
   strcat_ex(&dest, &len, glue);
  }
  strcat_ex(&dest, &len, strArr[ind]);//to avoid additional "glue"
  return dest;
}


int sortfunc(const void *a, const void *b)
{
  const char **a1 = (const char **)a;//string of characters
  const char **b1 = (const char **)b;
  return(strcmp(*a1,*b1));
}

void sortStringArray(char * * arrString, int len)
{
  qsort(arrString,len,sizeof(char*),sortfunc);
}


int sortfunc1(const void *a, const void *b)
{
  const char a1 = *(char*)a;//single character 
  const char b1 = *(char*)b;
  return((int)a1 - (int)b1);
}
void sortStringCharacters(char * str)
{
  qsort(str,strlen(str),sizeof(char),sortfunc1);
}


void destroyStringArray(char * * strArr, int len)
{
  int ind;
  for(ind = 0; ind < len; ind++)
  {
    free(strArr[ind]);
  }
  free(strArr);
  return;
}
