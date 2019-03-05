#include <iostream>
#include <mpi.h>
#include <cmath>

double riemannzeta(int i){
    // Calculate v_i by use of the riemann zeta formula
    double v_i = 1.0/(pow(i,2));
    return v_i;
}

int main(int argc, char** argv){
    if(argc<2) {
        std::cout<<"Requires arguemnt: n"<<std::endl;
        return 1;
    }

    // Size and rank
    int size,rank;

    // Number of elements in the series
    int n = atoi(argv[1]);    

    double* rz_vec = new double[n];
    double sum_total = 0;
    double sum_sub = 0;



    MPI_Init(&argc,&argv);

    MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    MPI_Comm_size(MPI_COMM_WORLD,&size);

    if (rank == 0){
        for (int i = 0; i<n; i++){
            rz_vec[i] = riemannzeta(i+1);
        }
    }

    // Send all elements to all processes
    MPI_Bcast(&rz_vec[0],n,MPI_DOUBLE, 0,MPI_COMM_WORLD);


    // Let all processes work on the received data
    for(int i = 0; i < n; i++){
        sum_sub += rz_vec[i];
    }

    MPI_Reduce(&sum_sub, &sum_total, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);

    if(rank==0){
    double my_pi = sqrt(6*sum_total)/size;
        // Need to divide on size, since we have summed all elements in all processes
    std::cout<< "Process "<<rank<<" computed pi = "<< my_pi <<std::endl;
    }    

    delete[] rz_vec;
    MPI_Finalize();

    return 0;
}