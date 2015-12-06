#include "client_eh.h"
#include "ru.h"
#include "reactor.h"

#include <string.h>
#include <sys/epoll.h>


#include <stdio.h>

static int handle_client_message(event_handler* self, struct message* m)
{
	int fd = self->fd;
	int result = -1;

	switch (m->x) {
	    case TEST:
            result = send_test(fd);
            break;
		default:
			break;
	}

	delete_message(m);
	return result;
}

static void serve_client(event_handler* self, uint32_t e)
{
	int result = -1;
	struct message* m = 0;
	if (e & EPOLLIN) {
		m = receive_message(self->fd);
		if (m)
			result = handle_client_message(self, m);
	}

	if (result < 0) {
		//self->ul->rm_user_by_fd(self->ul->ctx, self->fd);
		self->r->rm_eh(self->r, self->fd);
	}
}

event_handler* create_client_eh(int fd, reactor* r)//, user_list* ul)
{
	event_handler* eh = malloc(sizeof(event_handler));
	eh->fd = fd;
	eh->r = r;
	//eh->ul = ul;
	eh->handle_event = &serve_client;

	return eh;
}

