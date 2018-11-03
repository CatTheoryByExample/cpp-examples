#pragma once

#include <functional>

namespace monad {
template <template <class...> class M, class A, class B>
M<B> fmap(std::function<B(A)>, M<A>);

template < template< class ...> class M, class A> 
M<A> pure(A);

template < template< class ...> class M, class A> 
M<A> join(M< M<A> >);

template < template< class ...> class M, class A, class B> 
M<B> bind(std::function< M<B> (A) > f, M<A> a) {
  return join( fmap<>(f, a) );
};

}
