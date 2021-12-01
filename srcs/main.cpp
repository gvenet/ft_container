
#include "../inc/containers/map.hpp"
#include <iostream>

int main() {
	typedef ft::map<int, int> fft_map;

	fft_map m;

	for ( int i = 10; i < 60; i += 10 )
		m[i] = i * 10;

	for ( fft_map::iterator it = m.begin(); it != m.end(); it++ )
		std::cout << it->first << "_" << it->second << " ";
	std::cout << "\n";

	std::cout << m.insert( m.lower_bound( 20 ), ft::make_pair( 55, 550 ) )->first << "__\n";

	for ( fft_map::iterator it = m.begin(); it != m.end(); it++ )
		std::cout << it->first << "_" << it->second << " ";
	std::cout << "\n";
}