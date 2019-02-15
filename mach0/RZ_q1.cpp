#include <iostream>
#include <cmath>
using namespace std;


// Calculate pi by use of Riemann Zeta's formula
double RiemannZeta(int n) {
    double v [n];
    for( int i = 0; i < n; i ++){
        v[i] = 1/pow(i+1,2);
    }
    S_n = sum(v)
    return pow(S_n*6,0.5)
}