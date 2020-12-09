//client code
#include <stdio.h>
#include <strings.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <stdlib.h>
#define PORT 5000
#define MAXLINE 1000

int main()
{
	char *a[10],*b[10],*c[2];
	printf("enter 2 operands and an operator\n");
	scanf("%s",a); scanf("%s",b); scanf("%s",c); 


// char *message = "Hello Server";
char buff[200];
int sockfd, n, len;
struct sockaddr_in servaddr, cliaddr;
// clear servaddr
bzero(&servaddr, sizeof(servaddr));
servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
servaddr.sin_port = htons(PORT);
servaddr.sin_family = AF_INET;
// create datagram socket
sockfd = socket(AF_INET, SOCK_DGRAM, 0);

sendto(sockfd, a, sizeof(a), 0, (struct sockaddr *)&servaddr, sizeof(servaddr));
len = sizeof(cliaddr);


read(sockfd, buff, sizeof(buff));
		printf("result : %s", buff);

close(sockfd);
}
