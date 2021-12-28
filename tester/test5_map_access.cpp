#include "tester_utils.hpp"

template <class M>
class test_access {
	public:
		test_access( std::string out_id ) : _out_id( out_id ) { }

		void routine() {
			M m;

			for ( int i = 0; i < 100; i++ ) {
				m[i] = i;
			}
			for ( int i = 0; i < 100; i++ ) {
				std::cout << m[i] << " ";
			}
			std::cout << std::endl;
		}

		void file_out() {
			std::ofstream		out( _out_id );
			std::streambuf* coutbuf = std::cout.rdbuf();
			std::cout.rdbuf( out.rdbuf() );
			routine();
			std::cout.rdbuf( coutbuf );
		}

	private:
		std::string _out_id;
};
int main() {
	test_access<std::map<int, int> > std_acc( "std.txt" );
	test_access<ft::map<int, int> >	 ft_acc( "ft.txt" );
	std_acc.file_out();
	ft_acc.file_out();
}