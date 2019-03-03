#include <mpi.h>
#include <iostream>
#include <cmath>

double machin(int i, double x) {
    // Calculate v_i by use of the machin formula
    int num = 2 * i - 1;
    return pow(-1,i-1) * pow(x,num)/num;
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

    // Vectors

    double* numbers_first;
    numbers_first = new double[n];
    double* numbers_second;
    numbers_second = new double[n];

    double sum_first = 0;
    double sum_second = 0;
    double sum_first_total = 0;
    double sum_second_total = 0;
    double first = 1/5;
    double second = 1/239;


    MPI_Init(&argc,&argv);

    MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    MPI_Comm_size(MPI_COMM_WORLD,&size);

    if (rank == 0){
        std::cout<<"hello theerre"<<std::endl;
    }



    for (int i = 0; i<n; i++){
        sum_first += machin(i+1,first);
        sum_second += machin(i+1,second);
    }
    std::cout<<sum_first<<std::endl;

    // vil først sjekke at ting stemmer uten mpi


    //per nå er det kun én prosessor som får en sum > 0. Hvorfor???????????
    double my_pi = 4 * (4 * sum_first - sum_second);
    //double my_pi = 3.14;
    // tror at vi nå har sum nproc*sum i alle => må dele på nproc
    std::cout<< "Process "<<rank<<" computed pi = "<< my_pi <<std::endl;
    

    delete[] numbers_first;
    delete[] numbers_second;
    MPI_Finalize();
    return 0;

}