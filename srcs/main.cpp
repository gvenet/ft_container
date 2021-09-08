#include <iostream>
#include <string>
#include <vector>

#include "../inc/Vector.hpp"

int main() {
	ft::Vector<int>			  v1(5, 3);
	ft::Vector<int>::iterator it;

	// v1.push_back(42);

	for ( it = v1.begin(); it != v1.end(); it++ )
		std::cout << *it << " ";
	std::cout << std::endl;

	return 0;
}
