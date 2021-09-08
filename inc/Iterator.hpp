#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include "Utils.hpp"

namespace ft {


template <class Category, class T, class Distance = ptrdiff_t,
		  class Pointer = T*, class Reference = T&>
class iterator {
public:
	typedef T		  value_type;
	typedef Distance  difference_type;
	typedef Pointer	  pointer;
	typedef Reference reference;
	typedef Category  iterator_category;
};

class random_access_iterator_tag {};

template <typename T>
class random_access_iterator : ft::iterator<ft::random_access_iterator_tag, T> {
public:
	typedef typename ft::iterator<ft::random_access_iterator_tag, T>::iterator_category iterator_category;
	typedef typename ft::iterator<ft::random_access_iterator_tag, T>::value_type		value_type;
	typedef typename ft::iterator<ft::random_access_iterator_tag, T>::difference_type	difference_type;
	typedef T*																			pointer;
	typedef T&																			reference;

	random_access_iterator(void) : _elem(u_nullptr) {}

	random_access_iterator(pointer elem) : _elem(elem) {}

	random_access_iterator(const random_access_iterator& op) : _elem(op._elem) {}

	random_access_iterator& operator=(const random_access_iterator& op) {
		if ( this == &op )
			return (*this);
		this->_elem = op._elem;
		return (*this);
	}
	virtual ~random_access_iterator() {}

	pointer base() const { return (this->_elem); }

	reference operator*(void) const { return (*_elem); }

	pointer operator->(void) { return &(this->operator*()); }

	random_access_iterator& operator++(void) {
		_elem++;
		return (*this);
	}

	random_access_iterator operator++(int) {
		random_access_iterator rtn(*this);
							   operator++();
		return (rtn);
	}

	random_access_iterator& operator--(void) {
		_elem--;
		return (*this);
	}

	random_access_iterator operator--(int) {
		random_access_iterator rtn(*this);
							   operator--();
		return (rtn);
	}

	random_access_iterator operator+(difference_type n) const { return (_elem + n); }

	random_access_iterator operator-(difference_type n) const { return (_elem - n); }

	random_access_iterator& operator+=(difference_type n) {
		_elem += n;
		return (*this);
	}

	random_access_iterator& operator-=(difference_type n) {
		_elem -= n;
		return (*this);
	}

	reference operator[](difference_type n) { return (*(operator+(n))); }

	operator random_access_iterator<const T>() const { return (random_access_iterator<const T>(this->_elem)); }

private:
	pointer _elem;
};

}  // namespace ft
#endif