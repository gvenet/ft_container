#ifndef FUNCTIONAL_HPP
#define FUNCTIONAL_HPP

namespace ft {

template <class _Arg1, class _Arg2, class _Result>
struct binary_function {
	typedef _Arg1	first_argument_type;
	typedef _Arg2	second_argument_type;
	typedef _Result result_type;
};

template <class T>
struct less : ft::binary_function<T, T, bool> {
	bool operator()(const T& x, const T& y) const {
		return x < y;
	}
};

}  // namespace ft
#endif