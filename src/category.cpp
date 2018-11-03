#include <functional>
#include <iostream>
#include <string>

auto isEven = [](int x) { return x % 2 == 0; };

auto stringLength = [](std::string s) { return static_cast<int>(s.size()); };

// h = g . f
template <typename A, typename B> auto compose(A g, B f) {
  auto h = [f, g](auto a) {
    auto b = f(a);
    auto c = g(b);
    return c;
  };
  return h;
};

auto isStringLengthEven = compose<>(isEven, stringLength);

auto id = [](auto x) { return x; };

auto isStringLengthEvenLeft = compose<>(id, isStringLengthEven);

auto isStringLengthEvenRight = compose<>(isStringLengthEven, id);

int main() {
  std::cout << "3: " << isStringLengthEven("abc") << std::endl;
  std::cout << "4: " << isStringLengthEven("abcd") << std::endl;

  std::cout << "id . 3: " << isStringLengthEvenLeft("abc") << std::endl;
  std::cout << "id . 4: " << isStringLengthEvenLeft("abcd") << std::endl;

  std::cout << "3 . id: " << isStringLengthEvenRight("abc") << std::endl;
  std::cout << "4 . id: " << isStringLengthEvenRight("abcd") << std::endl;

  return 0;
}
