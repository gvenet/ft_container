#include "../inc/map.hpp"
#include <iostream>
#include <map>
#include <random>
#include <time.h>
#include <vector>

std::vector<int> random_tab( int size ) {
	typedef std::map<int, int> map;
	typedef std::vector<int>	 vec;
	map												 m1;
	vec												 v1;

	for ( int i = 0; i < size; i++ )
		m1[( rand() % 9000000 + 999999 )] = i;
	for ( map::iterator it = m1.begin(); it != m1.end(); it++ )
		v1.push_back( it->second );
	// for ( std::vector<int>::iterator it = v1.begin(); it != v1.end(); it++ )
	// 	std::cout << *it << " ";
	// std::cout << std::endl;
	return v1;
}

void prt( ft::map<int, int> m ) {
	for ( ft::map<int, int>::iterator it = m.begin(); it != m.end(); it++ ) {
		std::cout << "[" << it->first << " (";
		std::cout << it.base()->pred->value.first;
		if ( it.base()->pred->is_limit )
			std::cout << ".";
		std::cout << " " << it.base()->succ->value.first;
		if ( it.base()->succ->is_limit )
			std::cout << ".";
		std::cout << ")]   ";
	}
	std::cout << std::endl;
}

int main() {
	srand( (unsigned)time( 0 ) );

	typedef std::map<int, int> map;

	map m;

	int							 size = 100000;
	std::vector<int> v = random_tab( size );
	for ( std::vector<int>::iterator it = v.begin(); it != v.end(); it++ )
		m[*it];

	std::cout << "PT1\n\n";

	// std::map<int, int>::iterator it = m.begin();
	// std::map<int, int>::iterator itb = m.end();

	// while ( it != itb ) {
	// 	std::map<int, int>::iterator tmp = it;
	// 	it++;
	// 	m.erase( tmp );
	// }
	// std::cout << &(*itb) << " " << &(*it) << "\n";

	std::cout << "\nPT2\n\n";
}