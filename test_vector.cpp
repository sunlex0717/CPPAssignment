#include<iostream>
#include "vector.hpp"
// TODO: test code for vector.hpp
int main(){
  Vector<double> a(10);
  std::cout<<a << std::endl;;

  Vector<double> b = { 1, 2, 3, 4 };
  std::cout<<b << std::endl;;

  a = b;
  std::cout<<a << std::endl;;

  double res = dot(a,b);
  std::cout<<res << std::endl;;


}