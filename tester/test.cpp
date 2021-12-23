#include <time.h>

#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <random>
#include <sstream>
#include <string>
#include <vector>

#include "../inc/map.hpp"
#include "../inc/vector.hpp"

#define S 500
#define R 1

template <class V>
void print_vec( V b ) {
	typename V::iterator it;
	std::cout << "{ ";
	for ( it = b.begin(); it != --b.end(); it++ )
		std::cout << *it << ", ";
	std::cout << *it << " }";
	// std::cout << "\n";
}

template <class InputIterator>
void p( InputIterator it, std::string color ) {
	// std::cout << "\033[01;" << color << "m " << it->first << " \033[0m";
	std::cout << it->first << " ";
}

template <class T>
void print( T& b ) {
	typename T::iterator it;
	for ( it = b.begin(); it != b.end(); it++ )
		p( it, "31" );
	std::cout << "\n";
}

template <class T>
void rm( int x, T& b ) {
	std::cout << "-" << x << "\t\t";
	b.erase( x );
	print( b );
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
	return v1;
}

template <class T>
void test_remove1( int size, int rep, std::vector<int> v1, std::vector<int> v2 ) {
	typedef T								 map;
	typedef std::vector<int> vector;
	typedef vector::iterator iterator;

	map b;

	print_vec( v1 );
	for ( iterator it = v1.begin(); it != v1.end(); it++ )
		b[*it];
	std::cout << "\n\t\t\t";
	print( b );
	for ( iterator it = v2.begin(); it != v2.end(); it++ )
		rm( *it, b );

	print_vec( v2 );
	for ( iterator it = v2.begin(); it != v2.end(); it++ )
		b[*it];
	for ( iterator it = v1.begin(); it != v1.end(); it++ )
		rm( *it, b );
	std::cout << "SUCCES\n";
}

template <class T>
void t_2() {
	typedef T map;
	int				tab[] = { 2, 0, 1 };
	int				s = sizeof( tab ) / sizeof( tab[0] );
	map				x;

	for ( int i = 0; i < s; i++ )
		x[tab[i]] = 0;
	std::cout << "\n";
	typename T::iterator it;
	// std::cout << "\t\t\t\t\t\t";
	print( x );
	for ( int i = 0; i < s; i++ ) {
		rm( tab[i], x );
	}
	std::cout << "\n\n";
}

template <class M>
void file_out( std::string out_name, std::vector<int> v1, std::vector<int> v2 ) {
	std::ofstream		out( out_name );
	std::streambuf* coutbuf = std::cout.rdbuf();
	std::cout.rdbuf( out.rdbuf() );
	test_remove1<M>( S, R, v1, v2 );
	std::cout.rdbuf( coutbuf );
}

template <class T>
void test_remove2( int size, int rep ) {
	srand( (unsigned)time( 0 ) );
	typedef T								 map;
	typedef std::vector<int> vector;
	typedef vector::iterator iterator;

	vector vec;
	map		 b;

	for ( int i = 0; i < rep; i++ ) {
		vec = random_tab( size );
		print_vec( vec );
		for ( iterator it = vec.begin(); it != vec.end(); it++ )
			b[*it];
		std::cout << "\n\t\t\t";
		print( b );
		std::cout << "\n";
	}
	std::cout << "TEST_REMOVE_2_SUCCES\n";
}

int main() {
	struct timespec ts;
	clock_gettime( CLOCK_MONOTONIC, &ts );
	srand((time_t)ts.tv_nsec);

	std::vector<int> v1 = random_tab( S );
	std::vector<int> v2 = random_tab( S );

	file_out<ft::map<int, int> >( "ft.txt", v1, v2 );
	file_out<std::map<int, int> >( "std.txt", v1, v2 );

	// test_remove1<std::map<int,int> >(S,R,v1,v2);

	return 0;
}
