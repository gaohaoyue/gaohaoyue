#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "pa05.h"

int checktype(const char* filename);
void Huff_postOrderPrint(HuffNode *tree,FILE*output);

int checktype(const char* filename)
{
  int length = strlen(filename);
  char last=filename[length-1];
  if(last == 't')
    {
      return 1;
    }
  else
    {
      return 0;
    }
}


int main ( int argc, char**argv)
{
  if(argc <3)
    {
      printf("usage: ./pa05 <input file> <output file>\n");
      return EXIT_FAILURE;
    }
  FILE*input = fopen(argv[1],"r");
  if(input == NULL)
    {
      printf("Failed to open Input file");
      return EXIT_FAILURE;
    }
 

  int type = checktype(argv[1]);
  /********
  create Huffman Tree*/
  HuffNode*htree;
  if(type == 0)
    {
      htree = chtree(input);
    }
  else
    {
      htree = bittree(input);
    }


  /********
  print the result into output file*/
  FILE*output = fopen(argv[2],"w");
  if(output == NULL)
    {
      printf("Failed to open Output file");
      return EXIT_FAILURE;
    }
  Huff_postOrderPrint(htree,output);
  treedestroy(htree);

  fclose(input);
  fclose(output);
  return EXIT_SUCCESS ;
}

/*
int checktype(const char argv[1])
{
  char* way;
  char* comp = argv[1];
  way = strstr(comp,"bit");
  if(way != NULL)
    {
      // binary file;
      return 1;
    }
  else
    {
      // character file;
      return 0;
    }
}
*/
