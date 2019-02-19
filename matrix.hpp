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


struct Key
{
    array<int,2> key;

    Key(array<int,2> ele):key(ele)
    {}

    

    Key(std::initializer_list<int> list){
       std::copy(list.begin(),list.end(),key.begin());
    }

    bool operator< (const Key& other) const{
       return key[0]<other.key[0] || (key[0]==other.key[0] && key[1]<other.key[1]);
    }

    // for debug
    void show_key(){
        cout<<"(" << key[0] << "," <<key[1] << ")" ;
    }

};


template <typename T>
class Matrix
{
//typedef array<int,2> key;
private:
    int n_rows;
    int n_cols;
    map<array<int,2>,T> elements;
    

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

    
    
    template <class U>
    friend ostream& operator<<(ostream& os, const  Matrix<U>&  rhs);

    template <class U>
    friend Vector<U> operator*(const Matrix<U>& lhs, const Vector<U>& rhs);



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
        for(int j =0;j <rhs.n_cols;++j ){
            os << full_m[i][j]<<"\t";
        }
        os<<endl;
    }

    return os;
    //cout << end;
}


template<typename T>
Vector<T> operator*(const Matrix<T>& lhs, const Vector<T>& rhs)
{
    Vector<T> res(lhs.getNrows());
    for(const auto& it:lhs.elements){
        int i = it.first[0];
        int j = it.first[1];
        T value = it.second;
        res[i] += value*rhs[j];
    }
    return res;
    // Your implementation of the operator* starts here
}

#endif // MATRIX_HPP