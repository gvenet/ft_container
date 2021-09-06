#ifndef VECTOR_HPP
#define VECTOR_HPP
#include <memory>

namespace ft {

template <class T, class Allocator = std::allocator<T> > // generic template
class Vector {
public:
	typedef T										 value_type;
	typedef Allocator								 allocator_type;
	typedef typename allocator_type::reference		 reference;
	typedef typename allocator_type::const_reference const_reference;
	// typedef implementation-defined                   iterator
	// typedef implementation-defined                   const_iterator;
	typedef typename allocator_type::size_type		 size_type;
	typedef typename allocator_type::difference_type difference_type;
	typedef typename allocator_type::pointer		 pointer;
	typedef typename allocator_type::const_pointer	 const_pointer;
	typedef std::reverse_iterator<iterator>			 reverse_iterator;
	typedef std::reverse_iterator<const_iterator>	 const_reverse_iterator;

	//MEMBERS FUNCTIONS
	Vector();																								   //constructors
	Vector(const allocator_type &alloc = allocator_type());													   //_default (1)
	Vector(size_type n, const value_type &val = value_type(), const allocator_type &alloc = allocator_type()); //_fill (2)
	template <class InputIterator>																			   //_range (3)
	Vector(InputIterator first, InputIterator last, const allocator_type &alloc = allocator_type());		   //_
	Vector(const Vector &x);																				   //_copy (4)
	~Vector();																								   //destructor
	Vector &operator=(const Vector &x);																		   //operator=

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
	template <class InputIterator>							  //range (1)
	void	 assign(InputIterator first, InputIterator last); //
	void	 assign(size_type n, const value_type &val);	  //fill (2)
	void	 push_back(const value_type &x);
	void	 pop_back();
	iterator insert(iterator position, const value_type &val);					 // single element (1)
	void	 insert(iterator position, size_type n, const value_type &val);		 // fill (2)
	template <class InputIterator>												 // range (3)
	void	 insert(iterator position, InputIterator first, InputIterator last); //
	iterator erase(iterator position);
	iterator erase(iterator first, iterator last);
	void	 swap(Vector &x);
	void	 clear();

	//ALLOCATOR
	allocator_type get_allocator() const; //get_allocator
};

template <class T, class Allocator>
void swap(Vector<T, Allocator> &x, Vector<T, Allocator> &y);

template <class T, class Allocator>
bool operator==(const Vector<T, Allocator> &lhs, const Vector<T, Allocator> &rhs);
template <class T, class Allocator>
bool operator!=(const Vector<T, Allocator> &lhs, const Vector<T, Allocator> &rhs);
template <class T, class Allocator>
bool operator<(const Vector<T, Allocator> &lhs, const Vector<T, Allocator> &rhs);
template <class T, class Allocator>
bool operator<=(const Vector<T, Allocator> &lhs, const Vector<T, Allocator> &rhs);
template <class T, class Allocator>
bool operator>(const Vector<T, Allocator> &lhs, const Vector<T, Allocator> &rhs);
template <class T, class Allocator>
bool operator>=(const Vector<T, Allocator> &lhs, const Vector<T, Allocator> &rhs);

} // namespace ft
#endif
