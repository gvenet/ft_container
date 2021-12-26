#include "../inc/map.hpp"
#include <iostream>
#include <map>

using namespace ft;

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

struct KeyCompareInt {
		bool operator()( int x, int y ) const { return -x / 2 < -y / 2; }
};

struct KeyCompareStr {
		bool operator()( std::string x, std::string y ) const {
			return ( x.empty() && !y.empty() ) || ( !x.empty() && !y.empty() && x[0] < y[0] );
		}
};

typedef map<int, int>::iterator		iterator_type;
typedef pair<iterator_type, bool> insert_return_type;

template <class T1, class T2, class Comp>
void insert( map<T1, T2, Comp>& container, T1 k, T2 v ) {
	pair<T1, T2> val = make_pair( k, v );
	std::cout << "Inserting " << val << std::endl;

	pair<typename map<T1, T2, Comp>::iterator, bool> ret = container.insert( val );

	std::cout << "Was present : " << ret.second << std::endl;
	std::cout << "Iterator points to " << *ret.first << std::endl;
}

void insert_many( map<int, int>& container, int n ) {
	for ( int i = 0; i < n; ++i ) {
		container.insert( make_pair( i, i ) );
	}
}

void test_insert() {
	map<int, int> m0;

	std::boolalpha( std::cout );
	for ( int i = 0; i < 5; ++i ) {
		insert( m0, i, i );
	}
	for ( int i = 0; i < 5; ++i ) {
		insert( m0, i, 2 * i );
	}

	insert_many( m0, 10000 );
}

void test_clear() {
	srand( time( NULL ) );
	map<int, int> m;

	for ( int i = 0; i < 1000; ++i ) {
		m[i] = rand();
		if ( i > 0 )
			std::cout << ", ";
	}
	m.clear();
	print_container_nl( m );
	std::cout << m.size();
}

void test_swap() {
	map<int, int> m1, m2;

	for ( int i = 0; i < 10; ++i ) {
		m1[i] = i;
		m2[i] = 10 + i;
	}
	std::cout << "m1 = ";
	print_container_nl( m1 );
	std::cout << "m2 = ";
	print_container_nl( m2 );
	std::cout << "m1.swap(m2)..." << std::endl;
	m1.swap( m2 );
	std::cout << "m1 = ";
	print_container_nl( m1 );
	std::cout << "m2 = ";
	print_container_nl( m2 );
	std::cout << "swap(m1, m2)..." << std::endl;
	swap( m1, m2 );
	std::cout << "m1 = ";
	print_container_nl( m1 );
	std::cout << "m2 = ";
	print_container_nl( m2 );
}

void test_erase() {
	map<int, int> m;

	for ( int i = 0; i < 10; ++i ) {
		m[i] = i;
	}

	// m.print_tree();

	std::cout << "m.erase(2) = " << m.erase( 2 ) << std::endl;
	// print_container_nl(m);
	// m.print_tree();

	std::cout << "m.erase(2) = " << m.erase( 2 ) << std::endl;
	// print_container_nl(m);

	std::cout << "erase begin/ end--\n";
	m.erase( m.begin() );
	m.erase( --( m.end() ) );
  m.print_tree();
	print_container_nl( m );


	map<int, int>::iterator it[2] = { m.begin(), m.end() };
	it[0]++;
	it[0]++;
	it[1]--;
	it[1]--;
	
	std::cout << "erase : " << *it[0] << " " << *it[1] << std::endl;
	m.erase( it[0], it[1] );
  m.print_tree();
	print_container_nl( m );

	
	std::cout << "size = " << m.size() << std::endl;
}

int main() {
	// std::cout << "--- Test insert ---" << std::endl;
	// test_insert();
	std::cout << "--- Test erase ---" << std::endl;
	test_erase();
	// std::cout << "--- Test swap ---" << std::endl;
	// test_swap();
	// std::cout << "--- Test clear ---" << std::endl;
	// test_clear();
}
