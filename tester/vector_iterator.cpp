#include "../inc/vector.hpp"
#include <ios>
#include <fstream>
#include <iostream>
#include <vector>

template <class V>
void test_iterator_types() {
	V intVect;
	for ( int i = 0; i < 10; i++ )
		intVect.push_back( i );

	std::cout << "Mutable iterator" << std::endl;
	for ( typename V::iterator it = intVect.begin(); it != intVect.end(); ++it )
		std::cout << *it << ", ";
	std::cout << "END" << std::endl;

	std::cout << "Mutable reverse iterator" << std::endl;
	for ( typename V::reverse_iterator it = intVect.rbegin(); it != intVect.rend(); ++it )
		std::cout << *it << ", ";
	std::cout << "END" << std::endl;

	V const cIntVect( intVect );
	std::cout << "Const iterator" << std::endl;
	for ( typename V::const_iterator it = cIntVect.begin(); it != cIntVect.end(); ++it )
		std::cout << *it << ", ";
	std::cout << "END" << std::endl;

	std::cout << "Reverse const iterator" << std::endl;
	for ( typename V::const_reverse_iterator it = cIntVect.rbegin(); it != cIntVect.rend(); ++it )
		std::cout << *it << ", ";
	std::cout << "END" << std::endl;
}

// operator-> !
// Require size >= 3
template <class InputIterator>
void test_iterator_methods( InputIterator it ) {
	std::cout << "*it = " << *it << std::endl;
	// operator++
	std::cout << "++it = " << *( ++it ) << ", now *it = " << *it << std::endl;
	// operator++(int)
	std::cout << "it++ = " << *( it++ ) << ", now *it = " << *it << std::endl;
	// operator--
	std::cout << "--it = " << *( --it ) << ", now *it = " << *it << std::endl;
	// operator--
	std::cout << "it-- = " << *( it-- ) << ", now *it = " << *it << std::endl;
	// operator[]
	std::cout << "it[0] = " << it[0] << ", it[2] = " << it[2] << std::endl;
	// operator+=
	std::cout << "it += 2, now *it = " << *( it += 2 ) << std::endl;
	// operator-=
	std::cout << "it -= 1, now *it = " << *( it -= 1 ) << std::endl;
	// operator-
	std::cout << "*(it - 1) = " << *( it - 1 ) << std::endl;
	// operator+
	std::cout << "*(it + 1) = " << *( it + 1 ) << std::endl;
	// operator+
	std::cout << "*(1 + it) = " << *( 1 + it ) << std::endl;
	// operator-
	std::cout << "*(it - (it + 2)) = " << ( it - ( it + 2 ) ) << std::endl;
	std::cout << "*(it - (it - 1)) = " << ( it - ( it - 1 ) ) << std::endl;
	// operator==
	std::cout << "it == it : " << ( it == it ) << std::endl;
	std::cout << "it == (it + 1) : " << ( it == ( it + 1 ) ) << std::endl;
	// operator!=
	std::cout << "it != (it + 1) : " << ( it != ( it + 1 ) ) << std::endl;
	std::cout << "it != it : " << ( it != it ) << std::endl;
	// operator<
	std::cout << "it < it : " << ( it < it ) << std::endl;
	std::cout << "it < (it + 1) : " << ( it < ( it + 1 ) ) << std::endl;
	// operator>
	std::cout << "it > it : " << ( it > it ) << std::endl;
	std::cout << "it > (it - 1) : " << ( it > ( it - 1 ) ) << std::endl;
	// operator<=
	std::cout << "it <= it : " << ( it <= it ) << std::endl;
	std::cout << "it <= (it + 1) : " << ( it <= ( it + 1 ) ) << std::endl;
	// operator>=
	std::cout << "it >= it : " << ( it >= it ) << std::endl;
	std::cout << "it >= (it - 1) : " << ( it >= ( it - 1 ) ) << std::endl;
	std::cout << "(it + 3) - it = " << ( it + 3 ) - it << std::endl;
}

template <class V>
void test_comparison_iters() {
	V intVect;
	for ( int i = 0; i < 10; i++ )
		intVect.push_back( i );
	V const& cIntVect = intVect;

	std::cout << "begin() == (const_iterator)begin() : " << ( intVect.begin() == cIntVect.begin() )
						<< std::endl;
	std::cout << "(const_iterator)begin() == begin() : " << ( cIntVect.begin() == intVect.begin() )
						<< std::endl;
	std::cout << "end() == (const_iterator)end() : " << ( intVect.end() == cIntVect.end() )
						<< std::endl;
	std::cout << "(const_iterator)end() == end() : " << ( cIntVect.end() == intVect.end() )
						<< std::endl;
	std::cout << "begin() == (const_iterator)end() : " << ( intVect.begin() == cIntVect.end() )
						<< std::endl;
	std::cout << "(const_iterator)begin() == end() : " << ( cIntVect.begin() == intVect.end() )
						<< std::endl;
	std::cout << "end() == (const_iterator)begin() : " << ( intVect.end() == cIntVect.begin() )
						<< std::endl;
	std::cout << "(const_iterator)end() == begin() : " << ( cIntVect.end() == intVect.begin() )
						<< std::endl;
	std::cout << "begin() < (const_iterator)end() : " << ( intVect.begin() < cIntVect.end() )
						<< std::endl;
	std::cout << "(const_iterator)begin() < end() : " << ( cIntVect.begin() < intVect.end() )
						<< std::endl;
}

template <class V>
void test() {
	V intVect;
	for ( int i = 0; i < 10; i++ )
		intVect.push_back( i );
	V const cIntVect( intVect );

	std::boolalpha(std::cout);
	std::cout << "vector::iterator" << std::endl << std::endl;
	test_iterator_methods( intVect.begin() );
	std::cout << std::endl;
	std::cout << "vector::const_iterator" << std::endl << std::endl;
	test_iterator_methods( cIntVect.begin() );

	std::cout << std::endl;
	test_iterator_types<V>();

	std::cout << std::endl;
	test_comparison_iters<V>();
}

// int main() {
// 	std::cout << "\n############___FT___###############\n";
// 	test<ft::vector<int> >();
// 	std::cout << "\n############___STD___###############\n";
// 	// test<std::vector<int> >();
// }

template <class V>
void file_out( std::string out_name ) {
	std::ofstream		out( out_name );
	std::streambuf* coutbuf = std::cout.rdbuf();
	std::cout.rdbuf( out.rdbuf() );
	test<V>();
	std::cout.rdbuf( coutbuf );
}

int main() {
	file_out<ft::vector<int> >( "ft" );
	file_out<std::vector<int> >( "std" );

	// std::cout << "___FT___\n";
	// test<ft::vector<int> >();
	// std::cout << std::endl;
	// std::cout << "___STD___\n";
	// test<std::vector<int> >();
	return 0;
}

