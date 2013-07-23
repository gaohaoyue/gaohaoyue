#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include"pa05.h"
const masks[] = {0*80, 0*40, 0*20, 0*10, 0*08, 0*04, 0*02, 0*01};

HuffNode*treenode(char value)
{
  HuffNode * treenodecreate;
  treenodecreate = malloc(sizeof(HuffNode));
  treenodecreate -> left = NULL;
  treenodecreate -> right = NULL;
  treenodecreate -> value = value;
  //printf("Creating %c\n\n", value);
  return treenodecreate;
}

/*
Stack*stacknode (Stack*next,Stack*node)
{
  Stack* stacknodecreate;
  stacknodecreate = malloc(sizeof(Stack));
  stacknodecreate -> next = next;
  stacknodecreate -> node = node;
  return stacknodecreate;
  }*/

Stack*push(Stack*stack, HuffNode*node)
{
  Stack*item = malloc(sizeof(Stack));
  item->node = node;
  item->next = stack;

  return item;
}

Stack*pop(Stack*stack)
{
  Stack*next = stack->next;
  free(stack);
  return next;
}

int count(Stack*stack)
{
  if(stack == NULL)
    return 0;
  return 1+ count(stack->next);
}

//HuffNode*chtree(FILE*input,char*argv[1])
HuffNode*chtree(FILE*input)
{

  Stack*top = NULL;
  HuffNode*temp = NULL;
  HuffNode*rightnode = NULL;
  HuffNode*leftnode = NULL;
  HuffNode*newtopnode = NULL;
  //HuffNode*tree = NULL;

  char ch;
  char ch2;
  int done =0;
  
  while(done == 0)
    {
      ch = fgetc(input);
      if(ch == '1')
	{
	  ch2 = fgetc(input);
	  temp = treenode(ch2);
	  top = push(top,temp);
	}
      else
	{
	  rightnode = top -> node;
	  top = pop(top);
	  
	  if(top == NULL)
	    {
	      done = 1;
	    }
	  else
	    {
	      leftnode = top->node;
	      top = pop(top);

	      newtopnode = treenode(0);
	      newtopnode ->right = rightnode;
	      newtopnode ->left = leftnode;
	      //  newtopnode ->right = leftnode;
	      //  newtopnode ->left = rightnode;
	      top = push(top, newtopnode);
	    }
	}
    }
  return rightnode;
}


//HuffNode*bittree(FILE*input,char*argv[])
HuffNode*bittree(FILE*input)
{
  HuffNode*t;
  // return t;
  return NULL;
}

void Huff_postOrderPrint(HuffNode *tree,FILE*output)
{
  // Base case: empty subtree
  if (tree == NULL) 
    {
      return;
    }
  // Recursive case: post-order traversal
  // Visit left
  fprintf(output,"Left\n");
  Huff_postOrderPrint(tree->left,output);
  fprintf(output,"Back\n");
  // Visit right
  fprintf(output,"Right\n");
  Huff_postOrderPrint(tree->right,output);
  fprintf(output,"Back\n");
  // Visit node itself (only if leaf)
  if (tree->left == NULL && tree->right == NULL)
    {
      fprintf(output,"Leaf: %c\n", tree->value);
    }
  
  
}


void treedestroy(HuffNode * tree)
{
  if (tree == NULL)
    {
      return;
    }
  if(tree->left!= NULL)
    {
      treedestroy(tree -> left);
    }
  if(tree->right!= NULL)
    {
      treedestroy(tree -> right);
    }
  free(tree);
}
