#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

#define NUM_THREADS  3
#define MAX_STR     32

void *printMsg(void*);

int main() 
{
  char msg[NUM_THREADS][MAX_STR] = { "tic", "tac", "toe" };

  pthread_t badThreads1[NUM_THREADS];
  pthread_t badThreads2[NUM_THREADS];
  pthread_t goodThreads[NUM_THREADS];

// /*  Bad approach #1: not generic */
//   pthread_create(&badThreads1[0], NULL, printMsg, msg[0]);
//   pthread_create(&badThreads1[1], NULL, printMsg, msg[1]);
//   pthread_create(&badThreads1[2], NULL, printMsg, msg[2]);

//   pthread_join(badThreads1[0], NULL);
//   printf("\nBad thread, approach #1, thread #1 is back\n");

//   pthread_join(badThreads1[1], NULL);
//   printf("Bad thread, approach #1, thread #2 is back\n");

//   pthread_join(badThreads1[2], NULL);
//   printf("Bad thread, approach #1, thread #3 is back\n");
  
  printf("\n");
// /*  Bad approach #2:  no concurrency */
//   for (int i=0; i<NUM_THREADS; ++i) {
//     pthread_create(&badThreads2[i], NULL, printMsg, msg[i]);
//     pthread_join(badThreads2[i], NULL);
//     printf("Bad thread, approach #2, thread #%d is back\n", i);
//   }

/*  Good approach */
  for (int i=0; i<NUM_THREADS; ++i) {
    pthread_create(&goodThreads[i], NULL, printMsg, msg[i]);
  }

  for (int i=0; i<NUM_THREADS; ++i) {
    pthread_join(goodThreads[i], NULL);
    printf("Good threads, thread #%d is back\n", i);
  }

  return(0);
}


void *printMsg(void *str) 
{
  int i;

  for (i=0; i<10; ++i) {
    printf("%s\n", (char *)str);
    //usleep(500000);
  }

  return NULL;
}

