#include<iostream>
#include "vector.hpp"
// TODO: test code for vector.hpp
int main(){

  Vector<double> a(10);
  std::cout<< "Vector a : " <<  a << std::endl;
  Vector<double> b = { 1, 2, 3, 4 };
  std::cout<< "Vector b : " << b << std::endl;

  a = b;
  std::cout << "after a = b , a : " << a << std::endl;
  std::cout<<"a + b : " << a+b <<std::endl;
  std::cout<<"a - b : " << a-b <<std::endl;
  double res = dot(a,b);
  std::cout<< "dot(a,b) :" << res << std::endl;

  return 0;
}