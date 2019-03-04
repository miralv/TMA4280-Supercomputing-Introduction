#include <mpi.h>
#include <iostream>
#include <cmath>

double machin(int i, double x) {
    // Calculate v_i by use of the machin formula
    double num = double(2 * i - 1);
    double a =  pow(-1.0,double(i-1));
    double frac = pow(x,num)/num;
    double v_i = frac * a;
    return v_i;
}

// Add a program that distributes all elements to all the processes

int main(int argc, char** argv){
    if(argc<2) {
        std::cout<<"Requires arguemnt: n"<<std::endl;
        return 1;
    }

    // Size and rank
    int size,rank;

    // Number of elements in the series
    int n = atoi(argv[1]);

    double first = 1.0/5;
    double second = 1.0/239;        
    double* numbers_first;
    numbers_first = new double[n];
    double* numbers_second;
    numbers_second = new double[n];
    double sum_first = 0;
    double sum_second = 0;
    double sum_first_total = 0;
    double sum_second_total = 0;

    MPI_Init(&argc,&argv);

    MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    MPI_Comm_size(MPI_COMM_WORLD,&size);

    if (rank == 0){
        for (int i = 0; i<n; i++){
            // bare tester
            numbers_first[i] = machin(i+1,first);
            numbers_second[i] = machin(i+1,second);
        }
    }

    //send all elements to all processes
    MPI_Bcast(&numbers_first[0],n,MPI_DOUBLE, 0,MPI_COMM_WORLD);
    MPI_Bcast(&numbers_second[0],n,MPI_DOUBLE, 0,MPI_COMM_WORLD);

    //let all processes work on the received data
    for(int i = 0; i < n; i++){
        sum_first += numbers_first[i];
        sum_second += numbers_second[i];
    }

    MPI_Reduce(&sum_first, &sum_first_total, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);
    MPI_Reduce(&sum_second, &sum_second_total, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);

    if(rank==0){
        //per nå er det kun én prosessor som får en sum > 0. Hvorfor???????????
        double my_pi = 4 * (4 * sum_first - sum_second);
        //double my_pi = 3.14;
        // tror at vi nå har sum nproc*sum i alle => må dele på nproc
        std::cout<< "Process "<<rank<<" computed pi = "<< my_pi <<std::endl;
    }    

    delete[] numbers_first;
    delete[] numbers_second;
    MPI_Finalize();
    return 0;

}