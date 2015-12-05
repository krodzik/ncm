#include "event_handler.h"

typedef struct reactor_core reactor_core;

typedef struct reactor {
	void (*add_eh)(reactor* self, event_handler* eh);
	void (*rm_eh)(reactor* self, int fd);
	void (*event_loop)(reactor* self);
	reactor_core* rc;
} reactor;

reactor* create_reactor(int epoll_fd);
void destroy_reactor(reactor* r);

