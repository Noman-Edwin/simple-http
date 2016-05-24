#include <sys/types.h>  
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>

int
build_socked()
{

	int	 listenfd;
	struct 	sockaddr_in  servaddr;
	
	
	listenfd=socket(AF_INET, SOCK_STREAM, 0);
	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port = htons(80);
	bind(listenfd, (const struct sockaddr *) &servaddr, sizeof(servaddr));
	listen(listenfd, 5);
	return listenfd;
	
}
