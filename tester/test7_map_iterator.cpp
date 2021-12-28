#include "tester_utils.hpp"

template <class MI>
class test_map_iter {
	public:
		test_map_iter( std::string out_id ) : out_name( out_id ) { }
		
		void test_iterator_types() {
			MI bst;

			for ( int i = 0; i < 15; ++i )
				bst[i] = i;

			std::cout << "Mutable iterator" << std::endl;
			for ( typename MI::iterator it = bst.begin(); it != bst.end(); ++it )
				std::cout << *it << ", ";
			std::cout << "END" << std::endl;

			std::cout << "Mutable reverse iterator" << std::endl;
			for ( typename MI::reverse_iterator it = bst.rbegin(); it != bst.rend(); ++it )
				std::cout << *it << ", ";
			std::cout << "END" << std::endl;

			MI const cbst( bst );
			std::cout << "Const iterator" << std::endl;
			for ( typename MI::const_iterator it = cbst.begin(); it != cbst.end(); ++it )
				std::cout << *it << ", ";
			std::cout << "END" << std::endl;

			std::cout << "Reverse const iterator" << std::endl;
			for ( typename MI::const_reverse_iterator it = cbst.rbegin(); it != cbst.rend(); ++it )
				std::cout << *it << ", ";
			std::cout << "END" << std::endl;
		}

		// operator-> !
		// Require size >= 3
		template <class InputIterator>
		void test_iterator_methods( InputIterator it ) {
			std::cout << "*it = " << *it << std::endl;
			// operator++
			std::cout << "++it = " << *( ++it ) << ", now *it = " << *it << std::endl;
			// operator++(int)
			std::cout << "it++ = " << *( it++ ) << ", now *it = " << *it << std::endl;
			// operator--
			std::cout << "--it = " << *( --it ) << ", now *it = " << *it << std::endl;
			// operator--(int)
			std::cout << "it-- = " << *( it-- ) << ", now *it = " << *it << std::endl;
			// operator==
			std::cout << "it == it : " << ( it == it ) << std::endl;
			// operator!=
			std::cout << "it != it : " << ( it != it ) << std::endl;
		}

		void test_comparison_iters() {
			MI m;
			for ( int i = 0; i < 10; i++ )
				m[i] = i;
			MI const& cm = m;

			std::cout << "begin() == (const_iterator)begin() : " << ( m.begin() == cm.begin() )
								<< std::endl;
			std::cout << "(const_iterator)begin() == begin() : " << ( cm.begin() == m.begin() )
								<< std::endl;
			std::cout << "end() == (const_iterator)end() : " << ( m.end() == cm.end() ) << std::endl;
			std::cout << "(const_iterator)end() == end() : " << ( cm.end() == m.end() ) << std::endl;
			std::cout << "begin() == (const_iterator)end() : " << ( m.begin() == cm.end() ) << std::endl;
			std::cout << "(const_iterator)begin() == end() : " << ( cm.begin() == m.end() ) << std::endl;
			std::cout << "end() == (const_iterator)begin() : " << ( m.end() == cm.begin() ) << std::endl;
			std::cout << "(const_iterator)end() == begin() : " << ( cm.end() == m.begin() ) << std::endl;
		}

		void test() {
			MI bst;

			for ( int i = 0; i < 15; ++i )
				bst[i] = i;

			std::boolalpha( std::cout );
			MI const cbst( bst );
			std::cout << "map::iterator" << std::endl << std::endl;
			test_iterator_methods( bst.begin() );
			std::cout << std::endl;
			std::cout << "map::const_iterator" << std::endl << std::endl;
			test_iterator_methods( cbst.begin() );

			std::cout << std::endl;
			test_iterator_types();

			std::cout << std::endl;
			test_comparison_iters();
		}
		void file_out() {
			std::ofstream		out( out_name );
			std::streambuf* coutbuf = std::cout.rdbuf();
			std::cout.rdbuf( out.rdbuf() );
			test();
			std::cout.rdbuf( coutbuf );
		}

	private:
		std::string	 out_name;
		tester_utils utls;
};

int main() {
	test_map_iter<tester_utils::std_mapi> std_mit("std.txt");
	test_map_iter<tester_utils::ft_mapi>	ft_mit( "ft.txt" );
	std_mit.file_out();
	ft_mit.file_out();
}