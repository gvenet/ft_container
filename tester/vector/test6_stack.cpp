#include "tester_utils.hpp"
#include <ios>

template <typename T, size_t n>
T* array_end( T ( &array )[n] ) {
	return array + n;
}

template <class StackType>
void test_stack1( typename StackType::value_type ( &array )[4] ) {
	StackType s;

	std::cout << std::boolalpha;
	std::cout << "--- Test stack 1 ---" << std::endl;

	std::cout << "s.empty() = " << s.empty() << std::endl;
	std::cout << "s.size() = " << s.size() << std::endl;
	for ( int i = 0; i < 4; ++i ) {
		s.push( array[i] );
		std::cout << "s.top() = " << s.top() << std::endl;
	}
	std::cout << "s.empty() = " << s.empty() << std::endl;
	std::cout << "s.size() = " << s.size() << std::endl;
	for ( int i = 0; i < 4; ++i ) {
		s.pop();
		if ( i < 4 - 1 )
			std::cout << "s.top() = " << s.top() << std::endl;
	}
	std::cout << "s.empty() = " << s.empty() << std::endl;
	std::cout << "s.size() = " << s.size() << std::endl;
}

template <class StackType>
void test_stack2( typename StackType::container_type& c ) {
	StackType s( c );

	std::cout << "--- Test stack 2 ---" << std::endl;

	std::cout << "s.empty() = " << s.empty() << std::endl;
	std::cout << "s.size() = " << s.size() << std::endl;
	for ( typename StackType::size_type i = 0; i < c.size(); ++i ) {
		s.pop();
		if ( i < c.size() - 1 )
			std::cout << "s.top() = " << s.top() << std::endl;
	}
	std::cout << "s.empty() = " << s.empty() << std::endl;
	std::cout << "s.size() = " << s.size() << std::endl;
}

template <class S2>
void all_comparisons( std::vector<int> const& va, std::vector<int> const& vb ) {
	S2 a( va );
	S2 b( vb );
	std::cout << std::boolalpha;
	std::cout << "a == b : " << ( a == b ) << std::endl;
	std::cout << "a != b : " << ( a != b ) << std::endl;
	std::cout << "a < b : " << ( a < b ) << std::endl;
	std::cout << "a > b : " << ( a > b ) << std::endl;
	std::cout << "a >= b : " << ( a >= b ) << std::endl;
	std::cout << "a <= b : " << ( a <= b ) << std::endl;
	std::cout << std::noboolalpha;
}

template <class S2>
void test_relational() {
	int							 v1_values[] = { 0, 1, 2, 3 };
	std::vector<int> v1( v1_values, array_end( v1_values ) );
	int							 v1b_values[] = { 0, 1, 2, 3 };
	std::vector<int> v1b( v1b_values, array_end( v1b_values ) );
	int							 v2_values[] = { 0, 1, 2, 3, 4 };
	std::vector<int> v2( v2_values, array_end( v2_values ) );
	int							 v2b_values[] = { 0, 1, 2 };
	std::vector<int> v2b( v2b_values, array_end( v2b_values ) );
	int							 v3_values[] = { 0, 1, 10 };
	std::vector<int> v3( v3_values, array_end( v3_values ) );
	int							 v3b_values[] = { 0, 1, 1 };
	std::vector<int> v3b( v3b_values, array_end( v3b_values ) );

	all_comparisons<S2>( v1, v1b );
	all_comparisons<S2>( v1, v2 );
	all_comparisons<S2>( v1, v2b );
	all_comparisons<S2>( v1, v3 );
	all_comparisons<S2>( v1, v3b );
}

template <class S1, class S2>
void test() {
	int													array_int[] = { 42, 71, 33, 0 };
	typename S1::container_type default_container_int( array_int, array_int + sizeof( array_int ) /
																																								sizeof( int ) );
	std::vector<int> vect_int( array_int, array_int + sizeof( array_int ) / sizeof( int ) );

	test_stack1<S1>( array_int );
	test_stack2<S1>( default_container_int );
	test_stack1<S2>( array_int );
	test_stack2<S2>( vect_int );
	test_relational<S2>();
}

template <class S1, class S2>
void file_out( std::string id ) {
	std::ofstream		out( id );
	std::streambuf* coutbuf = std::cout.rdbuf();
	std::cout.rdbuf( out.rdbuf() );
	test<S1, S2>();
	std::cout.rdbuf( coutbuf );
}

int main() {
	file_out<ft::stack<int>, ft::stack<int, std::vector<int> > >( FT );
	file_out<std::stack<int>, std::stack<int, std::vector<int> > >( STD );
}