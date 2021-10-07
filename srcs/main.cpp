#include <algorithm>

#include "../inc/containers/map.hpp"
#include "../inc/containers/vector.hpp"

void fct(ft::pair<std::string, int> &p) {
	std::cout << p.first << " " << p.second << "\n";
}

void printMap(ft::map<std::string, int> &m) {
	for_each(m.begin(), m.end(), fct);
}

void test29() {
	typedef ft::map<std::string, int> msi;
	std::string						  st[] = {"A06", "A03", "A09", "A01", "A08"};
	size_t							  n = sizeof(st) / sizeof(st[0]);
	msi								  m;

	while ( n-- )
		m.insert(ft::make_pair(st[n], n));

	printMap(m);

	std::cout << "\n";
	msi m2(m);
	printMap(m2);
}

void test30() {
	typedef ft::vector<int> vi;
	typedef vi::iterator	vi_it;
	vi						v;

	v.push_back(42);
	v.push_back(18);
	v.push_back(3);

	for ( vi_it vit = v.begin(); vit != v.end(); vit++ ) {
		std::cout << *vit << "\n";
	}
}

int main() {
	test29();
	test30();
}