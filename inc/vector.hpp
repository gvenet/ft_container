#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <memory>

#include "iterator/random_access_iterator.hpp"
#include "iterator/reverse_iterator.hpp"
#include "utils/algorithm.hpp"

namespace ft {

template <class T, class Alloc = std::allocator<T> >
class vector {
	public:
		typedef T																						 value_type;
		typedef Alloc																				 allocator_type;
		typedef typename allocator_type::reference					 reference;
		typedef typename allocator_type::const_reference		 const_reference;
		typedef typename allocator_type::pointer						 pointer;
		typedef typename allocator_type::const_pointer			 const_pointer;
		typedef ft::random_access_iterator<value_type>			 iterator;
		typedef ft::random_access_iterator<const value_type> const_iterator;
		typedef ft::reverse_iterator<iterator>							 reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>				 const_reverse_iterator;
		typedef typename allocator_type::size_type					 size_type;
		typedef typename allocator_type::difference_type		 difference_type;

		vector( const allocator_type& alloc = allocator_type() )
				: _alloc( alloc ), _start( nullptr ), _end( nullptr ), _end_capacity( nullptr ) { }

		vector( size_type n, const value_type& val = value_type(),
						const allocator_type& alloc = allocator_type() )
				: _alloc( alloc ) {
			_start = _alloc.allocate( n );
			_end_capacity = _start + n;
			_end = _start;
			while ( n-- ) {
				_alloc.construct( _end, val );
				_end++;
			}
		}

		template <class InputIterator>
		vector( InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(),
						typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* =
								nullptr )
				: _alloc( alloc ) {
			size_type n = last - first;
			iterator	it = first;

			_start = _alloc.allocate( n );
			_end = _start;
			for ( size_type i = 0; i < n; i++ ) {
				_alloc.construct( _start + i, *( first + i ) );
				_end++;
			}
			_end_capacity = _end;
		}

		vector( const vector& x ) : _start( nullptr ), _end( nullptr ), _end_capacity( nullptr ) {
			*this = x;
		}

		~vector() {
			// std::cout << "C_" << this->capacity() << " "
			// 					<< "S_" << this->size() << "\n";
			// std::cout << size() << "___\n";
			_dealloc();
		}
		vector& operator=( const vector& x ) {
			_dealloc();
			_start = _alloc.allocate( x.capacity() );
			_end = _start + x.size();
			_end_capacity = _end;
			for ( size_type i = 0; i < this->size(); i++ ) {
				_alloc.construct( _start + i, x.at( i ) );
			}
			return *this;
		}

		////////////////////////////////////ITERATORS
		iterator begin() { return ( _start ); }

		const_iterator begin() const { return ( _start ); };

		iterator end() { return ( _end ); }

		const_iterator end() const { return ( _end ); }

		reverse_iterator rbegin() { return ( reverse_iterator( this->end() ) ); }

		const_reverse_iterator rbegin() const { return ( const_reverse_iterator( this->end() ) ); }

		reverse_iterator rend() { return ( reverse_iterator( this->begin() ) ); }

		const_reverse_iterator rend() const { return ( const_reverse_iterator( this->begin() ) ); }

		////////////////////////////////////CAPACITY
		size_type size() const { return ( _end - _start ); }

		size_type max_size() const {
			size_type maxVal = std::numeric_limits<size_type>::max() / sizeof( value_type );
			size_type maxAlloc = std::numeric_limits<size_type>::max() / 2;
			if ( maxVal > maxAlloc )
				return maxAlloc;
			return maxVal;
		}

		void resize( size_type sz, const value_type val = value_type() ) {
			pointer		new_start;
			size_type next_capacity;

			if ( sz > this->capacity() ) {
				( sz > this->capacity() * 2 ) ? next_capacity = sz : next_capacity = this->capacity() * 2;
				new_start = _alloc.allocate( next_capacity );
				for ( size_type i = 0; i < sz; i++ )
					_alloc.construct( new_start + i, ( i < this->size() ) ? *( _start + i ) : val );
				_dealloc();
				_start = new_start;
				_end_capacity = new_start + next_capacity;
			} else if ( sz > this->size() )
				for ( size_type i = this->size(); i < sz; i++ )
					_alloc.construct( _start + i, val );
			_end = _start + sz;
		}

		size_type capacity() const { return ( _end_capacity - _start ); }

		bool empty() const { return ( !this->size() ); }

		void reserve( size_type n ) {
			pointer		new_start;
			size_type size = this->size();

			if ( n > this->capacity() ) {
				new_start = _alloc.allocate( n );
				for ( size_type i = 0; i < size; i++ ) {
					_alloc.construct( new_start + i, *( _start + i ) );
				}
				_dealloc();
				_start = new_start;
				_end = _start + size;
				_end_capacity = _start + n;
			}
		}

		////////////////////////////////////ELEMENTS ACCES

		reference operator[]( size_type n ) { return *( _start + n ); }

		const_reference operator[]( size_type n ) const { return *( _start + n ); }

		reference at( size_type n ) { return *( _start + n ); }

		const_reference at( size_type n ) const { return *( _start + n ); }

		reference front() { return *( _start ); }

		const_reference front() const { return *( _start ); }

		reference back() { return *( _end - 1 ); }

		const_reference back() const { return *( _end - 1 ); }

		////////////////////////////////////MODIFIERS

		template <class InputIterator>
		void assign( InputIterator first, InputIterator last,
								 typename ft::enable_if<!is_integral<InputIterator>::value, InputIterator>::type* =
										 nullptr ) {
			pointer		new_start;
			size_type n = last - first;

			new_start = _alloc.allocate( n );
			for ( size_type i = 0; i < n; i++ ) {
				_alloc.construct( new_start + i, *( first + i ) );
			}
			_dealloc();
			_start = new_start;
			_end = _start + n;
			_end_capacity = _end;
		} // range(1)

		void assign( size_type n, const value_type& val ) {
			pointer new_start;

			if ( n > this->capacity() ) {
				new_start = _alloc.allocate( n );
				for ( size_type i = 0; i < n; i++ ) {
					_alloc.construct( new_start + i, val );
				}
				_dealloc();
				_start = new_start;
				_end = _start + n;
				_end_capacity = _end;
			} else {
				for ( size_type i = 0; i < n; i++ ) {
					_alloc.construct( _start + i, val );
				}
				_end = _start + n;
			}
		} // fill (2)

		void push_back( const value_type& x ) { this->insert( _end, x ); }

		// void pop_back() { this->erase( _end - 1 ); }

		void pop_back() {
			_end--;
			_alloc.destroy( _end );
		}

		iterator insert( iterator position, const value_type& val ) {
			// size_type next_capacity = 1;
			// size_type pos_len = &( *position ) - _start;

			// if ( this->size() < this->capacity() ) {
			// 	for ( size_type i = 0; i < ( this->size() - pos_len ); i++ ) {
			// 		_alloc.construct( _end - i, *( _end - i - 1 ) );
			// 	}
			// 	_end++;
			// 	_alloc.construct( &( *position ), val );
			// } else {
			// 	pointer new_start = pointer();
			// 	pointer new_end = pointer();
			// 	pointer new_end_capacity = pointer();

			// 	if ( this->size() * 2 > 0 )
			// 		next_capacity = this->size() * 2;

			// 	new_start = _alloc.allocate( next_capacity );
			// 	new_end = new_start + this->size() + 1;
			// 	new_end_capacity = new_start + next_capacity;

			// 	for ( size_type i = 0; i < pos_len; i++ )
			// 		_alloc.construct( new_start + i, *( _start + i ) );
			// 	_alloc.construct( new_start + pos_len, val );
			// 	for ( size_type i = 0; i < this->size() - pos_len; i++ )
			// 		_alloc.construct( new_end - i - 1, *( _end - i - 1 ) );
			// 	_dealloc();
			// 	_start = new_start;
			// 	_end = new_end;
			// 	_end_capacity = new_end_capacity;
			// }
			// return ( iterator( _start + pos_len ) );

			size_type pos_len = &( *position ) - _start;
			insert( position, 1, val );
			return ( iterator( _start + pos_len ) );

		} // single element (1)

		// void insert( iterator position, size_type n, const value_type& val ) {
		// 	if ( !this->size() ) {
		// 		_start = _alloc.allocate( 1 );
		// 		_end = _end_capacity = _start;
		// 	}
		// 	for ( size_type i = 0; i < n; i++ ) {
		// 		position = this->insert( position, val );
		// 	}
		// }

		void insert( iterator position, size_type n, const value_type& val ) {
			_allocate();

			(void)val;
			(void)n;
			(void)position;
		}

		void _allocate() {
			size_type next_capacity = 1;
			if ( _start == _end_capacity ) {
				_start = _alloc.allocate( next_capacity );
				_end = _start;
				_end_capacity = _start + next_capacity;
			} else if ( _end == _end_capacity ) {
				pointer new_start;
				pointer new_end;
				pointer new_end_capacity;

				next_capacity = capacity() * 2;
				new_start = _alloc.allocate( next_capacity );
				new_end = _end + 1;
				new_end_capacity = new_start + next_capacity;
				for ( size_type i = 0; i < size(); i++ ) {
					_alloc.construct( new_start + i, *( _start + i ) );
					_end++;
				}
				_dealloc();
				_start = new_start;
				_end = new_end;
				_end_capacity = new_end_capacity;
			}
		}

		template <class InputIterator>
		void
		insert( iterator position, InputIterator first, InputIterator last,
						typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* =
								nullptr ) {
			pointer		new_start;
			pointer		new_end;
			pointer		new_end_capacity;
			size_type new_size = this->size() + ( last - first );
			size_type pos_bound = position.base() - _start;
			size_type i = 0;

			new_start = _alloc.allocate( new_size );
			new_end = new_start;
			new_end_capacity = new_start + new_size;
			for ( ; i < pos_bound; i++ )
				_alloc.construct( new_end++, *( _start + i ) );
			for ( ; first != last; first++ )
				_alloc.construct( new_end++, *first );
			for ( ; i < this->size(); i++ )
				_alloc.construct( new_end++, *( _start + i ) );
			this->_dealloc();
			_start = new_start;
			_end = new_end;
			_end_capacity = new_end_capacity;
		}

		iterator erase( iterator position ) {
			size_type pos_len = &( *position ) - _start;
			size_type n = ( this->size() - pos_len );
			for ( size_type i = 0; i < n; i++ )
				_alloc.construct( _start + i + pos_len, *( _start + i + 1 + pos_len ) );
			_alloc.destroy( _end - 1 );
			_end--;
			return ( iterator( _start + pos_len ) );
		}

		iterator erase( iterator first, iterator last ) {
			size_type first_len = &( *first ) - _start;
			size_type it_range = ( last - first );
			size_type new_size = this->size() - it_range;
			size_type new_capacity = this->capacity();
			pointer		new_start;

			new_start = _alloc.allocate( new_capacity );
			for ( size_type i = 0; i < new_size; i++ ) {
				_alloc.construct( new_start + i,
													( i < first_len ) ? *( _start + i ) : *( _start + i + it_range ) );
			}
			this->_dealloc();
			_end_capacity = new_start + new_capacity;
			_end = new_start + new_size;
			_start = new_start;

			return ( iterator( _start ) );
		}

		void swap( vector& x ) {
			vector<T> tmp;

			tmp = x;
			x = *this;
			*this = tmp;
		}

		void clear() {
			size_type size = this->size();
			for ( size_type i = 0; i < size; i++ ) {
				_end--;
				_alloc.destroy( _end );
			}
		}

		////////////////////////////////////ALLOCATOR
		allocator_type get_allocator() const { return _alloc; };

	private:
		allocator_type _alloc;
		pointer				 _start;
		pointer				 _end;
		pointer				 _end_capacity;

		void _dealloc( void ) {
			this->clear();
			_alloc.deallocate( _start, this->capacity() );
		}
};

// https://www.cplusplus.com/reference/vector/vector/operators/

template <class T, class Alloc>
void swap( vector<T, Alloc>& x, vector<T, Alloc>& y ) {
	x.swap( y );
}

template <class T, class Alloc>
bool operator==( const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs ) {
	typename vector<T>::const_iterator lhsIt = lhs.begin();
	typename vector<T>::const_iterator rhsIt = rhs.begin();

	while ( lhsIt != lhs.end() )
		if ( lhs.size() != rhs.size() || *lhsIt++ != *rhsIt++ )
			return false;
	return true;
}

template <class T, class Alloc>
bool operator!=( const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs ) {
	return ( !( lhs == rhs ) );
}

template <class T, class Alloc>
bool operator<( const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs ) {
	typename vector<T>::const_iterator lhsItb = lhs.begin();
	typename vector<T>::const_iterator lhsIte = lhs.end();
	typename vector<T>::const_iterator rhsItb = rhs.begin();
	typename vector<T>::const_iterator rhsIte = rhs.end();

	return ft::lexicographical_compare( lhsItb, lhsIte, rhsItb, rhsIte );
}

template <class T, class Alloc>
bool operator<=( const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs ) {
	return ( !( rhs < lhs ) );
}

template <class T, class Alloc>
bool operator>( const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs ) {
	return ( rhs < lhs );
}

template <class T, class Alloc>
bool operator>=( const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs ) {
	return ( !( lhs < rhs ) );
}

} // namespace ft
#endif
