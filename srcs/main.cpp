#include <iostream>

#include "../inc/map.hpp"
#include "../inc/utils/pair.hpp"
#include <map>
#include <vector>

using namespace ft;

int _new;
int _del = 5;

struct A {
		A() {
			// std::cout << "___new_\n";
			_new++;
			m = new int();
		}
		A( A const& x ) {
			std::cout << "___new_\n";
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
			std::cout << "_del___\n";
			_del++;
			delete m;
		}

		friend std::ostream& operator<<( std::ostream& os, A const& a ) { return os << *a.m; }

		int* m;
};

template <class Container>
void print_container( Container const& m ) {
	for ( typename Container::const_iterator it = m.begin(); it != m.end(); ++it ) {
		if ( it != m.begin() )
			std::cout << ", ";
		std::cout << *it;
	}
}
template <class Container>
void print_container_nl( Container const& m ) {
	print_container( m );
	std::cout << std::endl;
}

template <typename T>
void test_with( T ( &array10 )[10], T ( &array7 )[7] ) {
	vector<T> vect;

	// push_back
	for ( int i = 0; i < 10; i++ ) {
		vect.push_back( array10[i] );
		std::cout << vect.size() << std::endl;
		std::cout << vect.back() << std::endl;
	}
	print_container_nl( vect );

	// insert iterator
	vect.insert( vect.begin() + 5, array7, array7 + 3 );

	// insert 1
	typename vector<T>::iterator it = vect.insert( vect.begin(), array7[3] );
	std::cout << *it << std::endl;
	std::cout << it - vect.begin() << std::endl;
	*it = array7[4];

	// insert range
	// vect.insert( vect.end() - 1, array7[5] );
	// vect.insert( vect.begin() + 8, 6, array7[5] );

	print_container_nl( vect );

	// pop_back
	for ( int i = 0; i < 5; i++ ) {
		vect.pop_back();
		std::cout << "back = " << vect.back() << "\t";
		std::cout << "size = " << vect.size() << "\t";
		std::cout << "capacity = " << vect.capacity() << "\n";
	}
	print_container_nl( vect );

	// erase, clear
	vect.clear();
}

template <typename T>
void test_erase( T ( &array10 )[10] ) {
	vector<T> vect( array10, array_end( array10 ) );

	vect.erase( vect.begin() + 2 );
	print_container_nl( vect );
	vect.erase( vect.begin() + 1, vect.begin() + 4 );
	print_container_nl( vect );
}

// template <typename T>
// void test_assign( T ( &array10 )[10] ) {
// 	vector<T> vect;

// 	vect.assign( array10, array10 + 10 );
// 	std::cout << "vect.size() = " << vect.size() << std::endl;
// 	print_container_nl( vect );

// 	vect.assign( array10, array10 + 5 );
// 	std::cout << "vect.size() = " << vect.size() << std::endl;
// 	print_container_nl( vect );

// 	vect.assign( 100, array10[0] );
// 	std::cout << "vect.size() = " << vect.size() << std::endl;
// 	print_container_nl( vect );

// 	vect.assign( 5, array10[1] );
// 	std::cout << "vect.size() = " << vect.size() << std::endl;
// 	print_container_nl( vect );
// }

// template <typename T>
// void test_swap( T ( &array10 )[10], T ( &array7 )[7] ) {
// 	vector<T> vect10;
// 	vector<T> vect7;

// 	vect10.assign( array10, array10 + 10 );
// 	vect7.assign( array7, array7 + 7 );
// 	print_container_nl( vect10 );
// 	print_container_nl( vect7 );
// 	std::cout << "Swapping" << std::endl;
// 	vect10.swap( vect7 );
// 	print_container_nl( vect10 );
// 	print_container_nl( vect7 );
// }

// int main() {
// 	std::cout << "Test on vector<int>" << std::endl;
// 	int array10_int[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
// 	int array7_int[7] = { 111, 222, 333, 444, 555, 666, 777 };
// 	// test_with<int>( array10_int, array7_int );
// 	// test_assign<int>( array10_int );
// 	// test_swap<int>( array10_int, array7_int );

// 	// std::cout << std::endl;

// 	std::cout << "Test on vector<A>" << std::endl;
// 	A array10_A[10];
// 	for ( int i = 0; i < 10; i++ )
// 		array10_A[i] = array10_int[i];
// 	A array7_A[7];
// 	for ( int i = 0; i < 7; i++ )
// 		array7_A[i] = array7_int[i];
// 	test_with<A>( array10_A, array7_A );
// 	// test_assign<A>( array10_A );
// 	// test_swap<A>( array10_A, array7_A );
// }

// int main() {
// 	typedef vector<A> vec;

// 	vec x;
// 	int array10_int[5] = { 0, 1, 2, 3, 4 };
// 	A		array10_A[5];

// 	for ( int i = 0; i < 5; i++ )
// 		array10_A[i] = array10_int[i];

// 	for ( int i = 0; i < 5; i++ )
// 		x.push_back( array10_A[i] );
// 	// std::cout << x.size() << "__size\n";
// 	// x.insert( x.end() - 3, array10_A[3] );
// 	x.insert( x.end() - 3, 3, array10_A[3] );
// 	// std::cout << x.size() << "__size\n";
// 	// x.insert( x.begin() + 8, 6, array10_A[5] );

// 	// x.pop_back();
// 	// x.clear();

// 	// typedef vector<int> vec;
// 	// vec									x;

// 	// for ( int i = 0; i < 10; i++ )
// 	// 	x.push_back(i);

// 	// x.insert( x.end() - 1, 00 );
// 	// x.insert( x.begin() + 8, 6, 77 );

// 	for ( vec::iterator it = x.begin(); it != x.end(); it++ )
// 		std::cout << *it << " ";
// 	std::cout << "\n";

// 	x.clear();
// 	std::cout << "del : " << _del << "\nnew : " << _new << "\n";
// }

template <class V>
void print( V& v ) {
	for ( typename V::iterator it = v.begin(); it != v.end(); it++ )
		std::cout << *it << " ";
	std::cout << "\n";
	std::cout << v.size() << "_s\n";
	std::cout << v.capacity() << "_c\n\n";
}

template <class V>
V& v_gen( V& v ) {
	for ( int i = 0; i < 10; i++ ) {
		v.push_back( i );
		print( v );
	}
	return v;
}

int main() {
	// typedef std::vector<int> vstd;
	// vstd vs;
	// print( v_gen<std::vector<int> >( vs ) );

	typedef ft::vector<int>	 vfft;
	vfft vf;
	print( v_gen<ft::vector<int> >( vf ) );
}