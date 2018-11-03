#include <utility>
#include <iostream>
#include <string>
#include <stdexcept>

template <typename A, typename B> class Either
{
public:
  Either(const Either& e) : is_left_(e.is_left_){
    if (is_left_){
      data.l = e.data.l;      
    } else {
      data.r = e.data.r;      
    }    
  }
  ~Either(){
    if (is_left_){
      data.l.~A();      
    } else {
      data.r.~B();      
    }        
  }
  
  Either(const A& l) : data(l), is_left_(true){
  }
  Either(const B& r) : data(r), is_left_(false){
  }
  const A& left() const {
    if (!is_left_){
      throw std::logic_error("no left");      
    }    
    return data.l;    
  }
  const B& right() const {
    if (is_left_){
      throw std::logic_error("no right");      
    }    
    return data.r;    
  }
private:
  union Data {
    Data() {}
    Data( const A& a) : l(a) {}
    Data (const B& b) : r(b) {}
    ~Data() {}
    A l;
    B r;
  } data;       
  bool is_left_;  
};

template <typename A, typename B, typename C, typename D>
auto factor(A f, B g, const Either<C, D>& either) {
  try {
    return f(either.left());               
  }
  catch(...) {
    return g(either.right());                              
  }
};

auto stringLength = [](std::string s) { return static_cast<int>(s.size()); };
auto id = [](auto x) { return x; };

int main()
{
  std::pair<int, bool> data(0, false);

  std::cout << "First projector: " << data.first << std::endl;
  std::cout << "Second projector: " << data.second << std::endl;

  Either<std::string, int> str = std::string("abc");
  std::cout << "String length:" <<
    factor<>(stringLength, id, str) << std::endl;
  Either<std::string, int> i = 4;
  std::cout << "id(int):" <<
    factor<>(stringLength, id, i) << std::endl;
  
  
  return 0;
}
