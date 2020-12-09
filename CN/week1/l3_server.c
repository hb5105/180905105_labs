//server code
// server program for udp connection
#include <stdio.h>
#include <strings.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#define PORT 5000
#define MAXLINE 1000
// Server code
int main()
{
char a[10],b[10],c[2];
int servsockfd, len, n;
struct sockaddr_in servaddr, cliaddr;
bzero(&servaddr, sizeof(servaddr));
// Create a UDP Socket
servsockfd = socket(AF_INET, SOCK_DGRAM, 0);
servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
servaddr.sin_port = htons(PORT);
servaddr.sin_family = AF_INET;
// bind server address to socket descriptor
bind(servsockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));

//receive the datagram
len = sizeof(cliaddr);
n = recvfrom(servsockfd, a, sizeof(a), 0, (struct sockaddr *)&cliaddr, &len);
a[3] = '\0';
int a1,b1;
a1=a[0]-'0';
b1=a[2]-'0';
char d[5];
if ((strcmp(a[1],'+')==0))
{
	sprintf(d,(a1+b1));

	/* code */
}
else if ((strcmp(a[1],'-')==0))
{
	sprintf(d,(a1-b1));

	/* code */
}
else if ((strcmp(a[1],"/")==0))
{
	sprintf(d,(a[1]/b1));

	/* code */
}
else if ((strcmp(a[1],"*")==0))
{
	sprintf(d,(a1*b1));

	/* code */
}
puts(d);
//Echoing back to the client
sendto(servsockfd, d, sizeof(d), 0, (struct sockaddr *)&cliaddr, sizeof(cliaddr));


// close the descriptor
close(servsockfd);
}