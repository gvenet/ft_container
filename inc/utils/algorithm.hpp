#ifndef ALGORITHM_HPP
#define ALGORITHM_HPP

#include "type_traits.hpp"
#include "functional.hpp"

namespace ft {

template <class InputIterator1, class InputIterator2>
bool lexicographical_compare(
		InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2,
		typename ft::enable_if<!ft::is_integral<InputIterator1>::value, InputIterator1>::type* =
				nullptr,
		typename ft::enable_if<!ft::is_integral<InputIterator2>::value, InputIterator2>::type* =
				nullptr ) {
	while ( first1 != last1 ) {
		if ( first2 == last2 || *first2 < *first1 )
			return false;
		else if ( *first1 < *first2 )
			return true;
		++first1;
		++first2;
	}
	return ( first2 != last2 );
}

template <class InputIterator1, class InputIterator2>
bool equal( InputIterator1 first1, InputIterator1 last1, InputIterator2 first2 ) {
	while ( first1 != last1 ) {
		if ( !( *first1 == *first2 ) )
			return false;
		++first1;
		++first2;
	}
	return true;
}

template <class _Tp, class _Compare>
const _Tp& min( const _Tp& __a, const _Tp& __b, _Compare __comp ) {
	return __comp( __b, __a ) ? __b : __a;
}

template <class _Tp>
const _Tp& min(const _Tp& __a, const _Tp& __b)
{
    return ft::min(__a, __b, ft::less<_Tp>());
}

} // namespace ft

#endif