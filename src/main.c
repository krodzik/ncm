#include <stdio.h>
#include <stdlib.h>

#include "read_configure_file.h"

int main(int argc, char **argv)
{
	/* Pobranie konfiguracji z pliku "config.cfg" i wypisanie pobranych parametrow */
	int port;
	int max_clients;
	if(get_config(&port, &max_clients))
		return(-1);
	
	printf("Z pliku konfiguracyjnego:\nport : %d \t\tmax_clients : %d \n", port, max_clients);

	return 0;
}
