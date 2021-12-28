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

template <class T, class Compare, class Node_Alloc>
class bst {
	public:
		typedef T																		 value_type;
		typedef T*																	 pointer;
		typedef T&																	 reference;
		typedef std::ptrdiff_t											 difference_type;
		typedef ft::bst_node<T>											 Node;
		typedef ft::bst_iterator<Node>							 iterator;
		typedef ft::bst_iterator<const Node>				 const_iterator;
		typedef ft::bst_reverse_iterator<Node>			 reverse_iterator;
		typedef ft::bst_reverse_iterator<const Node> const_reverse_iterator;
		typedef Node*																 node_pointer;
		typedef size_t															 size_type;
		typedef Compare															 value_compare;
		typedef Node_Alloc													 allocator_type;

		bst( Node_Alloc nodeAlloc = Node_Alloc() )
				: _nodeAlloc( nodeAlloc ), _root(), _comp(), _size() {
			_lastNode = _nodeAlloc.allocate( 1 );
			_assign_node( _lastNode, Node( value_type(), true ) );
			_firstNode = _nodeAlloc.allocate( 1 );
			_assign_node( _firstNode, Node( value_type(), true ) );
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

		size_type size() const { return _size; }

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
			node_pointer node = _find( val.first, _root );
			_assign_pred_succ_insert( node );
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
			node_pointer node = _find( val.first, _root );
			_assign_pred_succ_insert( node );
			return tmp;
		}

	private:
		ft::pair<iterator, bool> _insert( const value_type& val, node_pointer& node ) {
			ft::pair<iterator, bool> ret = ft::make_pair( node, false );

			if ( !node ) {
				node = _nodeAlloc.allocate( 1 );
				_nodeAlloc.construct( node, Node( val, false ) );
				_size++;
				ret = ft::make_pair( node, true );
			} else if ( _comp( val.first, node->value.first ) ) { //_comp(x < y) == true
				ret = _insert( val, node->left );
				node->left_depth = std::max( node->left->right_depth, node->left->left_depth ) + 1;
				node->left->parent = node;
				_balancing( node, node->left_depth, node->right_depth );
			} else if ( _comp( node->value.first, val.first ) ) {
				ret = _insert( val, node->right );
				node->right_depth = std::max( node->right->right_depth, node->right->left_depth ) + 1;
				node->right->parent = node;
				_balancing( node, node->left_depth, node->right_depth );
			}
			return ret;
		}

		void _assign_pred_succ_insert( node_pointer& node ) {
			node_pointer tmp_pred = _predecessor( node );
			tmp_pred->succ = node;
			node->pred = tmp_pred;

			node_pointer tmp_succ = _successor( node );
			tmp_succ->pred = node;
			node->succ = tmp_succ;
		}

		node_pointer _predecessor( node_pointer node ) {
			if ( node->left ) {
				node = node->left;
				while ( node->right && node->right->is_limit == false )
					node = node->right;
			} else if ( node == node->parent->right ) {
				node = node->parent;
			} else {
				while ( node == node->parent->left )
					node = node->parent;
				node = node->parent;
			}
			return node;
		}

		node_pointer _successor( node_pointer node ) {
			if ( node->right ) {
				node = node->right;
				while ( node->left && node->left->is_limit == false )
					node = node->left;
			} else if ( node == node->parent->left ) {
				node = node->parent;
			} else {
				while ( node == node->parent->right )
					node = node->parent;
				node = node->parent;
			}
			return node;
		}

		void _balancing( node_pointer& node, int& l, int& r ) {
			if ( l - r < -1 ) {
				if ( r - node->right->left_depth != 1 )
					node = _rr_rotation( node, node->right );
				else
					node = _rl_rotation( node, node->right->left, node->right );
			} else if ( l - r > 1 ) {
				if ( l - node->left->left_depth != 1 )
					node = _lr_rotation( node->left, node->left->right, node );
				else
					node = _ll_rotation( node->left, node );
			}
		}

		node_pointer _rr_rotation( node_pointer n1, node_pointer n2 ) {
			node_pointer tmp = n2->left;
			n2->parent = n1->parent;
			n2->left = n1;
			n1->right = tmp;
			n1->parent = n2;
			n1->right_depth = n2->left_depth;
			n2->left_depth = std::max( n1->left_depth, n1->right_depth ) + 1;
			if ( n1->right )
				n1->right->parent = n1;
			return n2;
		}

		node_pointer _ll_rotation( node_pointer n2, node_pointer n3 ) {
			node_pointer tmp = n2->right;
			n2->parent = n3->parent;
			n2->right = n3;
			n3->left = tmp;
			n3->parent = n2;
			n3->left_depth = n2->right_depth;
			n2->right_depth = std::max( n3->left_depth, n3->right_depth ) + 1;
			if ( n3->left )
				n3->left->parent = n3;
			return n2;
		}

		node_pointer _lr_rotation( node_pointer n1, node_pointer n2, node_pointer n3 ) {
			node_pointer tmpl = n2->left;
			node_pointer tmpr = n2->right;

			n2->parent = n3->parent;
			n2->right = n3;
			n2->left = n1;
			n2->left->parent = n2;
			n2->right->parent = n2;
			n1->right = tmpl;
			n3->left = tmpr;
			if ( n1->right )
				n1->right->parent = n1;
			if ( n3->left )
				n3->left->parent = n3;

			n1->right_depth = n2->left_depth;
			n2->left_depth = std::max( n1->left_depth, n1->right_depth ) + 1;
			n3->left_depth = n2->right_depth;
			n2->right_depth = std::max( n3->left_depth, n3->right_depth ) + 1;

			return n2;
		}

		node_pointer _rl_rotation( node_pointer n1, node_pointer n2, node_pointer n3 ) {
			node_pointer tmpl = n2->left;
			node_pointer tmpr = n2->right;
			n2->parent = n1->parent;
			n2->right = n3;
			n2->left = n1;
			n2->left->parent = n2;
			n2->right->parent = n2;
			n1->right = tmpl;
			n3->left = tmpr;
			if ( n1->right )
				n1->right->parent = n1;
			if ( n3->left )
				n3->left->parent = n3;

			n1->right_depth = n2->left_depth;
			n2->left_depth = std::max( n1->left_depth, n1->right_depth ) + 1;
			n3->left_depth = n2->right_depth;
			n2->right_depth = std::max( n3->left_depth, n3->right_depth ) + 1;

			return n2;
		}

	public:
		void _reset_limits() {
			if ( _firstNode->parent )
				_firstNode->parent->left = nullptr;
			if ( _lastNode->parent )
				_lastNode->parent->right = nullptr;
		}

		void _assign_limits() {
			if ( !_root ) {
				_assign_node( _firstNode, Node( value_type(), true ) );
				_assign_node( _lastNode, Node( value_type(), true ) );
			} else {
				node_pointer min = _findMin();
				node_pointer max = _findMax();
				min->left = _firstNode;
				_assign_node( _firstNode, Node( min->value, true ) );
				_firstNode->parent = min;
				_firstNode->succ = min;
				max->right = _lastNode;
				_assign_node( _lastNode, Node( max->value, true ) );
				_lastNode->parent = max;
				_lastNode->pred = max;
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
			while ( first != last )
				erase( first++ );
		}

		size_type erase( iterator pos ) {
			if ( pos == end() )
				return 0;
			node_pointer cur = pos.base();
			_size--;
			if ( cur->left && cur->left->is_limit == true && cur->right &&
					 cur->right->is_limit == true ) {
				_delete( _root );
			} else {
				_assign_pred_succ_erase( cur );
				_reset_limits();
				_erase( *pos, _root );
			}
			_assign_limits();
			return 1;
		}

	private:
		void _assign_pred_succ_erase( node_pointer node ) {
			node_pointer tmp_pred = node->pred;
			if ( tmp_pred )
				tmp_pred->succ = node->succ;
			node_pointer tmp_succ = node->succ;
			if ( tmp_succ )
				tmp_succ->pred = node->pred;
		}

		void _erase( value_type value, node_pointer& node ) {
			if ( !node )
				return;
			if ( _comp( node->value.first, value.first ) ) {
				_erase( value, node->right );
				_assign_right_depth( node );
				_balancing( node, node->left_depth, node->right_depth );
			} else if ( _comp( value.first, node->value.first ) ) {
				_erase( value, node->left );
				_assign_left_depth( node );
				_balancing( node, node->left_depth, node->right_depth );
			} else {
				if ( !node->left && !node->right ) {
					_delete( node );
				} else if ( node->left && !node->right ) {
					_has_one_child( node, node->left );
				} else if ( !node->left && node->right ) {
					_has_one_child( node, node->right );
				} else {
					node = _has_two_child( node );
				}
			}
		}

		void _assign_right_depth( node_pointer& node ) {
			if ( !node->right )
				node->right_depth = 0;
			else
				node->right_depth = std::max( node->right->right_depth, node->right->left_depth ) + 1;
		}

		void _assign_left_depth( node_pointer& node ) {
			if ( !node->left )
				node->left_depth = 0;
			else
				node->left_depth = std::max( node->left->right_depth, node->left->left_depth ) + 1;
		}

		node_pointer _has_two_child( node_pointer toRm ) {
			_find_successor_and_delete( toRm, toRm->right );
			_assign_right_depth( toRm );
			_balancing( toRm, toRm->left_depth, toRm->right_depth );
			return toRm;
		}

		void _find_successor_and_delete( node_pointer& toRm, node_pointer& succ ) {
			if ( succ->left ) {
				_find_successor_and_delete( toRm, succ->left );
				_assign_left_depth( succ );
				_balancing( succ, succ->left_depth, succ->right_depth );
				_assign_node_parent_child( succ, succ );
			} else {
				toRm = _swap_nodes( toRm, succ );
			}
		}

		node_pointer _swap_nodes( node_pointer toRm, node_pointer succ ) {
			node_pointer child = succ->right;
			node_pointer parent = succ->parent;

			succ->left = toRm->left;
			succ->left->parent = succ;
			if ( parent != toRm ) {
				succ->right = toRm->right;
				succ->right->parent = succ;
				if ( child )
					child->parent = parent;
				parent->left = child;
			}
			succ->parent = toRm->parent;
			if ( succ->parent )
				_assign_node_parent_child( succ, succ );
			succ->left_depth = toRm->left_depth;
			succ->right_depth = toRm->right_depth;
			_delete( toRm );
			return succ;
		}

		void _has_one_child( node_pointer toRm, node_pointer child ) {
			if ( toRm == _root ) {
				_root = child;
				_root->parent = nullptr;
			} else {
				child->parent = toRm->parent;
				_assign_node_parent_child( toRm, child );
			}
			_delete( toRm );
		}

		void _assign_node_parent_child( node_pointer node, node_pointer child ) {
			if ( _comp( node->value.first, node->parent->value.first ) )
				node->parent->left = child;
			else
				node->parent->right = child;
		}

		//// SWAP ////

	public:
		void swap( bst& x ) {
			std::swap( _root, x._root );
			std::swap( _firstNode, x._firstNode );
			std::swap( _lastNode, x._lastNode );
		}

		//// CLEAR ////

	public:
		void clear() { erase( begin(), end() ); }

		//// UTILS ////

	private:
		void _delete( node_pointer& node ) {
			_nodeAlloc.destroy( node );
			_nodeAlloc.deallocate( node, 1 );
			node = nullptr;
		}

		void _assign_node( node_pointer& addr, Node value ) {
			_nodeAlloc.destroy( addr );
			_nodeAlloc.construct( addr, value );
		}

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

	public:
		Compare get_comp() const { return _comp; }

		allocator_type get_allocator() const { return _nodeAlloc; }

	private:
		node_pointer get_root() const { return _root; }

		int height( node_pointer node ) {

			if ( node->left == 0 && node->right == 0 )
				return 1;
			else if ( node->right == 0 )
				return 1 + height( node->left );
			else if ( node->left == 0 )
				return 1 + height( node->right );
			else
				return 1 + std::max( height( node->left ), height( node->right ) );
		}

	private:
		Node_Alloc	 _nodeAlloc;
		node_pointer _root;
		node_pointer _firstNode;
		node_pointer _lastNode;
		Compare			 _comp;
		size_type		 _size;
};

} // namespace ft
#endif