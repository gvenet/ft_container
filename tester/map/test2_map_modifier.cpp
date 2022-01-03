#include "tester_utils.hpp"

struct test_modifier {
		typedef ft::map<int, int>	 ft_map;
		typedef ft::pair<int, int> ft_pair;
		typedef ft_pair( ft_pair_ptr )( int, int );
		typedef void( ft_func_type )( ft_pair_ptr );
		typedef std::map<int, int>	std_map;
		typedef std::pair<int, int> std_pair;
		typedef std_pair( std_pair_ptr )( int, int );
		typedef void( std_func_type )( std_pair_ptr );

		template <class M, class P>
		void test_insert( P* make_pair ) {
			M m0;
			std::boolalpha( std::cout );
			for ( int i = 0; i < 5; ++i )
				insert( m0, i, i, make_pair );
			for ( int i = 0; i < 5; ++i )
				insert( m0, i, 2 * i, make_pair );
			insert_many<M, P>( m0, 10000, make_pair );
		}

		template <class M, class P>
		void insert( M& m, int k, int v, P* make_pair ) {
			std::cout << "Inserting " << make_pair( k, v ) << std::endl;
			std::cout << "Was present : " << m.insert( make_pair( k, v ) ).second << std::endl;
			std::cout << "Iterator points to " << *( m.insert( make_pair( k, v ) ).first ) << std::endl;
		}

		template <class M, class P>
		void insert_many( M& container, int n, P* make_pair ) {
			for ( int i = 0; i < n; ++i ) {
				container.insert( make_pair( i, i ) );
			}
		}

		template <class M>
		void test_erase() {
			M m;

			for ( int i = 0; i < 10; ++i ) {
				m[i] = i;
			}

			std::cout << "m.erase(2) = " << m.erase( 2 ) << std::endl;
			std::cout << "m.erase(2) = " << m.erase( 2 ) << std::endl;
			std::cout << "erase begin/ end--\n";
			m.erase( m.begin() );
			m.erase( --( m.end() ) );
			utls.print_map( m );

			typename M::iterator it[2] = { m.begin(), m.end() };
			it[0]++;
			it[0]++;
			it[1]--;
			it[1]--;

			std::cout << "erase : " << *it[0] << " " << *it[1] << std::endl;
			m.erase( it[0], it[1] );
			utls.print_map( m );

			std::cout << "size = " << m.size() << std::endl;
		}

		template <class M>
		void test_swap() {
			M m1, m2;

			for ( int i = 0; i < 10; ++i ) {
				m1[i] = i;
				m2[i] = 10 + i;
			}
			std::cout << "m1 = ";
			utls.print_map( m1 );
			std::cout << "m2 = ";
			utls.print_map( m2 );
			std::cout << "m1.swap(m2)..." << std::endl;
			m1.swap( m2 );
			std::cout << "m1 = ";
			utls.print_map( m1 );
			std::cout << "m2 = ";
			utls.print_map( m2 );
			std::cout << "swap(m1, m2)..." << std::endl;
			swap( m1, m2 );
			std::cout << "m1 = ";
			utls.print_map( m1 );
			std::cout << "m2 = ";
			utls.print_map( m2 );
		}

		template <class M>
		void test_clear() {
			srand( time( NULL ) );

			std::vector<int> v = utls.random_tab(1000);
			M m;

			for ( int i = 0; i < v.size(); ++i ) {
				m[i] = v[i];
				if ( i > 0 )
					std::cout << ", ";
			}
			m.clear();
			utls.print_map( m );
			std::cout << m.size();
		}

		template <class M, class P>
		void file_out( std::string out_name, P* make_pair ) {
			std::ofstream		out( out_name );
			std::streambuf* coutbuf = std::cout.rdbuf();
			std::cout.rdbuf( out.rdbuf() );
			std::cout << "--- Test insert ---" << std::endl;
			test_insert<M, P>( make_pair );
			std::cout << "--- Test erase ---" << std::endl;
			test_erase<M>();
			std::cout << "--- Test swap ---" << std::endl;
			test_swap<M>();
			std::cout << "--- Test clear ---" << std::endl;
			test_clear<M>();
			std::cout.rdbuf( coutbuf );
		}

		void output() {
			file_out<ft::map<int, int>, ft_pair_ptr>( "ft.txt", &ft::make_pair );
			file_out<std::map<int, int>, std_pair_ptr>( "std.txt", &std::make_pair );
		}

	private:
		tester_utils utls;
};

int main() {

	test_modifier modifier;
	modifier.output();
}
