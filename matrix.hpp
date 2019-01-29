#ifndef MATRIX_HPP
#define MATRIX_HPP

#include "vector.hpp"
#include <unordered_map>
#include <array>
using namespace std;

template <typename T>
class Matrix
{
typedef array<int,2> key;
private:
    int n_rows;
    int n_cols;

    unordered_map<key,T> elements;

    // Start your implementation of the matrix class here
public:
    // constructor
    Matrix(int r,int c):n_rows(r),n_cols(c) = default{

    }

    T& operator[] (const key& k){
        return elements[k];
    }

    const T operator[](const key& k) const{
        return elements[k];
    }


};

template<typename T>
Vector<T> operator*(const Matrix<T>& lhs, const Vector<T>& rhs)
{
    // Your implementation of the operator* starts here
}

#endif // MATRIX_HPP