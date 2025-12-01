#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

void matmul(int n)
{
    float **A = malloc(n * sizeof(float *));
    float **B = malloc(n * sizeof(float *));
    float **C = malloc(n * sizeof(float *));
    
    for (int i = 0; i < n; i++) {
        A[i] = malloc(n * sizeof(float));
        B[i] = malloc(n * sizeof(float));
        C[i] = malloc(n * sizeof(float));
        for (int j = 0; j < n; j++) {
            A[i][j] = rand() % 10;
            B[i][j] = rand() % 10;
        }
    }

    #pragma omp parallel for collapse(2)
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            float sum = 0;
            for (int k = 0; k < n; k++)
                sum += A[i][k] * B[k][j];
            C[i][j] = sum;
        }

    printf("OpenMP multiplication done for %d x %d matrix\n", n, n);
}

int main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("Usage: ./matmul_omp <matrix_size>\n");
        return 1;
    }
    int n = atoi(argv[1]);
    matmul(n);
}
