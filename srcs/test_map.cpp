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
void test( P ( *make_pair )( T_L, T_R ) ) {
	M m;

	m.insert( make_pair( 65, 18 ) );
	std::cout << m << "\n";
}

template <typename T_L, typename T_R>
void type_choice() {
	std::cout << "__FT__\n";
	test<ft::map<T_L, T_R>, ft::pair<T_L, T_R> >( &( ft::make_pair<T_L, T_R> ) );
	std::cout << "__STD__\n";
	test<std::map<T_L, T_R>, std::pair<T_L, T_R> >( &( std::make_pair<T_L,T_R> ) );
}

int main() {
	type_choice<int,int>();
	type_choice<char,int>();
}