#include "tester_utils.hpp"

class test_correction {
	public:
		typedef std::map<int, int>								 std_mapi;
		typedef std::map<std::string, std::string> std_maps;
		typedef std::pair<const int, int>*				 std_pair;
		typedef ft::map<int, int>									 ft_mapi;
		typedef ft::map<std::string, std::string>	 ft_maps;
		typedef ft::pair<const int, int>*					 ft_pair;

		template <class MS>
		void test_only_one_key() {
			MS m;

			m["chat"] = "chien";
			m["chat"] = "cheval";
			m["chat"] = "ça va ?";
			std::cout << "Map is of size " << m.size() << ": ";
			utls.print_map( m );
		}

		template <class MI>
		void test_container_ordered() {
			MI m;

			m[3] = 3;
			m[0] = 0;
			m[4] = 4;
			m[2] = 2;
			m[1] = 1;
			std::cout << "Should be ordered : ";
			utls.print_map( m );
		}

		template <class MI>
		void test_iterator_valid() {
			MI m;

			for ( int i = 0; i < 5; ++i ) {
				m[i] = i;
			}
			typename MI::iterator it = m.begin();
			++it;
			++it;
			std::cout << "Map is : ";
			utls.print_map( m );
			std::cout << "Iterator is ponting at " << *it << std::endl;
			std::cout << "Erasing keys 1 and 3" << std::endl;
			m.erase( 1 );
			m.erase( 3 );
			std::cout << "Iterator is ponting at " << *it << std::endl;
			std::cout << "it++;" << std::endl;
			it++;
			std::cout << "Iterator is ponting at " << *it << std::endl;
			std::cout << "it--; it--;" << std::endl;
			it--;
			it--;
			std::cout << "Iterator is ponting at " << *it << std::endl;
		}

		template <class MI, class P>
		void test_swap_move_only_pointers() {
			MI m1;
			MI m2;
			P	 addr1;
			P	 addr2;

			m1[0] = 0;
			std::cout << "Before swap:" << std::endl;
			std::cout << "m1 = ";
			utls.print_map( m1 );
			std::cout << " and m2 = ";
			utls.print_map( m2 );
			// std::cout << "Address of " << *m1.begin() << " : " << &*m1.begin() << std::endl;
			addr1 = &*m1.begin();
			m1.swap( m2 );
			std::cout << "After swap:" << std::endl;
			std::cout << "m1 = ";
			utls.print_map( m1 );
			std::cout << "and m2 = ";
			utls.print_map( m2 );
			// std::cout << "Address of " << *m2.begin() << " : " << &*m2.begin() << std::endl;
			addr2 = &*m2.begin();
			std::cout << "Address before and after are equal ? " << ( addr1 == addr2 ) << std::endl;
		}

		template <class MI, class MS, class P>
		void file_out( std::string out_name ) {
			std::ofstream		out( out_name );
			std::streambuf* coutbuf = std::cout.rdbuf();
			std::cout.rdbuf( out.rdbuf() );
			std::boolalpha( std::cout );
			test_only_one_key<MS>();
			std::cout << std::endl;
			test_container_ordered<MI>();
			std::cout << std::endl;
			test_iterator_valid<MI>();
			std::cout << std::endl;
			test_swap_move_only_pointers<MI, P>();
			std::cout.rdbuf( coutbuf );
		}

		void output() {
			file_out<ft_mapi, ft_maps, ft_pair>( "ft.txt" );
			file_out<std_mapi, std_maps, std_pair>( "std.txt" );
		}

	private:
		tester_utils utls;
};

int main() {

	test_correction t_cor;
	t_cor.output();
}
