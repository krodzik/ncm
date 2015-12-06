#include "reactor.h"
#include "client_eh.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>

#include <stdlib.h> //malloc

static void handle_event(event_handler* self, uint32_t e)
{
	int cli_fd = -1;
	struct sockaddr_in cli_addr;
	socklen_t cli_addr_len = sizeof(cli_addr);

	memset(&cli_addr, 0, sizeof(cli_addr));

	cli_fd = accept(self->fd, (struct sockaddr*) &cli_addr, &cli_addr_len);

	event_handler* ceh = create_client_eh(cli_fd, self->r);//, self->ul);
	self->r->add_eh(self->r, ceh);
}

event_handler* create_acceptor(int fd, reactor* r)//, user_list* ul)
{
	event_handler* eh = malloc(sizeof(event_handler));
	eh->fd = fd;
	eh->r = r;
	//eh->ul = ul;
	eh->handle_event = &handle_event;

	return eh;
}

