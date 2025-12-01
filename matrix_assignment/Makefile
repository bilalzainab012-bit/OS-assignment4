CC = gcc
MPICC = mpicc
CFLAGS = -O2 -Wall
OMPFLAG = -fopenmp
PTHFLAG = -lpthread

all: matmul_seq matmul_omp matmul_pthread matmul_mpi

matmul_seq: matmul_seq.c
	$(CC) $(CFLAGS) -o matmul_seq matmul_seq.c

matmul_omp: matmul_omp.c
	$(CC) $(CFLAGS) $(OMPFLAG) -o matmul_omp matmul_omp.c

matmul_pthread: matmul_pthread.c
	$(CC) $(CFLAGS) $(PTHFLAG) -o matmul_pthread matmul_pthread.c

matmul_mpi: matmul_mpi.c
	$(MPICC) $(CFLAGS) $(OMPFLAG) -o matmul_mpi matmul_mpi.c

clean:
	rm -f matmul_seq matmul_omp matmul_pthread matmul_mpi
