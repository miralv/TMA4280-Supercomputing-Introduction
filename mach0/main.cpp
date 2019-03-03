#include <iostream>
#include <cmath>
#include <string>

double machin(int i, double x) {
    // Calculate v_i by use of the machin formula
    double num = double(2 * i - 1);
    double a =  pow(-1.0,double(i-1));
    double frac = pow(x,num)/num;
    double v_i = frac * a;
    return v_i;
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
    double x1 = 1.0/5;
    double x2 = 1.0/239;
    double sum1 = sum_v_machin(n,x1);
    double sum2 = sum_v_machin(n,x2);
    double pi = 4 * (4*sum1 - sum2);
    return pi;
}


int utest(){
    std::string test_name = "mach0: utest for n =3\n";

    double expected_pi = 3.14162102932503461972;
    double computed_pi = find_pi_machin(3);

    std::string message = (expected_pi == computed_pi) ? "OK" : "FAIL";
    
    std::cout<<test_name << message <<std::endl;
    
    }//

int main(int argc, char** argv){
    std::string message = "";


    if(argc<2) {
        std::cout<<"Requires arguemnt: n"<<std::endl;
        return 1;
    }

    int n = atoi(argv[1]);
    std::cout<<" Compute pi for n= " << n <<": "<<std::endl;


    double pi = find_pi_machin(n);

    std::cout<< pi<<std::endl;


    return 0;



}