#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <string.h>

void
head(int client)
{
	char 	buf[1024];
	
	sprintf(buf,"HTTP/1.0 200 OK\r\n");
	send(client, buf, strlen(buf), 0);
	sprintf(buf,"Content-Type: text/html\r\n");
	send(client, buf, strlen(buf), 0);
	sprintf(buf,"\r\n");
	send(client, buf, strlen(buf), 0);
}
