#ifndef UTILS_HPP
#define UTILS_HPP

#include <string>
#include "algorithm.hpp"
#include "iterator_traits.hpp"
#include "iterator.hpp"
#include "pair.hpp"
#include "random_access_iterator.hpp"
#include "reverse_iterator.hpp"
#include "type_traits.hpp"

namespace ft {

const char* FT = " ft\t";
const char* STD = "std\t";

template <class C>
void print(C& v, std::string ns) {
	typename C::iterator it;
	std::cout << ns << "  | s : " << v.size() << "\t| c : " << v.capacity() << "   \t| val : ";
	for ( it = v.begin(); it != v.end(); it++ ) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

}  // namespace ft
#endif