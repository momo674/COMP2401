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

  char inStr[80];
  char buffer[80];

/* create socket */
  mySocket = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
  if (mySocket < 0) {
    printf("eek! couldn't open socket\n");
    exit(-1);
  }


/* setup address */
  memset(&addr, 0, sizeof(addr));
  addr.sin_family = AF_INET;
  addr.sin_addr.s_addr = inet_addr(SERVER_IP);
  addr.sin_port = htons((unsigned short) SERVER_PORT);

/* connect to server */

  i = connect(mySocket, 
              (struct sockaddr *) &addr,
              sizeof(addr));
  if (i<0) {
    printf("client could not connect!\n");
    exit(-1);
  }

/* get input from user and send to server */
  while (1) {
    printf("what is your message?  ");
//    scanf("%s", inStr);
    fgets(inStr, sizeof(inStr), stdin);
    inStr[strlen(inStr)-1] = 0;
    strcpy(buffer, inStr);
    send(mySocket, buffer, strlen(buffer), 0);

    if(strcmp(inStr, "quit") == 0)
      break;
  } 

/* close the socket */

  close(mySocket);

  return 0;
}
