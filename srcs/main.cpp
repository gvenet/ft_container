#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#include "../inc/Vector.hpp"

static int rf = 20;

void test_ft(int i) {
	ft::vector<int> v1(i, 5);
	for ( int i = 0; i < rf; i++ ) {
		v1.push_back(6);
		std::cout << v1.size() << " " << v1.capacity() << " | ";
	}
}

void test_std(int i) {
	std::vector<int> v1(i, 5);
	for ( int i = 0; i < rf; i++ ) {
		v1.push_back(6);
		std::cout << v1.size() << " " << v1.capacity() << " | ";
	}
}

int main() {
	int r = 10;

	for ( int i = 2; i < r; i++ ) {
		test_std(i);
		std::cout << std::endl;
		test_ft(i);
		std::cout << std::endl;
		std::cout << std::endl;
	}

	return 0;
}

