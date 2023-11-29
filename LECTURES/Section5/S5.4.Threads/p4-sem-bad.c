#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

void *threadFunc(void*);

volatile long int count = 0;
sem_t mutex;


int main(int argc, char *argv[]) 
{
  long int numIterations;
  pthread_t t1, t2;


  if (argc < 2) 
    numIterations = 100000000;
  else
    numIterations = atoi(argv[1]);

  if (sem_init(&mutex, 0, 1) < 0) {
    printf("semaphore initialization error\n");
    exit(1);
  }

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

  if (sem_wait(&mutex) < 0) {
    printf("semaphore wait error\n");
    exit(1);
  }

  printf("-- Counting starts\n");

  for (i = 0; i < numItr; ++i)
    ++count;

  printf("-- Counting ends\n");

  if (sem_post(&mutex) < 0) {
    printf("semaphore wait error\n");
    exit(1);
  }

  return(0);
}

