#pragma once

#include <math.h>

#include <functional>
#include <optional>



namespace monad {
template <class A> using Maybe = std::optional<A>;

template < class A, class B> 
Maybe<B> fmap(std::function<B(A)> f, Maybe<A> a) {
  if (a) {
    return f(a.value());
  }
  return {};
}

template < class A> 
Maybe<A> pure(A a) {
  return a;
}

template < class A> 
Maybe<A> join(Maybe< Maybe<A> > a){
  if (a) {
    return a.value();
  }
  return {};
}

std::function<Maybe<float>(float)> f1 =
    [](float x) {
      if (x >= 0) {
        return Maybe<float>(sqrt(x));
      }
      return Maybe<float>();
    };

std::function<Maybe<float>(float)> f2 = [](float x) { return 2 * x; };

std::function<Maybe<float>(float)> f3 =
    [](float x) {
      if (x != 0) {
        return Maybe<float>(1 / x);
      }
      return Maybe<float>();
    };
}
