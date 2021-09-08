#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <memory>

#include "Iterator.hpp"
#include "Utils.hpp"

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

public:
	//MEMBERS FUNCTIONS
	Vector(const allocator_type &alloc = allocator_type())
		: _alloc(alloc),
		  _start(nullptr),
		  _end(nullptr),
		  _end_capacity(nullptr) { }  //default

	Vector(size_type n, const value_type &val = value_type(), const allocator_type &alloc = allocator_type())
		: _alloc(alloc),
		  _start(nullptr),
		  _end(nullptr),
		  _end_capacity(nullptr) {
		_start = _alloc.allocate(n);
		_end_capacity = _start + n;
		while ( n-- ) {
			_alloc.construct(_end, val);
			_end++;
		}
	}																								  //fill
	template <class InputIterator>																	  //
	Vector(InputIterator first, InputIterator last, const allocator_type &alloc = allocator_type());  //range
	Vector(const Vector &x);																		  //copy
	~Vector() { }
	Vector &operator=(const Vector &x);

	//ITERATORS
	iterator			   begin();
	const_iterator		   begin() const;
	iterator			   end();
	const_iterator		   end() const;
	reverse_iterator	   rbegin();
	const_reverse_iterator rbegin() const;
	reverse_iterator	   rend();
	const_reverse_iterator rend() const;

	//CAPACITY
	size_type size() const;
	size_type max_size() const;
	void	  resize(size_type sz);
	void	  resize(size_type sz, const value_type &c);
	size_type capacity() const;
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
	template <class InputIterator>							   //range (1)
	void	 assign(InputIterator first, InputIterator last);  //
	void	 assign(size_type n, const value_type &val);	   //fill (2)
	void	 push_back(const value_type &x);
	void	 pop_back();
	iterator insert(iterator position, const value_type &val);					  // single element (1)
	void	 insert(iterator position, size_type n, const value_type &val);		  // fill (2)
	template <class InputIterator>												  // range (3)
	void	 insert(iterator position, InputIterator first, InputIterator last);  //
	iterator erase(iterator position);
	iterator erase(iterator first, iterator last);
	void	 swap(Vector &x);
	void	 clear();

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
