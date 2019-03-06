#include <iostream>
#include <mpi.h>
#include <cmath>

double riemannzeta(int i){
    // Calculate v_i by use of the riemann zeta formula
    double v_i = 1.0/(pow(i,2));
    return v_i;
}

// Add a program that distributes the elements to all the processes
// Each process receives only parts of the data
// Then each process computes its partial sum, before the partial sums are added
// Assume n % n_processes = 0

int main(int argc, char** argv){
    if(argc<2) {
        std::cout<<"Requires arguemnt: n"<<std::endl;
        std::cout<<"Choose n and nproc s.t. n%nproc = 0\n n must be a power of 2\n "<<std::endl;
        return 1;
    }
    const double PI = 4*atan(1.0);

    // Size and rank
    int size,rank;

    // Number of elements in the series
    int n = atoi(argv[1]);    
    double time_start;

    double* rz_vec = new double[n];
    double sum_total = 0;


    MPI_Init(&argc,&argv);

    MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    MPI_Comm_size(MPI_COMM_WORLD,&size);

    if(size&(size- 1)&&(size >= 0)){
        printf("%i is not a power of two. Call the program again with a different number of processes.",size);
        return 1;
    }

    int n_each = n/size; 
    int rem = n%size;
    double* rz_vec_sub = new double[n_each + rem];
    double sum_sub = 0;


    if (rank == 0){
        for (int i = 0; i<n; i++){
            rz_vec[i] = riemannzeta(i+1);
        }
    }

    // Send all elements to all processes
    MPI_Scatter(&rz_vec[0], n_each, MPI_DOUBLE, &rz_vec_sub[0], n_each, MPI_DOUBLE, 0,MPI_COMM_WORLD);

    // Let all processes work on the received data
    for(int i = 0; i < n_each; i++){
        sum_sub += rz_vec[i];
    }

    MPI_Reduce(&sum_sub, &sum_total, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);

    if(rank==0){
    double my_pi = sqrt(6*sum_total);
    double error = fabs(my_pi-PI);
    double duration = MPI_Wtime() - time_start;
    printf("pi=%e\nerror=%e\nduration=%e\n", my_pi,error,duration);

    
    }    

    delete[] rz_vec;
    MPI_Finalize();

    return 0;
}