// TODO: EventHandler& operator=(const EventHandler&);
//      EventHandler(const EventHandler&);
// PRZEŁADOWANIE KONSTRUKTORA I OPERATORA

typedef struct _EventHandler EventHandler;

typedef void (*fptrGetHandle)(EventHandler*);
typedef void (*fptrDelete)(EventHandler *);

typedef struct _EventHandler
{
    // do dziedziczenia
    void* pDerivedObj;
    int m_fd;
    // w C++ to jest shared_ptr<>, ja z tego zrobiłem void* póki co, trzeba sprawdzić
    void* Ptr;

    //w C++ masz "virtual void handleEvent(uint32_t) = 0;"
    //tutaj chyba nie trzeba tego pisać

    // tu już coś do listy kombinowałem, apropo (typedef ::std::map<int, EventHandler::Ptr> t_handlers;) - masz to w EpollReactor. Zmieniaj. Kombinuj :)
    EventHandler* next;

    fptrGetHandle getHandler;
    fptrDelete deleteEH;
}EventHandler;

EventHandler* new_EventHandler(int);   // constructor
void delete_EventHandler(EventHandler* const); // destructor

int EventHandler_getHandler(EventHandler* const, void*);
