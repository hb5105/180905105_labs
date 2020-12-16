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
		
		printf("CHILD PROCESS ID %d \n",getpid());
		printf("PARENT ID %d OF CHILD %d \n",getppid(),getpid());
		sleep(5);
		printf("\nORPHAN CHILD %d \n",getpid());
		printf("ADOPTING PARENT ID %d OF ZOMBIE CHILD %d \n",getppid(),getpid());
		exit(0);
	}
	else
	{
		
		printf("\n\n");
	printf("PARENT PROCESS ID %d \n",getpid());
		exit(0);
}
;
exit(0);}