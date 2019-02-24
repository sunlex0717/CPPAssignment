#include "matrix.hpp"
#include "vector.hpp"
#include <iostream>

int main(){
  Matrix<double> m1(4,4);
  std::cout <<" m1(4,4) :" <<std::endl;
  std::cout << m1 <<std::endl;

  m1[{0,0}] = 1;
  m1[{0,3}] = 1;
  m1[{1,1}] = 2;
  m1[{1,2}] = 3;
  m1[{2,2}] = 5;
  m1[{3,0}] = 1;
  m1[{3,3}] = 1;
  std::cout <<"after assignments : \n" << m1 << std::endl;
  Vector<double> v1 = { 1, 1, 1, 1 };
  std::cout << "create a vector for Matrix*vector test" << std::endl;
  std::cout << " v1 : " << v1 <<std::endl;
  Vector<double> res = m1*v1;
  std::cout << "m1*v1 : " << res << std::endl;;
  return 0;

}