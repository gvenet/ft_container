#include <iostream>
#include <string>
#include <vector>

#include "../inc/vector.hpp"

int main() {
	ft::vector<int> x;
	ft::vector<int>::reverse_iterator it;

	for (int i = 0; i < 10; i++) {
		x.push_back(i);
	}
	
	for (it = x.rbegin(); it != x.rend(); it++) {
		std::cout << *it << " ";
	}
	std::cout << "\n";

	return 0;
}
