#include "../inc/map.hpp"
#include <ctime>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <sys/time.h>

#define INS 100
#define ACC 100

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

///// INSERT_ACCES_TEST ////////
template <class M, class P, typename T_L, typename T_R>
void test_insert_access( P ( *make_pair )( T_L, T_R ) ) {
	M map_int;
	for ( int i = 0; i < INS; ++i ) {
		map_int.insert( make_pair( rand(), rand() ) );
	}
	int sum = 0;
	for ( int i = 0; i < ACC; i++ ) {
		int access = rand() % map_int.size();
		sum += map_int[access];
	}
}

////// INSERT_COPY_TEST //////////
template <class M, class P, typename T_L, typename T_R>
void test_insert_copy( P ( *make_pair )( T_L, T_R ) ) {
	M map_int;
	for ( int i = 0; i < INS; ++i ) {
		map_int.insert( make_pair( rand(), rand() ) );
	}
	M copy;
	for ( int i = 0; i < ACC; ++i ) {
		copy = map_int;
	}
}

template <typename func_type, typename pair_ptr>
double exec_time( func_type* test_func, pair_ptr* make_pair ) {
	std::clock_t start, end;
	start = clock();
	test_func( make_pair );
	end = clock();
	double time_taken = double( end - start ) / double( CLOCKS_PER_SEC );
	std::cout << std::fixed << time_taken << std::setprecision( 4 ) << std::endl;
	return time_taken;
}

void ratio( double ft, double std ) {
	double ratio = ft / std;
	std::cout << "ratio ft / std = ";
	if ( ratio > 20 )
		std::cout << "\033[01;31m";
	else
		std::cout << "\033[01;32m";
	std::cout << ratio << " \033[0m\n";
}

template <typename T_L, typename T_R>
void type_choice() {
	typedef ft::map<T_L, T_R>	 ft_map;
	typedef ft::pair<T_L, T_R> ft_pair;
	typedef ft_pair( ft_pair_ptr )( T_L, T_R );
	typedef void( ft_func_type )( ft_pair_ptr );

	typedef std::map<T_L, T_R>	std_map;
	typedef std::pair<T_L, T_R> std_pair;
	typedef std_pair( std_pair_ptr )( T_L, T_R );
	typedef void( std_func_type )( std_pair_ptr );

	double clock_ft;
	double clock_std;

	std::cout << "__test_insert_access\n";
	std::cout << "__FT__  : ";
	clock_ft = exec_time<ft_func_type, ft_pair_ptr>( &(test_insert_access<ft_map, ft_pair>),
																									 &( ft::make_pair ) );

	std::cout << "__STD__ : ";
	clock_std = exec_time<std_func_type, std_pair_ptr>( &(test_insert_access<std_map, std_pair>),
																											&( std::make_pair ) );
	ratio( clock_ft, clock_std );

	std::cout << "__test_insert_copy\n";
	std::cout << "__FT__  : ";
	clock_ft = exec_time<ft_func_type, ft_pair_ptr>( &(test_insert_copy<ft_map, ft_pair>),
																									 &( ft::make_pair ) );
	std::cout << "__STD__ : ";
	clock_std = exec_time<std_func_type, std_pair_ptr>( &(test_insert_copy<std_map, std_pair>),
																											&( std::make_pair ) );
	ratio( clock_ft, clock_std );
}

int main() {
	std::cout << "TEST__INT__INT\n";
	type_choice<int, int>();
	std::cout << "\n\nTEST__CHAR__INT\n";
	type_choice<char, int>();

	return 0;
}