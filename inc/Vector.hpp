#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <limits.h>

#include <iostream>
#include <memory>

#include "Iterator.hpp"

namespace ft {

template <class T, class Alloc = std::allocator<T> >
class vector {
public:
	typedef T											 value_type;
	typedef Alloc										 allocator_type;
	typedef typename allocator_type::reference			 reference;
	typedef typename allocator_type::const_reference	 const_reference;
	typedef typename allocator_type::pointer			 pointer;
	typedef typename allocator_type::const_pointer		 const_pointer;
	typedef ft::random_access_iterator<value_type>		 iterator;
	typedef ft::random_access_iterator<const value_type> const_iterator;
	typedef std::reverse_iterator<iterator>				 reverse_iterator;
	typedef std::reverse_iterator<const_iterator>		 const_reverse_iterator;
	typedef typename allocator_type::size_type			 size_type;
	typedef typename allocator_type::difference_type	 difference_type;

	vector(const allocator_type &alloc = allocator_type())
		: _alloc(alloc),
		  _start(nullptr),
		  _end(nullptr),
		  _end_capacity(nullptr) { }

	vector(size_type n, const value_type &val = value_type(),
		   const allocator_type &alloc = allocator_type())
		: _alloc(alloc),
		  _start(nullptr),
		  _end(nullptr),
		  _end_capacity(nullptr) {
		_start = _alloc.allocate(n);
		_end_capacity = _start + n;
		_end = _start;
		while ( n-- ) {
			_alloc.construct(_end, val);
			_end++;
		}
	}

	// template <class InputIterator>
	// explicit vector(InputIterator first, InputIterator last, const allocator_type &alloc = allocator_type());

	vector(const vector &x);

	~vector() {
		clear();
		_alloc.deallocate(_start, this->capacity());
	}

	vector &operator=(const vector &x);

	////////////////////////////////////ITERATORS
	iterator begin() { return _start; }
	// const_iterator		   begin() const;
	iterator end() { return _end; }
	// const_iterator		   end() const;
	// reverse_iterator	   rbegin();
	// const_reverse_iterator rbegin() const;
	// reverse_iterator	   rend();
	// const_reverse_iterator rend() const;

	////////////////////////////////////CAPACITY
	size_type size() const { return (_end - _start); }

	size_type max_size() const {
		size_type maxVal = std::numeric_limits<size_type>::max() / sizeof(value_type);
		size_type maxAlloc = std::numeric_limits<size_type>::max() / 2;
		if ( maxVal > maxAlloc )
			return maxAlloc;
		return maxVal;
	}

	void resize(size_type sz);
	void resize(size_type sz, const value_type &c);

	size_type capacity() const { return (_end_capacity - _start); }

	bool empty() const { return (this->size() == 0); }

	void reserve(size_type n);

	////////////////////////////////////ELEMENTS ACCES
	reference		operator[](size_type n);
	const_reference operator[](size_type n) const;
	reference		at(size_type n) { return *(_start + n); }
	const_reference at(size_type n) const;

	reference		front();
	const_reference front() const;
	reference		back();
	const_reference back() const;

	////////////////////////////////////MODIFIERS
	// template <class InputIterator>							   //range (1)
	// void	 assign(InputIterator first, InputIterator last);  //
	void assign(size_type n, const value_type &val);  //fill (2)

	void push_back(const value_type &x) {
		this->insert(_end, x);
	}

	void pop_back() {
		this->erase(_end - 1);
	}

	iterator insert(iterator position, const value_type &val) {
		int		  next_capacity = 1;
		size_type pos_len = &(*position) - _start;
		if ( this->size() < this->capacity() ) {
			for ( size_type i = 0; i < (this->size() - pos_len); i++ ) {
				_alloc.construct(_end - i, *(_end - i - 1));
			}
			_end++;
			_alloc.construct(&(*position), val);
		} else {
			pointer new_start = pointer(0);
			pointer new_end = pointer();
			pointer new_end_capacity = pointer();

			if ( this->size() * 2 > 0 )
				next_capacity = this->size() * 2;

			new_start = _alloc.allocate(next_capacity);
			new_end = new_start + this->size() + 1;
			new_end_capacity = new_start + next_capacity;

			for ( size_type i = 0; i < pos_len; i++ )
				_alloc.construct(new_start + i, *(_start + i));
			_alloc.construct(new_start + pos_len, val);
			for ( size_type j = 0; j < this->size() - pos_len; j++ )
				_alloc.construct(new_end - j - 1, *(_end - j - 1));

			for ( size_type l = 0; l < this->size(); l++ )
				_alloc.destroy(_start + l);
			if ( _start )
				_alloc.deallocate(_start, this->capacity());

			_start = new_start;
			_end = new_end;
			_end_capacity = new_end_capacity;
		}
		return (iterator(_start + pos_len));
	}  // single element (1)

	// void insert(iterator position, size_type n, const value_type &val);		  // fill (2)
	// template <class InputIterator>											  // range (3)
	// void insert(iterator position, InputIterator first, InputIterator last);  //

	iterator erase(iterator position) {
		size_type pos_len = &(*position) - _start;
		for ( size_type i = 0; i < (this->size() - pos_len); i++ ) {
			_alloc.construct(_start + i + pos_len, *(_start + i + 1 + pos_len));
		}
		_alloc.destroy(_end);
		_end--;
		return (iterator(_start + pos_len));
	}

	// iterator erase(iterator first, iterator last);

	void swap(vector &x);

	void clear() {
		size_type size = this->size();
		for ( size_type i = 0; i < size; i++ ) {
			_end--;
			_alloc.destroy(_end);
		}
	}

	////////////////////////////////////ALLOCATOR
	allocator_type get_allocator() const;

private:
	static const unsigned __bits_per_word = static_cast<unsigned>(sizeof(size_type) * CHAR_BIT);
	allocator_type		  _alloc;
	pointer				  _start;
	pointer				  _end;
	pointer				  _end_capacity;
};

template <class T, class Alloc>
void swap(vector<T, Alloc> &x, vector<T, Alloc> &y);
template <class T, class Alloc>
bool operator==(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs);
template <class T, class Alloc>
bool operator!=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs);
template <class T, class Alloc>
bool operator<(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs);
template <class T, class Alloc>
bool operator<=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs);
template <class T, class Alloc>
bool operator>(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs);
template <class T, class Alloc>
bool operator>=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs);

}  // namespace ft
#endif
