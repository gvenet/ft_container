#ifndef UTILS_HPP
#define UTILS_HPP

#include "iterator_traits.hpp"

namespace ft {

// enable_if
template <bool B, typename T = void>
struct enable_if {
};

template <typename T>
struct enable_if<true, T> {
	typedef T type;
};

// is_same
template <class T, class U>
struct is_same {
	static const bool value = false;
};

template <class T>
struct is_same<T, T> {
	static const bool value = true;
};

// template <class C>
// void print(C &v, std::string ns) {
// 	typename C::iterator it;
// 	std::cout << ns << "  | s : " << v.size() << "\t| c : " << v.capacity() << "\t| val : ";
// 	for ( it = v.begin(); it != v.end(); it++ ) {
// 		std::cout << *it << " ";
// 	}
// 	std::cout << std::endl;
// }

}  // namespace ft

#endif