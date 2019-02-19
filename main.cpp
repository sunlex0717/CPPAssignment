#include "heat.hpp"
#include <iostream>

int main(int argc, char* argv[])
{

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
    std::cout<<"x = " << x << "\n"
            <<"-----------------------\n"<<std::endl;
    // Verification of 1d system matrix
    Heat<1,double> Heat1d(0.3125, 0.001, 99);
    //std::cout<<" get heat 1D matrix" << std::endl;
    //std::cout << Heat1d.getMatrix()<< std::endl ;
    std::cout<<"test for Heat1d(0.3125, 0.001, 99)"<<endl;
    std::cout<<" get exact result" << std::endl;
    std::cout << Heat1d.exact(1) << std::endl;
    std::cout<<" get solve result" << std::endl;
    std::cout << Heat1d.solve(1) << std::endl;
    // Verification of 2d system matrix
    Heat<2,double> Heat2d(0.3125, 0.001, 99);
    std::cout<<"test for Heat2d(0.3125, 0.001, 99)"<<endl;
    std::cout<<" get exact result" << std::endl;
    std::cout<< Heat2d.exact(0.5)<<std::endl;
    std::cout<<" get solve result" << std::endl;
    std::cout<< Heat2d.solve(0.5) << std::endl;

    //std::cout<<" Heat 2d Matrix M" << endl;
    //std::cout << Heat2d.getMatrix() << std::endl;


    return 0;
}