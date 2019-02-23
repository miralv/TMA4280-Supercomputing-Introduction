#include "findPi_RZ.h"
#include <iostream>
using namespace std;
//Create a unit test

void test_findPi_RZ();

//compare the value for n = 3

void test_findPi_RZ(){
    double pi_0 = RiemannZeta(3);
    //compute the theoretical result and compare

    cout << "Pi computed with n = 3, using the Riemann Zeta Formula: " << pi_0 <<endl;
}