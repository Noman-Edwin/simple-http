#include <sys/socket.h>

void accept_socked(int sock);
int build_socked();

int 
main()
{
	int sock;
	
	sock = build_socked();
	accept_socked(sock);
	return 0;
		
}
