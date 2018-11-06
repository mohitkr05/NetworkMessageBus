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

#define TCPPORT "1111"  // the TCPPORT users will be connecting to
#define UDPPORT "1112"  // the UDPPORT the server multicasts the information
#define BACKLOG 10  // how many pending connections queue will hold

#define BUFFERSIZE 32
#define LENGTH 100
#define MULTICAST_IP "239.0.0.1"
#define PROGNAME "local_server.o"
/*Function Definitions for the server */

struct MessageBuffer {
  long messageType;
  char messageData[LENGTH]
}

/* The UDP Listner and broadcaster */
int udp_listener(int msgid);
int udp_broadcaster(MsgBuf message);

/* The TCP Listner and broadcaster */
int tcp_listener(int sockfd);
/* Server does not broadcast on TCP , only client does */
int tcp_client(MsgBuf message);

/* The message get API for message receive and sending */

int msgget_nmb();
int msgsnd_nmb();
int msgrcv_nmb();
