#!/bin/bash
# Benchmark MPI + OpenMP matrix multiplication

# Number of MPI processes
MPI_PROCS=4

# Number of OpenMP threads per process
export OMP_NUM_THREADS=4

# Output log file
LOG_FILE=benchmark_results.txt
echo "Matrix Size, Execution Time (s)" > $LOG_FILE

# List of matrix pairs
declare -a matrices=(
  "data/mat_5x4.txt data/mat_4x5.txt 5x4"
  "data/mat_10x10.txt data/mat_10x10_b.txt 10x10"
  "data/mat_500x500.txt data/mat_500x500_b.txt 500x500"
  "data/mat_2000x2000.txt data/mat_2000x2000_b.txt 2000x2000"
  "data/mat_5000x5000.txt data/mat_5000x5000_b.txt 5000x5000"
)

# Benchmark loop
for matrix in "${matrices[@]}"
do
    set -- $matrix
    A=$1
    B=$2
    SIZE=$3

    echo "Benchmarking $SIZE ..."
    
    # Measure time using /usr/bin/time in seconds only
    TIME=$( /usr/bin/time -f "%e" mpirun -np $MPI_PROCS bin/mpi $A $B > /dev/null 2>&1 2>&1 )

    echo "$SIZE, $TIME" >> $LOG_FILE
done

echo "Benchmarking completed. Results saved in $LOG_FILE."
