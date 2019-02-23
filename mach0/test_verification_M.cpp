#include "findPi_M.h"
#include <cmath>
// Implement a test computing the error |pi -pi_n| for n ? 2^k with k = 1, ..., 24



double* verification_M();

// vil returnere en array med tall, hvordan gjøres det i c++? ved å returnere en peker? 
// kan evt sjekke ut noe eksempelkode på hjemmesiden


double* verification_M(){
    int n;
    double err[24];
    for (int k = 1; k<=24; k++){
        n = pow(2,k);
        err[k-1] = abs(atan(1)*4 - Machin(k)); 
    }

    return err;
}