#ifndef TESTER_UTILS_HPP
#define TESTER_UTILS_HPP

#include <fstream>
#include <iostream>
#include <map>
#include <random>
#include <string>
#include <time.h>
#include <vector>

#include "../../inc/vector.hpp"
#include "../../inc/map.hpp"
#include "../../inc/utils/pair.hpp"

struct KeyCompareInt {
		bool operator()( int x, int y ) const { return -x / 2 < -y / 2; }
};

struct KeyCompareStr {
		bool operator()( std::string x, std::string y ) const {
			return ( x.empty() && !y.empty() ) || ( !x.empty() && !y.empty() && x[0] < y[0] );
		}
};

struct tester_utils {
		typedef std::map<int, int>																std_mapi;
		typedef ft::map<int, int>																	ft_mapi;
		typedef std::pair<std_mapi::iterator, std_mapi::iterator> std_pair_it;
		typedef ft::pair<ft_mapi::iterator, ft_mapi::iterator>		ft_pair_it;
		typedef std::map<int, int, KeyCompareInt>									std_mapi_cmp;
		typedef std::map<std::string, std::string, KeyCompareStr> std_maps_cmp;
		typedef ft::map<int, int, KeyCompareInt>									ft_mapi_cmp;
		typedef ft::map<std::string, std::string, KeyCompareStr>	ft_maps_cmp;

		tester_utils() {
			struct timespec ts;
			clock_gettime( CLOCK_MONOTONIC, &ts );
			srand( (time_t)ts.tv_nsec );
		}

		std::vector<int> random_tab( int size ) {
			std_mapi m1;
			std::vector<int> v1;

			for ( int i = 0; i < size; i++ )
				m1[( rand() % 9000000 + 999999 )] = i;
			for ( std_mapi::iterator it = m1.begin(); it != m1.end(); it++ )
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
			std::cout << std::endl;
		}

		template <class InputIterator>
		void p( InputIterator it, std::string color ) {
			// std::cout << "\033[01;" << color << "m " << it->first << " \033[0m";
			std::cout << it->first << " ";
		}

		template <class M>
		void print_map( M& b ) {
			typename M::iterator it;
			for ( it = b.begin(); it != b.end(); it++ )
				p( it, "31" );
			std::cout << "\n";
		}

		template <class Iterator>
		void print_range( Iterator first, Iterator last ) {
			for ( Iterator it = first; it != last; ++it ) {
				if ( it != first )
					std::cout << ", ";
				std::cout << it->first;
			}
			std::cout << std::endl;
		}

		template <class M, class T>
		void file_out( std::string out_name, T& test ) {
			std::ofstream		out( out_name );
			std::streambuf* coutbuf = std::cout.rdbuf();
			std::cout.rdbuf( out.rdbuf() );
			test.template routine<M>();
			std::cout.rdbuf( coutbuf );
		}
};

template <class C1, class C2>
std::ostream& operator<<( std::ostream& os, std::pair<C1, C2> const& p ) {
	os << "(" << p.first << "," << p.second << ")";
	return os;
}

template <class C1, class C2>
std::ostream& operator<<( std::ostream& os, ft::pair<C1, C2> const& p ) {
	os << "(" << p.first << "," << p.second << ")";
	return os;
}

#endif
