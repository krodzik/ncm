#include "EchoREsponderEH.h"
#include <stdlib.h>     // for fprintf()
#include <string.h>
#include <unistd.h>
#include <sys/epoll.h>

EventHandler* new_EchoResponderEH(int p_fd)
{
    EchoResponderEH* self = NULL;
    EventHandler* pParentObj = NULL;
    pParentObj = new_EventHandler(p_fd); //calling base class constructor
    // allocating memory
    self = (EchoResponderEH*)malloc(sizeof(EchoResponderEH));
    if(self == NULL)
    {
        return 0;
    }
    // do dziedziczenia
    pParentObj->pDerivedObj = self; //pointing to derived object

    //to jest juz w konstruktorze EventHandler, nie wiem czy i tu jest potrzebne
    /*
    // variable initialization
    self->m_fd = p_fd;
    */
    // Initializing interface for access to functions
    //taki sam jak w funkcji z ktorej dziedziczy, a wiec nie potrzebny
    //self->getHandler = EventHandler_getHandler;
    // to jest wazne, bo z funkcji vitual w oryginale
    self->handleEvent = EchoResponderEH_handleEvent;
    //raczej zbedne, jako ze destruktory sie nie roznia
    self->deleteEH = delete_EchoResponderEH;
}

void delete_EchoResponderEH(EventHandler* const self)
{
    free(self);
}

void EchoResponderEH_handleEvent(EventHandler* const, uint32_t p_event)
{
    if (p_event & EPOLLIN)
	{
		char msg[2048];
		memset(msg, 0, 2048);
		int r = read(m_fd, msg, 2048);
		if (r < 0)
		{
			fprintf(stderr, "Cannot read.");
            return -1;
		}

		int w = ::write(m_fd, msg, r);
		if (w < 0)
		{
			fprintf(stderr, "Cannot write.");
            return -1;
		}
	}
	else
	{
	    fprintf(stderr, "Bad event for for responder");
        return -1;
	}
}
