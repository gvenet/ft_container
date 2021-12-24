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

#define S 7
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
	std::cout << "-" << x << "\t";
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

	std::cout << "construct : ";
	print_vec( v1 );
	std::cout << "\ndestruct  : ";
	print_vec( v2 );
	std::cout << "\n";

	for ( iterator it = v1.begin(); it != v1.end(); it++ )
		b[*it];
	std::cout << "\n\t";
	print( b );
	for ( iterator it = v2.begin(); it != v2.end(); it++ )
		rm( *it, b );

	std::cout << "\n";
	std::cout << "construct : ";
	print_vec( v2 );
	std::cout << "\ndestruct  : ";
	print_vec( v1 );
	std::cout << "\n";

	for ( iterator it = v2.begin(); it != v2.end(); it++ )
		b[*it];
	std::cout << "\n\t";
	print( b );
	for ( iterator it = v1.begin(); it != v1.end(); it++ )
		rm( *it, b );
	std::cout << "\nSUCCES\n";
}

template <class T>
void t_2() {
	typedef T map;
	int				tab[] = { 6, 2, 0, 4, 1, 5, 3 };
	int				tr[] = { 2, 3, 4, 1, 6, 0, 5 };

	// int				tab[] = { 1, 4, 5, 0, 2, 3, 6 };
	// int				tr[] = { 2, 6, 4, 5, 1, 3, 0 };

	int s = sizeof( tab ) / sizeof( tab[0] );
	map x;

	for ( int i = 0; i < s; i++ ) {
		x[tab[i]] = 0;
	}
	std::cout << "\n";

	x.print_tree();

	typename T::iterator it;
	std::cout << "\t";
	print( x );
	for ( int i = 0; i < s; i++ ) {
		std::cout << "----------------------------------\n";
		rm( tr[i], x );
		if ( !x.empty() )
			x.print_tree();
	}
	std::cout << "\n\n";
}

template <class M>
void file_out( std::string out_name, std::vector<int> v1, std::vector<int> v2, int size ) {
	std::ofstream		out( out_name );
	std::streambuf* coutbuf = std::cout.rdbuf();
	std::cout.rdbuf( out.rdbuf() );
	test_remove1<M>( size, R, v1, v2 );
	std::cout.rdbuf( coutbuf );
}

int main( int ac, char** av ) {
	if ( ac != 2 )
		return 1;
	struct timespec ts;
	clock_gettime( CLOCK_MONOTONIC, &ts );
	srand( (time_t)ts.tv_nsec );

	int								size;
	std::stringstream ss;
	ss << av[1];
	ss >> size;

	std::vector<int> v1 = random_tab( size );
	std::vector<int> v2 = random_tab( size );

	file_out<ft::map<int, int> >( "ft.txt", v1, v2, size );
	file_out<std::map<int, int> >( "std.txt", v1, v2, size );

	// test_remove1<ft::map<int, int> >( size, R, v1, v2 );
	// test_remove1<std::map<int,int> >(S,R,v1,v2);

	// t_2<ft::map<int, int> >();

	return 0;
}
