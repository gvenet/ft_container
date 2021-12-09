#ifndef BST_HPP
#define BST_HPP

#define RED "\033[01;31m"
#define GRN "\033[01;32m"
#define YLW "\033[01;33m"
#define CBN "\033[0m"

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

		bst( Node_Alloc nodeAlloc = Node_Alloc() )
				: _nodeAlloc( nodeAlloc ), _root(), _comp(), _size() {
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
			std::cout << GRN << "RR : " << CBN << n2->value.first << "\n\n";
			node_pointer tmp = n2->left;
			n2->parent = n1->parent;
			n2->left = n1;
			n1->right = tmp;
			n1->parent = n2;
			n1->right_depth += -2;
			n2->left_depth += 1;
			if ( n1->right )
				n1->right->parent = n1;
			return n2;
		}

		node_pointer _ll_rotation( node_pointer n2, node_pointer n3 ) {
			std::cout << GRN << "LL : " << CBN << n2->value.first << "\n\n";
			node_pointer tmp = n2->right;
			n2->parent = n3->parent;
			n2->right = n3;
			n3->left = tmp;
			n3->parent = n2;
			n3->left_depth += -2;
			n2->right_depth += 1;
			if ( n3->left )
				n3->left->parent = n3;
			return n2;
		}

		node_pointer _lr_rotation( node_pointer n1, node_pointer n2, node_pointer n3 ) {
			std::cout << GRN << "LR : " << CBN << n2->value.first << "\n\n";
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
			std::cout << GRN << "RL : " << CBN << n2->value.first << "\n\n";
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
			if ( position == end() )
				return 0;
			node_pointer cur( position.base() );
			_size--;
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
				_assign( toRm, Node( toRm->parent, toRm->left, toRm->right, succ->value, false, 0, 0 ) );
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
			if ( _comp( toRm->value.first, parent->value.first ) )
				parent->left = child;
			else
				parent->right = child;
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

		void _assign( node_pointer& addr, Node value ) {
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
		int height( node_pointer node ) {

			// std::cout<<"dans height "<<getKey()<<std::endl;
			if ( node->left == 0 && node->right == 0 )
				return 1;
			else if ( node->right == 0 )
				return 1 + height( node->left );
			else if ( node->left == 0 )
				return 1 + height( node->right );
			else
				return 1 + std::max( height( node->left ), height( node->right ) );
		}

		Compare get_comp() const { return _comp; }

		allocator_type get_allocator() const { return _nodeAlloc; }

		node_pointer get_root() const { return _root; }

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