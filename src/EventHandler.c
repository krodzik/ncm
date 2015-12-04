#include "EpollReactor.h"
#include <stdlib.h>     // for fprintf()

EventHandler* new_EventHandler(int p_fd)
{
    EventHandler* self = NULL;
    // allocating memory
    self = (EventHandler*)malloc(sizeof(EventHandler));
    if(self == NULL)
    {
        return 0;
    }
    // do dziedziczenia
    self->pDerivedObj = self; //pointing to itself
    // variable initialization
    self->m_fd = p_fd;

    // Initializing interface for access to functions
    self->getHandler = EventHandler_getHandler;
    self->deleteEH = delete_EventHandler;
}
void delete_EventHandler(EventHandler* const self)
{
    free(self);
}

int EventHandler_getHandler(EventHandler* const self, void* Ptr)
{
    return self->m_fd;
}
