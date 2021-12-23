#include "../inc/map.hpp"
#include <iostream>
#include <map>
#include <string>

using namespace ft;
// using namespace std;

template <class C1, class C2>
std::ostream& operator<<( std::ostream& os, pair<C1, C2> const& p ) {
	os << "(" << p.first << "," << p.second << ")";
	return os;
}

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

void pit( map<int, int>::iterator it ) {

	std::cout << *it << " p: ";
	if ( it.base()->parent )
		std::cout << it.base()->parent->value.first;
	else
		std::cout << "null";

	std::cout << " l: ";
	if ( it.base()->left )
		std::cout << it.base()->left->value.first;
	else
		std::cout << "null";

	std::cout << " r: ";
	if ( it.base()->right )
		std::cout << it.base()->right->value.first;
	else
		std::cout << "null";
	std::cout << std::endl;
}

void test_iterator_valid() {
	map<int, int> m;

	for ( int i = 0; i < 5; ++i ) {
		m[i] = i;
	}
	map<int, int>::iterator it = m.begin();

	std::cout << "Map is : ";
	print_container_nl( m );
	std::cout << "it++  ";
	++it;
	std::cout << *it << std::endl;

	std::cout << "it++  \n";
	++it;

	m.print_tree();
	pit( it );

	std::cout << "\nErasing keys 1 and 3" << std::endl;
	m.erase( 1 );
	m.erase( 3 );
	std::cout << std::endl;
	m.print_tree();
	pit( it );
	pit( ++it );
	pit( --it );
	pit( --it );

	m.erase( 2 );

	std::cout << std::endl;
	m.print_tree();

	// pit(it);

	// std::cout << "it--  ";
	// it--;
	// std::cout << *it << std::endl;

	// std::cout << "it++  ";
	// it++;
	// std::cout << *it << std::endl;

	// std::cout << "it++  ";
	// it++;
	// std::cout << *it << std::endl;

	// std::cout << "it--  ";
	// it--;
	// std::cout << *it << std::endl;

	// std::cout << "it--  ";
	// it--;
	// std::cout << *it << std::endl;
}

int main() { test_iterator_valid(); }
