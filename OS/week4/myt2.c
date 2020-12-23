#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

void* thread_create(void* param){
	//int *arr;
	int x=*((int*)param);
	printf("value of x is %d\n",x );
	int sum=0;
	for (int i = 0; i <= x; ++i)
	{
		sum=sum+i;
		//printf("%d\n",sum );
	}
	//*arr=sum;
	return (void*)sum;

}

int main()
{

	int n;
	int a;
	pthread_t thread;
	printf("enter the no\n");
	scanf("%d",&n);
	pthread_create(&thread,0,&thread_create,(void*)n);
	printf("thread has been created\n");
	pthread_join(thread, (void**)&a);
	printf("this is the sum%d\n",a);
}