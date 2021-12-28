#include "tester_utils.hpp"

template <class M>
class test_copy {
	public:
		test_copy( std::string out_id ) : out_name( out_id ) { }
		void routine() {
			M m;

			for ( int i = 0; i < 1000; i++ ) {
				m[i] = i;
			}
			M m_copy( m );
			utls.print_map( m_copy );

			M m_assign;
			m_assign = m;
			utls.print_map( m_assign );

			// Make sure all was duplicated
			m.clear();
			utls.print_map( m_copy );
			utls.print_map( m_assign );
		}

		void file_out() {
			std::ofstream		out( out_name );
			std::streambuf* coutbuf = std::cout.rdbuf();
			std::cout.rdbuf( out.rdbuf() );
			routine();
			std::cout.rdbuf( coutbuf );
		}

	private:
		std::string	 out_name;
		tester_utils utls;
};

int main() {
	test_copy<tester_utils::std_mapi> std_tc( "std.txt" );
	test_copy<tester_utils::ft_mapi>	ft_tc( "ft.txt" );
	std_tc.file_out();
	ft_tc.file_out();
}