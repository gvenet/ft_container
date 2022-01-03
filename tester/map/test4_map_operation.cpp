#include "tester_utils.hpp"

template <class MI, class P>
class test_operation {
	public:
		test_operation(std::string out_id) : out_name(out_id){

			for ( int i = 0; i < 10; ++i ) {
				m10[i] = i;
			}
		}

		void test_find_replace( MI& m, int k, int r ) {
			typename MI::iterator it = m.find( k );
			std::cout << k << " is in m : " << ( it != m.end() ) << std::endl;
			if ( it != m.end() )
				it->second = r;
			utls.print_map( m );
		}

		void test_find() {
			MI m = m10;
			test_find_replace( m, 1, 666 );
			test_find_replace( m, 12, 0 );
		}

		void test_count() {
			MI m = m10;
			std::cout << "Number of times 1 is present in m : " << m.count( 1 ) << std::endl;
			std::cout << "Number of times 12 is present in m : " << m.count( 12 ) << std::endl;
			utls.print_map( m );
		}

		void test_lower_bound() {
			MI m = m10;
			m.erase( 3 );

			std::cout << "lower_bound of 2 in m : ";
			utls.print_range( m.lower_bound( 2 ), m.end() );
			std::cout << "lower_bound of 3 in m : ";
			utls.print_range( m.lower_bound( 3 ), m.end() );
			std::cout << "lower_bound of 4 in m : ";
			utls.print_range( m.lower_bound( 4 ), m.end() );
		}

		void test_upper_bound() {
			MI m = m10;
			m.erase( 3 );

			std::cout << "upper_bound of 2 in m : ";
			utls.print_range( m.upper_bound( 2 ), m.end() );
			std::cout << "upper_bound of 3 in m : ";
			utls.print_range( m.upper_bound( 3 ), m.end() );
			std::cout << "upper_bound of 4 in m : ";
			utls.print_range( m.upper_bound( 4 ), m.end() );
		}

		void test_equal_range() {
			MI m = m10;
			m.erase( 3 );
			P range;

			range = m.equal_range( 2 );
			std::cout << "equal_range of 2 in m : ";
			utls.print_range( range.first, range.second );
			std::cout << "equal_range of 3 in m : ";
			range = m.equal_range( 3 );
			utls.print_range( range.first, range.second );
		}

		void file_out( ) {
			std::ofstream		out( out_name );
			std::streambuf* coutbuf = std::cout.rdbuf();
			std::cout.rdbuf( out.rdbuf() );
			std::boolalpha( std::cout );
			test_find();
			test_count();
			test_lower_bound();
			test_upper_bound();
			test_equal_range();
			std::cout.rdbuf( coutbuf );
		}

	private:
		MI					 m10;
		tester_utils utls;
		std::string out_name;
};

int main() {
	test_operation<tester_utils::std_mapi, tester_utils::std_pair_it> std_op("std.txt");
	std_op.file_out();
	test_operation<tester_utils::ft_mapi, tester_utils::ft_pair_it> ft_op("ft.txt");
	ft_op.file_out();
}
