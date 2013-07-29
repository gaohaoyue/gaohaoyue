
/**
 * The ENTIRE assignment should be completed within this file
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <pthread.h>

#include "pa06.h"
void* primecheck(void* th);

typedef struct _object{
  uint128 value;
  uint128 start;
  uint128 end;
  int check;

}thread;
/**
 * Read a uint128 from a string.
 * This function is provided for your convenience.
 */
uint128 alphaTou128(const char * str)
{
  uint128 ret = 0;
  while(*str >= '0' && *str <= '9') {
    ret *= 10; // "left-shift" a base-ten number
    ret += (*str - '0'); // add in the units
    ++str;
  }
  return ret;
}

/**
 * The caller is responsible for freeing the result 
 */
char * u128ToString(uint128 value)
{
  int digit =0;
  uint128 temp1 = value;
  uint128 temp2 = value;
  int ind;
  while(temp1 !=0)
    {
      temp1 = temp1/10;
      digit ++;
    }
  char * string = malloc(sizeof(char)*(digit+1));
  string[digit] = '\0';

  for(ind=digit-1;ind>=0;ind--)
    {
      string[ind] = (temp2 % 10) + '0';
      temp2 =temp2/10;
    }
  return string;
}

/**
 * Test is 'value' is prime.
 * 'n_threads' is the number of threads to create to complete this computation.
 * Return TRUE of FALSE.
 * 
 * LEAK NO MEMORY
 *
 * Good luck!
 */


int primalityTestParallel(uint128 value, int n_threads)
{
  if(value ==2 || value ==1)
    {
      return TRUE;
    }
  if((value % 2) ==0)
    {
      return FALSE;
    } 
  
  int ind;
  int j;
  int k;
  int result;
  uint128 range;
  uint128 chunk;

  range = floor(sqrt(value));
  chunk = (range + (uint128)n_threads + 1)/(uint128)n_threads;
  thread*one = malloc(sizeof(thread)*n_threads);
  pthread_attr_t*attr = malloc(sizeof(pthread_attr_t)*n_threads);
  pthread_t*th = malloc(sizeof(pthread_t)*n_threads);


  
  for(ind=0; ind<n_threads;ind++)
    {
      one[ind].value = value;
      one[ind].start = ind*chunk;
      one[ind].end = (ind+1)*chunk;
      one[ind].check = TRUE;
     
      
      if(one[ind].start < 3)
	{
	  one[ind].start = 3;
	}
      if(one[ind].start %2 == 0)
	{
	  one[ind].start++;
	}
      pthread_attr_init(&attr[ind]);
      pthread_create( &th[ind],&attr[ind],primecheck,(void*) & one[ind]);
    }
  
  for(j = 0; j<n_threads; j++)
    {
      pthread_join(th[j],NULL);
    }
  
  result =1;
  for(k = 0; k<n_threads; k++)
    {
      if(one[k].check != 1)
	{
	  result = FALSE;
	  k = n_threads;
	  
	}
    }
  
  free(one);
  free(attr);
  free(th);
  return result;
}



void* primecheck(void* th)
{
  thread * thr = (thread*)th;
  uint128 i;
  
  for(i = thr->start; i<= thr->end; i+=2)
    {
      if(thr->value %i ==0)
	{
	  thr ->check = FALSE;
	  // return NULL;
	  pthread_exit(SUCCESS);
	}
    }
  //thr->check = TRUE;
  //  return NULL;
  pthread_exit(SUCCESS);
}


