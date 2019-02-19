#include "matrix.hpp"
#include "vector.hpp"
#include <iostream>

using namespace std;
int main(){
  Matrix<double> m1(4,4);
  cout<<m1;

  m1[{0,0}] = 1;
  m1[{0,3}] = 1;
  m1[{1,1}] = 2;
  m1[{1,2}] = 3;
  m1[{2,2}] = 5;
  m1[{3,0}] = 1;
  m1[{3,3}] = 1;
  //cout<<m1[{3,3}];
  cout<<m1;
  Vector<double> v1 = { 1, 1, 1, 1 };
  Vector<double> res = m1*v1;
  std::cout<<res << std::endl;;
  return 0;

}