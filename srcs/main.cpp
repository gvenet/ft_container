#include "../inc/containers/map.hpp"
#include <algorithm>

void fct(ft::pair<std::string, int> &p) {
	std::cout << p.first << " " << p.second << "\n";
}

void printMap(ft::map<std::string, int> &m) {
	for_each(m.begin(), m.end(), fct);
}

void test29() {
	typedef ft::map<std::string, int> msi;
	std::string st[] = {"A06", "A03", "A09", "A01", "A08"};
	size_t n = sizeof(st) / sizeof(st[0]);
	msi m;

	while (n--)	
		m.insert(ft::make_pair(st[n], n));

	printMap(m);

	msi m2(m);
	printMap(m2);
}

int main() {
	test29();
}