/* The local TCP Server to listen and send the multicast traffic */
/* The TCP server listens on TCPPORT 1111
the server will have two parts
1. Parent server Process
2. Child listner , listens at TCP 1111
3. Child broadcaster , broadcasts at UDP 1112
*/
/* A basic Server */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/wait.h>
#include <signal.h>


/* Reference beez.us */

#define TCPPORT 1111  // the TCPPORT users will be connecting to
#define UDPPORT 1112  // the UDPPORT the server multicasts the information
#define BACKLOG 10  // how many pending connections queue will hold

#define BUFFERSIZE 32
#define LENGTH 100
#define MULTICAST_IP "239.0.0.1"
#define PROGNAME "local_server.o"
/*Function Definitions for the server */

struct MessageBuffer {
  long messageType;
  char messageData[LENGTH];
};

typedef struct MessageBuffer MessageBuffer;
typedef int nmb_t;


void gotError( char *s) {
  perror(s);
  exit(1);
}
