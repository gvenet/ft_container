#include "map.hpp"
#include <iostream>

#include <map>

template <class M>
struct custom_map : public M {

		custom_map() {
			this->insert( std::make_pair( 3, 0 ) );
			this->insert( std::make_pair( 0, 0 ) );
			this->insert( std::make_pair( 1, 0 ) );
			this->insert( std::make_pair( 2, 0 ) );
			this->insert( std::make_pair( 10, 0 ) );
			this->insert( std::make_pair( 9, 0 ) );
			this->insert( std::make_pair( 8, 0 ) );
			this->insert( std::make_pair( 7, 0 ) );
		}

		virtual ~custom_map() { }

		void print() {
			if ( this->empty() ) {
				std::cout << "empty\n";
			} else {
				for ( typename custom_map::iterator it = this->begin(); it != this->end(); it++ )
					std::cout << it->first << " ";
				std::cout << "\n";
			}
			std::cout << "\n";
		}
};

template <class M>
void routine() {
	M m;

	m.print();
	std::cout << m.lower_bound( 2 )->first << " " << m.upper_bound( 7 )->first << "\n";

	m.erase( m.lower_bound( 2 ), m.upper_bound( 7 ) );
	// m.erase( m.begin(), m.end() );
	m.print();
}

int main() {
	typedef custom_map<std::map<int, int> > std_map;
	typedef custom_map<ft::map<int, int> >	ft_map;

	routine<std_map>();
	routine<ft_map>();

}
