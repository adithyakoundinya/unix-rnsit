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
	int sockfd;
	struct sockaddr_in cliaddr;
	char send_data[1024];
	struct hostent *host;
	
	host = gethostbyname ("127.0.0.1");
	
	// creating a socket
	sockfd = socket ( AF_INET, SOCK_STREAM, IPPROTO_TCP);
	
	// Initializing socket address structure
	cliaddr.sin_port 	= 	htons(5000);
	cliaddr.sin_family	=	AF_INET;
	cliaddr.sin_addr	= 	*((struct in_addr *)host->h_addr);
	
	// connecting to the server
	
	connect(sockfd, (struct sockaddr *)&cliaddr, sizeof(struct sockaddr));
	printf("Connected to the server at port 5000\n");
	
	// Taking input from the user
	printf("Enter any statement at will\n");
	gets(send_data);
	
	// Sending the input statement to the server
	send(sockfd,send_data,1024,0);
	recv(sockfd,send_data,1024,0);
	printf("Echoed statement from server:  %s\n",send_data);
}
