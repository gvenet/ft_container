#ifndef BST_REVERSE_ITERATOR_HPP
#define BST_REVERSE_ITERATOR_HPP

#include "../iterator/iterator_traits.hpp"
#include "bst_iterator.hpp"

namespace ft {
template <class Node>
class bst_reverse_iterator {
	public:
		typedef typename Node::value_type																								 value_type;
		typedef typename ft::Iterator<bidirectional_iterator_tag, value_type>::pointer	 pointer;
		typedef typename ft::Iterator<bidirectional_iterator_tag, value_type>::reference reference;
		typedef typename ft::Iterator<bidirectional_iterator_tag, value_type>::difference_type
									difference_type;
		typedef Node* node_pointer;

		bst_reverse_iterator() : _elem() { }
		bst_reverse_iterator( node_pointer node ) : _elem( node ) { }
		bst_reverse_iterator( bst_iterator<Node> it ) : _elem( it.base() ) { }
		bst_reverse_iterator( const bst_reverse_iterator& op ) { *this = op; }
		bst_reverse_iterator& operator=( const bst_reverse_iterator& op ) {
			_elem = op._elem;
			return *this;
		}
		reference operator*() const { return const_cast<reference>( _elem->value ); }
		pointer		operator->() const { return &( const_cast<reference>( _elem->value ) ); }

		bst_reverse_iterator& operator--( void ) {
			_elem = _elem->succ;
			return ( *this );
		}

		bst_reverse_iterator operator--( int ) {
			bst_reverse_iterator tmp( *this );

			this->operator--();
			return ( tmp );
		}

		bst_reverse_iterator& operator++( void ) {
			_elem = _elem->pred;
			return ( *this );
		}

		bst_reverse_iterator operator++( int ) {
			bst_reverse_iterator tmp( *this );

			this->operator++();
			return ( tmp );
		}
		bool operator!=( const bst_reverse_iterator& rhs ) const { return _elem != rhs.base(); }

		operator bst_reverse_iterator<const Node>() const {
			return ( bst_reverse_iterator<const Node>( _elem ) );
		}

		node_pointer base() const { return _elem; }

	private:
		node_pointer _elem;
};

template <typename T>
bool operator==( const bst_reverse_iterator<T>& lhs, const bst_reverse_iterator<T>& rhs ) {
	return lhs.base() == rhs.base();
}

template <typename T_L, typename T_R>
bool operator==( const bst_reverse_iterator<T_L>& lhs, const bst_reverse_iterator<T_R>& rhs ) {
	return lhs.base() == rhs.base();
}

template <typename T>
bool operator!=( const bst_reverse_iterator<T>& lhs, const bst_reverse_iterator<T>& rhs ) {
	return lhs.base() != rhs.base();
}

template <typename T_L, typename T_R>
bool operator!=( const bst_reverse_iterator<T_L>& lhs, const bst_reverse_iterator<T_R>& rhs ) {
	return lhs.base() != rhs.base();
}

} // namespace ft
#endif