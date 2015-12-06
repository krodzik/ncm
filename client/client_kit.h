#ifndef __CLIENT_KIT_H
#define __CLIENT_KIT_H
#include<stdio.h>

int send_message( int s_fd , char * message, size_t len );
int recv_message( int s_fd );

void Displaymenu();
int GetDeviceInfo();
int SetDeviceParams();

#endif
