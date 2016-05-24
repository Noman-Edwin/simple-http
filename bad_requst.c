#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <string.h>

void
bad_requst(int client)
{
	char 	buf[1024];
	
	sprintf(buf,"HTTP/1.0 501 Method NOT Find\r\n");
	send(client, buf, strlen(buf), 0);
	sprintf(buf,"Server : jdbhttpd/0.1.0\r\n");
	send(client, buf, strlen(buf), 0);
	sprintf(buf,"Content-Type: text/html\r\n");
	send(client, buf, strlen(buf), 0);
	sprintf(buf,"\r\n");
	send(client, buf, strlen(buf), 0);
	sprintf(buf,"<HTML><HEAD><TITLE>Method NOT Find\r\n");
	send(client, buf, strlen(buf), 0);
	sprintf(buf,"</TITLE></HEAD>\r\n");
	send(client, buf, strlen(buf), 0);
	sprintf(buf,"<BODY><P>HTTP request method not supported\r\n");
	send(client, buf, strlen(buf), 0);
	sprintf(buf,"</BODY></HTML>\r\n");
	send(client, buf, strlen(buf), 0);
}
