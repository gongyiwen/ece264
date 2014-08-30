#include <stdlib.h>
#include "answer01.h"

int arraySum(int * array, int len)
{   
    int sum = 0;
    int ind;
    for(ind =0;ind<len;ind++)
    {
      sum = sum +array[ind];
    }
    return sum;
}

int arrayCountNegative(int * array, int len)
{
    int count = 0;
    int ind;
    for(ind = 0; ind < len; ind++)
    {
      if(array[ind] < 0)
      {
        count++;
      }
    return count;
}

int arrayIsIncreasing(int * array, int len)
{   
    int ind;
    int incre = 1;
    for(ind = 0; ind < len - 1; ind++)
    {
      if(array[ind] > array[ind + 1])
      {
         incre = 0;
      }

    return incre;
}

int arrayIndexRFind(int needle, const int * haystack, int len)
{
    int ind;
    int pos;
    for(ind = 0;ind < len;ind++)
    {
      if(haystack[ind] == needle)
      {
        pos = ind;
      }
      if(haystack[ind] != needle && ind == len - 1)
      {
        pos = -1;
      }
    return pos;
}

int arrayFindSmallest(int * array, int len)
{
    int ind;
    int small = array[0];
    int pos;
    
    for(ind = 0; ind < len; ind++)
    {
      if(small < array[ind+1])
      {
        pos = ind;
        small = array[ind];
      }
    }
    if(len==0)
    {
      small =0;
    }

    return small;
}
