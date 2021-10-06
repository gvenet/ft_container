#include <map>
#include <random>

#include "inc/utils/binary_search_tree.hpp"
#include "inc/utils/pair.hpp"
#include "iostream"

int main(void) {
	typedef ft::pair<std::string, std::string> psi;

	ft::Binary_search_tree<psi> x;
	psi							p("a", "b");

	x.insertPair(p);

	


	return 0;
}
