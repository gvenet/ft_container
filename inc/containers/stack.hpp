#ifndef STACK_HPP
#define STACK_HPP

#include "vector.hpp"

namespace ft {
template <class T, class Container = ft::vector<T> >
class stack {
public:
	typedef Container								 container_type;
	typedef typename container_type::value_type		 value_type;
	typedef typename container_type::reference		 reference;
	typedef typename container_type::const_reference const_reference;
	typedef typename container_type::size_type		 size_type;

protected:
	container_type _c;

public:
	stack(const container_type& ctnr = container_type()) : _c(ctnr) { }
	~stack() { }

	stack& operator=(const stack& other) {
		_c = other._c;
		return *this;
	}

	bool empty() const { return _c.empty(); }

	size_type size() const { return _c.size(); }

	reference		top() { return _c.back(); }
	
	const_reference top() const { return _c.back(); }

	void push(const value_type& x) { _c.push_back(x); }

	void pop() { _c.pop_back(); }
};

template <class T, class Container>
bool operator==(const stack<T, Container>& x, const stack<T, Container>& y) {
	return x._c == y._c;
}

template <class T, class Container>
bool operator<(const stack<T, Container>& x, const stack<T, Container>& y) {
	return x._c < y._c;
}

template <class T, class Container>
bool operator!=(const stack<T, Container>& x, const stack<T, Container>& y) {
	return !(x._c == y._c);
}

template <class T, class Container>
bool operator>(const stack<T, Container>& x, const stack<T, Container>& y) {
    return y < x;
}

template <class T, class Container>
bool operator>=(const stack<T, Container>& x, const stack<T, Container>& y) {
	return !(x < y);
}

template <class T, class Container>
bool operator<=(const stack<T, Container>& x, const stack<T, Container>& y) {
	return !(y < x);
}

}  // namespace ft

#endif