#include <iostream>

#include "../inc/map.hpp"
#include "../inc/utils/pair.hpp"
#include <map>
#include <vector>

struct StaticCounter {
		static int total;
		int				 idx;
		StaticCounter() { idx = StaticCounter::total++; }
		StaticCounter( StaticCounter const& ) { idx = StaticCounter::total++; }
		StaticCounter& operator=( StaticCounter const& ) { return *this; }
		~StaticCounter() { StaticCounter::total--; }
};

int StaticCounter::total = 0;

template <class M>
void test_size() {
	M m;
	std::cout << "insert :\n";
	for ( int i = 0; i < 10; ++i ) {
		m[i] = StaticCounter();
		m.insert( ft::make_pair( i, StaticCounter() ) );
		std::cout << "Map size = " << m.size() << std::endl;
		std::cout << "Actual size = " << StaticCounter::total << std::endl;
	}

	std::cout << "erase :\n";
	for ( int i = 0; i < 5; ++i ) {
		m.erase( i );
		std::cout << "Map size = " << m.size() << std::endl;
		std::cout << "Actual size = " << StaticCounter::total << std::endl;
	}

	std::cout << "clear :\n";
	m.clear();
	std::cout << "Map size = " << m.size() << std::endl;
	std::cout << "Actual size = " << StaticCounter::total << std::endl;
}

int main() {
	std::cout << "--- Test size ---" << std::endl;
	// std::cout << "--- STD ---\n\n";
	// test_size<std::map<int, StaticCounter> >();
	std::cout << "\n--- FT ---\n\n";
	test_size<ft::map<int, StaticCounter> >();
}