#include "../inc/map.hpp"
#include <iostream>
#include <fstream>
#include <map>

template <typename T_L, typename T_R>
std::ostream& operator<<(std::ostream& os, const std::map<T_L,T_R>& m)
{
	for ( typename std::map<T_L, T_R>::const_iterator it = m.begin(); it != m.end(); it++ )
		os << "(" << it->first << "_" << it->second << ")\n";
	return os;
}

template <typename T_L, typename T_R>
std::ostream& operator<<(std::ostream& os, const ft::map<T_L,T_R>& m)
{
	for ( typename ft::map<T_L, T_R>::const_iterator it = m.begin(); it != m.end(); it++ )
		os << "(" << it->first << "_" << it->second << ")\n";
	return os;
}

template <class M, class P>
void test(P ( *make_pair )( int, int )) {
	M m;

	m.insert( make_pair( 42, 18 ) );

	std::cout << m << "\n";
}

int main() {
	test<ft::map<int, int>, ft::pair<int, int> >(&(ft::make_pair));
	test<std::map<int, int>, std::pair<int, int> >(&(std::make_pair));
}