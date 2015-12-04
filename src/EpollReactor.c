#include "EpollReactor.h"
#include <sys/epoll.h>
#include <stdlib.h>     // for fprintf()

EpollReactor* new_EpollReactor()
{
    EpollReactor* self = NULL;
    // allocating memory
    self = (EpollReactor*)malloc(sizeof(EpollReactor));
    if(self == NULL)
    {
        return 0;
    }
    // variable initialization
    self->m_epollFd = -1;
    self->m_maxEvents = 100;
    m_epollFd = epoll_create(m_maxEvents);
    if(m_epollFd < 0)
    {
        fprintf(stderr, "Epoll create failed");
        return -1;
    }

    // Initializing interface for access to functions
    self->registerHandler = EpollReactor_registerHandler;
    self->removeHandler = EpollReactor_removeHandler;
    self->eventLoop = EpollReactor_eventLoop;
    self->deleteER = delete_EpollReactor;
}

void delete_EpollReactor(EpollReactor* const self)
{
    close(self->m_epollFd);
    free(self);
}

void EpollReactor_registerHandler(EpollReactor* const self, void* Ptr)
{
    int fd = Ptr->getHandle();
    int option = EPOLL_CTL_ADD;

    epoll_event e;
    memset(&e, 0, sizeof(e));
    e.data.fd = fd;
    e.events    |=EPOLLIN   |   EPOLLRDHUP
                | EPOLLERR  |   EPOLLHUP;
    if(epoll_ctl(self->m_epollFd, option, fd, &e) < 0)
    {
        fprintf(stderr, "Add handler to epoll failed");
        return -1;
    }

    // tutaj trzeba przerobić na C
    //m_handlers[fd] = p_eventHandler;
}
void EpollReactor_removeHandler(EpollReactor* const self, int );
void EpollReactor_eventLoop(EpollReactor* const self);
