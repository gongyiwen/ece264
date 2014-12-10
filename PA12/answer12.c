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
int primalityTestParallel(uint128 value, int n_threads);

#endif
