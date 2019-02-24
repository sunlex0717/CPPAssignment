#ifndef VECTOR_HPP
#define VECTOR_HPP
#include <array>
#include <initializer_list>
#include <memory>
#include <iostream>
using namespace std;
template <typename T>
class Vector
{
private:
    int length;
    T* data;
public: 
    // a default constructor that sets the length to zero
    Vector():length(0),data(nullptr){
    }
    // a constructor that takes a length as an argument
    Vector(int len):length(len),data(nullptr) {
        data = new T[length];
        for (int i = 0; i < len; ++i) {
            data[i] = 0; //initialize
        }
    }
    // a constructor that takes another Vector as a argument and copies the elements of the argument
    Vector(const Vector<T>& other):Vector(other.length) {
        for (int i=0; i<other.length; i++){
            data[i] = other.data[i];
        }
    }
    // a constructor that takes an initializer list representing the contents of this vector
    Vector(std::initializer_list<T> list):Vector((int)list.size()){
        std::uninitialized_copy(list.begin(), list.end(), data);
    }
    // destructor
    ~Vector(){
        length = 0;
        delete[] data;
    }

    int getLen() const{
        return length;
    }
    // copy operator 
    Vector<T>& operator=(const Vector<T>& other)
    {
        if (this != &other) // identity check
        {
            delete[] data;
            length = other.length;
            data   = new double[other.length];
            for (auto i=0; i<other.length; i++)
                data[i] = other.data[i];
        }
        return *this;
    }
    // move operator

    Vector<T>& operator=(Vector<T>&& other)
    {
        if (this != &other) // identity check
        {
            delete[] data;
            length = other.length;
            data   = other.data;
            other.length = 0;
            other.data   = nullptr;
        }
        return *this;
    }
    // pointwise + operator
    Vector<T> operator+(const Vector<T>& other) const{
        if(length != other.length){
            std::cout<< "Vectors have different size!"<<std::endl;
            std::abort();
        }

        Vector<T> res(length);
        for(int i = 0; i<length;++i){
            res.data[i] = data[i] + other.data[i];
        }

        return res;
    }
    // right multiplication with scalar
    Vector<T> operator*(T scalar) const{

        Vector<T> res(length);
        for(int i = 0; i<length;++i){
            res.data[i] = data[i]*scalar;
        }

        return res;
    }


    // pointwise - operator
    Vector<T> operator-(const Vector<T>& other) const{
        if(length != other.length){
            throw "Vectors have different size!";
        }

        Vector<T> res(length);
        for(int i = 0; i<length;++i){
            res.data[i] = data[i] - other.data[i];
        }
        return res;
    }

    const T operator[](int k) const{
        if(k<0 || k >=length){
            std::cout<< "Vector index out of bound"<<std::endl;
            std::abort();
        }
        return data[k];
    }

    T& operator[] (int k){
        if(k<0 || k >=length){
            std::cout<< "Vector index out of bound"<<std::endl;
            std::abort();
        }
        return data[k];
    }


    template <class U>
    friend Vector<U> operator*(U scalar,const Vector<U>& v);

    template <class U>
    friend  U dot(const Vector<U>& lhs, const Vector<U>& rhs);

    template <class U>
    friend ostream& operator<<(ostream& os, const Vector<U>& rhs);

    template <class U>
    friend U sum(const Vector<U>& lhs);


};

// friend function scalar*vector
template <typename T>
Vector<T> operator*(T scalar,const Vector<T>& other){
     Vector<T> res(other.length);
     res = other*scalar;
     return res;
}

// friend function dot
template<typename T>
T dot(const Vector<T>& lhs, const Vector<T>& rhs){
    if(lhs.length != rhs.length){
            throw "Vectors have different size!";
    }

    T res = 0;
    for(int i = 0; i<lhs.length;++i){
        res += lhs.data[i]*rhs.data[i];
    }

    return res;
}

template<typename T>
ostream& operator<<(ostream& os, const Vector<T>& rhs){
    for(int i = 0; i<rhs.length;++i){
        os<< rhs.data[i] <<" " ;
    }
    return os;
}

template <typename T>
T sum(const Vector<T>& lhs){
    T res = 0;
    for(int i=0;i<lhs.length;++i){
        res += lhs.data[i];
    }

    return res;
}


#endif // VECTOR_HPP