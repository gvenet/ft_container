#include "../inc/map.hpp"
#include <iostream>
#include <map>
#include <vector>
#include <time.h>
#include <random>

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

int main() {
	srand( (unsigned)time( 0 ) );

	typedef ft::map<int, int> map;
	typedef map::iterator			mit;
	typedef std::vector<int>	vec;
	typedef vec::iterator			vit;

	int size = 2;
	vec v = random_tab( size );
	map m;

	for ( vit it = v.begin(); it != v.end(); it++ ) ;

	m[1];
	m[0];

	for ( mit it = m.begin(); it != m.end(); it++ ) {
		std::cout << it->first << " ";
	}
	std::cout << std::endl;
	
	for ( mit it = --m.end(); it != --m.begin(); it-- ) {
		std::cout << it->first << " ";
	}
	std::cout << std::endl;
}