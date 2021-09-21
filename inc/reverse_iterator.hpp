#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP

#include "reverse_iterator.hpp"

namespace ft {

template <class Iterator>
class reverse_iterator {
public:
	typedef Iterator												  iterator_type;
	typedef typename ft::iterator_traits<Iterator>::iterator_category iterator_category;
	typedef typename ft::iterator_traits<Iterator>::value_type		  value_type;
	typedef typename ft::iterator_traits<Iterator>::difference_type	  difference_type;
	typedef typename ft::iterator_traits<Iterator>::pointer			  pointer;
	typedef typename ft::iterator_traits<Iterator>::reference		  reference;

	reverse_iterator() : _it(), _current() { }

	explicit reverse_iterator(Iterator it) : _it(it), _current(it) { }

	reverse_iterator(const reverse_iterator<Iterator>& cpy) : _it(cpy.base()), _current(cpy.base()) { }

	reverse_iterator& operator=(const reverse_iterator<Iterator>& cpy) {
		_it = _current = cpy.base();
		return *this;
	}

	Iterator base() const {
		return _current;
	}

	reference operator*() const {
		Iterator tmp = _current;
		return *--tmp;
	}

	pointer operator->() const {
		return (&(operator*()));
	}

	reverse_iterator& operator++() {
		--_current;
		return *this;
	}

	reverse_iterator operator++(int) {
		reverse_iterator tmp(*this);
		--_current;
		return tmp;
	}

	reverse_iterator& operator--() {
		++_current;
		return *this;
	}

	reverse_iterator operator--(int) {
		reverse_iterator tmp(*this);
		++_current;
		return tmp;
	}

	reverse_iterator operator+(difference_type n) const {
		return reverse_iterator(_current - n);
	}

	reverse_iterator& operator+=(difference_type n) {
		_current -= n;
		return *this;
	}

	reverse_iterator operator-(difference_type n) const {
		return reverse_iterator(_current + n);
	}

	reverse_iterator& operator-=(difference_type n) {
		_current += n;
		return *this;
	}

	reference operator[](difference_type n) const {
		return *(*this + n);
	}

private:
	Iterator _it;

protected:
	Iterator _current;
};

template <class _Iter1, class _Iter2>
bool operator!=(const reverse_iterator<_Iter1>& x, const reverse_iterator<_Iter2>& y) {
	return x.base() != y.base();
}

}  // namespace ft
#endif