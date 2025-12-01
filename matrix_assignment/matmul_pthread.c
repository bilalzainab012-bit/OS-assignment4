#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int n, num_threads;
float **A, **B, **C;

void *worker(void *arg)
{
    int row = *((int *)arg);
    for (int j = 0; j < n; j++) {
        float sum = 0;
        for (int k = 0; k < n; k++)
            sum += A[row][k] * B[k][j];
        C[row][j] = sum;
    }
    return NULL;
}

int main(int argc, char *argv[])
{
    if (argc != 3) {
        printf("Usage: ./matmul_pthread <matrix_size> <num_threads>\n");
        return 1;
    }

    n = atoi(argv[1]);
    num_threads = atoi(argv[2]);

    A = malloc(n * sizeof(float *));
    B = malloc(n * sizeof(float *));
    C = malloc(n * sizeof(float *));
    for (int i = 0; i < n; i++) {
        A[i] = malloc(n * sizeof(float));
        B[i] = malloc(n * sizeof(float));
        C[i] = malloc(n * sizeof(float));
        for (int j = 0; j < n; j++) {
            A[i][j] = rand() % 10;
            B[i][j] = rand() % 10;
        }
    }

    pthread_t threads[num_threads];
    int rows[num_threads];

    for (int i = 0; i < num_threads; i++) {
        rows[i] = i;
        pthread_create(&threads[i], NULL, worker, &rows[i]);
    }

    for (int i = 0; i < num_threads; i++)
        pthread_join(threads[i], NULL);

    printf("Pthread multiplication done for %d x %d matrix\n", n, n);
}
