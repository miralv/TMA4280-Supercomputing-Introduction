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

    double first = 1.0/5;
    double second = 1.0/239;        
    double* numbers_first = new double[n];
    double* numbers_second = new double[n];
    double sum_first_total = 0;
    double sum_second_total = 0;

    MPI_Init(&argc,&argv);

    MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    MPI_Comm_size(MPI_COMM_WORLD,&size);

    if(size%2!=0){
        printf("%i is not a power of two. Call the program again with a different number of processes.",size);
        return 1;
    }

    int n_each = n/size; 
    int rem = n%size;
    double* numbers_first_sub = new double[n_each + rem];
    double* numbers_second_sub = new double[n_each + rem];
    double sum_first_sub = 0;
    double sum_second_sub = 0;


    if (rank == 0){
        for (int i = 0; i<n; i++){
            numbers_first[i] = machin(i+1,first);
            numbers_second[i] = machin(i+1,second);
        }
    }

    // Spread the elements over the processes
    MPI_Scatter(&numbers_first[0], n_each, MPI_DOUBLE, &numbers_first_sub[0], n_each, MPI_DOUBLE, 0,MPI_COMM_WORLD);
    MPI_Scatter(&numbers_second[0], n_each, MPI_DOUBLE, &numbers_second_sub[0], n_each, MPI_DOUBLE, 0,MPI_COMM_WORLD);
    

    // Let all processes work on the received data
    for(int i = 0; i < n_each; i++){
        sum_first_sub += numbers_first_sub[i];
        sum_second_sub += numbers_second_sub[i];
    }

    MPI_Reduce(&sum_first_sub, &sum_first_total, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);
    MPI_Reduce(&sum_second_sub, &sum_second_total, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);

    if(rank==0){
        double my_pi = 4 * (4 * sum_first_total - sum_second_total);
        double error = fabs(my_pi-PI);
        double duration = MPI_Wtime() - time_start;
        printf("pi=%e\nerror=%e\nduration=%e\n", my_pi,error,duration);
    }    

    delete[] numbers_first;
    delete[] numbers_second;
    delete[] numbers_first_sub;
    delete[] numbers_second_sub;
    
    MPI_Finalize();
    return 0;

}