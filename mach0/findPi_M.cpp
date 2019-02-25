#include <iostream>
#include <cmath>
using namespace std;

double machin(int i, double x) {
    // Calculate v_i by use of the machin formula
    int num = 2 * i - 1;
    return pow(-1,i-1) * pow(x,num)/num;
}


double sum_v_machin(int n, double x){
    // find sum of vector v
    double sum = 0.0;
    for (int i = 0; i < n; i ++){
        sum += machin(i+1, x);
    }
    return sum;
}


double find_pi_machin(int n){
    // Compute pi by use of the machin formula
    double x1 = 1/5;
    double x2 = 1/239;
    double pi = 4*(4  * sum_v_machin(n,x1) - sum_v_machin(n,x2));
}
