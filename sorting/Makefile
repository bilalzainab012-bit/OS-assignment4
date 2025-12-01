CC = gcc
CFLAGS = -Wall -O2 -fopenmp -pthread

all: seq pthread omp

seq: seq_merge_sort.c
	$(CC) $(CFLAGS) seq_merge_sort.c -o seq

pthread: pthread_merge_sort.c
	$(CC) $(CFLAGS) pthread_merge_sort.c -o pthread

omp: omp_merge_sort.c
	$(CC) $(CFLAGS) omp_merge_sort.c -o omp

clean:
	rm -f seq pthread omp
