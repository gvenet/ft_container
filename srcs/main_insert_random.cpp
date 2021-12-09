#include "../inc/map.hpp"
#include <iostream>
#include <map>
#include <random>
#include <time.h>
#include <vector>

bool is_in_vec3( int to_find, std::vector<int>& vec3 ) {
	for ( std::vector<int>::iterator it = vec3.begin(); it != vec3.end(); it++ )
		if ( *it == to_find )
			return true;
	return false;
}

std::vector<int> random_tab( int size ) {
	srand( (unsigned)time( 0 ) );
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
	std::cout << "\n--------------------------------------------------------\n";
	return v1;
}
std::ostream& operator<<( std::ostream& os, const ft::map<int, int>& m ) {
	for ( ft::map<int, int>::const_iterator it = m.begin(); it != m.end(); it++ )
		os << it->first << "(" << it.base()->left_depth << "," << it.base()->right_depth << ")  ";
	os << std::endl;
	return os;
}

void add( ft::map<int, int>& m, int n ) {

	// std::cout << "add" << n << "\n\n";
	m[n];
	// m.print_tree();
	// std::cout << m << "--------------------------------------------------------\n";
	// std::cout << "--------------------------------------------------------\n";
}

void err( ft::map<int, int>& m, int n ) {
	m.erase( n );
	// if ( !m.empty() )
	// 	m.print_tree();
	// std::cout << m << "\n";
	// std::cout << "--------------------------------------------------------\n";
}

int main() {
	ft::map<int, int> m;

	int size = 300;
	std::vector<int>	v( random_tab( size ) );
	for ( int i = 0; i < size; i++ ) {
		add( m, v[i] );
	}
	// m.print_tree();
	// std::cout << m << "\n";

	// int t[] = { 8, 3, 13, 1, 5, 10, 15, 2, 4, 7, 9, 12, 14, 16, 6, 11 };

	// for ( int i = 0; i < size; i++ )
	// 	add( m, t[i] );
	// // m.print_tree();
	// std::cout << m << "\n";

	// for ( int i = 0; i < size; i++ )
	// 	err( m, i );

	// err( m, 0 );
	// err( m, 1 );
	// err( m, 2 );
	// err( m, 3 );
	// err( m, 4 );
	// err( m, 5 );
	// err( m, 6 );

	return 0;
}