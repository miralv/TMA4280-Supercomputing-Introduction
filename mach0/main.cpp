#include <iostream>
#include <fstream>
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

void utest(){
    std::string test_name = "mach0: utest for n =3\n";

    double expected_pi = 3.14162102932503461972;
    double computed_pi = find_pi_machin(3);
    std::string message = (expected_pi == computed_pi) ? "OK" : "FAIL";
    std::cout<<test_name << message <<std::endl;
    
    }//

void writeVerificationToFile(std::string filename, double* error_vec){
    std::ofstream myfile;
    myfile.open(filename);
    if (myfile.is_open()){
        myfile << "2^n error\n";
        for (int k = 1; k<=24; k++){
            myfile<< k <<"  "<<error_vec[k-1]<<"\n";
        }
        myfile.close();
        std::cout<<"Verification error written to file "<<filename<<std::endl;
    }
    else std::cout<<"Unable to open file";
}

void vtest(){
    std::cout<<"Running vtest"<<std::endl;
    int n;
    double err[24];
    double pi_true = atan(1)*4;
    for (int k = 1; k<=24; k++){
        n = pow(2,k);
        err[k-1] = fabs(pi_true - find_pi_machin(k)); 
    }
    writeVerificationToFile("mach0_vtest.txt", err);
} 

void printOptions(){
    std::cout<<"argv[1]=n\nOptional parameters:"<<std::endl;
    std::cout<<"argv[2]=1: run unit test"<<std::endl;
    std::cout<<"argv[3]=1: run verification test\n";
}


int main(int argc, char** argv){
    if(argc<2) {
        std::cout<<"Requires arguemnt: n"<<std::endl;
        printOptions();
        return 1;
    }

    int n = atoi(argv[1]);
    std::cout<<" Computed pi for n= " << n <<": "<<std::endl;
    double pi = find_pi_machin(n);
    std::cout<< pi<<std::endl;

    if (atoi(argv[2])==1){
        utest();
    }

    if (atoi(argv[3])==1){
        vtest();
    }

    return 0;

}