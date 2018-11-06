
#include "lib.h"


/* The message get API for message receive and sending */





int udp_broadcast_msg(MessageBuffer message ){

  struct in_addr localInterface;
  struct sockaddr_in groupSock;
  int sd;


  sd = socket(AF_INET, SOCK_DGRAM , 0);

  if (sd<0) {
    gotError("Opening datagram socket error \n");
  }
  else {
    printf("Opening the datagram socket...OK.\n");
  }

  memset((char *) &groupSock, 0, sizeof(groupSock));


  /* The group sock provides the multicast detals */

  groupSock.sin_family = AF_INET;
  groupSock.sin_addr.s_addr = inet_addr(MULTICAST_IP);
  groupSock.sin_port = htons(UDPPORT);


  if(sendto(sd, message.messageData, sizeof(message), 0, (struct sockaddr*)&groupSock, sizeof(groupSock)) < 0) {
    gotError("Sending datagram message error \n");
  }
  else {
    printf("Sending datagram message...OK\n");
    fprintf(stdout, "%s\n",message.messageData );
  }

  return 0;
}



int tcp_listener() {

    int socket_desc , client_sock , c , read_size;
    struct sockaddr_in server , client;
    char client_message[2000];

    //Create socket
    socket_desc = socket(AF_INET , SOCK_STREAM , 0);
    if (socket_desc == -1)
    {
      gotError("Could not create socket");
    }
    puts("Socket created");

    //Prepare the sockaddr_in structure
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons( TCPPORT );
     //Bind
     if( bind(socket_desc,(struct sockaddr *)&server , sizeof(server)) < 0)
     {
     //print the error message
     gotError("bind failed. Error");
     return 1;
   }
   puts("bind done");

   //Listen
   listen(socket_desc , 3);

   //Accept and incoming connection
   puts("Waiting for incoming connections...");
   c = sizeof(struct sockaddr_in);

   //accept connection from an incoming client
   client_sock = accept(socket_desc, (struct sockaddr *)&client, (socklen_t*)&c);
   if (client_sock < 0)
   {
     gotError("accept failed");
     return 1;
   }
   puts("Connection accepted");

 //Receive a message from client
  while( (read_size = recv(client_sock , client_message , 2000 , 0)) > 0 )
  {
     //Send the message back to client
     write(client_sock , client_message , strlen(client_message));
   }

   if(read_size == 0)
   {
     puts("Client disconnected");
     fflush(stdout);
   }
   else if(read_size == -1)
   {
     gotError("recv failed");
   }

 return 0;
}


int main(){
  MessageBuffer msg =
  {
    .messageType = 1,
    .messageData = "Multicast Message\n"
  };

  //udp_broadcast_msg(msg);
  tcp_listener();

}
