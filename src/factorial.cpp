#include <iostream>

int factorial_imperative(int n) {
  int res = 1;
  for (int i = 1; i <= n; ++i) {
    res *= i;
  }
  return res;
}

int main(){
  std::cout << factorial_imperative(10) << std::endl;
  return 0;
}
