#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <iostream>
#include "vector.hpp"
#include <map>
#include <array>
#include <initializer_list>
#include <memory>
#include <vector>
using namespace std;

template <typename T>
class Matrix
{
private:
    int n_rows;
    int n_cols;
    mutable map<array<int,2>,T> elements;


    // Start your implementation of the matrix class here
public:
    
    // constructor
    Matrix(int r,int c):n_rows(r),n_cols(c) {

    }
    int getNrows() const{
        return n_rows;
    }

    int getNcols() const{
        return n_cols;
    }

    T& operator[] (array<int,2> key){
        if(key[0] > n_rows-1 || key[1] > n_cols-1){
            throw "Matrix index out of bound";
        }
        return elements[key];
    }

    const T operator[](array<int,2> key) const{
        if(key[0] > n_rows-1 || key[1] > n_cols-1){
            throw "Matrix index out of bound";
        }
        if(elements.find(key)!=elements.end()){
            return 0; // to avoid creating a new entry
        }else{
            return elements[key];
        }
        
    }
    Vector<T> operator*(const Vector<T>& rhs) const{
        Vector<T> res(this->getNrows());
        for(const auto& it:this->elements){
            int i = it.first[0];
            int j = it.first[1];
            T value = it.second;
            res[i] += value*rhs[j];
        }
        return res;
    }

    void remove_zero()const{

        //std::cout << "remove zeros , size of map: " << elements.size()<<std::endl;
        for(auto it = elements.begin(); it != elements.end();){
            T value = it->second;
            if(value == 0){
               it = elements.erase(it);
            } else{
                ++it;
            }
        }
        //std::cout << "after clean zeros , size of map: " << elements.size() <<std::endl;
    }
    
    
    template <class U>
    friend ostream& operator<<(ostream& os, const  Matrix<U>&  rhs);





};
template<typename T>
ostream& operator<<(ostream& os, const Matrix<T>& rhs){
    std::vector<std::vector<T>> full_m(rhs.n_rows,vector<T>(rhs.n_cols,0));
    for(const auto& it:rhs.elements){
        int i = it.first[0];
        int j = it.first[1];
        T value = it.second;
        full_m[i][j] = value;
    }
    for(int i=0;i<rhs.n_rows;++i){
        for(int j =0;j <rhs.n_cols;++j ) {
            os << full_m[i][j] << "  ";
        }
        std::cout << std::endl;
    }

    return os;
    //cout << end;
}


#endif // MATRIX_HPP