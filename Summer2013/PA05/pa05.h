#ifndef PA05_H
#define PA05_H

typedef struct _huffnode {
  char value;
  struct _huffnode *left;
  struct _huffnode *right;
} HuffNode;

typedef struct _stack {
  struct _stack * next;
  HuffNode * node;
} Stack;

HuffNode*treenode(char value);
Stack*stacknode (Stack*next,Stack*node);
Stack*push(Stack*stack, HuffNode*node);
Stack*pop(Stack*stack);
int count(Stack*stack);
//HuffNode*chtree(FILE*input,char*argv[]);
//HuffNode*bittree(FILE*input,char*argv[]);
HuffNode*chtree(FILE*input);
HuffNode*bittree(FILE*input);
int checktype(const char* filename);
void Huff_postOrderPrint(HuffNode *tree,FILE*output);
void treedestroy(HuffNode * tree);

#endif
