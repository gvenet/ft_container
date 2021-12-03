#ifndef BST_HPP
#define BST_HPP

#include <memory>

#include "../utils/algorithm.hpp"
#include "../utils/pair.hpp"
#include "../vector.hpp"
#include "bst_iterator.hpp"
#include "bst_node.hpp"
#include "bst_reverse_iterator.hpp"

namespace ft {

template <class T, class Compare, class Node = ft::bst_node<T>,
					class Node_Alloc = std::allocator<Node> >
class bst {
	public:
		typedef T																		 value_type;
		typedef T*																	 pointer;
		typedef T&																	 reference;
		typedef std::ptrdiff_t											 difference_type;
		typedef ft::bst_iterator<Node>							 iterator;
		typedef ft::bst_iterator<const Node>				 const_iterator;
		typedef ft::bst_reverse_iterator<Node>			 reverse_iterator;
		typedef ft::bst_reverse_iterator<const Node> const_reverse_iterator;
		typedef Node*																 node_pointer;
		typedef size_t															 size_type;
		typedef Compare															 value_compare;
		typedef Node_Alloc													 allocator_type;

		bst( Node_Alloc nodeAlloc = Node_Alloc() ) : _nodeAlloc( nodeAlloc ), _root(), _comp() {
			_lastNode = _nodeAlloc.allocate( 1 );
			_assign( _lastNode, Node( value_type(), true ) );
			_firstNode = _nodeAlloc.allocate( 1 );
			_assign( _firstNode, Node( value_type(), true ) );
		}

		~bst() {
			clear();
			_delete( _lastNode );
			_delete( _firstNode );
		}

		// ITERATOR //

	public:
		iterator begin() {
			if ( !_root )
				return end();
			return ++iterator( _firstNode );
		}

		iterator begin() const {
			if ( !_root )
				return end();
			return ++iterator( _firstNode );
		}

		iterator end() { return _lastNode; }

		iterator end() const { return _lastNode; }

		reverse_iterator rbegin() {
			if ( !_root )
				return rend();
			return ++reverse_iterator( _lastNode );
		}

		reverse_iterator rbegin() const {
			if ( !_root )
				return rend();
			return ++reverse_iterator( _lastNode );
		}

		reverse_iterator rend() { return reverse_iterator( _firstNode ); }

		reverse_iterator rend() const { return reverse_iterator( _firstNode ); }

		//// CAPACITY ////
		bool empty() const { return !_root; }

		size_type size() const {
			size_type c = 0;
			for ( iterator it = begin(); it != end(); it++ )
				c++;
			return c;
		}

		size_type max_size() const {
			return ft::min<size_type>( std::allocator_traits<Node_Alloc>::max_size( _nodeAlloc ),
																 std::numeric_limits<difference_type>::max() );
		}

		//// INSERT ////

	public:
		ft::pair<iterator, bool> insert( const value_type& val ) {
			ft::pair<iterator, bool> tmp;
			_reset_limits();
			tmp = _insert( val, _root );
			_assign_limits();
			return tmp;
		}

		template <class InputIterator>
		void insert( InputIterator first, InputIterator last ) {
			for ( ; first != last; first++ ) {
				insert( *first );
			}
		}

		iterator insert( iterator position, const value_type& val ) {
			iterator tmp;
			_reset_limits();
			node_pointer cur( position.base() );
			tmp = _insert( val, cur ).first;
			_assign_limits();
			return tmp;
		}

	private:
		ft::pair<iterator, bool> _insert( const value_type& val, node_pointer& node ) {
			ft::pair<iterator, bool> ret;

			if ( !node ) {
				node = _nodeAlloc.allocate( 1 );
				_nodeAlloc.construct( node, Node( val, false ) );
				ret = ft::make_pair( node, true );
			} else if ( _comp( val.first, node->value.first ) ) {
				ret = _insert( val, node->left );
				node->left->parent = node;
			} else if ( _comp( node->value.first, val.first ) ) {
				ret = _insert( val, node->right );
				node->right->parent = node;
			}
			return ret;
		}

		void _reset_limits() {
			if ( _firstNode->parent )
				_firstNode->parent->left = nullptr;
			if ( _lastNode->parent )
				_lastNode->parent->right = nullptr;
		}

		void _assign_limits() {
			if ( !_root ) {
				_assign( _firstNode, Node( value_type(), true ) );
				_assign( _lastNode, Node( value_type(), true ) );
			} else {
				node_pointer min = _findMin();
				node_pointer max = _findMax();
				min->left = _firstNode;
				_assign( _firstNode, Node( min->value, true ) );
				_firstNode->parent = min;
				max->right = _lastNode;
				_assign( _lastNode, Node( max->value, true ) );
				_lastNode->parent = max;
			}
		}

		//// FIND ////

	public:
		template <typename key_type>
		iterator find( const key_type& key ) {
			node_pointer ret( _find( key, _root ) );
			if ( !ret )
				return end();
			return ret;
		}

		template <typename key_type>
		const_iterator find( const key_type& key ) const {
			node_pointer ret = _find( key, _root );

			if ( !ret )
				return end();
			return ret;
		}

	private:
		template <typename key_type>
		node_pointer _find( const key_type& key, node_pointer node ) {
			if ( !node )
				return nullptr;
			if ( _comp( key, node->value.first ) )
				node = _find( key, node->left );
			else if ( _comp( node->value.first, key ) )
				node = _find( key, node->right );
			else
				return node;
			return node;
		}

		template <typename key_type>
		node_pointer _find( const key_type& key, node_pointer node ) const {
			if ( !node )
				return nullptr;
			if ( _comp( key, node->value.first ) )
				node = _find( key, node->left );
			else if ( _comp( node->value.first, key ) )
				node = _find( key, node->right );
			else
				return node;
			return node;
		}

		//// ERASE ////

	public:
		template <class InputIterator>
		void erase( InputIterator first, InputIterator last ) {
			typedef ft::vector<InputIterator> vec;
			vec																v;
			while ( first != last )
				v.push_back( first++ );
			for ( typename vec::iterator it = v.begin(); it != v.end(); it++ )
				erase( *it );
		}

		size_type erase( iterator position ) {
			node_pointer cur( position.base() );
			if ( cur->left && cur->left->is_limit == true && cur->right &&
					 cur->right->is_limit == true ) {
				_delete( _root );
			} else {
				_reset_limits();
				_erase( *position );
			}
			_assign_limits();
			return 1;
		}

	private:
		void _erase( value_type value ) {
			node_pointer toRm( _find_by_value( _root, value ) );
			if ( !toRm->left && !toRm->right ) {
				if ( toRm != _root ) {
					_assign_child( toRm, nullptr );
					_delete( toRm );
				} else
					_delete( _root );
			} else if ( toRm->left && !toRm->right ) {
				_has_one_child( toRm, toRm->left );
			} else if ( !toRm->left && toRm->right ) {
				_has_one_child( toRm, toRm->right );
			} else {
				node_pointer succ( _successor( toRm ) );
				_assign( toRm, Node( toRm->parent, toRm->left, toRm->right, succ->value, false ) );
				if ( succ->right )
					succ->right->parent = succ->parent;
				_assign_child( succ, succ->right );
				_delete( succ );
			}
		}

		void _has_one_child( node_pointer& toRm, node_pointer& child ) {
			if ( toRm == _root ) {
				_root = child;
				_root->parent = nullptr;
			} else {
				child->parent = toRm->parent;
				_assign_child( toRm, child );
			}
			_delete( toRm );
		}

		void _assign_child( node_pointer& toRm, node_pointer child ) {
			node_pointer parent = toRm->parent;
			if ( _comp(toRm->value.first, parent->value.first ) )
				parent->left = child;
			else
				parent->right = child;
		}

		//// CLEAR ////

	public:
		void clear() { erase( begin(), end() ); }

		//// UTILS ////

		void _delete( node_pointer& node ) {
			_nodeAlloc.destroy( node );
			_nodeAlloc.deallocate( node, 1 );
			node = nullptr;
		}

		void _assign( node_pointer& addr, Node value ) {
			_nodeAlloc.destroy( addr );
			_nodeAlloc.construct( addr, value );
		}

	private:
		node_pointer _findMax() {
			node_pointer node = _root;
			while ( node->right )
				node = node->right;
			return node;
		}

		node_pointer _findMin() {
			node_pointer node = _root;
			while ( node->left )
				node = node->left;
			return node;
		}

		node_pointer _find_by_value( node_pointer node, value_type value ) {
			if ( !node )
				return nullptr;
			if ( _comp( node->value.first, value.first ) )
				return _find_by_value( node->right, value );
			else if ( _comp( value.first, node->value.first ) )
				return _find_by_value( node->left, value );
			else
				return node;
		}

		node_pointer _findMin( node_pointer& node ) {
			if ( !node->left )
				return node;
			else
				return _findMin( node->left );
		}

		node_pointer _successor( value_type value ) {
			node_pointer valueNode = _find_by_value( _root, value );
			return _successor( valueNode );
		}

		node_pointer _successor( node_pointer& node ) {
			if ( node->right ) {
				return _findMin( node->right );
			} else {
				node_pointer parentNode = node->parent;
				node_pointer currentNode = node;

				while ( parentNode && ( currentNode == parentNode->right ) ) {
					currentNode = parentNode;
					parentNode = currentNode->parent;
				}
				return parentNode;
			}
		}

	public:
		Compare get_comp() const { return _comp; }

		allocator_type get_allocator() const { return _nodeAlloc; }

	private:
		Node_Alloc	 _nodeAlloc;
		node_pointer _root;
		node_pointer _firstNode;
		node_pointer _lastNode;
		Compare			 _comp;
};

} // namespace ft
#endif