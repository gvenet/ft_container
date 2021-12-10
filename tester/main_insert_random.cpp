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
	typedef std::map<int, int> map;
	typedef std::vector<int>	 vec;
	map												 m1;
	vec												 v1;

	for ( int i = 0; i < size; i++ )
		m1[( rand() % 9000000 + 999999 )] = i;
	for ( map::iterator it = m1.begin(); it != m1.end(); it++ )
		v1.push_back( it->second );
	std::cout << "{ ";
	for ( std::vector<int>::iterator it = v1.begin(); it != v1.end(); it++ )
		std::cout << *it << ", ";
	std::cout << "}\n--------------------------------------------------------\n";
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
	std::cout << "err : " << n << "\n";
	m.erase( n );
	if ( !m.empty() )
		// m.print_tree();
	std::cout << m << "\n";
	std::cout << "--------------------------------------------------------\n";
}

void rdm( int size ) {
	srand( (unsigned)time( 0 ) );
	typedef std::vector<int> vec;
	ft::map<int, int>				 m;

	vec v( random_tab( size ) );
	for ( vec::iterator it = v.begin(); it != v.end(); it++ )
		add( m, *it );

	m.print_tree();
	std::cout << m << "\n";
	std::cout << "--------------------------------------------------------\n";

	v = random_tab( size );
	for ( vec::iterator it = v.begin(); it != v.end(); it++ )
		err( m, *it );
}

void pre() {
	ft::map<int, int> m;
	int								t1[] = { 9,2,10,3 };
	int								s1 = sizeof( t1 ) / sizeof( *t1 );
	int								t2[] = { 2 };
	int								s2 = sizeof( t2 ) / sizeof( *t2 );

	for ( int i = 0; i < s1; i++ )
		add( m, t1[i] );

	m.print_tree();
	std::cout << m << "\n";
	std::cout << "--------------------------------------------------------\n";

	for ( int i = 0; i < s2; i++ )
		err( m, t2[i] );
}

int main() {
	rdm( 10 );
	// pre();
}