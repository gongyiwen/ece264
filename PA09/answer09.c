#include "answer09.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

BusinessNode * create_node(char * stars, char * name, char * address)
{
  BusinessNode * node;
  node = malloc(sizeof(BussinessNode));
  if(node == NULL)
  {
    return node;
  }
  node -> stars = *stars;
  node -> address = *address;
  node -> name = *name;
  node -> left = NULL;
  node -> right = NULL;
  return(node);
}

BusinessNode * tree_insert(BusinessNode * node, BusinessNode * root)
{
  if(root == NULL)
  {
    return(create_node(node));
  }
  if((node -> name) <= (root -> name))
  {
    root -> left = tree_insert(node, root -> left); 
  }
  else
  {
    root -> right = tree_insert(node, root -> right);
  }
  return root;
}

char * * explode(const char * str, const char * delims)
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
  int arrLen = N+1; //if there is one delim, there should be two arrays in the string.
  char * * strArr = malloc((arrLen) * sizeof(char *));//create the return array
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

BusinessNode * load_tree_from_file(char * filename)
{
  FILE * fptr = fopen(filename,'r');
  BussinessNode * root = NULL;
  while(!foef(fptr))
  {
    char * ch;
    int ind = 0;
   do
   {
     ch[ind] = fgetc(fptr);
     ind++;
   }while(ch != '\n');
   char **strArr = explode(ch,'\t');
   BussinessNode * node = create_node(strArr[0],strArr[1],strArr[2]);
   root = tree_insert(node, root);
  }
  return root;
}
     
BusinessNode * tree_search_name(char * name, BusinessNode * root)
{
  if(root == NULL)
  {
    return NULL;
  }
  if(name == (root -> name))
  {
    return root;
  }
  if(name <= (root -> name))
  {
    return tree_search_name(name, root -> left);
  }
  return tree_search_name(name, root -> right);
}


void print_node(BusinessNode * node)
{
  if(node == NULL)
  {
    printf("The node is empty.");
  }
  printf("rate:%s \nname: %s \naddress: %s \n",node -> stars, node -> name, node -> address);
}

void print_tree(BusinessNode * tree)
{
  if(tree == NULL)
  {
    return;
  }
  printf("rate:%s name: %s address: %s\n",tree -> stars, tree -> name, tree -> address);
  print_tree(printPreorder(tree -> left);
  print_tree(printPreorder(tree -> right);
}


void destroy_tree(BusinessNode * root)
{
  if(root == NULL)
  {
    return;
  }
  destroy_tree(root -> left);
  destory_tree(root -> right);
  free(root);
}

