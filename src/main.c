#include <stdio.h>
#include <stdlib.h>

#include "read_config.h"
#include "AcceptorEH.h"

int main(int argc, char **argv)
{
	// Read arguments from "config.cfg" file and printing them
	int port;
	int max_clients;
	if(get_config(&port, &max_clients))
		return(-1);

	printf("From configuration file:\nport number : %d \t\tmax clients number : %d \n", port, max_clients);

    // tutaj część właściwa
    EpollReactor* reactor = new_EpollReactor();
    // do skończenia

	return 0;
}
