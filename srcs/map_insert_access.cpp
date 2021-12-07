#include "../inc/map.hpp"
#include <ctime>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <sys/time.h>

void test_insert_access() {
	ft::map<int, int> map_int;
	for ( int i = 0; i < 10000; ++i ) {
		map_int.insert( ft::make_pair( rand(), rand() ) );
	}
	int sum = 0;
	for ( int i = 0; i < 100000; i++ ) {
		int access = rand() % map_int.size();
		sum += map_int[access];
	}
}

double exec_time( void ( *test_func )() ) {
	std::clock_t start, end;
	start = clock();
	test_func();
	end = clock();
	double time_taken = double( end - start ) / double( CLOCKS_PER_SEC );
	return time_taken;
}

void ratio( double ft, double std ) {
	double ratio = ft / std;
	std::cout << "\033[01;33mft  = \033[0m" << ft << "\n";
	std::cout << "\033[01;33mstd = \033[0m" << std << "\n";
	std::cout << "\033[01;33mratio ft / std = \033[0m";
	if ( ratio > 20 )
		std::cout << "\033[01;31m";
	else
		std::cout << "\033[01;32m";
	std::cout << ratio << " \033[0m\n";
}

int main() {
	double ft = exec_time( &test_insert_access );
	ratio( ft, 0.0815 );
	return 0;
}