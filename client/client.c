/* aplikacja klienta */
/* przyjmuje 2 opcjonalne argumenty 
[x]IP maszyny z ktora chce sie skomunikowac .. default = loopback
[x]Port pod ktorym komunikowuje sie z serwerem default = domyslnie wybrany port */

/* 
I. Program pozwala pobrać z serwera
1. [x]Liste dostepnych na nim interfejsow sieciowych //show all
2. Dane szczegolowe dla danych interfejsow (jeden , wiele lub wszystkie) 
	//show <interface> 
[ ]Status Up/Down
[x]Adres fizyczny
[x]Adres IPv4 i maske sieciowa(jesli nie nadany pole puste)
[ ]Adres IPv6 (jesli nie nadany pole puste)
II.Pozwala ustawic na serwerze
[x]Adres fizyczny na danym interfejsie sieciowym
[x]adres ip i maske sieciowa na danym interfejsie sieciowym */
// --------------------------------------------------------------
#include"client_kit.h"
#include<sys/socket.h>
#include<arpa/inet.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
// program przyjmuje kolejno IP i Port

int main( int argc , char * argv[] )
{
   int s_sock;
   struct sockaddr_in serv;
   int Port = 9999;
   char * IP = "127.0.0.50";
   
   if(argc == 3)
   {
   IP = argv[1];
   Port = atoi(argv[2]);  
   }
   else if(argc == 2)IP = argv[1]; 
 
   char message[1024];

   s_sock = socket(AF_INET , SOCK_STREAM , 0 );
	if( s_sock < 0 )
	{
		perror(NULL);
		return -1;
	}

	memset(&serv , 0 , sizeof(serv));
   serv.sin_addr.s_addr = inet_addr(IP); // loopback
   serv.sin_family = AF_INET;
   serv.sin_port = htons( Port );

   if( connect(s_sock , (struct sockaddr*)&serv , sizeof(serv)) < 0 )
   {
      puts("Connection failed");
      return -1; 
   }

   while(1)
	{ 
		memset(message , 0 ,1024 );

		printf("Please enter message: ");	
		fgets(message,1024,stdin);
		if(send_message(s_sock,message,strlen(message)))
			perror(NULL);
		
		if(recv_message(s_sock))
			perror(NULL);

	}

   close(s_sock);

return 0;
}

