#include <stdio.h>
#include <answer11.h>
#include <stdlib.h>


HuffNode * HuffNode_create(int value)
{
  HuffNode * node = malloc(sizeof(HuffNode));
  node -> value = value;
  node -> right = NULL;
  node -> left = NULL;
  return node;


void HuffNode_destroy(HuffNode * tree)
{
  if(tree == NULL)
  {
    return;
  }
  HuffNode_destroy(tree -> right);
  HuffNode_destroy(tree -> left);
  free(tree);
}

// ----------------------------------------------------------------------- Stack


/**typedef struct StackNode_st
{
    HuffNode * tree;
    struct StackNode_st * next;
} StackNode;

typedef struct Stack_st
{
    StackNode * head; // head node of a linked-list
} Stack;
**/

Stack * Stack_create()
{
  Stack * node = malloc(sizeof(Stack));
  node -> head = NULL;
  return(node);
}


void Stack_destroy(Stack * stack)
{
  if(stack == NULL)
  {
    return;
  }
  StackNode * node = stack -> head;//no tree in stack head
  StackNode * nx = stack -> head -> next;
  while(node != NULL)
  {
    HuffNode_destroy(nx-> tree);
    free(nx);
    node = nx;
  }
  free(stack); 
}


int Stack_isEmpty(Stack * stack)
{
  if(stack/*->head*/ == NULL)
  {
    return 1;
  }
  return 0;
}


HuffNode * Stack_popFront(Stack * stack)
{
  if(Stack_isEmpty(stack))//if empty, return
  {
    return;
  }
  HuffNode * tn = stack -> head -> tree;
  StackNode * a = stack -> head;
  stack -> head = stack -> head -> next;
  free(a);
  return(tn);
}


void Stack_pushFront(Stack * stack, HuffNode * tree)
{
  if(stack == NULL)
  {
    return;
  }
  StackNode* sn = malloc(sizeof(StackNode));
  sn -> tree = tree;
  sn -> next = stack -> head;
  stack -> head = sn;
}
  
void Stack_popPopCombinePush(Stack * stack)
{
  HuffNode * first = Stack_popFront(stack);
  HuffNode * second = Stack_popFront(stack);
  HuffNode * node = HuffNode_create(0);
  node -> left = second;
  node -> right = first;
  Stack_pushFront(stack,node);
}

// ---------------------------------------------------- Reading HuffTree headers

/**
 * Read a Huffman Coding Tree (in text format) from 'fp'.
 */
int SizeofStack(Stack * stack)
{
  if(stack ==NULL)
  {
    return 0;
  }
  int ind = 0;
  StackNode * sn = stack -> head;
  while(sn != NULL)
  {
    ind++;
    sn = sn -> next;
  }
  return ind;
}
  
HuffNode * HuffTree_readTextHeader(FILE * fp)
{
  int c;
  Stack* sk = Stack_create();
  while((c = fgetc(fp)) != EOF)
  {
    if(c == '1')
    {
      c = fgetc(fp);
      HuffNode * tree = HuffNode_create(c);
      Stack_pushFront(sk,tree);
    }
    else if( c =='0')
    {
      if(sizeofStack(sk) == 1)
      {
	break;
      }
      Stack_popPopCombinePush(sk);
    }
  }
  Huffnode * tn = Stack_popFront(stack);
  Stack_destroy(stack);
  return tn;
}
    
    
  

/**
 * Read a Huffman Coding Tree (in binary format) from 'fp'.
 * You will need to (conceptually) read a file a bit at a time. See the README
 * for hints on how to do this.
 */
HuffNode * HuffTree_readBinaryHeader(FILE * fp);

#endif

