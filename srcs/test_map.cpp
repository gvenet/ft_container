#include "../inc/map.hpp"
#include <fstream>
#include <iostream>
#include <map>

template <typename T_L, typename T_R>
std::ostream& operator<<( std::ostream& os, const std::map<T_L, T_R>& m ) {
	for ( typename std::map<T_L, T_R>::const_iterator it = m.begin(); it != m.end(); it++ )
		os << "(" << it->first << "_" << it->second << ")";
	return os;
}

template <typename T_L, typename T_R>
std::ostream& operator<<( std::ostream& os, const ft::map<T_L, T_R>& m ) {
	for ( typename ft::map<T_L, T_R>::const_iterator it = m.begin(); it != m.end(); it++ )
		os << "(" << it->first << "_" << it->second << ")";
	return os;
}

template <class M, class P, typename T_L, typename T_R>
void test_insert_access( P ( *make_pair )( T_L, T_R ) ) {
	M map_int;
	for ( int i = 0; i < 10000; ++i ) {
		map_int.insert( make_pair( rand(), rand() ) );
	}

	int sum = 0;
	for ( int i = 0; i < 100000; i++ ) {
		int access = rand() % map_int.size();
		(void)access;
		sum += map_int[access];
	}
}

template <class M, class P, typename T_L, typename T_R>
void test_insert_copy( P ( *make_pair )( T_L, T_R ) ) {

	M map_int;
	for ( int i = 0; i < 1000; ++i ) {
		map_int.insert( make_pair( rand(), rand() ) );
	}
	for ( int i = 0; i < 1000; ++i ) {
		M copy = map_int;
	}
}

template <typename T_L, typename T_R>
void type_choice() {
	std::cout << "__test_insert_access\n";
	std::cout << "__FT__\n";
	test_insert_access<ft::map<T_L, T_R>, ft::pair<T_L, T_R> >( &(ft::make_pair<T_L, T_R>));
	std::cout << "__STD__\n";
	test_insert_access<std::map<T_L, T_R>, std::pair<T_L, T_R> >( &(std::make_pair<T_L, T_R>));

	std::cout << "__test_insert_copy\n";
	std::cout << "__FT__\n";
	test_insert_copy<ft::map<T_L, T_R>, ft::pair<T_L, T_R> >( &(ft::make_pair<T_L, T_R>));
	std::cout << "__STD__\n";
	test_insert_copy<std::map<T_L, T_R>, std::pair<T_L, T_R> >( &(std::make_pair<T_L, T_R>));
}

int main() {
	type_choice<int, int>();
	// type_choice<char, int>();
}