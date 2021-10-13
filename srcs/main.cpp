#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#include "../inc/containers/map.hpp"
#include "../inc/containers/vector.hpp"

int main() {
	ft::vector<int> x;

	x.push_back(42);
	x.push_back(42);
	x.push_back(42);
	x.push_back(42);

	for(ft::vector<int>::iterator it = x.begin(); it != x.end(); it++) {
		std::cout << *it << "\n";

	}





	return 0;
}
