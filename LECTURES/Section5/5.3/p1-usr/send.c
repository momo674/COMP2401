#include <stdio.h>
#include <stdlib.h>
#include <signal.h>


int main()
{
  int pid, choice;

  printf("Enter target process number: ");
  scanf("%d", &pid);

  while (1) {
    printf("User sig: ");
    scanf("%d", &choice);
    if (choice == 0)
      break;
    else if (choice == 1)
      kill(pid, SIGUSR1);
    else if (choice == 2)
      kill(pid, SIGUSR2);
  }
}

