#include <iostream>
#include <omp.h>
#include <cmath>

double riemannzeta(int i){
    // Calculate v_i by use of the riemann zeta formula
    double v_i = 1.0/(pow(i,2));
    return v_i;
}

// OpenMP  implementation
int main(int argc, char** argv){
    if(argc<2) {
        std::cout<<"Requires arguemnt: n"<<std::endl;
        std::cout<<"Choose n and nproc s.t. n%nproc = 0\n n must be a power of 2\n "<<std::endl;
        return 1;
    }

    int n = atoi(argv[1]);
    int n_threads = atoi(argv[2]);

    const double PI = 4*atan(1.0);
    double time_start = omp_get_wtime();

    double sum_total = 0.0;


    #pragma omp parallel for num_threads(n_threads) reduction(+:sum_total)
        for(int i = 1; i<=n;i++){
            sum_total += riemannzeta(i);
        }

    
    double my_pi = sqrt(6*sum_total);
    double duration = omp_get_wtime() - time_start;
    double error = fabs(my_pi-PI);
    printf("pi=%e\nerror=%e\nduration=%e\n", my_pi,error,duration);

    
    return 0;
}