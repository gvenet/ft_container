#ifndef STACK_HPP
#define STACK_HPP

#include <deque>

namespace ft {

template <class T, class Container = std::deque<T> >
class stack {
public:
	typedef Container								 container_type;
	typedef typename container_type::value_type		 value_type;
	typedef typename container_type::reference		 reference;
	typedef typename container_type::const_reference const_reference;
	typedef typename container_type::size_type		 size_type;

protected:
	container_type c;

public:
	stack(const container_type& ctnr = container_type()) : c(ctnr) { }
	~stack() { }

	template <class C>
	C& operator=(const C& other) {
		c = other.c;
		return *this;
	}

	bool empty() const { return c.empty(); }

	size_type size() const { return c.size(); }

	reference		top() { return c.back(); }
	
	const_reference top() const { return c.back(); }

	void push(const value_type& x) { c.push_back(x); }

	void pop() { c.pop_back(); }
};

template <class T, class Container>
bool operator==(const stack<T, Container>& x, const stack<T, Container>& y) {
	return x.c == y.c;
}

template <class T, class Container>
bool operator<(const stack<T, Container>& x, const stack<T, Container>& y) {
	return x.c < y.c;
}

template <class T, class Container>
bool operator!=(const stack<T, Container>& x, const stack<T, Container>& y) {
	return !(x.c == y.c);
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