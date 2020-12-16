#include<stdio.h>
#include <stdlib.h>
#include<sys/wait.h>
int main(){
	
	pid_t pid;
	
	int i=0,j=0;
	pid=fork();
	if (pid==-1)
	{
		printf("child not created\n");
	}
	if (pid==0)
	{
		
		printf("child PROCESS ID %d \n",getpid());
		//printf("parent ID %d OF CHILD %d \n",getppid(),getpid());
		sleep(6);
		printf("the parent has died\n");
		printf("\nchild %d is now orphan\n",getpid());
		printf("adopting init parent ID %d OF orphan child %d \n",getppid(),getpid());
		exit(0);
	}
	else
	{
		
		printf("\n\n");
	printf("parent process ID %d \n",getpid());
		exit(0);
}

}