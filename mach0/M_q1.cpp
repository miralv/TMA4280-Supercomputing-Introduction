#include <iostream>
#include <cmath>
using namespace std;


// Calculate pi by use of the Machin formula with n elements
double Machin(int n) {
    double x1 = 1/5;
    double x2 = 1/239;
    pi = 4*(arctan(x1) - arctan(x2));
    return pi
}



double arctan(double x, int n) {        
    for( int i = 0; i < n; i ++){
        v[i] = (-1)^i * x^(2*(i+1)-1)/(2*(i+1)-1);
    }
    return sum(v)
}