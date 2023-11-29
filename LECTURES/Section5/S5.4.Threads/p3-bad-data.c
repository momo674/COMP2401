#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *threadFunc(void*);

volatile long int count = 0;


int main(int argc, char *argv[]) 
{
  long int numIterations;
  pthread_t t1, t2;


  if (argc < 2) 
    numIterations = 100000000;
  else
    numIterations = atoi(argv[1]);

  pthread_create(&t1, NULL, threadFunc, &numIterations);
  pthread_create(&t2, NULL, threadFunc, &numIterations);

  pthread_join(t1, NULL);
  pthread_join(t2, NULL);

  if (count == 2 * numIterations) {
    printf("Good news!  count is %ld\n", count);
  }
  else {
    printf("Bad news!  count is %ld\n", count);
  }

  return(0);
}


void *threadFunc(void *arg) 
{
  long int i; 
  long int numItr = *((long int *)arg);

  printf("-- Counting starts\n");

  for (i = 0; i < numItr; ++i)
    ++count;

  printf("-- Counting ends\n");

  return(0);
}

