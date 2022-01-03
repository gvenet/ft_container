#include "tester_utils.hpp"

struct test_swap {
	private:
		tester_utils utls;

	public:
		test_swap() {
			this->file_out<ft::vector<int> >( FT );
			this->file_out<std::vector<int> >( STD );
		}

		template <class V>
		void test() {
			V v1;
			V v2;

			for ( int i = 10; i < 20; i++ ) {
				v1.push_back( i );
			}
			for ( int i = 20; i < 30; i++ ) {
				v2.push_back( i );
			}

			typename V::iterator it1 = v1.begin() + 3;
			typename V::iterator it2 = v2.begin() + 3;
			int*								 p1 = &v1[4];
			int*								 p2 = &v2[4];
			int&								 r1 = v1[5];
			int&								 r2 = v2[5];

			std::cout << "V1__ : ";
			utls.print_vec( v1 );
			std::cout << "V2__ : ";
			utls.print_vec( v2 );
			std::cout << "SWAP__\n";
			swap( v1, v2 );
			std::cout << "V1__ : ";
			utls.print_vec( v1 );
			std::cout << "V2__ : ";
			utls.print_vec( v2 );
			std::cout << "\n";

			std::cout << "*IT1__ " << *it1 << std::endl;
			std::cout << "*IT2__ " << *it2 << std::endl;
			std::cout << "*P1__ " << *p1 << std::endl;
			std::cout << "*P2__ " << *p2 << std::endl;
			std::cout << "*R1__ " << r1 << std::endl;
			std::cout << "*R2__ " << r2 << std::endl;
			*it1 = -1;
			*it2 = -2;
			*p1 = -3;
			*p2 = -4;
			r1 = -5;
			r2 = -6;
			std::cout << "\nV1__ : ";
			utls.print_vec(v1);
			std::cout << "V2__ : ";
			utls.print_vec(v2);
		}

		template <class V>
		void file_out( std::string out_name ) {
			std::ofstream		out( out_name );
			std::streambuf* coutbuf = std::cout.rdbuf();
			std::cout.rdbuf( out.rdbuf() );
			test<V>();
			std::cout.rdbuf( coutbuf );
		}
};

int main() {
	test_swap test;
	return 0;
}