#include <iostream>

int f(int n) {
  int res = 1;
  for (int i = 1; i <= n; ++i) {
    res *= i;
  }
  return res;
}

int main(){
  std::cout << f(10) << std::endl;
  return 0;
}
