#ifndef ITERATOR_TRAITS_HPP
#define ITERATOR_TRAITS_HPP

#include "random_access_iterator.hpp"
#include <cstddef>

namespace ft {

template <class Iter>
struct iterator_traits {
		typedef Iter											 value_type;
		typedef value_type*								 pointer;
		typedef value_type&								 reference;
		typedef std::ptrdiff_t						 difference_type;
		typedef bidirectional_iterator_tag iterator_category;
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