#include <iostream>
#include <cmath>
using namespace std;


// Calculate pi by use of Riemann Zeta's formula
/*
double RiemannZeta(int n) {
    double sum = 0;
    for( int i = 0; i < n; i ++){
        sum += 1/pow(i+1,2);
    }
    return pow(sum*6,0.5);
}*/


// Refactor
double riemannzeta(int i){
    double v_i = 1/(pow(i,2));
    return v_i;
}

double sum_v_rz(int n){
    double sum = 0.0;
    for (int i = 0; i<n; i++){
        sum += riemannzeta(i+1);
    }
    return sum;
}

double find_pi_rz(int n){
    // Compute pi by use of the riemann zeta formula
    double pi = 6 * pow(sum_v_rz(n),0.5);
    return pi;
}

