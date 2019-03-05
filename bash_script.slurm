#!/bin/sh
#SBATCH --partition= WORKQ
#SBATCH -- time==00:10:00
#SBATCH -- nodes=1
#SBATCH -- ntasks-per-node=8
#SBATCH -- ncpus-per-task= 4
#SBATCH --job-name="test"


WORKDIR=${SLURM_SUBMIT_DIR}
cd ${WORKDIR}

module purge
module load g++
module load OpenMPI
module load OpenMP





