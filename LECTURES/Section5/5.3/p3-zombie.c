#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>

void handleSig1(int);

volatile int running;


int main()
{
  int pid;
  char text[80];

  pid = fork();	

  if (pid == 0) {  // child process
    signal(SIGUSR1, handleSig1);
    printf("Child waiting...\n");
    running = 1;
    while (running == 1)  
      sleep(1);
  }
  else {  // parent process
    while (1) {
      sleep(1);
      printf("Command? ");
      scanf("%s", text);
      if (strcmp(text, "frog") == 0) {
        kill(pid,SIGUSR1);
      }
      if (strcmp(text, "quit") == 0) {
        break;
      }
    }
  }
}

void handleSig1(int signum)
{
  printf("Child received a frog!\n");
  running = 0;
}
