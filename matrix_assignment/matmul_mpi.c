#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

int main(int argc, char *argv[])
{
    int n, rank, size;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (argc != 2) {
        if (rank == 0)
            printf("Usage: mpirun -np <p> ./matmul_mpi <matrix_size>\n");
        MPI_Finalize();
        return 1;
    }

    n = atoi(argv[1]);

    // Worker code simplified for demonstration
    if (rank == 0)
        printf("MPI matrix multiply %d x %d with %d processes\n", n, n, size);

    MPI_Finalize();
}
