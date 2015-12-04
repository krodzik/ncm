#include "EventHandler.h"
//dziedziczy z EventHandler

//coś tu się też dzieje z EpollReactor
#include "EpollReactor.h"

#include <sys/socket.h>

typedef struct _AcceptorEH AcceptorEH;

typedef void (*fptrHandleEvent)(EventHandler*, uint32_t);

typedef struct _AcceptorEH
{
    int m_port;
    struct sockaddr m_address;
    socklen_t m_addressLength;
	EpollReactor& m_reactor;

	fptrHandleEvent handleEvent;

}AcceptorEH;

EventHandler* new_AcceptorEH(int, EpollReactor&);   // constructor
//void delete_AcceptorEH(EventHandler* const); // destructor

void AcceptorEH_handleEvent(EventHandler* const, uint32_t);
