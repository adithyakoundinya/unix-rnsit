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
	socklen_t length;
	struct sockaddr_in servaddr;
	char send_data[1024];
	struct hostent *host;
	
	host = gethostbyname ("127.0.0.1");
	
	
	
	// Initializing socket address structure
	servaddr.sin_port 	= 	htons(5000);
	servaddr.sin_family	=	AF_INET;
	servaddr.sin_addr	= 	*((struct in_addr *)host->h_addr);
	
	// creating a UDP socket
	sockfd = socket ( AF_INET, SOCK_DGRAM, IPPROTO_UDP);
	
	// Taking input from the user
	printf("Enter any statement at will\n");
	gets(send_data);
	
	length = sizeof(servaddr);
	// Sending the input statement to the server
	sendto(sockfd, send_data, strlen(send_data), 0, &servaddr, length);
	recvfrom(sockfd, send_data, 1024, 0, NULL, NULL);
	printf("Echoed statement from server:  %s\n",send_data);
}