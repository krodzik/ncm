#ifndef EVENT_HANDLER_H
#define EVENT_HANDLER_H

#include "user_list.h"
#include <stdint.h>

typedef struct reactor reactor;

typedef struct event_handler {
	int fd;
	reactor* r;
	user_list* ul;
	void (*handle_event)(struct event_handler* self, uint32_t e);

} event_handler;

#endif //EVENT_HANDLER_H

