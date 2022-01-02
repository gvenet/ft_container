#include <iostream>
#include <map>
#include <string>

template <class M, class P, typename T_L, typename T_R>
int test_insert_access( P ( *make_pair )( T_L, T_R ), T_L __x, T_R __y ) {
	M										 map_int;
	typename M::iterator it( map_int.insert( make_pair( __x,__y) ).first );
	std::cout << it->first << "_" << it->second << " | test_insert_access" << std::endl;
	return 42;
}

template <typename T_L, typename T_R>
void func(T_L __x, T_R __y) {
	typedef std::pair<T_L, T_R> std_pair;
	typedef std::map<T_L, T_R> std_map;

	typedef std_pair(makepair_ptr)(T_L,T_R);
	
	makepair_ptr *make_pair = &std::make_pair<T_L, T_R>;

	std::cout << make_pair(__x,__y).first << "__\n";
	
	int i = test_insert_access<std_map, std_pair>( make_pair, __x, __y);

	// void ( *insert_access )( std_pair( * )( int, int ) ) = &( test_insert_access<std_map, std_pair> );
	// insert_access(make_pair);
}

int main() {
	std::string str = "BITE";

	func<std::string, int>(str, 42);
}