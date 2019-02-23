#include <iostream>
#include <cmath>
using namespace std;


// Calculate pi by use of the Machin formula with n elements

double Machin(int n) {
    
    double x1 = 1/5;
    double x2 = 1/239;
    double pi = 4*(arctan(x1,n) - arctan(x2,n));
    return pi;
}

double arctan(double x, int n) {
    double sum = 0;     
    for( int i = 0; i < n; i ++){
        sum += pow(-1,i) * pow(x,(2*(i+1)-1))/(2*(i+1)-1);
    }
    return sum;
}