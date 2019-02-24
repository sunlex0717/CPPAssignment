#ifndef HEAT_HPP
#define HEAT_HPP

#include "cg.hpp"
#include <cmath>

using namespace std;
template <int n, typename T> //n : number of dimension
class Heat
{
    // Your implementation of the heat class starts here
private:
    T alpha; //diffusion coefficient
    T dt; // the timestep
    int m; // the number of points per dimension
    mutable Matrix<T> M; //iteration matrix 
    mutable Vector<T> Initial; // store the initial value for exact solution
    mutable bool is_init;

    void computeInit() const{
        for(int i = 0;i< m;++i){
            for(int j=0;j<m;++j){
                // compute initial values
                //cout<< "compute initial values with n = " << n <<endl;
                if(n == 1){
                    //cout << "n=1" <<endl;
                    T tmp = sin(M_PI*((1.0+i)/(1.0+m)));
                    Initial[i] = tmp;
                }
                else if(n == 2){
                    T tmp = sin(M_PI*((1.0+i)/(1.0+m)))*sin(M_PI*((1.0+j)/(1.0+m)));
                    //cout<<i*m+j << " ";
                    Initial[i*m + j] = tmp;
                    //cout<<Initial[i*m+j] << " ";
                }else{
                    cout << "unsupported value n";
                    std::abort();
                    //throw "unsupported value n";
                }
            }
        }
        is_init = true;
    }

public:
    //constructor 
    Heat(T alpha_ , T dt_, int m_):alpha(alpha_),dt(dt_),m(m_),
    M(int(pow(m,n)),int(pow(m,n))),Initial(int(pow(m,n))),is_init(false)
    {
        //std::cout << "length of initial vector: " <<Initial.getLen()<<std::endl;
        T dx = 1.0/(double(m)+1);
        for(int i = 0;i< pow(m,n);++i){
            for(int j=0;j<pow(m,n);++j){
                if(i==j){ // D = -2
                    M[{i,j}] = 1 - alpha * (dt / (pow(dx,2)))*(-2*n);
                }
                else if((j+1) == i || (j-1) == i || i == (j+m)|| (i+m) == j){ // D =1
                    M[{i,j}] = 0 - alpha * (dt / (pow(dx,2)));
                }
            }
        }
        M.remove_zero();

    }
    Matrix<T> getMatrix(){
        //cout<<"get M";
        return M;
    }

    Vector<T> exact(T t) const{
        if(!is_init){
            computeInit();
        }
        Vector<T> res = Initial * exp(-n * pow(M_PI,2) * alpha * t);
        return res;
    }

    Vector<T> solve(T t) const{
        std::cout << "solve start: "<<std::endl;
        if(!is_init){
            computeInit();
        }
        Vector<T> w_0 = Initial;
        Vector<T> w_1 = Initial;

        //cout<<"initial: " << Initial<<endl;
        for(int k = 0;k < t/dt;++k){
            int a = cg(M,w_0,w_1,0.1,50);
            w_0 = w_1;
            //if(k%10 == 0){
            //    std::cout<< k <<" \\ "<< t/dt <<std::endl;
            //}
        }

        return w_1;
    }

};

#endif // HEAT_HPP