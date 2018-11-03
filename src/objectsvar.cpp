#include <utility>
#include <iostream>
#include <string>
#include <variant>

template <typename A, typename B, typename C, typename D>
auto factor(A f, B g, const std::variant<C, D>& either) {
  try {
    return f(std::get<C>(either));               
  }
  catch(...) {
    return g(std::get<D>(either));                              
  }
};

auto stringLength = [](std::string s) { return static_cast<int>(s.size()); };
auto id = [](auto x) { return x; };

int main()
{
  std::pair<int, bool> data(0, false);

  std::cout << "First projector: " << data.first << std::endl;
  std::cout << "Second projector: " << data.second << std::endl;

  std::variant<std::string, int> var = std::string("abc");
  std::cout << "String length:" <<
    factor<>(stringLength, id, var) << std::endl;
  var = 4;
  std::cout << "id(int):" <<
    factor<>(stringLength, id, var) << std::endl;
  
  
  return 0;
}
