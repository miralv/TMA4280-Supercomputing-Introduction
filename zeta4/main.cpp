#include <iostream>
#include <mpi.h>
#include <omp.h>
#include <cmath>
//Final program, combining MPI and OpenMP

double riemannzeta(int i){
    // Calculate v_i by use of the riemann zeta formula
    double v_i = 1.0/(pow(i,2));
    return v_i;
}


int main(int argc, char** argv){
    if(argc<2) {
        std::cout<<"Requires arguemnts: n, nproc and nthreads."<<std::endl;
        std::cout<<"Choose n and nproc and nthreads s.t. n%nprox = 0\n n must be a power of 2\n "<<std::endl;
        return 1;
    }
    const double PI = 4*atan(1.0);
    int n = atoi(argv[1]);
    int n_threads = atoi(argv[2]);


    // Size and rank
    int size,rank;
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
        time_start = MPI_Wtime();
        for (int i = 0; i<n; i++){
            rz_vec[i] = riemannzeta(i+1);
        }
    }

    // Send all elements to all processes
    MPI_Scatter(&rz_vec[0], n_each, MPI_DOUBLE, &rz_vec_sub[0], n_each, MPI_DOUBLE, 0,MPI_COMM_WORLD);

    // Let all processes work on the received data
    #pragma omp parallel for num_threads(n_threads) reduction(+:sum_total)
        for(int i = 0; i<n;i++){
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