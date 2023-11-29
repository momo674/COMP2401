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
  int myListenSocket, clientSocket;
  struct sockaddr_in  myAddr, clientAddr;
  int i, bytesRcv;
  socklen_t addrSize;

  char buffer[30];

/* create socket */

  myListenSocket = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
  if (myListenSocket < 0) {
    printf("eek! couldn't open socket\n");
    exit(-1);
  }


/* setup my server address */
  memset(&myAddr, 0, sizeof(myAddr));
  myAddr.sin_family = AF_INET;
  myAddr.sin_addr.s_addr = htonl(INADDR_ANY);
  myAddr.sin_port = htons((unsigned short) MY_PORT);

/* bind my listen socket */

  i = bind(myListenSocket, 
           (struct sockaddr *) &myAddr,
           sizeof(myAddr));
  if (i < 0) {
    printf("eek! couldn't bind socket\n");
    exit(-1);
  }


/* listen */
  i = listen(myListenSocket, 5);
  if (i < 0) {
    printf("eek! couldn't listen\n");
    exit(-1);
  }


/* wait for connection request */

  addrSize = sizeof(clientAddr);

  clientSocket = accept(myListenSocket,
                        (struct sockaddr *) &clientAddr,
                        &addrSize);
  if (clientSocket < 0) {
    printf("eek! couldn't accept the connection\n");
    exit(-1);
  }

/* read message from client and do something with it */
  while (1) {
    bytesRcv = recv(clientSocket, buffer, sizeof(buffer), 0);
    buffer[bytesRcv] = 0;
    printf("this is what the client sent:  %s\n", buffer);
    if(strcmp(buffer,"quit") == 0)
      break;
  } 

/* close sockets */

  close(myListenSocket);
  close(clientSocket);

  return 0;
}
