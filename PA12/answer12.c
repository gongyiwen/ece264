#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <math.h>
#include "answer12.h"

/**
 * Convert the initial portion of C-string 'str' to an unsigned 128-bit integer
 *
 * This function should be just like atoi(...), except that it returns an 128
 * bit unsigned integer. Return 0 on any error. Don't forget you must skip 
 * white-space.
 *
 * See PA02 for hints on implementing this function.
 */
uint128 alphaTou128(const char * str)
{    //convert initial portion of str to unsigned 128 bit integer
    //just skip the white-spaces in the front
    while(*str == ' ')
    {
      str++;//skip white-space
    }
    uint128 ind = 0;
    while(*str >= 0 && *str <=9)
    {
      ind *=10;
      ind+=(*str - '0');
      str++;//increment pointer pos
    }
    return ind;
}

/**
 * Return a newly allocated C-string which represents the passed value.
 * The caller is responsible for freeing the allocated string.
 *
 * If you have already implemented alphaTou128(...) (see hint), then you should
 * be able to figure out how to implement u128ToString(...).
 */
char * u128ToString(uint128 value)
{
    uint128 num = value;
    uint128 ind = 0;
    
    while(num >= 1) 
    {// 0/10 = 0, leads to infinity loop
      ind++;
      num = num / 10;
    }
    if(num == 0) 
    {
      ind += 1;
    }
    char * str = malloc(sizeof(char) * (ind+1));
    str[ind] = '\0';
    ind -= 1;
    while(ind >= 0) 
    {
      ret[ind] = value % 10 + '0';
      ind--;
      value = floor(value / 10);
    }
    return ret;
}

/**
 * Test is 'value' is prime.
 * 'n_threads' is the number of threads to create to complete this computation.
 * Return TRUE of FALSE.
 * 
 * LEAK NO MEMORY.
 *
 * Good luck!
 */
typedef struct
{
  uint128 value;
  uint128 left;//first number in one interval
  unit128 right;//last number in one interval
  int * check;
}ThreadData;

ThreadData * ThreadData_create(uint128 value, uint128 left, uint128 right, int* check)
{
  ThreadData * thread = malloc(sizeof(ThreadData)); 
  thread -> value = value;
  thread -> left = left;
  thread -> right = right;
  thread -> check = check;
  return(thread);
}

void * worker(void * arg)
{
    ThreadData * p_x = (ThreadData *) arg;
    uint128 ind;
    if(p_x -> left <= 3) 
    {
      p_x -> left = 3;
    }
    if(p_x -> left % 2 == 0)
    {
      p_x -> left++;
    }
    if(p_x -> value > 2 && (p_x -> left < p_x ->value)) 
    {
      i = p_x -> left;
      while(i< = p_x -> right  && *(p_x -> check) == TRUE)
      {
	if (p->value % ind == 0)
	{
	  *(p-> check) = FALSE;
        }
        ind = ind + 2;
      }
    }
    pthread_exit(0);
}


int primalityTestParallel(uint128 value, int n_threads)
{
    if (value <= 1 || (value > 2 && value % 2 ==0)) 
    {
      return FALSE;
    }
    
    
    ThreadData * * ptr = malloc(sizeof(ThreadData *) * n_threads);
    pthread_t * th = malloc(sizeof(pthread_t) * n_threads);
    uint128 max = floor(sqrt(value) * 1.10);
    int ind;
    int check = TRUE;
    for(ind = 0; ind < n_threads; ind++) 
    {
      ptr[ind] = ThreadData_create(value, ind * (max / n_threads) + 1, (ind + 1) * (max/n_threads), &check);
    }

    for(ind = 0; ind < n_threads; ind++) 
    {
      pthread_create(&th[ind], NULL, worker, &ptr[ind]);
    }
    for(ind = 0; ind < n_threads; ind++) 
    {
      pthread_join(th[ind], NULL);
    }
    for(ind = 0; ind< n_threads; ind++) 
    {
      free(ptr[ind]);
    }
    free(ptr);
    free(th);

    return check;

}