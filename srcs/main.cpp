#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#include "../inc/Vector.hpp"

// void print(int i) {
// 	std::cout << i << " ";
// }

void test(int i) {
	ft::Vector<int> v1(i, 5);
	v1.insert(v1.end(), 42);
	std::cout << v1.size() << " " << v1.capacity() << "\n";
}

int main() {
	for ( int i = 0; i < 10; i++ ) {
		test(i);
		std::cout << "\n";	
	}

	// ft::Vector<int>::iterator it;

	// for ( it = v1.begin(); it != v1.end(); it++ )
	// 	std::cout << *it << " ";
	// std::cout << std::endl;

	return 0;
}

// void resize_display(int n, size_t val, std::vector<int> &v1) {
// 	v1.resize(n, val);
// 	for_each(v1.begin(), v1.end(), print);
// 	std::cout << std::endl;
// }

// int main(void) {
// 	std::vector<int>		   v1(10, 5);
// 	std::vector<int>::iterator it;

// 	resize_display(20, 2, v1);
// 	resize_display(2, 1, v1);
// 	resize_display(10, 9, v1);
// 	resize_display(20, 0, v1);
// 	resize_display(0, 0, v1);
// 	resize_display(10, 9, v1);
// 	resize_display(20, 3, v1);
// 	resize_display(15, 4, v1);
// 	v1.insert(v1.end(), 42);
// 	for_each(v1.begin(), v1.end(), print);
// 	std::cout << std::endl;
// 	v1.insert(v1.begin(), 42);
// 	for_each(v1.begin(), v1.end(), print);
// 	std::cout << std::endl;

// 	return 0;
// }
