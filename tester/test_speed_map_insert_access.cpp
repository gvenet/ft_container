#include "../inc/map.hpp"
#include <ctime>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <sys/time.h>
#include "tester_utils.hpp"

#define GRN "\033[01;31m"
#define RED "\033[01;32m"
#define YLW "\033[01;33m"
#define CBN "\033[0m"

struct test_speed {
	private:
		tester_utils utls;
		std::stringstream ss1;
		std::stringstream ss2;
		int								ins_size;
		int								acc_size;
		double						ft;
		double						std;
		std::vector<int>	v1;
		std::vector<int>	v2;

	public:
		test_speed( std::string ins, std::string acc ) {
			ss1 << ins;
			ss1 >> ins_size;
			ss2 << acc;
			ss2 >> acc_size;
			v1 = utls.random_tab( ins_size );
			v2 = utls.random_tab( ins_size );
			ft = exec_time<ft::map<int, int> >();
			std = exec_time<std::map<int, int> >();
			this->ratio();
		}

		template <class M>
		void test_insert_access() {
			M map_int;
			for ( int i = 0; i < ins_size; ++i ) {
				map_int[v1[i]] = v2[i];
			}
			int sum = 0;
			for ( int i = 0; i < acc_size; i++ ) {
				sum += map_int[v2[i]];
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
			std::cout << YLW << "inserts = " << CBN << ins_size << std::endl;
			std::cout << YLW << "access = " << CBN << acc_size << std::endl;
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