#include <sys/socket.h>
#include<netinet/in.h>
#include <ctype.h>
#include <strings.h>
#include <stdio.h>
#include <stdlib.h>

int 
accept_socked(int socked)
{
	int conn;
	struct sockaddr_in cliaddr;
	socklen_t len;
	len = sizeof(cliaddr);
	char method[255];
	char	buf[1024];
	size_t	i;	
	pid_t	pid;

	while((conn =  accept(socked,(struct sockaddr *)&cliaddr,&len)) > -1)
	{
		if ((pid=fork()) == 0)
		{
			get_line(conn,buf, sizeof(buf));
			i = 0;
			while(!isspace(buf[i]) &&(i < sizeof(buf) - 1))
			{	
				method[i] = buf[i];
				i++;
			}
			method[i] = '\0';
			if (strcasecmp(method,"get"))
				bad_requst(conn);
			else
			{	
				head(conn);
				send_socked(conn);
			}	
			exit(0);
		}
		close(conn);
	}
	return 0;
}
