#include <iostream>

#include "../inc/map.hpp"
#include "../inc/utils/pair.hpp"
#include <map>

int main() {

	// ft::pair<const int, int>* addr;
	ft::map<int, int> m;

	int tab[] = { 1, 0, 9, 8, 2, 3, 4, 5, 6, 7 };
	for ( int i = 0; i < 10; i++ )
		m.insert( ft::make_pair( tab[i], tab[i] * 10 ) );

	m.erase( 1 );

	for ( ft::map<int, int>::iterator it = m.begin(); it != m.end(); it++ )
		std::cout << it->first << "_" << it->second << " ";
	std::cout << "\n";

	m.clear();

	for ( ft::map<int, int>::iterator it = m.begin(); it != m.end(); it++ )
		std::cout << it->first << "_" << it->second << " ";
	std::cout << "\n";
}