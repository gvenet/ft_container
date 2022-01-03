#include "tester_utils.hpp"

template <class M, class P, class P_ptr>
class test_comp_s {
	public:
		test_comp_s( P_ptr* make_pair ) : _make_pair( make_pair ) { }

		void insert_str( M& container, std::string k, std::string v ) {
			P val = _make_pair( k, v );
			std::cout << "Inserting " << val << std::endl;
			std::cout << "Was present : " << container.insert( val ).second << std::endl;
			std::cout << "Iterator points to " << *( container.insert( val ) ).first << std::endl;
		}

		void test_str() {
			M m;
			for ( int i = 0; i < 20; ++i )
				insert_str( m, std::to_string( i ), std::to_string( i ) );
			for ( int i = 0; i < 20; ++i )
				std::cout << m[std::to_string( i )] << std::endl;
		}

	private:
		P_ptr* _make_pair;
};

template <class M, class P, class P_ptr>
class test_comp_i {
	public:
		test_comp_i( P_ptr* make_pair ) : _make_pair( make_pair ) { }

		void insert_int( M& container, int k, int v ) {
			P val = _make_pair( k, v );
			std::cout << "Inserting " << val << std::endl;
			std::cout << "Was present : " << container.insert( val ).second << std::endl;
			std::cout << "Iterator points to " << *( container.insert( val ) ).first << std::endl;
		}

		void test_int() {
			M m;
			for ( int i = 0; i < 20; ++i )
				insert_int( m, i, i );
			for ( int i = 0; i < 20; ++i )
				std::cout << m[i] << std::endl;
		}

	private:
		P_ptr* _make_pair;
};

template <class I, class S>
void file_out( I i, S s, std::string out_name ) {
	std::ofstream		out( out_name );
	std::streambuf* coutbuf = std::cout.rdbuf();
	std::cout.rdbuf( out.rdbuf() );
	i.test_int();
	s.test_str();
	std::cout.rdbuf( coutbuf );
}

int main() {
	typedef ft::map<int, int, KeyCompareInt> ft_mapi;
	typedef ft::pair<int, int>							 ft_pairi;
	typedef ft_pairi( ft_pairi_ptr )( int, int );

	typedef ft::map<std::string, std::string, KeyCompareStr> ft_maps;
	typedef ft::pair<std::string, std::string>							 ft_pairs;
	typedef ft_pairs( ft_pairs_ptr )( std::string, std::string );

	typedef std::map<int, int, KeyCompareInt> std_mapi;
	typedef std::pair<int, int>								std_pairi;
	typedef std_pairi( std_pairi_ptr )( int, int );

	typedef std::map<std::string, std::string, KeyCompareStr> std_maps;
	typedef std::pair<std::string, std::string>								std_pairs;
	typedef std_pairs( std_pairs_ptr )( std::string, std::string );

	test_comp_i<ft_mapi, ft_pairi, ft_pairi_ptr> ft_tcmpi( &ft::make_pair );
	test_comp_s<ft_maps, ft_pairs, ft_pairs_ptr> ft_tcmps( &ft::make_pair );

	test_comp_i<std_mapi, std_pairi, std_pairi_ptr> std_tcmpi( &std::make_pair );
	test_comp_s<std_maps, std_pairs, std_pairs_ptr> std_tcmps( &std::make_pair );

	file_out( ft_tcmpi, ft_tcmps, "ft.txt" );
	file_out( std_tcmpi, std_tcmps, "std.txt" );
}
