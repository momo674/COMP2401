#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void *printMsg(void*);

int main() 
{
  pthread_t t1, t2, t3;

  pthread_create(&t1, NULL, printMsg, "tic");
  pthread_create(&t2, NULL, printMsg, "tac");
  pthread_create(&t3, NULL, printMsg, "toe");

  pthread_join(t1, NULL);
  pthread_join(t2, NULL);
  pthread_join(t3, NULL);

  return(0);
}


void *printMsg(void *str) 
{
  int i;

  for (i=0; i<10; ++i) {
    printf("%s\n", (char *)str);
    usleep(500000);
  }

  return(NULL);
}

