#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define SERVER_IP "127.0.0.1"
#define SERVER_PORT 60002

int main()
{
  int mySocket;
  struct sockaddr_in  addr;
  int i;

  char inStr[300];
  char buffer[300];

/* create socket */
  mySocket = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP);
  if (mySocket < 0) {
    printf("could not create socket\n");
    exit(-1);
  }


/* setup address */
  memset(&addr, 0, sizeof(addr));
  addr.sin_family = AF_INET;
  addr.sin_addr.s_addr = inet_addr(SERVER_IP);
  addr.sin_port = htons((unsigned short) SERVER_PORT);


/* send to server */

  while (1) {
    printf("enter your input: ");
    fgets(inStr, sizeof(inStr), stdin);
    inStr[strlen(inStr)-1] = 0;
    strcpy(buffer, inStr);
    sendto(mySocket, buffer, strlen(buffer), 0,
      (struct sockaddr *) &addr, sizeof(addr));
    if (strcmp(inStr, "quit") == 0)
      break;

  } 

  close(mySocket);

  return 0;
}
