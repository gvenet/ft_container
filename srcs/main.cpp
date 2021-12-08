#include "../inc/map.hpp"
#include <iostream>

std::ostream& operator<<( std::ostream& os, const ft::map<int, int>& m ) {
	for ( ft::map<int, int>::const_iterator it = m.begin(); it != m.end(); it++ )
		os << it->first << "(" << it.base()->left_depth << "," << it.base()->right_depth << ")  ";
	os << std::endl;
	return os;
}

int main() {
	ft::map<int, int> m;

	m[9];
	m[8];
	m[4];
	m[3];
	m[2];
	m[1];
	m[0];
	std::cout << m;

	m.print_tree();
	
	return 0;
}