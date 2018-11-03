#include <iostream>

#include "maybe.h"
#include "monad.h"

using namespace monad;

auto h(float x) {
  Maybe<float> a = pure(x);
  return bind(f3,bind(f2,bind(f1, a)));
};

int main() {
  auto b = h(-1);

  if (b) {
    std::cout << b.value() << std::endl;
  } else {
    std::cout << "Nothing" << std::endl;
  }
  return 0;
}
