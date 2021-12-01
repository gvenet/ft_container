#ifndef ITERATOR_TRAITS_HPP
#define ITERATOR_TRAITS_HPP

#include <cstddef>

#include "random_access_iterator.hpp"

namespace ft {

template <class Iter>
struct iterator_traits {
		typedef typename Iter::value_type				 value_type;
		typedef typename Iter::pointer					 pointer;
		typedef typename Iter::reference				 reference;
		typedef typename Iter::difference_type	 difference_type;
		typedef typename Iter::iterator_category iterator_category;
};

template <class T>
class iterator_traits<T*> {
		typedef std::ptrdiff_t								 difference_type;
		typedef T															 value_type;
		typedef T*														 pointer;
		typedef T&														 reference;
		typedef ft::random_access_iterator_tag iterator_category;
};

template <class T>
class iterator_traits<const T*> {
		typedef std::ptrdiff_t								 difference_type;
		typedef T															 value_type;
		typedef T const*											 pointer;
		typedef T const&											 reference;
		typedef ft::random_access_iterator_tag iterator_category;
};

} // namespace ft
#endif