#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

int main()
{
	int listenfd, connfd, strlen;
	struct sockaddr_in cliaddr, servaddr;
	char recv_data[1024];
	struct hostent *host;
	
	
	// creating a socket
	listenfd = socket ( AF_INET, SOCK_STREAM, IPPROTO_TCP);
	
	// Initializing socket address structure
	servaddr.sin_port 	= 	htons(5000);
	servaddr.sin_family =	AF_INET;
	servaddr.sin_addr.s_addr = INADDR_ANY;
	
	// connecting to the server
	bind(listenfd, (struct sockaddr *)&servaddr, sizeof(struct sockaddr));

	// Putting the socket into listening mode
	listen(listenfd,5);
	
	strlen = sizeof(struct sockaddr);
	connfd = accept(listenfd, (struct sockaddr *) &cliaddr, &strlen);
	
	// Recieving the input statement from the client
	printf("waiting for data\n");
	recv(connfd,recv_data,1024,0);
	printf("%s\n",recv_data);
	// sending data back to client
	send(connfd,recv_data,1024,0);
	
	close (connfd);
	close (listenfd);
	
	return 0;
}