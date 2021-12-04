#include "../inc/vector.hpp"
#include <vector>
#include <iostream>
#include <fstream>

using namespace ft;

template <class Container>
void print_container( Container const& m ) {
	for ( typename Container::const_iterator it = m.begin(); it != m.end(); ++it ) {
		if ( it != m.begin() )
			std::cout << ", ";
		std::cout << *it;
	}
}
template <class Container>
void print_container_nl( Container const& m ) {
	print_container( m );
	std::cout << std::endl;
}

template <class V>
void test() {
	V vect1;
	V vect2;

	for ( int i = 0; i < 10; i++ ) {
		vect1.push_back( i );
	}
	for ( int i = 10; i < 20; i++ ) {
		vect2.push_back( i );
	}

	typename V::iterator it1 = vect1.begin() + 3;
	typename V::iterator it2 = vect2.begin() + 3;
	int*									p1 = &vect1[4];
	int*									p2 = &vect2[4];
	int&									r1 = vect1[5];
	int&									r2 = vect2[5];

	print_container_nl( vect1 );
	print_container_nl( vect2 );
	swap( vect1, vect2 );
	print_container_nl( vect1 );
	print_container_nl( vect2 );

	std::cout << *it1 << std::endl;
	std::cout << *it2 << std::endl;
	std::cout << *p1 << std::endl;
	std::cout << *p2 << std::endl;
	std::cout << r1 << std::endl;
	std::cout << r2 << std::endl;
	*it1 = -1;
	*it2 = -2;
	*p1 = -3;
	*p2 = -4;
	r1 = -5;
	r2 = -6;
	print_container_nl( vect1 );
	print_container_nl( vect2 );
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

	test<ft::vector<int> >();
	std::cout << std::endl;
	test<std::vector<int> >();
	return 0;
}