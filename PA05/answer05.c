#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "answer05.h"

void printfunc(int * arr, int length)
{
  int ind;
  printf("= ");
  for(ind = 0; ind < length;ind++)
  {
    if(ind !=0)
    {
      printf(" + ");
    }
    printf("%d",*arr);
    arr++;
  }
  printf("\n");
}

void partitionAllfunc(int value, int * arr, int pos)
{
  if(value == 0)
  {
    printfunc(arr,pos);
    return;
  }
  int ind;
  for(ind = 1; ind <= value; ind ++)
  {
    arr[pos]=ind;
    partitionAllfunc(value - ind, arr, pos+1);
  }
}
    
void partitionAll(int value)
{
  int * arr;
  arr = malloc(sizeof(int) * value);
  partitionAllfunc(value,arr,0);
  free(arr);
}

void partitionIncrefunc(int value, int *arr, int pos)
{
   if(value == 0)
  {
    printfunc(arr,pos);
    return;
  }
  int ind;
  for(ind = 1; ind <= value; ind ++)
  {
    arr[pos] = ind;
    if(pos > 0)
    {
      if(arr[pos] < arr[pos + 1]) //is increasing
      {
        partitionIncrefunc(value - ind, arr, pos+1);
      }
    }
    else
    {
        partitionIncrefunc(value - ind, arr, pos+1);
     }
  }
}
  

void partitionIncreasing(int value)
{
  int * arr;
  arr = malloc(sizeof(int) * value);
  partitionIncrefunc(value,arr,0);
  free(arr);
}

void partitionDecrefunc(int value, int *arr, int pos)
{
   if(value == 0)
  {
    printfunc(arr,pos);
    return;
  }
  int ind;
  for(ind = 1; ind <= value; ind ++)
  {
    arr[pos] = ind;
    if(pos <= 0)
    {
      partitionDecrefunc(value - ind, arr, pos+1);
    }
    else
    {
      if(arr[pos] > arr[pos + 1]) //is decreasing
      {
      partitionDecrefunc(value - ind, arr, pos+1);
      }
    }
  }
}

void partitionDecreasing(int value)
{
  int * arr;
  arr = malloc(sizeof(int) * value);
  partitionDecrefunc(value,arr,0);
  free(arr);
}

void partitionOddfunc(int value, int *arr, int pos)
{
  if(value == 0)
  {
    printfunc(arr,pos);
    return;
  }
  int ind;
  for(ind = 1; ind <= value; ind ++)
  {
    if((ind % 2) == 0)
    {
      return;
    }
    else
    {
      arr[pos] = ind;
      partitionOddfunc(value - ind, arr, pos+1);
    }
  }
}
      
void partitionOdd(int value)
{
  int * arr;
  arr = malloc(sizeof(int) * value);
  partitionOddfunc(value,arr,0);
  free(arr);
}

void partitionEvenfunc(int value, int *arr, int pos)
{
  if(value == 0)
  {
    printfunc(arr,pos);
    return;
  }
  int ind;
  for(ind = 1; ind <= value; ind ++)
  {
    if((ind % 2) != 0)
    {
      return;
    }
    else
    {
      arr[pos] = ind;
      partitionEvenfunc(value - ind, arr, pos+1);
    }
  }
}
void partitionEven(int value)
{
  int * arr;
  arr = malloc(sizeof(int) * value);
  partitionEvenfunc(value,arr,0);
  free(arr);
}

void partitionOddEvenfunc(int value,int *arr,int pos)
{
  if(value == 0)
  {
    printfunc(arr,pos);
    return;
  }
  int ind;
  for(ind = 1; ind <= value; ind ++)
  {
    arr[pos] = ind;
    if (pos == 0)
    {
       partitionOddEvenfunc(value - ind, arr, pos+1);
    }
    else
    {
      if((arr[pos] % 2) != (arr[pos-1] %2))
      {
        arr[pos] = ind;
        partitionOddEvenfunc(value - ind, arr, pos+1);
      }
    }
  }
}

void partitionOddAndEven(int value)
{
  int * arr;
  arr = malloc(sizeof(int) * value);
  partitionOddEvenfunc(value,arr,0);
  free(arr);
}

int Prime(int value)
{
  int ind;
  for(ind =2; ind < value;ind++)
  {
    if(value % ind == 0)
    {
      return 0;
    }
  }
  return 1;
}

void partitionPrimefunc(int value,int *arr,int pos)
{
  if(value == 0)
  {
    printfunc(arr,pos);
    return;
  }
  int ind;
  for(ind = 2; ind <= value; ind ++)
  {
    if(Prime(ind))
    {
      arr[pos] = ind;
      partitionPrimefunc(value - ind, arr, pos+1);
    }
  }
}
  
    
  
  
void partitionPrime(int value)
{
  if(value == 1)
  {
    return;
  }
  int * arr;
  arr = malloc(sizeof(int) * value);
  partitionPrimefunc(value,arr,0);
  free(arr);
}