#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#include "../inc/Vector.hpp"

void print(int i) {
	std::cout << i << " ";
}

int main() {
	ft::Vector<int>			  v1(5, 3);
	ft::Vector<int>::iterator it;

	// v1.insert(v1.end(), 42);

	for ( it = v1.begin(); it != v1.end(); it++ )
		std::cout << *it << " ";
	std::cout << std::endl;

	return 0;
}


// int main(void) {
// 	std::vector<int>		   v1(5, 3);
// 	std::vector<int>::iterator it;

// 	// for ( int i = 0; i < 8; i += 2 ) {
// 	v1.insert(v1.begin() + 3, 10, 10);
// 	v1.insert(v1.begin() + 6, 5, 5);
// 	for_each(v1.begin(), v1.end(), print);
// 	std::cout << std::endl;
// 	// }
// 	return 0;
// }
