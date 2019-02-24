#include<iostream>
#include "cg.hpp"
int main(){
    Matrix<double> A(2,2);
    Vector<double> b({1,2});
    Vector<double> x(2);
    double tol = 0.1;
    int maxiter = 10;
    A[{0,0}] = 4;
    A[{0,1}] = 1;
    A[{1,0}] = 1;
    A[{1,1}] = 3;
    cg<double>(A,b,x,tol,maxiter);
    std::cout<<"x = " << x << "\n";
}