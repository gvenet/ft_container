#ifndef UTILS_HPP
#define UTILS_HPP

#include <ostream>

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