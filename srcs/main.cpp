#include <iostream>

#include "../inc/map.hpp"
#include "../inc/utils/pair.hpp"
#include <map>
#include <vector>

using namespace std;

template <class V>
void print( V v ) {
	for ( typename V::iterator it = v.begin(); it != v.end(); it++ )
		std::cout << *it << " ";
	std::cout << "\n";
}

template <class V>
V vec_gen() {
	V v;
	for ( int i = 0; i < 5; ++i )
		v.push_back( i );
	return v;
}

template <class V>
V ins( V v ) {
	typename V::iterator pos( v.begin() + 2 );
	v.insert( pos, v.begin(), v.end() );
	v.insert( v.begin() + 6, 12 );
	v.insert( v.begin(), 3, 42 );
	return v;
}

int main() {
	typedef std::vector<int> std_v;
	typedef ft::vector<int>	 fft_v;

	print( ins( vec_gen<std_v>() ) );
	print( ins( vec_gen<fft_v>() ) );
}