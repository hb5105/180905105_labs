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
		printf("\n\n");
		while(j<4){
		printf("the child process is ecxecuting QUESTION 2\n");
	j++;
	}
	printf("\n\n NEW PROCESS (output of Q1) ASSIGNED TO child\n");
	execl("./obj","obj",NULL);
	printf("\n\n THIS WILL NOT BE EXECUTED\n");
	}
	else
	{
		printf("\n\n");

	while(i<2){

		printf("the parent process is ecxecuting QUESTION 2\n");
		
		i++;}
		wait(&status);
		while(i<5){
		printf("the parent process is ecxecuting QUESTION 2\n");
		
		i++;}
	}
	exit(0);
}