#include <random>

#include "inc/utils/binary_search_tree.hpp"
#include "iostream"

using namespace ft;

int main(void) {
	// srand((unsigned int)time(NULL));
	// binary_search_tree<int> x;
	// int						rdm;

	// for ( int i = 0; i < 10; i++ ) {
	// 	rdm = rand() % 2000 + 1;
	// 	std::cout << rdm << "\n";
	// 	x.insert(rdm);
	// }
	
	// x.insert(1000);
	// std::cout << "1000\n";

	// for ( int i = 0; i < 10; i++ ) {
	// 	rdm = rand() % 2000 + 1;
	// 	std::cout << rdm << "\n";
	// 	x.insert(rdm);
	// }
	// // x.printTreeInOrder();

	// // std::cout << std::boolalpha << x.search(42) << " " << x.search(0) << "\n";
	// // std::cout << x.findMin() << " " << x.findMax() << "\n";
	// // std::cout << x.successor(6) << "\n";
	// // std::cout << x.predecessor(265) << "\n\n";

	// x.printTreeInOrder();
	// x.remove(1000);
	// x.printTreeInOrder();

	binary_search_tree<int> x;

	x.insert(6);
	x.insert(1);
	x.insert(7);
	x.insert(4);
	x.insert(9);
	x.insert(8);
	x.insert(2);
	x.insert(5);
	x.insert(3);

	x.printTreeInOrder();
	return 0;
}
