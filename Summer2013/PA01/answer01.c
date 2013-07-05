/*
 * Please fill the functions in this file.
 * You can add additional functions. 
 *
 * Hint: 
 * You can write additonal functions.
 *
 * You may create additional arrays if needed.  The maximum size
 * needed is specified by MAXLENGTH in pa01.h.
 */

#include "pa01.h"
#include <stdio.h>
#include <stdlib.h>

void printPartition(int*part,int length);
void partition(int*part,int ind, int left);
void printPartition2(int*part,int length);
void partition2(int*part,int ind, int left);
void printPartition3(int*part,int length);
void partition3(int*part,int ind, int left);
void printPermute(char*charset, int length);
void recursivePermute(char*charset, int ind, int length);
void permutation(char*charset,int length);


/*
 * =================================================================
 * This function prints all partitions of a positive integer value
 * See the file "expected/example-output" for the output specification
 */


void printPartition(int*part,int length)
{
  int ind;
  printf("=");
  for(ind = 0; ind<length-1;ind++)
    {
      
      printf(" %d +",part[ind]);
    }
  printf(" %d\n",part[length-1]);
}


void partition(int*part,int ind, int left)
{
  int val; 
  if(left == 0)
    {
      printPartition(part,ind);
      return;
    }
  for (val = 1; val <= left; val ++)
    {
      part[ind]= val;
      partition(part,ind+1,left-val);
    }
}

void partitionAll(int value)
{
  printf("partitionAll %d\n", value);
  int * arr;
  arr = malloc(sizeof(int)*value);
  partition(arr,0,value);
  free(arr);
  
}




/*
 * =================================================================
 * This function prints the partitions that use increasing values.
 *
 * For example, if value is 5
 * 2 + 3 and
 * 1 + 4 are valid partitions
 *
 * 5 is a valid partition
 * 
 * 1 + 1 + 3 and
 * 2 + 1 + 2 and
 * 3 + 2 are invalid partitions.
 * 
 * The program should generate only valid partitions.  Do not
 * generates invalid partitions and checks validity before printing.
 *
 * See the file "expected/example-output" for the output specification
 */


void printPartition2(int*part,int length)
{
  int ind;
  printf("=");
  for(ind = 0; ind<length-1;ind++)
    {
      printf(" %d +",part[ind]);
    }
  printf(" %d\n",part[length-1]);
}


void partition2(int*part,int ind, int left)
{
  int val;
  if(left == 0)
    {
      printPartition2(part,ind);
      return;
    }    
   for (val = 1; val <= left; val ++)
	{
	  part[ind] = val;
	  if(ind == 0)
	    {
	      partition2(part,ind+1,left-val); 
	    }
	  else if (part[ind] > part[ind -1])
	    {
	      partition2(part,ind+1,left-val);
	    }
	}
}

void partitionIncreasing(int value)
{
  printf("partitionIncreasing %d\n", value); 
  int * arr2;
  arr2 = malloc(sizeof(int)*value);
  partition2(arr2,0,value);
  free(arr2);
}

/*
 * =================================================================
 * This function prints the partitions that use unique values.
 *
 * For example, if value is 5
 * 2 + 3 and
 * 3 + 2 and
 * 1 + 4 are valid partitions
 *
 * 5 is a valid partition
 * 
 * 1 + 1 + 3 and
 * 2 + 1 + 2 are invalid partitions.
 *
 * The program should generate only valid partitions.  Do not
 * generates invalid partitions and checks validity before printing.
 *
 * See the file "expected/example-output" for the output specification
 */


void printPartition3(int*part,int length)
{
  int ind;
  printf("=");
  for(ind = 0; ind<length-1;ind++)
    {
      printf(" %d +",part[ind]);
    }
  printf(" %d\n",part[length-1]);
}


void partition3(int*part,int ind, int left)
{
  int val; 
  int i;
  int y;
  if(left == 0)
    {
      printPartition3(part,ind);
      return;
    }
  for (val = 1; val <= left; val ++)
    {
      y=0;
      part[ind]= val;
	  for(i=0; i < ind; i++)
	    {
	      if((part[ind]- part[i]) ==0)
		{
		  y++;
		}
	    }
	  if(y == 0)
	    {
	      partition3(part,ind+1,left-val);
	    }
    }
}

void partitionUnique(int value)
{
  printf("partitionUnique %d\n", value);
  int * arr3;
  arr3 = malloc(sizeof(int)*value);
  partition3(arr3,0,value);
  free(arr3);
}



/*
 * =================================================================
 * See the file "expected/example-output" for the output specification
 */
void printPermute(char*charset, int length)
{
  int iter;
  for(iter = 0; iter<length; iter++)
    {
      printf("%c ",charset[iter]);
    }
  printf("\n");
}
void swap(char* c1, char*c2)
{
  char t = *c1;
  *c1 = *c2;
  *c2 = t;
}

void recursivePermute(char*charset, int ind, int length)
{
  int iter;
  if(ind == length)
    {
      printPermute(charset,length);
    }
  for(iter = ind; iter< length; iter++)
    {
      swap(& charset[iter], & charset[ind]);
      recursivePermute(charset, ind+1, length);
      swap(&charset[iter],&charset[ind]);
    }

}

void permutation(char*charset,int length)
{
  recursivePermute(charset,0,length);
}


void permute(char * charset, int len)
{
  printf("permute %d\n", len);
  permutation(charset,len);
}

