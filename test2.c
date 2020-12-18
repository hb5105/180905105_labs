    
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>


#define MAX 80
#define PORT 5555
#define SA struct sockaddr


void clifunc(int sockfd)
{​​​​​​​
    char buff[MAX];
    int n;


    for (;;) {​​​​​​​
        bzero(buff, sizeof(buff));
        printf("Enter the character : ");
        n = 0;
        
        while ((buff[n++] = getchar()) != '\n');


        write(sockfd, buff, sizeof(buff));
        bzero(buff, sizeof(buff));
        read(sockfd, buff, sizeof(buff));


        printf("From Server : %s", buff);
    }​​​​​​​
}​​​​​​​



int main()
{​​​​​​​
    int sockfd, connfd;
    struct sockaddr_in servaddr, cli;


    // socket create and verification
    sockfd = socket(AF_INET, SOCK_STREAM, 0);


    if (sockfd == -1) {​​​​​​​
        printf("socket creation failed...\n");
        exit(0);
    }​​​​​​​    
    else
        printf("Socket successfully created..\n");
    
    bzero(&servaddr, sizeof(servaddr));
    
    // assign IP, PORT
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr("172.16.57.152");
    servaddr.sin_port = PORT;


    // connect the client socket to server socket
    if (connect(sockfd, (SA*)&servaddr, sizeof(servaddr)) != 0) {​​​​​​​
        printf("connection with the server failed...\n");
        exit(0);
    }​​​​​​​
    else
        printf("connected to the server..\n");


    // function for client
    clifunc(sockfd);


    // close the socket
    close(sockfd);
}​​​​​​​














