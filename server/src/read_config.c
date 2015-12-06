#include "read_config.h"

int get_config(int *port, int *max_clients)
{
	config_t cfg;
	
	/* Initialization */
	config_init(&cfg);
	
	/* Read the file. If there is an error, report it and exit. */
	if(! config_read_file(&cfg, "../build/config.cfg"))
	{
		fprintf(stderr, "%s:%d - %s\n", config_error_file(&cfg),
				config_error_line(&cfg), config_error_text(&cfg));
		config_destroy(&cfg);
		return(EXIT_FAILURE);
	}
	
	/* Read the parameter */
	if(! config_lookup_int(&cfg, "port", port))
		fprintf(stderr, "Brak konfiguracji dla portu.\n");
		
	if(! config_lookup_int(&cfg, "max_clients", max_clients))
		fprintf(stderr, "Brak konfiguracji dla maksymalnej liczby klientow.\n");
	
	config_destroy(&cfg);
	return(EXIT_SUCCESS);
}
