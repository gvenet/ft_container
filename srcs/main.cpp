#include "../inc/Vector.hpp"
#include <iostream>
#include <string>
#include <vector>

typedef ft::Vector<int>::Iterator Iterator;

int main() {
	std::vector<int>		   v1(10, 10);
	std::vector<int>::iterator it;

	it = v1.begin();
	std::cout << *it << std::endl;

	return 0;
}

// int main() {

// 	int numbers[] = {10, 20, 30, 40, 50, 60};

// 	Iterator begin(numbers);
// 	Iterator end(numbers + 6);
// 	Iterator it;

// 	for ( it = begin; it != end; it++ )
// 		std::cout << *it << " ";
// 	std::cout << "\n------------\n";
// 	it = end - 1;
// 	for ( ; it >= begin ; it-- )
// 		std::cout << *it << " ";
// 	std::cout << "\n------------\n";
// 	for ( it = begin; it < end; it++ )
// 		std::cout << *it << " ";
// 	std::cout << "\n------------\n";
// 	it = begin + 5;
// 	std::cout << *it << std::endl;
// 	it = end - 6;
// 	std::cout << *it << std::endl;

// 	return 0;
// }

// int main() {
// 	std::vector<int> numbers;
// 	std::vector<int>::iterator it;

// 	numbers.push_back(0);
// 	numbers.push_back(10);
// 	numbers.push_back(20);
// 	numbers.push_back(30);
// 	numbers.push_back(40);
// 	numbers.push_back(50);

// 	for (it = numbers.begin(); it < numbers.end(); it++ )
// 		std::cout << *it << " ";
// 	std::cout << std::endl;
// 	// for (it = numbers.end() - 1; it != numbers.begin() - 1; --it )
// 		// std::cout << *it << " ";
// 	// std::cout << std::endl;

// 	// std::cout << numbers.begin() << std::endl;

// 	std::cout << (it < numbers.end()) << std::endl;

// 	return 0;
// }