#ifndef TYPE_TRAITS_HPP
#define TYPE_TRAITS_HPP

#include "iterator_traits.hpp"

namespace ft {

//value_type
struct false_type {
	static const bool value = false;
};

struct true_type {
	static const bool value = true;
};

// enable_if
template <bool B, typename = void>
struct enable_if {
};

template <typename T>
struct enable_if<true, T> {
	typedef T type;
};

// is_same
template <class T, class U>
struct is_same : false_type {
};

template <class T>
struct is_same<T, T> : true_type {
};

//is_integral
template <typename T, typename = void>
struct is_integral : false_type {
};

template <typename T>
struct is_integral<T, typename T::result_type> : true_type {
};

}  // namespace ft
#endif