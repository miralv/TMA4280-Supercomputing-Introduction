#include <iostream>
#include <cmath>
using namespace std;


// Are we supposed to return pi or Sn?
// What is x?
double Machin(int n) {
    double v [n];
    for( int i = 0; i < n; i ++){
        v[i] = (-1)^i * x^(2*(i+1)-1)/(2*(i+1)-1);
    }
    return sum(v)
}