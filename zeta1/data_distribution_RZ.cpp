#include <mpi>
#include <iostream>
#include <cmath>
using namespace std;


double* RiemannZeta_vec(int n);

// Constraint: All elements should be put in a vector before being summed
double* RiemannZeta_vec(int n) {
    double vec[n];
    for( int i = 0; i < n; i ++){
        vec[i] =  1/pow(i+1,2);
    }

    // now all the n elements v_i are stored in vec.
    // what remains to compute pi:
    // pow(sum*6,0.5)

    return vec;
}