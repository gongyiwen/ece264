#include <stdio.h>
#include <stdlib.h>
#include "answer11.h"


HuffNode * HuffNode_create(int value)
{
  HuffNode * node = malloc(sizeof(HuffNode));
  node -> value = value;
  node -> right = NULL;
  node -> left = NULL;
  return node;
}

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

Stack * Stack_create()//head of a linked list
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
  while(node != NULL)//until reach the end of the linked list
  {
    nx = node -> next;
    HuffNode_destroy(node-> tree);//destroy the tree in each node
    free(node);//free the current node
    node = nx;//point to the next node
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
    return NULL;
  }
  HuffNode * tn = stack -> head -> tree;//step 1,save the tree
  StackNode * a = stack -> head;
  stack -> head = stack -> head -> next;
  free(a);//step2
  return(tn);//step3
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
  if(Stack_isEmpty(stack))//if empty, return
  {
    return;
  }
  StackNode* sn = malloc(sizeof(StackNode));//create a new StackNode
  sn -> tree = tree;//with 'tree' for its tree
  sn -> next = stack -> head;//push the node onto the front of the linked list
  stack -> head = sn;//make the node the head
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
  HuffNode * second = Stack_popFront(stack);//pop the front 2 trees
  HuffNode * node = HuffNode_create(0);//create a n empty node
  node -> left = second;
  node -> right = first;//combie them into a signel node
  Stack_pushFront(stack,node);//push the new node back onto the fron of the list
}

// ---------------------------------------------------- Reading HuffTree headers

/**
 * Read a Huffman Coding Tree (in text format) from 'fp'.
 */

HuffNode * HuffTree_readTextHeader(FILE * fp)
{
  int c = fgetc(fp);
  Stack* sk = Stack_create();
  while(!feof(fp))
  {
    if(c == '1')//leaf node
    {
      c = fgetc(fp);//get the character
      HuffNode * tree = HuffNode_create(c);//a tree node with value 'c'
      Stack_pushFront(sk,tree);//push the tree node to the front of the linked list,sk->head will be 'tree'
    }
    else if( c =='0')//non-leaf node,combine
    {
      if(sk -> head -> next == NULL)//have nothing to combine
      {
	break;
      }
      Stack_popPopCombinePush(sk);
    }
    c = fgetc(fp);//continue read the next character
  }
  HuffNode * tn = Stack_popFront(sk);//pop the front node,which is the completed huffman tree
  Stack_destroy(sk);//destory the stack
  return tn;
}
    
/**
 * Read a Huffman Coding Tree (in binary format) from 'fp'.
 * You will need to (conceptually) read a file a bit at a time. See the README
 * for hints on how to do this.
 */

typedef struct {
  FILE * fp;
  int  offset;
  unsigned char byte;
} Bits;

Bits * Bits_create(FILE * fp)
{
  Bits * bit = malloc(sizeof(Bits));
  bit -> fp = fp;
  bit -> offset = 8; // 1 byte is 8 bits
  bit -> byte = 0;
return bit;
}

int Read_bits(Bits * bit)
{
  if (bit -> offset == 8)
  {
    bit -> offset = 0;            //8 bits
    if (fread(&(bit -> byte), sizeof(unsigned char), 1, bit -> fp) !=1)//read 1 byte then store into bit->byte
    {
    return -1;//out of bit
    }
  }
  return ((bit -> byte) >> (7 - ((bit -> offset)++)) & 0x01);//clear out all the bit except for the zeroth bit
}


int Read_bytes(Bits * bit)
{
  int ret = 0;
  int pos = 0;
  while(pos <= 7)//0-7
  {
    int num = Read_bits(bit);
    if (num < 0)
    {
      return -1;//there's no more bits available 
    }
    ret = ret | (num << (7 - pos));
    pos++;
  }
  return ret;
}

void Bits_destroy(Bits * bit)
{
  free(bit);
}

HuffNode * HuffTree_readBinaryHeader(FILE * fp)
{
  Stack * stack = Stack_create();
  Bits * bit = Bits_create(fp);
  int num = Read_bits(bit);
  while (num >= 0)
  {
    if (num == 1)
    {
      num = Read_bytes(bit);
      Stack_pushFront(stack, HuffNode_create(num));
    }
    else if (num == 0)
    {
      if (stack -> head != NULL && stack ->head ->next == NULL)  //just have a head
      {
	break;
      }
      Stack_popPopCombinePush(stack);
    }
    num = Read_bits(bit);
  }
  HuffNode * tree = Stack_popFront(stack);
  Stack_destroy(stack);
  Bits_destroy(bit);
  return tree;
}

