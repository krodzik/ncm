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
#include "user_list.h"
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

	printf("From configuration file:\nport number : %d \t\tmax clients number : %d \n", port, max_clients);

	// Main
	int srv_fd = -1;
	int epoll_fd = -1;

	user_list* ul = 0;
	reactor* r = 0;
	event_handler* seh = 0;

	if (init_server(&srv_fd, &epoll_fd) != 0)
		return 1;

	ul = create_user_list();
	r  = create_reactor(epoll_fd);
	seh = create_acceptor(srv_fd, r, ul);
	r->add_eh(r, seh);

	r->event_loop(r);

	return 0;
}
