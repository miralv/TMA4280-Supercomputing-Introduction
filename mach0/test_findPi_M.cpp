#include "findPi_M.h"
#include <iostream>
using namespace std;
//Create a unit test

void test_findPi_M();

//compare the value for n = 3
//skal jeg sammenlikne med pi, eller med det jeg tror jeg burde få for n = 3????

void test_findPi_M(){
    double pi_0 = Machin(3);
    //compute the theoretical result and compare

    cout << "Pi computed with n = 3, using the Machin Formula: " << pi_0 <<endl;
}

