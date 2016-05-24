#include <sys/socket.h>
#include <string.h>

int
get_line(int sock, char *buf, int size)
{
	int	i = 0;
	char 	c = '\0';
	int	n;
	
	memset(buf,0,sizeof(buf));
	while ((i<size-1) && (c != '\n') )
	{	
		n = recv(sock, &c, 1, 0);
		if (n > 0)
		{
			if (c == '\r') 
			{
				n = recv(sock, &c, 1, MSG_PEEK);
				if((n > 0)&& ( c == '\n') )
					recv(sock, &c, 1, 0);
				else
					c = '\n';
			}
			buf[i] = c;
			i++ ;
		}
		else
			c = '\n';
	}
	buf[i] = '\0';
	return (i);
	
}
