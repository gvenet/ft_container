#include <sstream>
#include <string>

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
		void rm( int x, T& b ) {
			std::cout << "-" << x << "\t";
			b.erase( x );
			utls.print_map( b );
		}

		template <class T>
		void routine() {
			typedef T								 map;
			typedef std::vector<int> vector;
			typedef vector::iterator iterator;

			map b;

			std::cout << "construct : ";
			utls.print_vec( v1 );
			std::cout << "destruct  : ";
			utls.print_vec( v2 );

			for ( iterator it = v1.begin(); it != v1.end(); it++ )
				b[*it];
			std::cout << "\n\t";
			utls.print_map( b );
			for ( iterator it = v2.begin(); it != v2.end(); it++ )
				rm( *it, b );

			std::cout << "\nconstruct : ";
			utls.print_vec( v2 );
			std::cout << "destruct  : ";
			utls.print_vec( v1 );

			for ( iterator it = v2.begin(); it != v2.end(); it++ )
				b[*it];
			std::cout << "\n\t";
			utls.print_map( b );
			for ( iterator it = v1.begin(); it != v1.end(); it++ )
				rm( *it, b );
			std::cout << "\nSUCCES\n";
		}

		void output() {
			utls.file_out<ft::map<int, int> >( "ft.txt", *this );
			utls.file_out<std::map<int, int> >( "std.txt", *this );
		}

	public:
		int							 size;
		tester_utils		 utls;
		std::vector<int> v1;
		std::vector<int> v2;
};

int main( int ac, char** av ) {
	if ( ac != 2 )
		return 1;
	test_remove test( av[1] );
	test.output();
	return 0;
}
