#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <memory>

#include "Iterator.hpp"

namespace ft {

template <class T, class Alloc = std::allocator<T> >
class Vector {
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

	Vector(const allocator_type &alloc = allocator_type())
		: _alloc(alloc),
		  _start(nullptr),
		  _end(nullptr),
		  _end_capacity(nullptr) { }

	Vector(size_type n, const value_type &val = value_type(),
		   const allocator_type &alloc = allocator_type())
		: _alloc(alloc),
		  _start(nullptr),
		  _end(nullptr),
		  _end_capacity(nullptr) {
		_end_capacity = _start + n;
		_start = _alloc.allocate(n);
		_end = _start;
		while ( n-- ) {
			_alloc.construct(_end, val);
			_end++;
		}
	}

	// template <class InputIterator>
	// explicit Vector(InputIterator first, InputIterator last, const allocator_type &alloc = allocator_type());

	Vector(const Vector &x);

	~Vector() {
		clear();
		_alloc.deallocate(_start, this->capacity());
	}

	Vector &operator=(const Vector &x);

	//ITERATORS
	iterator begin() { return _start; }
	// const_iterator		   begin() const;
	iterator end() { return _end; }
	// const_iterator		   end() const;
	// reverse_iterator	   rbegin();
	// const_reverse_iterator rbegin() const;
	// reverse_iterator	   rend();
	// const_reverse_iterator rend() const;

	//CAPACITY
	size_type size() const { return (_end - _start); }
	size_type max_size() const;
	void	  resize(size_type sz);
	void	  resize(size_type sz, const value_type &c);
	size_type capacity() const { return (_end_capacity - _start); }
	bool	  empty() const;
	void	  reserve(size_type n);

	//ELEMENTS ACCES
	reference		operator[](size_type n);
	const_reference operator[](size_type n) const;
	reference		at(size_type n);
	const_reference at(size_type n) const;

	reference		front();
	const_reference front() const;
	reference		back();
	const_reference back() const;

	//MODIFIERS
	// template <class InputIterator>							   //range (1)
	// void	 assign(InputIterator first, InputIterator last);  //
	void assign(size_type n, const value_type &val);  //fill (2)
	void push_back(const value_type &x);
	void pop_back();

	iterator insert(iterator position, const value_type &val) {
		size_type v_len = &(*position) - _start;
		std::cout << "v_len     : " << v_len<< " " << std::endl;
		std::cout << "empty_len : " << (_end_capacity - _end) << " " << std::endl;
		
		return (position);
	}  // single element (1)
	// void	 insert(iterator position, size_type n, const value_type &val);		  // fill (2)
	// template <class InputIterator>												  // range (3)
	// void	 insert(iterator position, InputIterator first, InputIterator last);  //

	// iterator erase(iterator position);
	// iterator erase(iterator first, iterator last);
	void swap(Vector &x);
	void clear() {
		size_type size = this->size();
		for ( size_type i = 0; i < size; i++ ) {
			_end--;
			_alloc.destroy(_end);
		}
	}

	//ALLOCATOR
	allocator_type get_allocator() const;

private:
	allocator_type _alloc;
	pointer		   _start;
	pointer		   _end;
	pointer		   _end_capacity;
};

template <class T, class Alloc>
void swap(Vector<T, Alloc> &x, Vector<T, Alloc> &y);
template <class T, class Alloc>
bool operator==(const Vector<T, Alloc> &lhs, const Vector<T, Alloc> &rhs);
template <class T, class Alloc>
bool operator!=(const Vector<T, Alloc> &lhs, const Vector<T, Alloc> &rhs);
template <class T, class Alloc>
bool operator<(const Vector<T, Alloc> &lhs, const Vector<T, Alloc> &rhs);
template <class T, class Alloc>
bool operator<=(const Vector<T, Alloc> &lhs, const Vector<T, Alloc> &rhs);
template <class T, class Alloc>
bool operator>(const Vector<T, Alloc> &lhs, const Vector<T, Alloc> &rhs);
template <class T, class Alloc>
bool operator>=(const Vector<T, Alloc> &lhs, const Vector<T, Alloc> &rhs);

}  // namespace ft
#endif
