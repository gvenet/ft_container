#include "tester_utils.hpp"
#include <ctime>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <sys/time.h>

#define GRN "\033[01;31m"
#define RED "\033[01;32m"
#define YLW "\033[01;33m"
#define CBN "\033[0m"

struct test_speed {
	private:
		tester_utils			utls;
		std::vector<int>	v1;
		std::stringstream ss1;
		std::stringstream ss2;
		std::stringstream ss3;
		int								ins_size;
		int								acc_size;
		int								era_size;
		double						ft;
		double						std;

	public:
		test_speed( std::string ins, std::string acc, std::string era ) {

			ss1 << ins;
			ss1 >> ins_size;
			ss2 << acc;
			ss2 >> acc_size;
			ss3 << era;
			ss3 >> era_size;
			v1 = utls.random_tab( ins_size );
			ft = exec_time<ft::vector<int> >();
			std = exec_time<std::vector<int> >();
			this->ratio();
		}

		template <class V>
		void test_insert_access() {
			V v;
			for ( int i = 0; i < v1.size(); ++i ) {
				v.push_back( rand() );
			}
			int sum = 0;
			for ( int i = 0; i < acc_size; i++ ) {
				sum += v.at( rand() % v.size() );
			}
			for ( int i = 0; i < era_size; i++ ) {
				v.erase( v.begin() += rand() % v.size() );
			}
		}

		template <class V>
		double exec_time() {
			std::clock_t start, end;
			start = clock();
			test_insert_access<V>();
			end = clock();
			double time_taken = double( end - start ) / double( CLOCKS_PER_SEC );
			return time_taken;
		}

		void ratio() {
			double ratio = ft / std;
			std::cout << YLW << "inserts = " << CBN << ins_size << std::endl;
			std::cout << YLW << "access = " << CBN << acc_size << std::endl;
			std::cout << YLW << "erase = " << CBN << era_size << std::endl;
			std::cout << YLW << "ft  = " << CBN << ft << std::endl;
			std::cout << YLW << "std = " << CBN << std << std::endl;
			std::cout << YLW << "ratio ft / std = " << CBN;
			( ratio > 20 ) ? std::cout << GRN : std::cout << RED;
			std::cout << ratio << CBN << std::endl << std::endl;
		}
};

int main( int ac, char** av ) {
	if ( ac != 4 )
		return 1;
	test_speed test( av[1], av[2], av[3] );
	return 0;
}
