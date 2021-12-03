#include <iostream>

#include "../inc/map.hpp"
#include "../inc/utils/pair.hpp"
#include <map>
#include <vector>

using namespace ft;

template <class C1, class C2>
std::ostream& operator<<( std::ostream& os, pair<C1, C2> const& p ) {
	os << "(" << p.first << "," << p.second << ")";
	return os;
}

struct KeyCompareInt {
		bool operator()( int x, int y ) const { return -x / 2 < -y / 2; }
};

// struct KeyCompareInt {
// 		bool operator()( int x, int y ) const { return x  < y ; }
// };

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

int main() {
	map<int, int, KeyCompareInt> m;

	for ( int i = 0; i < 20; ++i )
		insert( m, i, i );

	for ( int i = 0; i < 20; ++i )
		std::cout << m[i] << " ";
	std::cout << "\n";

	for ( map<int, int, KeyCompareInt>::iterator it = m.begin(); it != m.end(); it++ )
		std::cout << *( it ) << " ";
	std::cout << "\n";
}

// int main() {
// 	map<int, int> m;

// 	for ( int i = 0; i < 10; i++ )
// 		m.insert( make_pair( i, i * 10 ) );

// 	std::cout << *m.find( 5 )<< "\n";
// }