#include <sys/types.h>  
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <stdio.h>

int
main()
{

	int sockfd;
	struct sockaddr_in servaddr;
	char recvline[1024];
	char sendline[255];
	ssize_t nread;
	int	n;

	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(80);
	servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	connect(sockfd,(struct sockaddr *) &servaddr, sizeof(servaddr));
	
	fgets(sendline, sizeof(sendline), stdin);
	if ( (n = send(sockfd,sendline,sizeof(sendline),0)) < 0 )
		printf("send");		
	memset(recvline, 0, sizeof(recvline));
	while( (nread = read(sockfd, recvline, 1024)) > 0){
  		fputs(recvline,stdout);
		fflush(stdout);
	}
	printf("\r\n The connect is closed\r\n");
	close(sockfd);
}
