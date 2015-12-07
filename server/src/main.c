#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/epoll.h>
#include <arpa/inet.h>
//#include <errno.h>

#include "read_config.h"
#include "reactor.h"
#include "init_server.h"
#include "acceptor_eh.h"
#include "client_eh.h"

//extern errno;

int main(int argc, const char *argv[])
{
	// Read arguments from "config.cfg" file and printing them
	int port;
	int max_clients;
	if(get_config(&port, &max_clients))
		return(-1);

	// Main
	int srv_fd = -1;
	int epoll_fd = -1;

	reactor* r = 0;
	event_handler* seh = 0;

	if (init_server(&srv_fd, &epoll_fd, port, max_clients) != 0)
		return 1;

	r  = create_reactor(epoll_fd, max_clients);
	seh = create_acceptor(srv_fd, r);
	r->add_eh(r, seh);

	r->event_loop(r);

	return 0;
}
