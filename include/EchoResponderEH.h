#include "EventHandler.h"
//dziedziczy z EventHandler

typedef struct _EchoResponderEH EchoResponderEH;

typedef void (*fptrHandleEvent)(EventHandler*, uint32_t);
typedef void (*fptrDelete)(EchoResponder *);

typedef struct _EchoResponderEH
{
    fptrHandleEvent handleEvent;
}EchoResponderEH;

EventHandler* new_EchoResponderEH(int);   // constructor
void delete_EchoResponderEH(EventHandler* const); // destructor

void EchoResponderEH_handleEvent(EventHandler* const, uint32_t);
