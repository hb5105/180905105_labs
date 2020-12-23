#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>
 
int mat[100][100];
 
void *rowsum(void *para)
{
    int n=*((int *)para);
    int arr[n];
    for(int i=0;i<n;i++)
    {
        arr[i]=0;
        for(int j=0;j<n;j++)
            arr[i]+=mat[i][j];
    }
    int *sol=(int *)calloc(n, sizeof(int));
    memcpy(sol,arr,sizeof(int)*n);
    return sol;
 
}
void *colsum(void *para)
{
    int n=*((int *)para);
    int arr[n];
    for(int i=0;i<n;i++)
    {
        arr[i]=0;
        for(int j=0;j<n;j++)
            arr[i]+=mat[j][i];
    }
    int *sol=(int *)calloc(n, sizeof(int));
    memcpy(sol,arr,sizeof(int)*n);
    return sol;
}
int main(int argc, char const *argv[])
{
    int n;
    int *row,*col;
    pthread_t tid1,tid2;
    printf("n: ");
    scanf("%d",&n);
    printf("Enter elements\n");
    for (int i = 0; i < n; ++i)
    {
        for (int j=0;j<n;j++)
            scanf("%d",&mat[i][j]);
    }
    pthread_create(&tid1,0,&rowsum,(void *)&n);
    pthread_create(&tid2,0,&colsum,(void *)&n);
    pthread_join(tid1,(void *)&row);
    pthread_join(tid2,(void *)&col);
    printf("Rowsum: ");
    for (int i = 0; i < n; ++i)
        printf("%d\t",row[i] );
    printf("\nColsum: ");
    for (int i = 0; i < n; ++i)
        printf("%d\t",col[i] );
    printf("\n");
    return 0;
}