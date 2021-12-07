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

typedef void( func_type )();

#define A1 10000
#define A2 100000

void test_insert_access_ft() {
	ft::map<int, int> map_int;
	for ( int i = 0; i < A1; ++i ) {
		map_int.insert( ft::make_pair( rand(), rand() ) );
	}
	int sum = 0;
	for ( int i = 0; i < A2; i++ ) {
		int access = rand() % map_int.size();
		sum += map_int[access];
	}
}

void test_insert_access_std() {
	std::map<int, int> map_int;
	for ( int i = 0; i < A1; ++i ) {
		map_int.insert( std::make_pair( rand(), rand() ) );
	}
	int sum = 0;
	for ( int i = 0; i < A2; i++ ) {
		int access = rand() % map_int.size();
		sum += map_int[access];
	}
}

double exec_time( func_type* test_func ) {
	std::clock_t start, end;
	start = clock();
	test_func();
	end = clock();
	double time_taken = double( end - start ) / double( CLOCKS_PER_SEC );
	return time_taken;
}

void ratio( double ft, double std ) {
	double ratio = ft / std;
	std::cout << YLW << "ft  = " << CBN << ft << std::endl;
	std::cout << YLW << "std = " << CBN << std << std::endl;
	std::cout << YLW << "ratio ft / std = " << CBN;
	( ratio > 20 ) ? std::cout << GRN :	std::cout << RED;
	std::cout << ratio << CBN << std::endl;
}

int main() {
	double ft = exec_time( &test_insert_access_ft );
	double std = exec_time( &test_insert_access_std );
	ratio( ft, std );

	return 0;
}