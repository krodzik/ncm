// TODO: EpollReactor(const EpollReactor&);
//       EpollReactor& operator=(const EpollReactor&);
// PRZEŁADOWANIE KONSTRUKTORA I OPERATORA

typedef struct _EpollReactor EpollReactor;

typedef void (*fptrRegisterHandler)(EpollReactor*, void*);
typedef void (*fptrRemoveHandler)(EpollReactor*, int);
typedef void (*fptrEventLoop)(EpollReactor*);
typedef void (*fptrDelete)(EpollReactor *);

typedef struct _EpollReactor
{
    // JAK TO ZROBIĆ?
    // typedef ::std::map<int, EventHandler::Ptr> t_handlers;
    int m_epollFd;
    int m_maxEvents;
    //t_handlers m_handlers;

    // Interface to access member functions
    fptrRegisterHandler registerHandler;
    fptrRemoveHandler removeHandler;
    fptrEventLoop eventLoop;
    fptrDelete deleteER;
}EpollReactor;

EpollReactor* new_EpollReactor();   // constructor
void delete_EpollReactor(EpollReactor* const); // destructor

void EpollReactor_registerHandler(EpollReactor* const, void*);
void EpollReactor_removeHandler(EpollReactor* const, int);
void EpollReactor_eventLoop(EpollReactor* const);
