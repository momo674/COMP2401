#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void ignoreMe(int);
void sleep5();

int main()
{
  int i;

  printf("\n");
  printf("Ignoring the interrupt signal...\n");

  signal(SIGINT, SIG_IGN);

  sleep5();


  printf("\n");
  printf("Really ignoring the interrupt signal...\n");

  signal(SIGINT, ignoreMe);

  sleep5();


  printf("\n");
  printf("Restoring the default handler...\n");

  signal(SIGINT, SIG_DFL);

  sleep5();

  printf("\n");
  printf("all done!\n");

  return 0;
}

void ignoreMe(int x) {
  printf(" Neener-neener!\n");
}

void sleep5()
{
  int i;

  for (i=1; i<=5; ++i) {
    printf("sleeping %d\n",i);
    sleep(1);
  }
}

