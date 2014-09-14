#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char * strcat_ex(char * * dest, int * n, const char * src)
{
  int src_len = strlen(src);
  int dst_len = strlen(*dest);
  if( (*dest == NULL) )
  {
    *n = 1 + 2 * strlen(src);
    char *buffer= malloc(sizeof(char) * (*n));
    *buffer = '\0';
    strcat(buffer,src);
    free(*dest);
  }
  else if((src_len + dst_len + 1) > *n)
  {
    *n = 1 + 2 * (strlen(*dest) + strlen(src));
    char *buffer= malloc(sizeof(char) * (*n));
    *buffer = '\0';
    strcpy(buffer,*dest);
    strcat(*dest,src);
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
  char * dest;
  int ind;
  int len = strlen(str);
  int N = 0;
  for(ind = 0;ind<len;ind++)
  {
    if(strchr(delims, str[ind]) != NULL)
    {
      N=N+1;
    }
    char * * strArr = malloc((N+1) * sizeof(char *));//create the return array
  memcpy(dest,src,strlen(src)+1);
  return ;
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