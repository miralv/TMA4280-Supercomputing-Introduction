# TMA4280-Supercomputing-Introduction
Use the folder TestRun for building.
Type in terminal
cmake ..
make
Then the different programs can be run as specified below.

prog: mach0, zeta0
./prog arg1 arg2, arg3
arg1:n (required)
arg2: 1 if utest wanted (optional)
arg3: 1 if vtest wanted (optional)


prog: mach1, zeta1, mach2, zeta2
mpirun -np <nprocesses> ./prog arg1
arg1: n (required)

prog: mach3, zeta3
./prog arg1 arg2
arg1: n (required)
arg2: n threads (required)

prog: mach4, zeta4
mpirun -np <nprocesses> ./prog arg1 arg2
arg1: n (required)
arg2: n threads (required)



