#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <omp.h>

double machin(int i, double x) {
    // Calculate v_i by use of the machin formula
    double num = double(2 * i - 1);
    double a =  pow(-1.0,double(i-1));
    double frac = pow(x,num)/num;
    double v_i = frac * a;
    return v_i;
}

// OpenMP implementation
int main(int argc, char** argv){
    if(argc<3) {
        std::cout<<"Requires arguemnt: n and nthreads"<<std::endl;
        return 1;
    }

    int n = atoi(argv[1]);
    int n_threads = atoi(argv[2]);

    const double PI = 4*atan(1.0);
    double time_start = omp_get_wtime();


    double sum_first = 0.0;
    double sum_second = 0.0;

    #pragma omp parallel for num_threads(n_threads) reduction(+:sum_first,sum_second)
        for(int i = 1; i<=n;i++){
            sum_first += machin(i,1.0/5);
            sum_second += machin(i,1.0/239);
        }

    
    double pi = 4*(4*sum_first - sum_second);
    double duration = omp_get_wtime() - time_start;
    double error = fabs(pi-PI);
    printf("pi=%e\nerror=%e\nduration=%e\n", pi,error,duration);


    
    return 0;

}