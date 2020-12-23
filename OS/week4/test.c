#include<stdlib.h>
#include<stdio.h>
#include<pthread.h>
#include<string.h>

void* thread_create(void* param){
	int id=((int)param);
	printf("%d thisis what is shared\n",id);
	return (void*)id;
}

int main()
{
	pthread_t thread[10];
	int retur_val[10];
	for(int i=0;i<10;i++)
	{
		pthread_create(&thread[i],0,&thread_create,(void*)i);
	}
	for (int i = 0; i < 10; ++i)
	{
		pthread_join(thread[i],(void**)&retur_val[i]);
		printf("end of thread %d\n",retur_val[i]);
	}
}