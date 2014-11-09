#include "answer09.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

BusinessNode * create_node(char * stars, char * name, char * address)
{
  BusinessNode * node;
  node = malloc(sizeof(BusinessNode));
  if(node == NULL)
  {
    return node;
  }
  node -> stars = stars;
  node -> address = address;
  node -> name = name;
  node -> left = NULL;
  node -> right = NULL;
  return(node);
}

BusinessNode * tree_insert(BusinessNode * node, BusinessNode * root)
{
  if(root == NULL)
  {
    return(node);
  }
  else if(strcmp((node -> name),(root -> name)) <= 0)
  {
    root -> left = tree_insert(node, root -> left); 
  }
  else
  {
    root -> right = tree_insert(node, root -> right);
  }
  return root;
}

char * * explode(char * str)
{  
  int ind;
  int N = 0;
  int arrInd = 0; // this is the next position where we'll create a string
  int last = 0; // 1 + the last index we saw a delimiter. Init to 0.
  if(str == NULL)
  {
    return NULL;
  }
  for(ind = 0;ind < strlen(str);ind++)
  {
    if(str[ind]=='\t')
    {
      N++;
    }
  }
  int arrLen = N+1; //if there is one delim, there should be two arrays in the string.
  //printf("arrLen = %d",arrLen);
  char * * strArr = malloc((arrLen) * sizeof(char *));//create the return array
  if(N != 0)
  {
    while(arrInd < N)
    {
      for(ind = 0; ind <strlen(str) ; ind++)
      {
	if(str[ind] == '\t')
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
  FILE * fptr = fopen(filename,"r");
  if(fptr == NULL)
  {
    return NULL;
  }
  BusinessNode * root=NULL;
  while(! feof(fptr))
  {
    char ch[250];
    fgets(ch, 200, fptr);
    char * * strArr = explode(ch);
    //printf("%s %s %s\n",strArr[0],strArr[1],strArr[2]);
    BusinessNode * node = create_node(strArr[0],strArr[1],strArr[2]);

    //free(ch);
    free(strArr);
    root = tree_insert(node, root);
    //print_tree(root);
  }
  fclose(fptr);
  return root;
}
     
BusinessNode * tree_search_name(char * name, BusinessNode * root)
{
  BusinessNode * node = NULL;
  if(root == NULL)
  {
    return NULL;
  }
  if(strcmp(name, root -> name) ==0)
  {
    return root;
  }
  if(strcmp(name, root -> name) < 0)
  {
    node = tree_search_name(name, root -> left);
  }
  if(strcmp(name, root -> name) > 0)
  {
    node = tree_search_name(name,root -> right);
  }
  return node;
  /*
  if(root == NULL)
  {
    return NULL;
  }
  if(name == (root -> name))
  {
    print_node(root);
    return root;
  }
  if(name < (root -> name))
  {
    return tree_search_name(name, root -> left);
  }
  return tree_search_name(name, root -> right);*/
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
  print_tree(tree -> left);
  printf("rate:%s \nname: %s \naddress: %s \n",tree -> stars, tree -> name, tree -> address);
  print_tree(tree -> right);
}


void destroy_tree(BusinessNode * root)
{
  if(root == NULL)
  {
    return;
  }
  destroy_tree(root -> left);
  destroy_tree(root -> right);
  free(root->stars);
  free(root->name);
  free(root->address);
  free(root);
}
/*
int main(int argc, char * * argv)
{
   //BusinessNode * root = create_node("5.0", "random name", "random address");
   //root->left = create_node("3.5", "another name", "another address");
   //root->right = create_node("4.0", "yet another name", "some address");
   //root->left->right = create_node("1.5", "name 3", "address 3");
   //print_tree(root);
   BusinessNode * root = load_tree_from_file("yelp_businesses.tsv");
   BusinessNode * node = create_node(strdup("5.0"),strdup("test node"),strdup("no address"));
   root = tree_insert(node,root);
   print_tree(root);
   //BusinessNode *node = tree_search_name("Eric Goldberg",tree);
   //print_node(node);
   //print_node(tree_search_name("another name",root));
   //root = load_tree_from_file(argv[1]);
  // print_tree(root);
   return 0;
}
*/







