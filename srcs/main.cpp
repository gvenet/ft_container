#include <algorithm>
#include <string>
#include <iostream>


#include "../inc/containers/map.hpp"
#include "../inc/containers/vector.hpp"


template <class C>
void print_map(C &x) {
	std::cout << x.second << "\t" << x.first << "\n";
}

int main() {

	typedef ft::map<std::string, int> msi;
	typedef ft::pair<std::string, int> psi;

	std::string tab[] = {"jkd", "pwls", "pojdjd", "ok", "terere", "kbmf", "kdmcn"};
	size_t n = sizeof(tab) / sizeof(tab[0]);

	msi m1;

	for (size_t i = 0; i < n; i++) {
		m1.insert(ft::make_pair(tab[i], i));
	}

	for_each(m1.begin(), m1.end(), print_map<psi>);
	return 0;
}