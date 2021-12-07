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

#define S 100
#define R 3

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

bool is_in_vec3( int to_find, ft::vector<int>& vec3 ) {
	for ( ft::vector<int>::iterator it = vec3.begin(); it != vec3.end(); it++ )
		if ( *it == to_find )
			return true;
	return false;
}

ft::vector<int> random_tab( int size ) {
	typedef ft::vector<int> vector;

	vector vec1;
	vector vec2;
	vector vec3;

	vec1.resize( size );
	for ( size_t i = 0; i < vec1.size(); i++ )
		vec2.push_back( rand() % 9000000 + 999999 );

	int i = -1;
	while ( ++i < size ) {
		int value_tmp = INT_MAX;
		int index_tmp = 0;
		for ( ft::vector<int>::iterator it = vec2.begin(); it != vec2.end(); it++ ) {
			int index = -( vec2.begin() - it );
			if ( *it < value_tmp && !is_in_vec3( index, vec3 ) ) {
				value_tmp = *it;
				index_tmp = index;
			}
		}
		vec3.push_back( index_tmp );
		vec1[index_tmp] = i;
	}
	return vec1;
}

template <class T>
void test_remove1( int size, int rep ) {
	srand( (unsigned)time( 0 ) );
	typedef T								 map;
	typedef ft::vector<int> vector;
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
		vec = random_tab( size );
		for ( iterator it = vec.begin(); it != vec.end(); it++ )
			rm( *it, b );
		std::cout << "\n";
	}
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
void file_out( std::string out_name ) {
	std::ofstream		out( out_name );
	std::streambuf* coutbuf = std::cout.rdbuf();
	std::cout.rdbuf( out.rdbuf() );
	test_remove1<M>( S, R );
	std::cout.rdbuf( coutbuf );
}

template <class T>
void test_remove2( int size, int rep ) {
	srand( (unsigned)time( 0 ) );
	typedef T								 map;
	typedef ft::vector<int> vector;
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
		// for ( typename map::iterator it = b.begin(); it != b.end(); it++ ) {
		// 	b.erase( it );
		// 	print( b );
		// }
		std::cout << "\n";
	}
	std::cout << "TEST_REMOVE_2_SUCCES\n";
}

int main() {
	// test_remove1<ft::map<int, int> >( 3, 10 );
	// test_remove2<ft::map<int, int> >( 10, 1 );

	file_out<ft::map<int, int> >( "ft.txt" );
	file_out<std::map<int, int> >( "std.txt" );

	// t_2<ft::map<int, int> >();

	return 0;
}
