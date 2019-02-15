#include <iostream>
#include <cmath>
using namespace std;


// Are we supposed to return pi or Sn?
double RiemannZeta(int n) {
    double v [n];
    for( int i = 0; i < n; i ++){
        v[i] = 1/pow(i+1,2);
    }
    return sum(v)
}