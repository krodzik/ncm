/* implementacje funkcji do prawidlowej komunikacji client-server */
#include "client_kit.h"
#include <malloc.h>
#include <unistd.h>

int send_message( int s_fd , char * message, size_t len )
{
	if( write(s_fd, &len, sizeof(size_t)) > 0 )
		if( write(s_fd, message , len ) > 0 ) 
			return 0;

	perror(NULL);
	return -1;
}

int recv_message( int s_fd )
{
	size_t len = 0;
	char * message = 0;

	if( read(s_fd, &len, sizeof(size_t)) < 1 )
	{
		perror(NULL);
		return -1;
	}

	// Alocate exactly size = length of reading message
	message = malloc( len * sizeof(char));

		if( read(s_fd, message , len+1 ) < 1 ) 
		{
			perror(NULL);
			free(message);
			return -1;
		}
	message[len] = '\0';
	printf("%s\n",message);

	free(message);
	return 0;
}

/* funkcje pozwalaja wyswietlic dane interfejsow i zmieniac ich parametry
 na maszynie dedykowanej */
void Displaymenu()
{
   return;
}

int GetDeviceInfo()
{
   
   return 1;
}

int SetDeviceParams()
{
   return 1;
}
