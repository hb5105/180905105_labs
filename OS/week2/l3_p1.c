#include<stdio.h>
#include <stdlib.h>

#include<sys/wait.h>
int main(){
	int status;
	pid_t pid;
	
	int i=0,j=0;
	pid=fork();
	if (pid==-1)
	{
		printf("child not created\n");
	}
	if (pid==0)
	{
		while(j<4){
		printf("child process is ecxecuting Q1\n");
	j++;
	}
	}
	else
	{
		
	while(i<2){
		printf("parent process is ecxecuting Q1\n");
		
		i++;}
		wait(&status);
		while(i<5){
		printf("parent process is ecxecuting Q1\n");
		
		i++;}
		printf("\n\n");
	}
	exit(0);
}