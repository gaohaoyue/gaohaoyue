/*
 * Please fill the functions in this file.
 * You can add additional functions. 
 *
 * For this assignment, you must use qsort and give appropriate
 * comparison functions.
 *
 * You can assume that the input files have no empty lines and the
 * last line ends with '\n'.  You can count the number of lines by
 * counting the occurrences of '\n'.
 *
 * Hint: 
 * You can write additonal functions.
 *
 */

#include "pa02.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define INT     0
#define STRING  1
#define FAILURE 0
#define SUCCESS 1

int compar(const void*a,const void*b);
int comparint (const void*a, const void*b);

/*
 * =================================================================
 * read the integers from the file whose name is inName
 * sort the integers
 * stored the sorted integers in the file whose name is outName
 */

void sortInt(char * inName, char * outName)
{
  
  int count=0;
  char check;
  int i=0;
  char **arr1;
  int *arrint;
  int element;

  FILE*input = fopen(inName,"r");
  while(!feof(input)) //This function checks the rows of the input file
    {
      check = fgetc(input);
      if(check =='\n')
	{
	  count++;
	}
    }
  //  printf("the number of the line are %d\n", count);
  
  arr1 = malloc(sizeof(char*)*count);
  for(i=0;i<count;i++)
    {
      arr1[i]=malloc(sizeof(char)*LINELENGTH);
    } //This function malloc a two dimensional array
  
  fseek(input,0,SEEK_SET);
  for(i=0;i<count;i++)
    {
      {
	fgets(arr1[i],LINELENGTH,input);
	//	printf("the number is %s",arr1[i]);
      }
    } //This function store the input string into the two dimensional array
  
  arrint = malloc(sizeof(int)*count);

  for(i=0;i<count;i++)
    {
      arrint[i] = strtol(arr1[i],NULL,10);
      //  printf("the converted number is %d\n",arrint[i]);
    } //This function convert the string to integer

  qsort(&arrint[0],count,sizeof(int),comparint); //This function sort the integer
  /* 
 for(i=0;i<count;i++)
    {
      printf("The sorted numbers are %d\n",arrint[i]);
    }
  */

  FILE*output = fopen(outName,"w");
  //  fseek(output,0,SEEK_SET);
  if (output==NULL)
    {
      printf("does not open\n");
    } //This function checks whether the ouput is open 
 
  for(i=0; i<count;i++)
    {
      element = arrint[i];
      fprintf(output,"%d\n",element);
    } //This function write the integer into the output

  for(i=0;i<count;i++)
    {
      free(arr1[i]);
    }
  free(arr1);
  free(arrint);
  fclose(input);
  fclose(output);
  
}


/*
 * =================================================================
 * read the strings from the file whose name is inName
 * sort the strings
 * stored the sorted strings in the file whose name is outName
 *
 * The strings are sorted by ASCII order (using strcmp). Thus, 'B' will
 * appear before 'a'.
 */

void sortString(char * inName, char * outName)
{
  int count=0;
  char check;
  char **arr2;
  int q;
  int p;
  int i;
  FILE*input = fopen(inName,"r");

  while(!feof(input))
    {
      check = fgetc(input);
      if(check == '\n')
	{
	  count++;
	}
    }
  printf("The number of lines in the file %s is %d\n",inName,count);
  
  fseek(input,0,SEEK_SET);
  arr2 = malloc(sizeof(char*)*count);
  for (q=0;q<count;q++)
    {
      arr2[q]=malloc(sizeof(char)*LINELENGTH);
    }

  for(p=0;p<count;p++)
    {
      fgets(arr2[p],LINELENGTH,input);
    }
  
  qsort(&arr2[0],count,sizeof(char*),compar);

  /*
  for(i=0;i<count;i++)
    {
      printf("%s",arr2[i]);
    }
  */
  
  FILE*output = fopen(outName,"w");
  fseek(output,0,SEEK_SET);
 
  if (output==NULL)
    {
      printf("does not open");
    }
  for(i=0;i<count;i++)
    {
      fprintf(output, "%s",arr2[i]);
    }

  /*  
  for(i=0;i<count;i++)
    {
      printf("%s",arr2[i]);
    }
  */

  for(i=0;i<count;i++)
    {
      free(arr2[i]);
    }
  free(arr2);
  fclose(input);
  fclose(output);
 
}



int compar (const void*a, const void*b)
{
  return strcmp(*(char**)a, *(char**)b);
}


int comparint (const void*a, const void*b)
{
  const int *ia = (const int*)a;
  const int *ib = (const int*)b;
  return *ia - *ib;
}


