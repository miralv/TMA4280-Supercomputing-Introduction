#include <iostream>
#include <fstream>
#include <cmath>
#include <string>

double riemannzeta(int i){
    // Calculate v_i by use of the riemann zeta formula
    double v_i = 1.0/(pow(i,2));
    return v_i;
}

double sum_v_rz(int n){
    double sum = 0.0;
    for (int i = 0; i<n; i++){
        sum += riemannzeta(i+1);
    }
    return sum;
}

double find_pi_rz(int n){
    // Compute pi by use of the riemann zeta formula
    double sum_v = sum_v_rz(n);
    double pi = sqrt(6*sum_v);
    return pi;
}


void utest(){
    std::string test_name = "zeta0: utest for n =3\n";
    double expected_pi = 2.85773803324704145368;
    double computed_pi = find_pi_rz(3);
    std::string message = (expected_pi == computed_pi) ? "OK" : "FAIL";
    std::cout<<test_name << message <<std::endl;
    }

void writeVerificationToFile(std::string filename, double* error_vec){
    std::ofstream myfile;
    myfile.open(filename);
    if (myfile.is_open()){
        myfile << "2^k error\n";
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
        err[k-1] = fabs(pi_true - find_pi_rz(k)); 
    }
    writeVerificationToFile("zeta0_vtest.txt", err);
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
    double pi = find_pi_rz(n);
    std::cout<< pi<<std::endl;
    if (argc>2 && atoi(argv[2])==1){
        utest();
    }
    if (argc>3 && atoi(argv[3])==1){
        vtest();
    }

    return 0;

}