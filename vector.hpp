#ifndef VECTOR_HPP
#define VECTOR_HPP
#include<array>
#include <initializer_list>

using namespace std;
template <typename T>
class Vector
{
private:
    int length;
    T* data;
public: 
    // a default constructor that sets the length to zero
    Vector():length(0),data(nullptr) = default{
    }
    // a constructor that takes a length as an argument
    Vector(int len):length(len),data(nullptr) {
        data = new T[length];
    }
    // a constructor that takes another Vector as a argument and copies the elements of the argument
    Vector(const Vector<T>& other):Vector(other.length) {
        for (auto i=0; i<other.length; i++){
            data[i] = other.data[i];
        }
    }
    // a constructor that takes an initializer list representing the contents of this vector
    Vector(std::initializer_list<T> list):Vector((int)list.size()){
        std::uninitialized_copy(list.begin(), list.end(), data);
    }
    // deconstructor
    ~Vector(){
        length = 0;
        delete[] data;
    }

    // copy operator 
    Vector<T>& operator=(const Vector<T>& other)
    {
        if (this != &other)
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
        if (this != &other)
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
    Vector<T> operator+(const Vector<T>& other){
        if(length != other.length){
            throw "Vectors have different size!"
        }

        Vector<T> res(length);
        for(int i = 0; i<length;++i){
            res.data[i] = data[i] + other.data[i];
        }

        return res;
    }
    // right multiplication with scalar
    Vector<T> operator*(T scalar){

        Vector<T> res(length);
        for(int i = 0; i<length;++i){
            res.data[i] = data[i]*scalar;
        }

        return res;
    }


    // pointwise - operator
    Vector<T> operator-const Vector<T>& other){
        if(length != other.length){
            throw "Vectors have different size!"
        }

        Vector<T> res(length);
        for(int i = 0; i<length;++i){
            res.data[i] = data[i] - other.data[i];
        }

        return res;
    }


    // right multiplication with scalar vector*scalar
    Vector<T> operator*(T scalar){

        Vector<T> res(length);
        for(int i = 0; i<length;++i){
            res.data[i] = data[i]*scalar;
        }

        return res;
    }

friend:
    Vector<T> operator*(T scalar,const Vector<T>& v);
    T dot(const Vector<T>& lhs, const Vector<T>& rhs);
    // Your implementation of the Vector class starts here
};

// friend function scalar*vector
template <typename T>
Vector<T> Vector<T>::operator*(T scalar,const Vector<T>& other){
     Vector<T> res(other.length);
     res = other*scalar;
     return res;
}

// friend function dot
template<typename T>
T Vector<T>::dot(const Vector<T>& lhs, const Vector<T>& rhs){
    if(lhs.length != other.length){
            throw "Vectors have different size!"
    }

    T res = 0;
    for(int = 0; i<lhs.length;++i){
        T += lhs.data[i]*rhs.data[i];
    }

    return T;
}



#endif // VECTOR_HPP