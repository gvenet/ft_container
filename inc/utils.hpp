#ifndef UTILS_HPP
#define UTILS_HPP

#include "iterator_traits.hpp"

namespace ft {

// enable_if
template <bool B, typename T = void>
struct enable_if { };

template <typename T>
struct enable_if<true, T> {
	typedef T type;
};
​
	// is_same
	template <class T, class U>
	struct is_same {
	static const bool value = false;
};

template <class T>
struct is_same<T, T> {
	static const bool value = true;
};
​
	// is_iterator
	template <typename T, typename = void>
	struct is_iterator {
	static const bool value = false;
};

template <typename T>
struct is_iterator<T, typename ft::enable_if<!std::is_same<typename ft::iterator_traits<T>::value_type, void>::value>::type> {
	static const bool value = true;
};

}  // namespace ft

#endif