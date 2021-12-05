#include "../inc/vector.hpp"
#include <fstream>
#include <ios>
#include <iostream>
#include <vector>

template <class Iterator>
void iter( Iterator begin, Iterator end, void ( *f )( typename Iterator::value_type& ) ) {
	for ( Iterator it = begin; it != end; ++it ) {
		f( *it );
	}
}

template <class T>
void printElem( T& elem ) {
	std::cout << elem << " ";
}

template <class V>
void test() {
	V vect( 6, 1 );
	vect.push_back( 0 );
	vect.push_back( 1 );
	vect[2] = 2;
	std::cout << "size = " << vect.size() << std::endl;
	std::cout << "capacity = " << vect.capacity() << std::endl;
	try {
		vect.at( 10 );
	} catch ( std::exception const& e ) {
		std::cout << e.what() << std::endl;
	}

	V vectIter( vect.begin(), vect.end() - 1 );
	iter( vect.begin(), vect.end(), printElem );
	std::cout << std::endl;
	iter( vectIter.begin(), vectIter.end(), printElem );
	std::cout << std::endl;
}

template <class V>
void file_out( std::string out_name ) {
	std::ofstream		out( out_name );
	std::streambuf* coutbuf = std::cout.rdbuf();
	std::cout.rdbuf( out.rdbuf() );
	test<V>();
	std::cout.rdbuf( coutbuf );
}

int main() {
	// file_out<ft::vector<int> >( "ft" );
	// file_out<std::vector<int> >( "std" );

	std::cout << "___FT___\n";
	test<ft::vector<int> >();
	std::cout << std::endl;
	std::cout << "___STD___\n";
	test<std::vector<int> >();
	return 0;
}
