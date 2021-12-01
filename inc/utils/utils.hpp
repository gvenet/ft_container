#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>
#include <map>

#define FT = " ft\t";
#define STD = "std\t";

namespace ft {


template <class C>
void print( C& v, std::string ns ) {
	typename C::iterator it;
	std::cout << ns << "  | s : " << v.size() << "\t| c : " << v.capacity() << "   \t| val : ";
	for ( it = v.begin(); it != v.end(); it++ ) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

template <typename T1, typename T2>
void print( std::map<T1, T2>& v, std::string ns ) {
	typename std::map<T1, T2>::iterator it;
	std::cout << "\n-----------------\n\n";
	std::cout << ns << "  | s : " << v.size() << "\n";
	for ( it = v.begin(); it != v.end(); it++ ) {
		std::cout << it->first << "\t<=>\t" << it->second << "\n";
	}
	std::cout << std::endl;
}

} // namespace ft
#endif