#ifndef BIDIRECTIONAL_ITERATOR_HPP
#define BIDIRECTIONAL_ITERATOR_HPP

#include "iterator.hpp"

namespace ft {

template <typename T>
class bidirectional_iterator : ft::Iterator<ft::bidirectional_iterator_tag, T> {
	public:
		typedef typename ft::Iterator<ft::bidirectional_iterator_tag, T>::iterator_category
																																								 iterator_category;
		typedef typename ft::Iterator<ft::bidirectional_iterator_tag, T>::value_type value_type;
		typedef
				typename ft::Iterator<ft::bidirectional_iterator_tag, T>::difference_type difference_type;
		typedef T*																																		pointer;
		typedef T&																																		reference;

		bidirectional_iterator( void ) : _elem( nullptr ) { }

		bidirectional_iterator( pointer elem ) : _elem( elem ) { }

		bidirectional_iterator( const bidirectional_iterator& op ) : _elem( op._elem ) { }

		bidirectional_iterator& operator=( const bidirectional_iterator& op ) {
			if ( this == &op )
				return ( *this );
			this->_elem = op._elem;
			return ( *this );
		}
		virtual ~bidirectional_iterator() { }

		pointer base() const { return ( this->_elem ); }

		reference operator*( void ) const { return ( *_elem ); }

		pointer operator->( void ) { return &( this->operator*() ); }

		bidirectional_iterator& operator++( void ) {
			_elem++;
			return ( *this );
		}

		bidirectional_iterator operator++( int ) {
			bidirectional_iterator tmp( *this );
														 operator++();
			return ( tmp );
		}

		bidirectional_iterator& operator--( void ) {
			_elem--;
			return ( *this );
		}

		bidirectional_iterator operator--( int ) {
			bidirectional_iterator tmp( *this );
														 operator--();
			return ( tmp );
		}

		operator bidirectional_iterator<const T>() const {
			return ( bidirectional_iterator<const T>( this->_elem ) );
		}

	private:
		pointer _elem;
};

template <typename T>
typename ft::bidirectional_iterator<T>::difference_type
operator==( const ft::bidirectional_iterator<T> lhs, const ft::bidirectional_iterator<T> rhs ) {
	return ( lhs.base() == rhs.base() );
}

template <typename T_L, typename T_R>
typename ft::bidirectional_iterator<T_L>::difference_type
operator==( const ft::bidirectional_iterator<T_L> lhs, const ft::bidirectional_iterator<T_R> rhs ) {
	return ( lhs.base() == rhs.base() );
}

template <typename T>
typename ft::bidirectional_iterator<T>::difference_type
operator!=( const ft::bidirectional_iterator<T> lhs, const ft::bidirectional_iterator<T> rhs ) {
	return ( lhs.base() != rhs.base() );
}

template <typename T_L, typename T_R>
typename ft::bidirectional_iterator<T_L>::difference_type
operator!=( const ft::bidirectional_iterator<T_L> lhs, const ft::bidirectional_iterator<T_R> rhs ) {
	return ( lhs.base() != rhs.base() );
}

} // namespace ft
#endif