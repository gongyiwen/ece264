#include "answer08.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

List * List_createNode(const char * str)
{
  List * nd = malloc(sizeof(List));
  nd -> str = strdup(str);
  nd -> next = NULL;
  return nd;
}

void List_destroy(List * list)
{
  while(list != NULL)
  {
    List *p= list -> next;
    free(list -> str);
    free(list);
    list = p;
  }
}

int List_length(List * list)
{
  int length = 0;
  while(list != NULL)
  {
    if(list == NULL)
    {
      return(length);
    }
    else
    {
      length++;
    }
    list = list -> next;
  }
  return(length);
}

List * List_merge(List * lhs, 
		  List * rhs, 
		  int (*compar)(const char *, const char*))
		  {
		    if (lhs == NULL)
		    {
		      return rhs;
		    }
		    if(rhs == NULL)
		    {
		      return lhs;
		    }
		    List * first = NULL;
		    List * last = NULL;
		    while(lhs != NULL && rhs != NULL)
		    {
		      int cmp = compar(lhs -> str,rhs -> str);
		      if(cmp <= 0)
		      {
			if(last == NULL)
			{
			  first = lhs;
			  last = lhs;
			} 
			else
			{
			  last -> next = lhs;
			  last = lhs;
			}
			lhs = lhs -> next;
			last -> next = NULL;
		      }
		      else
		      {
			if(last == NULL)
			{
			  first = rhs;
			  last = rhs;
			}
			else
			{
			  last -> next = rhs;
			  last = rhs;
			}
			rhs = rhs -> next;
			last -> next = NULL;
		        }
		      if(lhs == NULL)
		      {
			last -> next = rhs;
		      }
		      else
		      {
			last -> next = lhs;
		      }
		    }
		      return first;
		  }

List * List_sort(List * list, int (*compar)(const char *, const char*))
{
    int length = List_length(list);
    if(length <= 1)
    {
      return list;
    }
    int leftLen = length / 2;
    List * lhs = list;
    List * lhs_last = list;
    while(leftLen > 0)
    {
      lhs_last = list;
      list = list ->next;
      leftLen--;
    }
    List * rhs = lhs_last -> next;
    lhs_last -> next= NULL;
    lhs = List_sort(lhs,compar);
    rhs = List_sort(rhs,compar);
    return(List_merge(lhs,rhs,compar));
}
  
  