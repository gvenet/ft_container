#include "../inc/map.hpp"
#include <ctime>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <sys/time.h>

#define GRN "\033[01;31m"
#define RED "\033[01;32m"
#define YLW "\033[01;33m"
#define CBN "\033[0m"
#define A1 1000
#define A2 1000

typedef void( func_type_ft )( ft::map<int, int> );
typedef void( func_type_std )( std::map<int, int> );

template <class M>
void test_insert_access( M map_int ) {
	for ( int i = 0; i < A1; ++i ) {
		map_int[rand()] = rand();
	}
	int sum = 0;
	for ( int i = 0; i < A1; i++ ) {
		int access = rand() % map_int.size();
		sum += map_int[access];
	}
}

template <class M, class F>
double exec_time( F* test_func ) {
	std::clock_t start, end;
	M						 map;
	start = clock();
	test_func( map );
	end = clock();
	double time_taken = double( end - start ) / double( CLOCKS_PER_SEC );
	return time_taken;
}

void ratio( const double& ft, const double& std ) {
	double ratio = ft / std;
	std::cout << YLW << "ft  = " << CBN << ft << std::endl;
	std::cout << YLW << "std = " << CBN << std << std::endl;
	std::cout << YLW << "ratio ft / std = " << CBN;
	( ratio > 20 ) ? std::cout << GRN : std::cout << RED;
	std::cout << ratio << CBN << std::endl;
}

int main() {
	const double ft = exec_time<ft::map<int, int>, func_type_ft>( &test_insert_access );
	const double std = exec_time<std::map<int, int>, func_type_std>( &test_insert_access );
	ratio( ft, std );
	return 0;
}