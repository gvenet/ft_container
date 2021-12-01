#ifndef MAP_HPP
#define MAP_HPP

#include <memory>

#include "../binary_search_tree/bst.hpp"

namespace ft {

template <class Key, class T, class Compare = std::less<Key>,
					class Alloc = std::allocator<std::pair<const Key, T> > >
class map {
	public:
		typedef Key								key_type;
		typedef T									mapped_type;
		typedef std::pair<Key, T> value_type;

	private:
		typedef ft::bst<value_type, Compare> __bst;

	public:
		typedef Alloc																	 allocator_type;
		typedef typename __bst::iterator							 iterator;
		typedef typename __bst::const_iterator				 const_iterator;
		typedef typename __bst::reverse_iterator			 reverse_iterator;
		typedef typename __bst::const_reverse_iterator const_reverse_iterator;
		typedef size_t																 size_type;
		typedef Compare																 key_compare;

		class _LIBCPP_TEMPLATE_VIS value_compare
				: public std::binary_function<value_type, value_type, bool> {
				friend class map;

			protected:
				key_compare comp;
				value_compare( key_compare c ) : comp( c ) { }

			public:
				bool operator()( const value_type& __x, const value_type& __y ) const {
					return comp( __x.first, __y.first );
				}
		};

		map( const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type() ) {
		}

		template <class InputIterator>
		map( InputIterator first, InputIterator last, const key_compare& comp = key_compare(),
				 const allocator_type& alloc = allocator_type() ) {
			insert( first, last );
		}

		map( const map& x ) { *this = x; }

		map& operator=( const map& x ) {
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
			iterator tmp = find( k );
			insert( std::make_pair( k, mapped_type() ) );
			tmp = find( k );
			return tmp->second;
		}

		//// MODIFIERS ////

		//// INSERT ////

		std::pair<iterator, bool> insert( const value_type& val ) { return _bst.insert( val ); }

		iterator insert( iterator position, const value_type& val ) { return insert( val ).first; }

		template <class InputIterator>
		void insert( InputIterator first, InputIterator last ) {
			_bst.insert( first, last );
		}

		//// ERASE ////

		void erase( iterator position ) { _bst.erase( position ); }

		size_type erase( const key_type& k ) { return _bst.erase( find( k ) ); }

		void erase( iterator first, iterator last ) { _bst.erase( first, last ); }

		//// SWAP ////

		void swap( map& x ) {
			map tmp( x );
			x = *this;
			*this = tmp;
		}

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

		std::pair<iterator, iterator> equal_range( const key_type& k ) {
			return std::make_pair( lower_bound( k ), upper_bound( k ) );
		}

		std::pair<const_iterator, const_iterator> equal_range( const key_type& k ) const {
			return std::make_pair( lower_bound( k ), upper_bound( k ) );
		}

		allocator_type get_allocator() const { return _bst.get_allocator(); }

	private:
		__bst _bst;
};

} // namespace ft
#endif