#include "tester_utils.hpp"

template <class Iterator>
void iter( Iterator begin, Iterator end, void ( *f )( typename Iterator::value_type& ) ) {
	for ( Iterator it = begin; it != end; ++it ) {
		f( *it );
	}
}

template <class T>
void printElem( T& elem ) {
	std::cout << elem << " ";
}

template <class V>
void test() {
	int ret;
	V vect( 6, 1 );
	vect.push_back( 0 );
	vect.push_back( 1 );
	vect[2] = 2;
	std::cout << "size = " << vect.size() << std::endl;
	std::cout << "capacity = " << vect.capacity() << std::endl;
	try {
		ret = vect.at( 10 );
	} catch ( std::exception const& e ) {
		std::cout << e.what() << std::endl;
	}

	V vectIter( vect.begin(), vect.end() - 1 );
	iter( vect.begin(), vect.end(), printElem );
	std::cout << std::endl;
	iter( vectIter.begin(), vectIter.end(), printElem );
	std::cout << std::endl;
}

template <class V>
void file_out( std::string out_name ) {
	std::ofstream		out( out_name );
	std::streambuf* coutbuf = std::cout.rdbuf();
	std::cout.rdbuf( out.rdbuf() );
	test<V>();
	std::cout.rdbuf( coutbuf );
}

int main() {
	file_out<ft::vector<int> >( FT );
	file_out<std::vector<int> >( STD );
	return 0;
}
