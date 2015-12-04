#include "EchoREsponderEH.h"
#include <stdlib.h>     // for fprintf()
#include <string.h>
#include <unistd.h>
#include <sys/epoll.h>

EventHandler* new_AcceptorEH(int p_fd, EpollReactor& p_reactor)
{
    AcceptorEH* self = NULL;
    EventHandler* pParentObj = NULL;
    pParentObj = new_EventHandler(p_fd); //calling base class constructor

    // DO SKOŃCZENIA. SORRY, NIE ZDĄŻYŁEM JUŻ
}
