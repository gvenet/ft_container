#include <time.h>

#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <random>
#include <sstream>
#include <string>
#include <vector>

#include "../inc/containers/map.hpp"
#include "../inc/containers/vector.hpp"

#define SEED srand( (unsigned)time( 0 ) );
#define S 10
#define R 5

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

template <class M>
void print( M m ) {
	for ( typename M::iterator it = m.begin(); it != m.end(); it++ )
		// for ( typename M::reverse_iterator it = m.rbegin(); it != m.rend(); it++ )
		std::cout << it->first << "_" << it->second << " ";
	std::cout << "\n";
}

template <class M>
M routine_random( int size ) {
	SEED;
	ft::vector<int> vec = random_tab( size );
	M								m;

	for ( size_t i = 0; i < vec.size(); i++ ) {
		m.insert( ft::make_pair( vec[i], i ) );
	}
	for ( ft::vector<int>::iterator it = vec.begin(); it != vec.end(); it++ )
		std::cout << *it << " ";
	std::cout << "\t";

	return m;
}

template <class M>
M routine( int* t, int s ) {
	M m;

	for ( int i = 0; i < s; i++ ) {
		std::cout << t[i] << " ";
		m.insert( ft::make_pair( t[i], i ) );
	}
	std::cout << "\t";

	return m;
}

template <class M>
void test1( M mymap ) {

	std::cout << "mymap contains:\n";
	ft::pair<int, int>	 highest = *mymap.rbegin();
	typename M::iterator it = mymap.begin();
	do {
		std::cout << it->first << " => " << it->second << '\n';
	} while ( mymap.value_comp()( *it++, highest ) );
}

template <class M>
void test2( M m ) {
	for ( typename M::iterator it = m.begin(); it != m.end(); it++ ) {
		m.erase( it );
		// std::cout << &(*it) << "__" << it->first << "__" << ft::boolalpha << it.base()->is_limit <<
		// "\n"; std::cout << m.get_root() << "\n";
		print( m );
		// std::cout << &(*it) << "\n" << &(*m.end()) << "\n";
	}
}

template <class M>
void test3( M m ) {
	// std::cout << m.count( 8 );

	typename M::const_iterator it = m.find( 8 );
	std::cout << it->first << " " << m.count( 8 ) << " " << m.count( 24 ) << "\n";
}

template <class M>
void test4() {
	M m;

	m.insert( ft::make_pair( 5, 60 ) );
	m.insert( ft::make_pair( 2, 70 ) );
	m.insert( ft::make_pair( 9, 20 ) );

	const M cpy( m );

	typename M::const_iterator lit;
	for ( int i = 0; i < 12; i++ ) {
		lit = cpy.lower_bound( i );
		std::cout << lit->first << " ";
	}
	std::cout << "\n";
}

template <class M>
void test5() {
	M m;

	m.insert( ft::make_pair( 5, 60 ) );
	m.insert( ft::make_pair( 2, 70 ) );
	m.insert( ft::make_pair( 9, 20 ) );

	const M cpy( m );

	// 	for ( int i = 0; i < 12; i++ )
	// 	std::cout << cpy.lower_bound( i )->first  << " ";
	// std::cout << "\n";
	for ( int i = 0; i < 12; i++ )
		std::cout << m.upper_bound( i )->first << " ";
	std::cout << "\n";
	for ( int i = 0; i < 12; i++ )
		std::cout << cpy.upper_bound( i )->first << " ";
	std::cout << "\n";
}

template <class M>
void test7( M m ) {
	ft::pair<typename M::iterator, typename M::iterator> equ;
	equ = m.equal_range( 9 );
	std::cout << equ.first->first << " " << equ.second->first << " _ ";
	equ = m.equal_range( 4 );
	std::cout << equ.first->first << " " << equ.second->first << " _ ";
	equ = m.equal_range( 20 );
	std::cout << equ.first->first << " " << equ.second->first << " _ ";
	equ = m.equal_range( 30 );
	std::cout << equ.first->first << " " << equ.second->first << " _ ";
	equ = m.equal_range( 5 );
	std::cout << equ.first->first << " " << equ.second->first << " _ ";
	equ = m.equal_range( 23 );
	std::cout << equ.first->first << " " << equ.second->first << "\n";
}

template <class M>
void test8( M mymap ) {
	int												psize;
	ft::pair<const int, int>* p;

	p = mymap.get_allocator().allocate( 5 );

	psize = sizeof( ft::map<char, int>::value_type ) * 5;

	std::cout << psize << " bytes\n";

	mymap.get_allocator().deallocate( p, 5 );
}

template <class M>
void test6( M m ) {
	// print( m );

	typedef ft::vector<int> vec;
	vec											data;

	int count = m.size();
	for ( int i = 0; i < 2; i++ )
		data.push_back( rand() % count );
	std::sort( data.begin(), data.end() );
	for ( typename vec::iterator it = data.begin(); it != data.end(); it++ )
		std::cout << *it << " ";
	std::cout << "\t";

	m.erase( m.lower_bound( data[0] ), m.upper_bound( data[1] ) );
	// m.erase( m.begin(), m.end() );
	print( m );
}

int main() {
	// typedef ft::map<int, int> std_map;
	typedef ft::map<int, int> fft_map;
	// test2( routine<std_map>() );
	// test2 (routine<ft_map>());

	// test3( routine<ft_map>() );
	// test3( routine<std_map>() );

	// int s = 30;
	// test6( routine_random<std_map>( s ) );
	// test6( routine_random<fft_map>( s ) );

	// int t[] = { 0, 23, 5, 10, 60 };
	// int s = sizeof( t ) / sizeof( t[0] );
	// test6( routine<fft_map>( t, s ) );
	// test6( routine<std_map>( t, s ) );

	// test7( routine<std_map>( t, s ) );
	// test7( routine<fft_map>( t, s ) );

	// test8( routine_random<std_map>( s ) );
	// test8( routine_random<fft_map>( s ) );
	// x.erase(x.begin(), x.end());

	// test2( routine<ft_map>() );
	// ft_map x(routine<ft_map>());
	// print( x );

	// for ( ft_map::reverse_iterator cit = x.rbegin(); cit != x.rend(); cit++ )
	// 	std::cout << cit->first << " ";
	// std::cout << ft::endl;

	fft_map x;
	for ( int i = 10; i < 50; i += 10 )
		x.insert( ft::make_pair( i, i * 10 ) );
	x.insert( x.end(), ft::make_pair( 50, 500 ) );
	x.insert( x.end(), ft::make_pair( 60, 600 ) );
	fft_map y( x.begin(), x.end() );
	fft_map z( y );

	x.erase( 60 );
	y.erase( 50 );
	y.erase( 60 );
	z.erase( 40 );
	z.erase( 50 );
	z.erase( 60 );

	print( x );
	print( y );
	print( z );

	std::cout << x.max_size() << "__\n";
}
