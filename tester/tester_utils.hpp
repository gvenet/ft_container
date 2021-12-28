#ifndef TESTER_UTILS_HPP
#define TESTER_UTILS_HPP

#include <fstream>
#include <iostream>
#include <map>
#include <random>
#include <time.h>
#include <vector>

struct tester_utils {

		typedef std::map<int, int> map;
		typedef std::vector<int>	 vec;

		tester_utils() {
			struct timespec ts;
			clock_gettime( CLOCK_MONOTONIC, &ts );
			srand( (time_t)ts.tv_nsec );
		}

		std::vector<int> random_tab( int size ) {
			map m1;
			vec v1;

			for ( int i = 0; i < size; i++ )
				m1[( rand() % 9000000 + 999999 )] = i;
			for ( map::iterator it = m1.begin(); it != m1.end(); it++ )
				v1.push_back( it->second );
			return v1;
		}

		template <class V>
		void print_vec( V b ) {
			typename V::iterator it;
			std::cout << "{ ";
			for ( it = b.begin(); it != --b.end(); it++ )
				std::cout << *it << ", ";
			std::cout << *it << " }";
			std::cout << "\n";
		}

		template <class InputIterator>
		void p( InputIterator it, std::string color ) {
			// std::cout << "\033[01;" << color << "m " << it->first << " \033[0m";
			std::cout << it->first << " ";
		}

		template <class T>
		void print_map( T& b ) {
			typename T::iterator it;
			for ( it = b.begin(); it != b.end(); it++ )
				p( it, "31" );
			std::cout << "\n";
		}

		template <class T>
		void rm( int x, T& b ) {
			std::cout << "-" << x << "\t";
			b.erase( x );
			print_map( b );
		}
};

#endif
