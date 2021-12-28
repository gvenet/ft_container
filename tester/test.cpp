#include <time.h>

#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <random>
#include <sstream>
#include <string>
#include <vector>

#include "../inc/map.hpp"
#include "../inc/vector.hpp"

#include "tester_utils.hpp"

struct test_remove {

		test_remove( std::string str ) {
			std::stringstream ss;
			ss << str;
			ss >> size;
			v1 = utls.random_tab( size );
			v2 = utls.random_tab( size );
		}

		template <class T>
		void routine() {
			typedef T								 map;
			typedef std::vector<int> vector;
			typedef vector::iterator iterator;

			map b;

			std::cout << "construct : ";
			utls.print_vec( v1 );
			std::cout << "\ndestruct  : ";
			utls.print_vec( v2 );
			std::cout << "\n";

			for ( iterator it = v1.begin(); it != v1.end(); it++ )
				b[*it];
			std::cout << "\n\t";
			utls.print_map( b );
			for ( iterator it = v2.begin(); it != v2.end(); it++ )
				utls.rm( *it, b );

			std::cout << "\n";
			std::cout << "construct : ";
			utls.print_vec( v2 );
			std::cout << "\ndestruct  : ";
			utls.print_vec( v1 );
			std::cout << "\n";

			for ( iterator it = v2.begin(); it != v2.end(); it++ )
				b[*it];
			std::cout << "\n\t";
			utls.print_map( b );
			for ( iterator it = v1.begin(); it != v1.end(); it++ )
				utls.rm( *it, b );
			std::cout << "\nSUCCES\n";
		}

	public:
		int							 size;
		tester_utils		 utls;
		std::vector<int> v1;
		std::vector<int> v2;
};

template <class M, class T>
void file_out( std::string out_name, T& test ) {
	std::ofstream		out( out_name );
	std::streambuf* coutbuf = std::cout.rdbuf();
	std::cout.rdbuf( out.rdbuf() );
	test.template routine<M>();
	std::cout.rdbuf( coutbuf );
}

int main( int ac, char** av ) {
	if ( ac != 2 )
		return 1;

	test_remove test( av[1] );

	// file_out<ft::map<int, int> >( "ft.txt", test );
	// file_out<std::map<int, int> >( "std.txt", test );

	test.routine<ft::map<int, int> >();
	test.routine<std::map<int, int> >();
	
	return 0;
}
