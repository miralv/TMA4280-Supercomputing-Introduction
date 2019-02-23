#include <iostream>
#include <cmath>
using namespace std;


// Calculate pi by use of Riemann Zeta's formula
double RiemannZeta(int n) {
    double sum = 0;
    for( int i = 0; i < n; i ++){
        sum += 1/pow(i+1,2);
    }
    return pow(sum*6,0.5);
}