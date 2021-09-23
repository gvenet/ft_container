#ifndef UTILS_HPP
#define UTILS_HPP

#include "iterator_traits.hpp"

namespace ft {

const char* FT = " ft\t";
const char* STD = "std\t";

// // enable_if
// template <bool B, typename T = void>
// struct enable_if {
// };

// template <typename T>
// struct enable_if<true, T> {
// 	typedef T type;
// };

// enable_if
template <bool B, typename = void>
struct enable_if {
};

template <typename T>
struct enable_if<true, T> {
	typedef T type;
};

//value_type
struct false_type {
	static const bool value = false;
};

struct true_type {
	static const bool value = true;
};

// is_same
template <class T, class U>
struct is_same : false_type {
};

template <class T>
struct is_same<T, T> : true_type {
};

// template <class T, class = void>
// struct is_integral : false_type {
// };

// template <typename T>
// struct is_integral<T, void_t<typename T::result_type>> : true_type {
// };

//nice little chip print newbie fonction
template <class C>
void print(C &v, std::string ns) {
	typename C::iterator it;
	std::cout << ns << "  | s : " << v.size() << "\t| c : " << v.capacity() << "   \t| val : ";
	for ( it = v.begin(); it != v.end(); it++ ) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

}  // namespace ft

#endif