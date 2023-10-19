#!/bin/bash

# Request resources:
#SBATCH -n 4           # number of MPI ranks (1 per CPU core)
#SBATCH -N 2           # number of compute nodes. 
#SBATCH --partition=cpu           # number of compute nodes. 
#SBATCH -t 0:0:30       # time limit for job (format: days-hours:minutes:seconds) 

module load intel-oneapi/2022.1.2/mpi
cd hpl-2.3
make clean # Important
./configure
make -j 4
cd testing
cp ptest/HPL.dat .

mpirun ./xhpl