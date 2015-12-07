#include <sys/socket.h>
#include <sys/types.h>
#include <sys/epoll.h>
#include <arpa/inet.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h> //memset
#include <unistd.h> //close

int init_server(int* s, int* e, const int port, const int max_clients);
