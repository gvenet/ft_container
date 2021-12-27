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
	for ( std::vector<int>::iterator it = v1.begin(); it != v1.end(); it++ )
		std::cout << *it << " ";
	std::cout << std::endl;
	return v1;
}

void prt( ft::map<int, int> m ) {
	for ( ft::map<int, int>::iterator it = m.begin(); it != m.end(); it++ ) {
		std::cout << it->first << " ";
	}
	std::cout << std::endl;
}

int main() {
	srand( (unsigned)time( 0 ) );

	typedef ft::map<int, int> map;
	typedef std::vector<int>	vec;
	typedef vec::iterator			vit;

	int size = 10;
	vec v = random_tab( size );
	map m;

	for ( vit it = v.begin(); it != v.end(); it++ )
		m[*it];

	std::cout << std::endl;
	m.print_tree();
	prt( m );
	m.erase(5);
	prt( m );
	m.erase(5);
	prt( m );
	m.erase(9);
	prt( m );
	
	// for ( mit it = --m.end(); it != --m.begin(); it-- ) {
	// 	std::cout << it->first << " ";
	// }
	// std::cout << std::endl;
}