#include "../inc/map.hpp"
#include <iostream>

// void print_depth( const ft::map<int, int>& m ) {
// 	for ( ft::map<int, int>::const_iterator it = m.begin(); it != m.end(); it++ )
// 		std::cout << it->first << "(" << it.base()->left_depth << "," << it.base()->right_depth << ")";
// 	std::cout << std::endl;
// }

std::ostream& operator<<( std::ostream& os, const ft::map<int, int>& m ) {
	for ( ft::map<int, int>::const_iterator it = m.begin(); it != m.end(); it++ )
		os << it->first << "(" << it.base()->left_depth << "," << it.base()->right_depth << ")";
	os << std::endl;
	return os;
}

int main() {
	ft::map<int, int> m;

	m[50];
	std::cout << m;
	m[100];
	std::cout << m;
	m[150];
	std::cout << m;

	
	return 0;
}