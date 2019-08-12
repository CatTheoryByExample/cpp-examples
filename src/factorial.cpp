#include <iostream>

int f(int n) {
  if (n < 0)
    throw std::invalid_argument("the argument has to be greater or equal 0");
  int res = 1;
  for (int i = 1; i <= n; ++i) {
    res *= i;
  }
  return res;
}

int main(){
  std::cout << f(10) << std::endl;
  std::cout << f(-10) << std::endl;
  return 0;
}
