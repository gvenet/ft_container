#ifndef REV_ITER
#define REV_ITER

#include "bst_iterator.hpp"
#include "iterator_traits.hpp"

namespace ft {
template <class Node>
class bst_reverse_iterator {
	public:
		typedef typename Node::value_type																	value_type;
		typedef typename ft::iterator_traits<value_type>::pointer					pointer;
		typedef typename ft::iterator_traits<value_type>::reference				reference;
		typedef typename ft::iterator_traits<value_type>::difference_type difference_type;

		bst_reverse_iterator() : _elem() { }

		bst_reverse_iterator( Node* node ) : _elem( node ) { }

		bst_reverse_iterator( bst_iterator<Node> it ) : _elem( it.base() ) { }

		bst_reverse_iterator( const bst_reverse_iterator& op ) { *this = op; }

		bst_reverse_iterator& operator=( const bst_reverse_iterator& op ) {
			_elem = op._elem;
			return *this;
		}

		value_type get_value() const { return _elem->value; }

		reference operator*() const { return _elem->value; }

		pointer operator->() const { return &( const_cast<value_type&>( _elem->value ) ); }

		Node* base() const { return _elem; }

		bst_reverse_iterator& operator--( void ) {
			if ( _elem->right ) {
				_elem = _elem->right;
				while ( _elem->left && _elem->left->is_limit == false)
					_elem = _elem->left;
			} else if ( _elem == _elem->parent->left ) {
				_elem = _elem->parent;
			} else {
				while ( _elem == _elem->parent->right )
					_elem = _elem->parent;
				_elem = _elem->parent;
			}
			return ( *this );
		}

		bst_reverse_iterator operator--( int ) {
			bst_reverse_iterator tmp( *this );
													 operator--();
			return ( tmp );
		}

		bst_reverse_iterator& operator++( void ) {
			if ( _elem->left ) {
				_elem = _elem->left;
				while ( _elem->right && _elem->right->is_limit == false)
					_elem = _elem->right;
			} else if ( _elem == _elem->parent->right ) {
				_elem = _elem->parent;
			} else {
				while ( _elem == _elem->parent->left )
					_elem = _elem->parent;
				_elem = _elem->parent;
			}
			return ( *this );
		}

		bst_reverse_iterator operator++( int ) {
			bst_reverse_iterator tmp( *this );
													 operator++();
			return ( tmp );
		}
		bool operator!=( const bst_reverse_iterator& rhs ) const { return _elem != rhs.base(); }

		operator bst_reverse_iterator<const Node>() const { return ( bst_reverse_iterator<const Node>( _elem ) ); }

	private:
		Node* _elem;
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