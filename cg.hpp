#ifndef CG_HPP
#define CG_HPP

#include "matrix.hpp"

template<typename T>
int cg(const Matrix<T> &A, const Vector<T> &b, Vector<T> &x, T tol, int maxiter)
{
    Vector<T> r_k0(maxiter);
    Vector<T> r_k1(maxiter);
    Vector<T> p(maxiter);
    p = b - A*x;
    r_k0 = p;

    for(int k =1; k<maxiter;++k){

        T alpha_k = dot(r_k0,r_k0) / dot(A*p,p);
        x = x + alpha_k*p;
        r_k1 = r_k0 - alpha_k*(A*p);

        if (dot(r_k1,r_k1) < tol*tol ){
            return k;
        }

        T beta = dot(r_k1,r_k1) / dot(r_k0,r_k0);
        p = r_k1 + beta*p;
        r_k0 = r_k1;
    }
    return -1;
}
#endif // CG_HPP