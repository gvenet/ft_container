#ifndef TYPE_TRAITS_HPP
#define TYPE_TRAITS_HPP

namespace ft {

//value_type
struct false_type {
	static const bool value = false;
};

struct true_type {
	static const bool value = true;
};

// enable_if
template <bool, class T = void>
struct enable_if {
};

template <class T>
struct enable_if<true, T> {
	typedef T type;
};

// is_same
template <class T, class U>
struct is_same : false_type {
};

template <class T>
struct is_same<T, T> : true_type {
};

//is_integral
template <class T>
struct is_integral_base : false_type { };
template <>
struct is_integral_base<bool> : true_type { };
template <>
struct is_integral_base<char> : true_type { };
template <>
struct is_integral_base<signed char> : true_type { };
template <>
struct is_integral_base<unsigned char> : true_type { };
template <>
struct is_integral_base<wchar_t> : true_type { };
template <>
struct is_integral_base<char16_t> : true_type { };
template <>
struct is_integral_base<char32_t> : true_type { };
template <>
struct is_integral_base<short> : true_type { };
template <>
struct is_integral_base<unsigned short> : true_type { };
template <>
struct is_integral_base<int> : true_type { };
template <>
struct is_integral_base<unsigned int> : true_type { };
template <>
struct is_integral_base<long> : true_type { };
template <>
struct is_integral_base<unsigned long> : true_type { };
template <>
struct is_integral_base<long long> : true_type { };
template <>
struct is_integral_base<unsigned long long> : true_type { };
template <>
struct is_integral_base<__int128_t> : true_type { };
template <>
struct is_integral_base<__uint128_t> : true_type { };

template <class T>
struct is_integral : is_integral_base<T> {
};

template <class T>
struct is_input_iterator_tagged : true_type {

};

template <class _InputIter>
typename iterator_traits<_InputIter>::difference_type distance(_InputIter __first, _InputIter __last)
{
    typename iterator_traits<_InputIter>::difference_type __r(0);
    for (; __first != __last; ++__first)
        ++__r;
    return __r;
}

}  // namespace ft
#endif