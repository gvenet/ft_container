#ifndef ITERATOR_TRAITS_HPP
#define ITERATOR_TRAITS_HPP

#include "random_access_iterator.hpp"

namespace ft {

template <class Iterator>
struct iterator_traits {
	typedef typename Iterator::difference_type	 difference_type;
	typedef typename Iterator::value_type		 value_type;
	typedef typename Iterator::pointer			 pointer;
	typedef typename Iterator::reference		 reference;
	typedef typename Iterator::iterator_category iterator_category;
};

template <class T>
class iterator_traits<T*> {
	typedef std::ptrdiff_t				   difference_type;
	typedef T							   value_type;
	typedef T*							   pointer;
	typedef T&							   reference;
	typedef ft::random_access_iterator_tag iterator_category;
};

template <class T>
class iterator_traits<const T*> {
	typedef std::ptrdiff_t				   difference_type;
	typedef T							   value_type;
	typedef T const*					   pointer;
	typedef T const&					   reference;
	typedef ft::random_access_iterator_tag iterator_category;
};

}  // namespace ft
#endif