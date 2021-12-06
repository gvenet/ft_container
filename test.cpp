#include <iostream>
#include <map>

template <class M, class P, typename T_L, typename T_R>
void test_insert_access( P ( *make_pair )( T_L, T_R ) ) {
	M										 map_int;
	typename M::iterator it( map_int.insert( make_pair( 42, 101 ) ).first );
	std::cout << it->first << "_" << it->second << " | test_insert_access" << std::endl;
}

int main() {
	typedef std::pair<int, int> std_pair;
	typedef std::map<int, int>	std_map;
	
	
	std_pair (*make_pair)(int,int) = &std::make_pair<int,int>;

	// std::cout << make_pair(50,50).first << "__\n";
	
	// test_insert_access<std_map, std_pair>( make_pair);

	void ( *insert_access )( std_pair( * )( int, int ) ) = &( test_insert_access<std_map, std_pair> );
	insert_access(make_pair);
}