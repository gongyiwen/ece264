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
  StackNode * node = stack -> head;
  StackNode * nx = NULL;//next
  while(node != NULL)
  {
    nx = node -> next;
    HuffNode_destroy(node-> tree);
    free(node);
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
/**
 * Pop the front (top) 'value' (i.e. Huffman tree) from the stack.
 *
 * More precisely, this function must do three things:
 * (1) Save the value (i.e. Huffman tree) of the head node of the stack's list
 * (2) Remove the head node of the stack's list, freeing it.
 * (3) Return the value (i.e. Huffman tree) saved in (1).
 */
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

/**
 * Push a 'value' (i.e. Huffman tree) onto the front (top) of the stack.
 *
 * More precisely, this function must do two things:
 * (1) Create a new StackNode with 'tree' for its tree.
 * (2) Push that new StackNode onto the front of the stack's list.
 */
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
  /**
 * This function helps simplify building a Huffman Coding Tree from the header
 * information. It takes a stack as input. As a precondition, you can assume 
 * that the stack has at least two nodes. This function pops the front (top) 
 * two nodes, combines them into a single node, and pushes the new node back 
 * onto the stack. See Huffman_Coding.pdf to understand conceptually how this
 * should be done.
 */
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
  int c=fgetc(fp);
  Stack* sk = Stack_create();
  while(!feof(fp))
  {
    if(c == '1')//leaf node
    {
      c = fgetc(fp);//get the character
      HuffNode * tree = HuffNode_create(c);
      Stack_pushFront(sk,tree);
    }
    else if( c =='0')//non-leaf node
    {
      if(sizeofStack(sk) == 1)
      {
	break;
      }
      Stack_popPopCombinePush(sk);
    }
    c=fgetc(fp);
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

typedef struct {
  FILE * fp;
  int position;
  unsigned char byte;
} Bits;

Bits * Bits_create(FILE * fp)
{
  Bits * bit = malloc(sizeof(Bits));
  bit -> fp = fp;
  bit -> byte = 0;
  bit -> pos = 8; // 1 byte is 8 bits
return bit;
}

void Bits_destroy(BitFile * bit)
{
  free(bit);
}

int Bits_nbi(Bits * bit)
{
  if (bit -> pos == 8)
  {
    bit -> pos = 0;            //8 bits
    if (fread(&(bit -> byte), sizeof(unsigned char), 1, bit -> fp) !=1)
    {
    return -1;
    }
  }
  int val = (bit -> byte >> (7 - bit -> pos)) & 1;
  (bit -> pos)++;
  return val;
}



HuffNode * HuffTree_readBinaryHeader(FILE * fp)
{
  Stack * stack = Stack_create();
  Bits * bit = Bits_create(fp);
  int ind = Bits_nbi(bit);
  while (ind >= 0)
  {
    if (ind == 1)
    {
      val = Bits_nby(bit);
      Stack_pushFront(stack, HuffNode_create(ind));
    }
    else if (ind == 0)
    {
      if (Stack_size(stack) == 1)
      {
	break;
      }
      Stack_popPopCombinePush(stack);
    }
    val = Bits_nbi(bit);
  }
  HuffNode * tree = Stack_popFront(stack);
  Stack_destroy(stack);
  Bits_destroy(bit);
  return tree;
}

