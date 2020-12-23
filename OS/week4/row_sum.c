#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define M 10
#define N 10

int rows, columns, a[M][N], s[M];

// compute the sum of each row

void* f(void* p) {
   int k = *((int*) p);
   int i;
   for (i = 0; i < columns; i++) {
      s[i] += a[k][i];
   }
   return NULL;
}

int main() {
    int i, j, *p, rc;
    int sum = 0;
    pthread_t th[M];

    // matrix creation
    printf("no. of rows = ");
    scanf("%d", &rows);
    printf("no. of columns = ");
    scanf("%d", &columns);

    for (i = 0; i < rows; i++) {
        for (j = 0; j < columns; j++) {
            printf("a[%d][%d] = \n", i, j);
            scanf("%d", &a[i][j]);
        }
    }

    printf("\nThe matrix is: \n");
    for(i=0; i < rows; i++) {
        for(j=0; j < columns; j++)
            printf("%d ", a[i][j]);
    printf("\n");
    }

    // thread creation
    for (i=0; i < rows; i++) {
        p = malloc(sizeof(int));
        *p = i;
        rc = pthread_create(&th[i], NULL, f, p);
        if (rc != 0) {
            printf("Thread creation failed");
            exit(-1);
        }
    }

    for (i=0; i < rows; i++) {
        pthread_join(th[i], NULL);
    }
    // compute the final sum
    for (i=0; i < rows; i++) {
        sum += s[i];
    }
    printf("The sum is = %d\n", sum);

    return 0;
    }