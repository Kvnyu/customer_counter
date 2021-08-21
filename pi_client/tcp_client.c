#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080          /* the port client will be connecting to */
#define SERVER "127.0.0.1" /* replace this with your server IP address*/

int main(int argc, char *argv[])
{
  int sockfd;
  /* A struct is a composite data type that defines a physically
   grouped list of variables under one name in a block of memory
  */
  struct sockaddr_in server;

  // This creates the socket
  // AF_INET is for IPV4
  // SOCK_STREAM is for TCP
  // sockfd stands for file descriptor, a file descriptor is a unique handled for a file/IO resource
  if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
  {
    perror("socket");
    exit(1);
  }

  server.sin_addr.s_addr = inet_addr(SERVER);
  server.sin_family = AF_INET;
  server.sin_port = htons(PORT);

  // This is typecasting the address of the server struct to a a pointer to a sockaddr
  if (connect(sockfd, (struct sockaddr *)&server,
              sizeof(struct sockaddr)) < 0)

  {
    perror("connect");
    exit(1);
  }
  while (1)
  {

    send(sockfd, "1", 14, 0);
    sleep(1);
  }

  close(sockfd);

  return 0;
}

// The boiler plate for this TCP code is adapted from http://www.cs.tau.ac.il/~eddiea/samples/TCP-Simple/tcp-simple-server.c.html
