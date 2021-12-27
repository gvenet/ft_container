#ifndef BST_ITERATOR_HPP
#define BST_ITERATOR_HPP

#include "../iterator/iterator.hpp"

namespace ft {
template <class Node>
class bst_iterator {
	public:
		typedef typename Node::value_type																								 value_type;
		typedef typename ft::Iterator<bidirectional_iterator_tag, value_type>::pointer	 pointer;
		typedef typename ft::Iterator<bidirectional_iterator_tag, value_type>::reference reference;
		typedef typename ft::Iterator<bidirectional_iterator_tag, value_type>::difference_type
									difference_type;
		typedef Node* node_pointer;

		bst_iterator() : _elem() { }

		bst_iterator( node_pointer node ) : _elem( node ) { }

		bst_iterator( const bst_iterator& op ) { *this = op; }

		bst_iterator& operator=( const bst_iterator& op ) {
			_elem = op._elem;
			return *this;
		}

		reference operator*() const { return const_cast<reference>( _elem->value ); }

		pointer operator->() const { return &( const_cast<reference>( _elem->value ) ); }

		node_pointer base() const { return _elem; }

		bst_iterator& operator++( void ) {
			// if ( _elem->right ) {
			// 	_elem = _elem->right;
			// 	while ( _elem->left && _elem->left->is_limit == false )
			// 		_elem = _elem->left;
			// } else if ( _elem == _elem->parent->left ) {
			// 	_elem = _elem->parent;
			// } else {
			// 	while ( _elem == _elem->parent->right )
			// 		_elem = _elem->parent;
			// 	_elem = _elem->parent;
			// }
			_elem = _elem->succ;
			return ( *this );
		}

		bst_iterator operator++( int ) {
			bst_iterator tmp( *this );
									 operator++();
			return ( tmp );
		}

		bst_iterator& operator--( void ) {
			// if ( _elem->left ) {
			// 	_elem = _elem->left;
			// 	while ( _elem->right && _elem->right->is_limit == false )
			// 		_elem = _elem->right;
			// } else if ( _elem == _elem->parent->right ) {
			// 	_elem = _elem->parent;
			// } else {
			// 	while ( _elem == _elem->parent->left )
			// 		_elem = _elem->parent;
			// 	_elem = _elem->parent;
			// }
			_elem = _elem->pred;
			return ( *this );
		}

		bst_iterator operator--( int ) {
			bst_iterator tmp( *this );
									 operator--();
			return ( tmp );
		}
		bool operator!=( const bst_iterator& rhs ) const { return _elem != rhs.base(); }

		operator bst_iterator<const Node>() const { return ( bst_iterator<const Node>( _elem ) ); }

	private:
		node_pointer _elem;
};

template <typename T>
bool operator==( const bst_iterator<T>& lhs, const bst_iterator<T>& rhs ) {
	return lhs.base() == rhs.base();
}

template <typename T_L, typename T_R>
bool operator==( const bst_iterator<T_L>& lhs, const bst_iterator<T_R>& rhs ) {
	return lhs.base() == rhs.base();
}

template <typename T>
bool operator!=( const bst_iterator<T>& lhs, const bst_iterator<T>& rhs ) {
	return lhs.base() != rhs.base();
}

template <typename T_L, typename T_R>
bool operator!=( const bst_iterator<T_L>& lhs, const bst_iterator<T_R>& rhs ) {
	return lhs.base() != rhs.base();
}

} // namespace ft
#endif