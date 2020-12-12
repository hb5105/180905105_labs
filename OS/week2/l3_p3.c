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
		
		printf("CHILD PROCESS\n");
		printf("PROCESS ID %d \n",getpid());
		printf("PARENT ID %d \n",getppid());
	
	}
	else
	{
		wait(&status);
		printf("\n\n");
	printf("PARENT PROCESS\n");
		printf("PROCESS ID %d \n",getpid());
		
	exit(0);
}}