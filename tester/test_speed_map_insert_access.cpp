#include "../inc/map.hpp"
#include <ctime>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <sys/time.h>

#define GRN "\033[01;31m"
#define RED "\033[01;32m"
#define YLW "\033[01;33m"
#define CBN "\033[0m"

struct test_speed {
	private:
		std::stringstream ss1;
		std::stringstream ss2;
		int								insert;
		int								access;
		double						ft;
		double						std;

	public:
		test_speed( std::string ins, std::string acc ) {
			ss1 << ins;
			ss1 >> insert;
			ss2 << acc;
			ss2 >> access;
			ft = exec_time<ft::map<int, int> >();
			std = exec_time<std::map<int, int> >();
			this->ratio();
		}

		template <class M>
		void test_insert_access() {
			M map_int;
			for ( int i = 0; i < insert; ++i ) {
				map_int[rand()] = rand();
			}
			int sum = 0;
			for ( int i = 0; i < access; i++ ) {
				int access = rand() % map_int.size();
				sum += map_int[access];
			}
		}

		template <class M>
		double exec_time() {
			std::clock_t start, end;
			start = clock();
			test_insert_access<M>();
			end = clock();
			double time_taken = double( end - start ) / double( CLOCKS_PER_SEC );
			return time_taken;
		}

		void ratio() {
			double ratio = ft / std;
			std::cout << YLW << "inserts = " << CBN << insert << std::endl;
			std::cout << YLW << "access = " << CBN << access << std::endl;
			std::cout << YLW << "ft  = " << CBN << ft << std::endl;
			std::cout << YLW << "std = " << CBN << std << std::endl;
			std::cout << YLW << "ratio ft / std = " << CBN;
			( ratio > 20 ) ? std::cout << GRN : std::cout << RED;
			std::cout << ratio << CBN << std::endl;
		}
};

int main( int ac, char** av ) {
	if ( ac != 3 )
		return 1;
	test_speed test( av[1], av[2] );
	return 0;
}