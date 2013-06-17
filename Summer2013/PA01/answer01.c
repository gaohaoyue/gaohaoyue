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

/*
 * =================================================================
 * This function prints all partitions of a positive integer value
 * See the file "expected/example-output" for the output specification
 */


void printPartition(int*part,int length)
{
  int ind;
  for(ind = 0; ind<length-1;ind++)
    {
      printf("%d+",part[ind]);
    }
  printf("%d\n",part[length-1]);
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
  int * arr;
  arr = malloc(sizeof(int)*value);
  partition(arr,0,value);
  free(arr);
  return EXIT_SUCCESS;
  //  printf("partitionAll %d\n", value);
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

void partitionIncreasing(int value)
{
  printf("partitionIncreasing %d\n", value);
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

void partitionUnique(int value)
{
  printf("partitionUnique %d\n", value);
}

/*
 * =================================================================
 * See the file "expected/example-output" for the output specification
 */
void permute(char * charset, int len)
{
  printf("permute %d\n", len);
}

