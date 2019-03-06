# TMA4280-Supercomputing-Introduction
How to run the different folders are specified below.

prog: mach0, zeta0
./prog arg1 arg2, arg3
arg1:n (required)
arg2: 1 if utest wanted (optional)
arg3: 1 if vtest wanted (optional)


mach1:
mpirun -np <nprocesses> ./mach1


mach3: 
hvis man kjører fra mappen mach3, så virker dette:
g++ main.cpp .-lgomp -o test.exe 

eller: export OMP_NUM_THREADS=8; ./myprogram


