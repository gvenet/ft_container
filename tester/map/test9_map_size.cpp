#include "tester_utils.hpp"

struct StaticCounter {
		static int total;
		int				 idx;
		StaticCounter() { idx = StaticCounter::total++; }
		StaticCounter( StaticCounter const& ) { idx = StaticCounter::total++; }
		StaticCounter& operator=( StaticCounter const& ) { return *this; }
		~StaticCounter() { StaticCounter::total--; }
};

int StaticCounter::total = 0;

template <class M, class P_ptr>
class test_size {
	public:
		test_size( P_ptr* make_pair ) : _make_pair( make_pair ) { }

		void t_size() {
			M m;
			for ( int i = 0; i < 10; ++i ) {
				m.insert( _make_pair( i, StaticCounter() ) );
				std::cout << "Map size = " << m.size() << std::endl;
				std::cout << "Actual size = " << StaticCounter::total << std::endl;
			}
			for ( int i = 0; i < 5; ++i ) {
				m.erase( i );
				std::cout << "Map size = " << m.size() << std::endl;
				std::cout << "Actual size = " << StaticCounter::total << std::endl;
			}
			m.clear();
			std::cout << "Map size = " << m.size() << std::endl;
			std::cout << "Actual size = " << StaticCounter::total << std::endl;
		}

		void test() {
			std::cout << "--- Test size ---" << std::endl;
			t_size();
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
		P_ptr*			 _make_pair;
};

int main() {
	typedef ft::map<int, StaticCounter>	 ft_map;
	typedef ft::pair<int, StaticCounter> ft_pair;
	typedef ft_pair( ft_pair_ptr )( int, StaticCounter );

	typedef std::map<int, StaticCounter>	std_map;
	typedef std::pair<int, StaticCounter> std_pair;
	typedef std_pair( std_pair_ptr )( int, StaticCounter );

	test_size<ft_map, ft_pair_ptr>	 ft_size( &ft::make_pair );
	test_size<std_map, std_pair_ptr> std_size( &std::make_pair );
}