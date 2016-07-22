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
	
	// binding to the server
	bind(listenfd, (struct sockaddr *)&servaddr, sizeof(struct sockaddr));

	// Recieving the input statement from the client
	printf("waiting for data\n");
	
	recvfrom(listenfd, recv_data, MAXLINE, 0, NULL, NULL);
	//recv(listenfd,recv_data,1024,0);
	printf("%s\n",recv_data);
	// sending data back to client
	sendto(listenfd, recv_data, strlen(recv_data), 0, servaddr, sizeof(sockaddr_in));
	
	close (connfd);
	close (listenfd);
	
	return 0;
}