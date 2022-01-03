#include "tester_utils.hpp"

int _new;
int _del;

struct A {
		A() {
			_new++;
			m = new int();
		}
		A( A const& x ) {
			_new++;
			m = new int();
			*m = *x.m;
		}
		A& operator=( A const& x ) {
			*m = *x.m;
			return *this;
		}
		A& operator=( int n ) {
			*m = n;
			return *this;
		}
		~A() {
			_del++;
			delete m;
		}

		friend std::ostream& operator<<( std::ostream& os, A const& a ) { return os << *a.m; }

		int* m;
};

struct test_modifier {
	private:
		tester_utils utls;

	public:
		test_modifier() {
			file_in_out<ft::vector<int>, ft::vector<A> >( FT );
			file_in_out<std::vector<int>, std::vector<A> >( STD );
		}
		template <typename T, class V>
		void test_with( T ( &array10 )[10], T ( &array7 )[7] ) {
			V vect;

			// push_back
			for ( int i = 0; i < 10; i++ ) {
				vect.push_back( array10[i] );
				std::cout << vect.size() << std::endl;
				std::cout << vect.back() << std::endl;
			}
			utls.print_vec( vect );

			// insert iterator
			vect.insert( vect.begin() + 5, array7, array7 + 3 );

			// insert 1
			typename V::iterator it = vect.insert( vect.begin(), array7[3] );
			std::cout << *it << std::endl;
			std::cout << it - vect.begin() << std::endl;
			*it = array7[4];

			// insert range
			vect.insert( vect.end() - 1, array7[5] );
			vect.insert( vect.begin() + 8, 6, array7[5] );

			utls.print_vec( vect );

			// pop_back

			for ( int i = 0; i < 5; i++ ) {
				vect.pop_back();

				std::cout << "vect.back() = " << vect.back() << std::endl;
				std::cout << "vect.size() = " << vect.size() << std::endl;
			}
			utls.print_vec( vect );

			// erase, clear
			vect.clear();
		}

		template <typename T, class V>
		void test_erase( T ( &array10 )[10] ) {
			V vect( array10, array_end( array10 ) );

			vect.erase( vect.begin() + 2 );
			utls.print_vec( vect );
			vect.erase( vect.begin() + 1, vect.begin() + 4 );
			utls.print_vec( vect );
		}

		template <typename T, class V>
		void test_assign( T ( &array10 )[10] ) {
			V vect;

			vect.assign( array10, array10 + 10 );
			std::cout << "vect.size() = " << vect.size() << std::endl;
			utls.print_vec( vect );

			vect.assign( array10, array10 + 5 );
			std::cout << "vect.size() = " << vect.size() << std::endl;
			utls.print_vec( vect );

			vect.assign( 100, array10[0] );
			std::cout << "vect.size() = " << vect.size() << std::endl;
			utls.print_vec( vect );

			vect.assign( 5, array10[1] );
			std::cout << "vect.size() = " << vect.size() << std::endl;
			utls.print_vec( vect );

			std::cout << "S_" << vect.size() << "\n";
			std::cout << "C_" << vect.capacity() << "\n\n";
		}

		template <typename T, class V>
		void test_swap( T ( &array10 )[10], T ( &array7 )[7] ) {
			V vect10;
			V vect7;

			vect10.assign( array10, array10 + 10 );
			vect7.assign( array7, array7 + 7 );
			utls.print_vec( vect10 );
			utls.print_vec( vect7 );
			std::cout << "Swapping" << std::endl;
			vect10.swap( vect7 );
			utls.print_vec( vect10 );
			utls.print_vec( vect7 );
		}

		template <class VI, class VA>
		void test_tot() {
			std::cout << "Test on vector<int>" << std::endl;
			int array10_int[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
			int array7_int[7] = { 111, 222, 333, 444, 555, 666, 777 };
			test_with<int, VI>( array10_int, array7_int );
			test_assign<int, VI>( array10_int );
			test_swap<int, VI>( array10_int, array7_int );

			std::cout << std::endl;

			std::cout << "Test on vector<A>" << std::endl;
			A array10_A[10];
			for ( int i = 0; i < 10; i++ )
				array10_A[i] = array10_int[i];
			A array7_A[7];
			for ( int i = 0; i < 7; i++ )
				array7_A[i] = array7_int[i];
			test_with<A, VA>( array10_A, array7_A );
			test_assign<A, VA>( array10_A );
			test_swap<A, VA>( array10_A, array7_A );
		}

		template <class VI, class VA>
		void file_in_out( std::string out_name ) {
			std::ofstream		out( out_name );
			std::streambuf* coutbuf = std::cout.rdbuf();
			std::cout.rdbuf( out.rdbuf() );
			test_tot<VI, VA>();
			std::cout.rdbuf( coutbuf );
		}
};

int main() {
	test_modifier test;
	return 0;
}
