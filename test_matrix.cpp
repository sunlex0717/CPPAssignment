#include "matrix.hpp"
#include <iostream>

using namespace std;
int main(){
  Matrix<double> m1(10,10);
  m1[{1,2}] = 0.5;
  cout << m1[{1,2}] <<endl;

}