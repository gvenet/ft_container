#include "../inc/vector.hpp"
#include <vector>

template <class V>
void print( V& v ) {

	for ( typename V::iterator it = v.begin(); it != v.end(); it++ )
		std::cout << *it << " ";
	std::cout << "\n";
}

template <class V>
void test() {
	V v;
	for ( int i = 0; i != 20; i++ )
		v.push_back( i );


	v.erase( v.begin() + 2 );
	print(v);

	v.erase( v.begin() + 2, v.end() - 5 );
	print( v );

	// std::cout << "S : " << v.size() << "\n";
	// std::cout << "C : " << v.capacity() << "\n";
}

int main() {
	test<std::vector<int> >();
	test<ft::vector<int> >();
}