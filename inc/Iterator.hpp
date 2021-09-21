#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include <stddef.h>
// #include "iterator_traits.hpp"

namespace ft {

template <class Category, class T, class Distance = std::ptrdiff_t, class Pointer = T*, class Reference = T&>
struct Iterator {
	typedef T		  value_type;
	typedef Distance  difference_type;
	typedef Pointer	  pointer;
	typedef Reference reference;
	typedef Category  iterator_category;
};

struct input_iterator_tag { };
struct output_iterator_tag { };
struct forward_iterator_tag : public input_iterator_tag { };
struct bidirectional_iterator_tag : public forward_iterator_tag { };
struct random_access_iterator_tag : public bidirectional_iterator_tag { };

template <typename T>
class random_access_iterator : ft::Iterator<ft::random_access_iterator_tag, T> {
public:
	typedef typename ft::Iterator<ft::random_access_iterator_tag, T>::iterator_category iterator_category;
	typedef typename ft::Iterator<ft::random_access_iterator_tag, T>::value_type		value_type;
	typedef typename ft::Iterator<ft::random_access_iterator_tag, T>::difference_type	difference_type;
	typedef T*																			pointer;
	typedef T&																			reference;

	random_access_iterator(void) : _elem(nullptr) { }

	random_access_iterator(pointer elem) : _elem(elem) { }

	random_access_iterator(const random_access_iterator& op) : _elem(op._elem) { }

	random_access_iterator& operator=(const random_access_iterator& op) {
		if ( this == &op )
			return (*this);
		this->_elem = op._elem;
		return (*this);
	}
	virtual ~random_access_iterator() { }

	pointer base() const {
		return (this->_elem);
	}

	reference operator*(void) const {
		return (*_elem);
	}

	pointer operator->(void) {
		return &(this->operator*());
	}

	random_access_iterator& operator++(void) {
		_elem++;
		return (*this);
	}

	random_access_iterator operator++(int) {
		random_access_iterator tmp(*this);
							   operator++();
		return (tmp);
	}

	random_access_iterator& operator--(void) {
		_elem--;
		return (*this);
	}

	random_access_iterator operator--(int) {
		random_access_iterator tmp(*this);
							   operator--();
		return (tmp);
	}

	random_access_iterator operator+(difference_type n) const {
		return (_elem + n);
	}

	random_access_iterator operator-(difference_type n) const {
		return (_elem - n);
	}

	random_access_iterator& operator+=(difference_type n) {
		_elem += n;
		return (*this);
	}

	random_access_iterator& operator-=(difference_type n) {
		_elem -= n;
		return (*this);
	}

	reference operator[](difference_type n) {
		return (*(operator+(n)));
	}

	operator random_access_iterator<const T>() const {
		return (random_access_iterator<const T>(this->_elem));
	}

private:
	pointer _elem;
};

template <typename T>
typename ft::random_access_iterator<T>::difference_type
operator==(const ft::random_access_iterator<T> lhs,
		   const ft::random_access_iterator<T> rhs) {
	return (lhs.base() == rhs.base());
}

template <typename T_L, typename T_R>
typename ft::random_access_iterator<T_L>::difference_type
operator==(const ft::random_access_iterator<T_L> lhs,
		   const ft::random_access_iterator<T_R> rhs) {
	return (lhs.base() == rhs.base());
}

template <typename T>
typename ft::random_access_iterator<T>::difference_type
operator!=(const ft::random_access_iterator<T> lhs,
		   const ft::random_access_iterator<T> rhs) {
	return (lhs.base() != rhs.base());
}

template <typename T_L, typename T_R>
typename ft::random_access_iterator<T_L>::difference_type
operator!=(const ft::random_access_iterator<T_L> lhs,
		   const ft::random_access_iterator<T_R> rhs) {
	return (lhs.base() != rhs.base());
}

template <typename T>
typename ft::random_access_iterator<T>::difference_type
operator<(const ft::random_access_iterator<T> lhs,
		  const ft::random_access_iterator<T> rhs) {
	return (lhs.base() < rhs.base());
}

template <typename T_L, typename T_R>
typename ft::random_access_iterator<T_L>::difference_type
operator<(const ft::random_access_iterator<T_L> lhs,
		  const ft::random_access_iterator<T_R> rhs) {
	return (lhs.base() < rhs.base());
}

template <typename T>
typename ft::random_access_iterator<T>::difference_type
operator>(const ft::random_access_iterator<T> lhs,
		  const ft::random_access_iterator<T> rhs) {
	return (lhs.base() > rhs.base());
}

template <typename T_L,
		  typename T_R>
typename ft::random_access_iterator<T_L>::difference_type
operator>(const ft::random_access_iterator<T_L> lhs,
		  const ft::random_access_iterator<T_R> rhs) {
	return (lhs.base() > rhs.base());
}

template <typename T>
typename ft::random_access_iterator<T>::difference_type
operator<=(const ft::random_access_iterator<T> lhs,
		   const ft::random_access_iterator<T> rhs) {
	return (lhs.base() <= rhs.base());
}

template <typename T_L, typename T_R>
typename ft::random_access_iterator<T_L>::difference_type
operator<=(const ft::random_access_iterator<T_L> lhs,
		   const ft::random_access_iterator<T_R> rhs) {
	return (lhs.base() <= rhs.base());
}

template <typename T>
typename ft::random_access_iterator<T>::difference_type
operator>=(const ft::random_access_iterator<T> lhs,
		   const ft::random_access_iterator<T> rhs) {
	return (lhs.base() >= rhs.base());
}

template <typename T_L,
		  typename T_R>
typename ft::random_access_iterator<T_L>::difference_type
operator>=(const ft::random_access_iterator<T_L> lhs,
		   const ft::random_access_iterator<T_R> rhs) {
	return (lhs.base() >= rhs.base());
}

template <typename T>
ft::random_access_iterator<T> operator+(
	typename ft::random_access_iterator<T>::difference_type n,
	typename ft::random_access_iterator<T>&					ref) {
	return (&(*ref) + n);
}

template <typename T>
typename ft::random_access_iterator<T>::difference_type
operator-(const ft::random_access_iterator<T> lhs,
		  const ft::random_access_iterator<T> rhs) {
	return (lhs.base() - rhs.base());
}

template <typename T_L, typename T_R>
typename ft::random_access_iterator<T_L>::difference_type
operator-(const ft::random_access_iterator<T_L> lhs,
		  const ft::random_access_iterator<T_R> rhs) {
	return (lhs.base() - rhs.base());
}

// template <class Iterator>
// struct iterator_traits {
// 	typedef typename Iterator::difference_type	 difference_type;
// 	typedef typename Iterator::value_type		 value_type;
// 	typedef typename Iterator::pointer			 pointer;
// 	typedef typename Iterator::reference		 reference;
// 	typedef typename Iterator::iterator_category iterator_category;
// };

// template <class T>
// class iterator_traits<T*> {
// 	typedef std::ptrdiff_t				   difference_type;
// 	typedef T							   value_type;
// 	typedef T*							   pointer;
// 	typedef T&							   reference;
// 	typedef ft::random_access_iterator_tag iterator_category;
// };

// template <class T>
// class iterator_traits<const T*> {
// 	typedef std::ptrdiff_t				   difference_type;
// 	typedef T							   value_type;
// 	typedef T const*					   pointer;
// 	typedef T const&					   reference;
// 	typedef ft::random_access_iterator_tag iterator_category;
// };

// template <class Iterator>
// class reverse_iterator {
// public:
// 	typedef Iterator												  iterator_type;
// 	typedef typename ft::iterator_traits<Iterator>::iterator_category iterator_category;
// 	typedef typename ft::iterator_traits<Iterator>::value_type		  value_type;
// 	typedef typename ft::iterator_traits<Iterator>::difference_type	  difference_type;
// 	typedef typename ft::iterator_traits<Iterator>::pointer			  pointer;
// 	typedef typename ft::iterator_traits<Iterator>::reference		  reference;

// 	reverse_iterator();

// 	explicit reverse_iterator(iterator_type it);

// 	reverse_iterator(const reverse_iterator<Iterator>& rev_it);
// };

}  // namespace ft

#endif