#include "defs.h"

/*
  Function:  viewEscape
  Purpose:   Top-level function for the client process, given the server IP address.
             Sends a connection request to the server at the given IP address,
             loops, and waits for data that it prints out until a quit message is received.
  Parameters:
    in:      Server IP address as a string.
    out:     Client application in terminal.
*/
void viewEscape(char* ip) {
    int socket;
    char messageFromServer[MAX_BUFF];
    printf("[Client] You are now connected to the server.\n");
    setupClientSocket(&socket, ip);

    while (1) {
        rcvData(socket, messageFromServer);

        if (strlen(messageFromServer) < 50) {
            printf("%s", messageFromServer);
            break; 
        }

        usleep(300000); 
        system("clear");
        printf("%s", messageFromServer);
    }
    
    close(socket);
}
