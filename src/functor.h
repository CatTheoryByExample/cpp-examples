#include <functional>

template < template< class ...> class F, class A, class B> 
F<B> fmap(std::function<B(A)>, F<A>);
