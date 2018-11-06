#README


Server
1. Keeps running the TCP server
2. Listens for a message on server , as soon as message recieves, calls for the UDP multicast running on port 1112
3. Multicasts the message to all the users
