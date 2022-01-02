#ifndef MAP_HPP
#define MAP_HPP

#include "binary_search_tree/bst.hpp"
#include "binary_search_tree/bst_node.hpp"
#include "utils/pair.hpp"
#include <math.h>
#include <memory>
#include <queue>

namespace ft {

template <class Key, class T, class Compare = ft::less<Key>,
					class Alloc = std::allocator<ft::pair<const Key, T> > >
class map {
	public:
		typedef Key																					 key_type;
		typedef T																						 mapped_type;
		typedef ft::pair<const Key, T>											 value_type;
		typedef ft::bst_node<value_type>										 Node;
		typedef Alloc																				 allocator_type;
		typedef typename Alloc::template rebind<Node>::other node_allocator_type;

	private:
		typedef ft::bst<value_type, Compare, node_allocator_type> __bst;

	public:
		typedef typename __bst::iterator							 iterator;
		typedef typename __bst::const_iterator				 const_iterator;
		typedef typename __bst::reverse_iterator			 reverse_iterator;
		typedef typename __bst::const_reverse_iterator const_reverse_iterator;
		typedef size_t																 size_type;
		typedef Compare																 key_compare;

		class _LIBCPP_TEMPLATE_VIS value_compare
				: public ft::binary_function<value_type, value_type, bool> {
				friend class map;

			protected:
				key_compare comp;
				value_compare( key_compare c ) : comp( c ) { }

			public:
				bool operator()( const value_type& __x, const value_type& __y ) const {
					return comp( __x.first, __y.first );
				}
		};

		map( const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type() )
				: _comp( comp ), _alloc( alloc ), _bst() { }

		template <class InputIterator>
		map( InputIterator first, InputIterator last, const key_compare& comp = key_compare(),
				 const allocator_type& alloc = allocator_type() )
				: _comp( comp ), _alloc( alloc ), _bst() {
			insert( first, last );
		}

		map( const map& x ) { *this = x; }

		map& operator=( const map& x ) {
			if ( !empty() )
				clear();
			insert( x.begin(), x.end() );
			return *this;
		}

		//// ITERATORS ////

		iterator begin() { return _bst.begin(); }

		const_iterator begin() const { return _bst.begin(); }

		iterator end() { return _bst.end(); }

		const_iterator end() const { return _bst.end(); }

		reverse_iterator rbegin() { return _bst.rbegin(); }

		const_reverse_iterator rbegin() const { return _bst.rbegin(); }

		reverse_iterator rend() { return _bst.rend(); }

		const_reverse_iterator rend() const { return _bst.rend(); }

		//// CAPACITY ////

		bool empty() const { return _bst.empty(); }

		size_type size() const { return _bst.size(); }

		size_type max_size() const { return _bst.max_size(); }

		//// ELEMENT ACCES ////

		mapped_type& operator[]( const key_type& k ) {
			insert( ft::make_pair( k, mapped_type() ) );
			iterator tmp = find( k );
			return tmp->second;
		}

		//// MODIFIERS ////

		//// INSERT ////

		ft::pair<iterator, bool> insert( const value_type& val ) { return _bst.insert( val ); }

		iterator insert( iterator position, const value_type& val ) {
			return _bst.insert( position, val );
		}

		template <class InputIterator>
		void insert( InputIterator first, InputIterator last ) {
			_bst.insert( first, last );
		}

		//// ERASE ////

		void erase( iterator position ) { _bst.erase( position ); }

		size_type erase( const key_type& k ) { return _bst.erase( find( k ) ); }

		void erase( iterator first, iterator last ) { _bst.erase( first, last ); }

		//// SWAP ////

		void swap( map& x ) { _bst.swap( x._bst ); }

		//// CLEAR ////

		void clear() { _bst.clear(); }

		//// OBSERVERS ////

		key_compare key_comp() const { return _bst.get_comp(); }

		value_compare value_comp() const { return value_compare( _bst.get_comp() ); }

		//// OPERATIONS ////

		iterator find( const key_type& k ) { return _bst.find( k ); }

		const_iterator find( const key_type& k ) const { return _bst.find( k ); }

		size_type count( const key_type& k ) const { return find( k )->first == k; }

		iterator lower_bound( const key_type& k ) {
			key_type tmp = k;
			while ( !count( tmp ) && tmp < end()->first )
				tmp++;
			return _bst.find( tmp );
		}
		const_iterator lower_bound( const key_type& k ) const {
			key_type tmp = k;
			while ( !count( tmp ) && k < end()->first )
				tmp++;
			return _bst.find( tmp );
		}

		iterator upper_bound( const key_type& k ) {
			if ( count( k ) )
				return ++( _bst.find( k ) );
			key_type tmp = k;
			while ( !count( tmp ) && k < end()->first )
				tmp++;
			return _bst.find( tmp );
		}

		const_iterator upper_bound( const key_type& k ) const {
			if ( count( k ) )
				return ++( _bst.find( k ) );
			key_type tmp = k;
			while ( !count( tmp ) && k < end()->first )
				tmp++;
			return _bst.find( tmp );
		}

		ft::pair<iterator, iterator> equal_range( const key_type& k ) {
			return ft::make_pair( lower_bound( k ), upper_bound( k ) );
		}

		ft::pair<const_iterator, const_iterator> equal_range( const key_type& k ) const {
			return ft::make_pair( lower_bound( k ), upper_bound( k ) );
		}

		allocator_type get_allocator() const { return _bst.get_allocator(); }

	public:
		void print_tree() {

			_bst._reset_limits();
			int																		i = 0;
			int																		tour = 0;
			int																		space = pow( 2, _bst.height( _bst.get_root() ) - 1 );
			int																		vide = 0;
			int																		v = 1;
			int																		debug = 0;
			std::queue<ft::bst_node<value_type>*> n;
			ft::bst_node<value_type>*							temp;
			ft::bst_node<value_type>*							temp_head = _bst.get_root();

			n.push( temp_head );
			ft::bst_node<value_type>* temp2;
			for ( int x = 0; x < space; x++ ) {
				std::cout << " ";
			}
			while ( !n.empty() ) {
				debug++;
				temp = n.front();
				n.pop();
				if ( temp->getKey() == '*' )
					std::cout << (char)( temp->getKey() );
				else
					std::cout << ( temp->getKey() );
				i++;
				if ( i != 0 && i == pow( 2, tour ) / 2 )
					std::cout << " ";

				if ( i == pow( 2, tour ) ) {
					if ( v == 0 ) {

						std::cout << "\n\n";
						_bst._assign_limits();
						return;
					}
					std::cout << "\n";
					for ( int x = 0; x < space - pow( 2, tour ); x++ ) {
						std::cout << " ";
					}
					tour++;
					i = 0;
					v = 0;
				}
				if ( temp->getKey() == '*' ) {
					pair<const char, int> p1( '*', 0 );
					temp2 = _bst.get_allocator().allocate( 1 );
					_bst.get_allocator().construct( temp2, ft::bst_node<value_type>( p1 ) );
					n.push( temp2 );
					temp2 = _bst.get_allocator().allocate( 1 );
					_bst.get_allocator().construct( temp2, ft::bst_node<value_type>( p1 ) );
					n.push( temp2 );
					delete temp;
					continue;
				}
				if ( temp->left != 0 ) {
					n.push( temp->left );
					if ( temp->getKey() != '*' )
						v++;
				} else {
					pair<const char, int> p1( '*', 0 );
					temp2 = _bst.get_allocator().allocate( 1 );
					_bst.get_allocator().construct( temp2, ft::bst_node<value_type>( p1 ) );
					n.push( temp2 );
				}
				if ( temp->right != 0 ) {
					n.push( temp->right );
					if ( temp->getKey() != '*' )
						v++;
				} else {
					pair<const char, int> p1( '*', 0 );
					temp2 = _bst.get_allocator().allocate( 1 );
					_bst.get_allocator().construct( temp2, ft::bst_node<value_type>( p1 ) );
					n.push( temp2 );
					vide++;
				}
			}
			std::cout << "\n";
		}

	private:
		key_compare					_comp;
		node_allocator_type _alloc;
		__bst								_bst;
};

} // namespace ft
#endif