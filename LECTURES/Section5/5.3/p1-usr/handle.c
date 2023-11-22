#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void handleSig1(int);
void handleSig2(int);

int main()
{
  signal(SIGUSR1, handleSig1);
  signal(SIGUSR2, handleSig2);

  while (1)
    sleep(1);

  printf("we made it\n");

}


void handleSig1(int i)
{
  printf("we are handling this problem all by ourselves\n");
}


void handleSig2(int i)
{
  printf("we can't handle this!  it's gonna blow!\n");
  exit(SIGUSR2);
}
