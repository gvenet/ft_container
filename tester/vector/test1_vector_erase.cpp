#include "tester_utils.hpp"

struct vector_erase {
	private:
		tester_utils utls;

	public:
		vector_erase() {
			file_out<std::vector<int> >( STD );
			file_out<ft::vector<int> >( FT );
		}

		template <class V>
		void test() {
			V v;
			for ( int i = 0; i != 20; i++ )
				v.push_back( i );

			v.erase( v.begin() + 2 );
			utls.print_vec( v );

			v.erase( v.begin() + 2, v.end() - 5 );
			utls.print_vec( v );
		}

		template <class V>
		void file_out( std::string id ) {
			std::ofstream		out( id );
			std::streambuf* coutbuf = std::cout.rdbuf();
			std::cout.rdbuf( out.rdbuf() );
			test<V>();
			std::cout.rdbuf( coutbuf );
		}
};

int main() {
	vector_erase test;
	return 0;
}