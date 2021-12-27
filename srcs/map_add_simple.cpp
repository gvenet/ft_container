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

	typedef ft::map<int, int> map;

	map m;

	int							 size = 60000;
	std::vector<int> v = random_tab( size );
	for ( std::vector<int>::iterator it = v.begin(); it != v.end(); it++ )
		m[*it];

	// for ( int i = 0; i < 10000000; i++ )
	// 	m[i];

	std::cout << "PT1\n";

	// m.print_tree();
	// m.erase( 0 );
	// m.erase( 1 );
	// m.erase( 2 );
	// m.print_tree();
	// m.erase(m.begin(), m.end());

	// std::cout << "PT2\n";
	// m[1];
	// m[2];
	// m[0];

	// std::cout << std::endl;
	// m.print_tree();
	// m.print_tree();
	// prt( m );
	// m.erase( 5 );
	// prt( m );
	// m.erase( 8 );
	// m.print_tree();
	// m.erase( 9 );
	// m.print_tree();
	// prt( m );
	// prt( m );
	// prt( m );
	// m.erase( 5 );
	// prt( m );
	// m.erase( 9 );
	// prt( m );

	// ft::map<int, int>::iterator it[] = {m.begin() , m.end()};
	// it[0]++;
	// it[0]++;
	// it[1]--;
	// it[1]--;
	// std::cout << it->first << "___\n";

	// while ( it[0] != it[1] ) {
	// 	m.erase( it[0]++ );
	// 	// m.print_tree();
	// }
	// prt( m );
	// m.erase(9);
	// prt( m );
	// m.erase(m.begin());
	// prt( m );
	// m.erase(--m.end());
	// prt( m );
	// for ( mit it = --m.end(); it != --m.begin(); it-- ) {
	// 	std::cout << it->first << " ";
	// }
	// std::cout << std::endl;
}