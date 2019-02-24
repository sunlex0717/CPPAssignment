#include "heat.hpp"
#include <iostream>
#include <chrono>


int main(int argc, char* argv[])
{
    auto start = chrono::steady_clock::now();

    std::cout<<"test for Heat1d(0.3125, 0.001, 99)"<<std::endl;
    Heat<1,double> Heat1d(0.3125, 0.001, 20);

    std::cout<<"Compute exact result for 1D" << std::endl;
    Vector<double> res_1d_exact =  Heat1d.exact(1);
    std::cout<<"Done" << std::endl;

    std::cout<<"Compute solve result for 1D" << std::endl;
    Vector<double > res_1d_solve = Heat1d.solve(1);
    std::cout<<"Done" << std::endl;

    double diff1D = sum(res_1d_exact-res_1d_solve);
    std::cout<<"sum difference of res_1d_exact-res_1d_solve = " << diff1D<<std::endl;
    std::cout << "average difference per element  : diff1D / m*m =  " << diff1D/(99*99) << std::endl;
    // Verification of 2d system matrix
    std::cout<<"test for Heat2d(0.3125, 0.001, 99)"<<std::endl;
    Heat<2,double> Heat2d(0.3125, 0.001, 99);

    std::cout<<"Compute exact result for 2D" << std::endl;
    Vector<double> res_2d_exact = Heat2d.exact(0.5);
    std::cout<<"Done" << std::endl;

    std::cout<<"Compute solve result for 2D" << std::endl;
    Vector<double> res_2d_solve = Heat2d.solve(0.5);
    std::cout<<"Done" << std::endl;

    double diff2D = sum(res_2d_exact-res_2d_solve);
    std::cout<<"sum difference of res_2d_exact-res_2d_solve = " << diff2D<<std::endl;
    std::cout << "average difference per element  : diff2D / m*m =  " << diff2D/(99*99) << std::endl;

    auto end = chrono::steady_clock::now();

    std::cout << "Elapsed time in milliseconds : "
         << chrono::duration_cast<chrono::milliseconds>(end - start).count()
         << " ms" << std::endl;
    return 0;
}