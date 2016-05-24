#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <string.h>

void
send_socked(int socked)
{
	
	char buf[1024];
	memset(buf,0,sizeof(buf));	
	FILE *fp;
	fp = fopen("/root/index.html","r");
	fgets(buf,sizeof(buf),fp);
	while(!feof(fp))
	{
		send(socked,buf,sizeof(buf),0);
		fgets(buf,sizeof(buf),fp);
	}
	send(socked,buf,sizeof(buf),0);
	close(socked);
}
