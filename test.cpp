#include <random>

#include "inc/utils/binary_search_tree.hpp"
#include "iostream"

using namespace ft;

int main(void) {
	srand((unsigned int)time(NULL));
	binary_search_tree<int> x;
	int						rdm;

	for ( int i = 0; i < 5; i++ ) {
		rdm = rand() % 2000 + 1;
		x.insert(rdm);
	}
	x.insert(1000);
	for ( int i = 0; i < 5; i++ ) {
		rdm = rand() % 2000 + 1;
		x.insert(rdm);
	}
	// x.printTreeInOrder();

	// std::cout << std::boolalpha << x.search(42) << " " << x.search(0) << "\n";
	// std::cout << x.findMin() << " " << x.findMax() << "\n";
	// std::cout << x.successor(6) << "\n";
	// std::cout << x.predecessor(265) << "\n\n";

	x.printTreeInOrder();
	x.remove(1000);
	x.printTreeInOrder();

	return 0;
}
