#!/bin/bash

# Custom matrix sizes
ROWS=(5 10 500 2000 5000)
COLS=(4 10 500 2000 5000)

THREADS=4
MPI_PROCS=4

echo "============================================"
echo " MATRIX MULTIPLICATION BENCHMARK"
echo " Sizes: 5×4, 10×10, 500×500, 2000×2000, 5000×5000"
echo "============================================"
echo ""

for i in ${!ROWS[@]}
do
    R=${ROWS[$i]}
    C=${COLS[$i]}

    echo "*************** SIZE = ${R} x ${C} ***************"

    echo -n "Sequential: "
    /usr/bin/time -f "%E" ./matmul_seq $R $C > /dev/null

    echo -n "OpenMP (${THREADS} threads): "
    OMP_NUM_THREADS=$THREADS /usr/bin/time -f "%E" ./matmul_omp $R $C > /dev/null

    echo -n "Pthreads (${THREADS} threads): "
    /usr/bin/time -f "%E" ./matmul_pthread $R $C $THREADS > /dev/null

    echo -n "MPI (${MPI_PROCS} processes): "
    /usr/bin/time -f "%E" mpirun -np $MPI_PROCS ./matmul_mpi $R $C > /dev/null

    echo ""
done
