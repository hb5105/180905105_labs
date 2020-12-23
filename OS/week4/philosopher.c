#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
 
sem_t chopsticks[5];
 
void *philosopher(void *arg)
{
    int i=*(int *)arg;
    sem_wait(&chopsticks[i]);
    sem_wait(&chopsticks[(i+1)%5]);
    printf("Philosopher %d eating..\n",i );
    sleep(1);
    printf("Philosopher %d finished eating!\n",i );
    sem_post(&chopsticks[(i+1)%5]);
    sem_post(&chopsticks[i]);
}
 
int main(int argc, char const *argv[])
{
    pthread_t p[5];
    int a[5];
    for (int i = 0; i < 5; ++i)
    {
        sem_init(&chopsticks[i],0,1);
    }
    for (int i = 0; i < 5; ++i)
    {
        a[i]=i;
        pthread_create(&p[i],0,&philosopher,(void *)&a[i]);
    }
    for (int i = 0; i < 5; ++i)
    {
        pthread_join(p[i],NULL);
    }
    return 0;
}