#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MY_PORT 60002

int main()
{
  int myRcvSocket;
  struct sockaddr_in  myAddr, clientAddr;
  int i, addrSize, bytesRcv, selectRC;
  fd_set readfds;
  struct timeval timeout={0,0};

  char buffer[30];

/* create socket */

  myRcvSocket = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP);
  if (myRcvSocket < 0) {
    printf("could not open server socket\n");
    exit(-1);
  }


/* setup my server address */
  memset(&myAddr, 0, sizeof(myAddr));
  myAddr.sin_family = AF_INET;
  myAddr.sin_addr.s_addr = htonl(INADDR_ANY);
  myAddr.sin_port = htons((unsigned short) MY_PORT);

/* bind my socket */
  i = bind(myRcvSocket, (struct sockaddr *) &myAddr, sizeof(myAddr));
  if (i < 0) {
    printf("could not bind server socket\n");
    exit(-1);
  }


/* wait for connection request */

  while (1) {
    do {
      FD_ZERO(&readfds);
      FD_SET(myRcvSocket, &readfds);
      selectRC = select(myRcvSocket+1, &readfds,
         NULL, NULL, &timeout);
      if (selectRC > 0) {
        addrSize = sizeof(clientAddr);
        bytesRcv = recvfrom(myRcvSocket, buffer, sizeof(buffer),
                   0, (struct sockaddr *) &clientAddr, &addrSize);
        if (bytesRcv > 0) {
          buffer[bytesRcv] = '\0';
          printf("this is what we got: %s\n", buffer);
        }
      }
    } while (selectRC > 0);
    if (strcmp(buffer, "quit") == 0)
      break;
  } 

  close(myRcvSocket);

  return 0;
}
