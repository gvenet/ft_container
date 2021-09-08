#ifndef UTILS_HPP
#define UTILS_HPP

static class nullptr_t {
public:
	template <class T>
	operator T*() const { return (0); }

	template <class C, class T>
	operator T C::*() const { return (0); }

private:
	void operator&() const;

} u_nullptr = {};

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

class random_access_iterator_tag { };

}  // namespace ft

#endif
