#ifndef ALGORITHM_HPP
#define ALGORITHM_HPP

namespace ft {

template <class InputIterator1, class InputIterator2>
bool lexicographical_compare(InputIterator1 first1,
							 InputIterator1 last1,
							 InputIterator2 first2,
							 InputIterator2 last2,
							 typename ft::enable_if<
								 !ft::is_integral<InputIterator1>::value,
								 InputIterator1>::type* = nullptr,
							 typename ft::enable_if<
								 !ft::is_integral<InputIterator2>::value,
								 InputIterator2>::type* = nullptr) {
	while ( first1 != last1 ) {
		if ( first2 == last2 || *first2 < *first1 )
			return false;
		else if ( *first1 < *first2 )
			return true;
		++first1;
		++first2;
	}
	return (first2 != last2);
}

}  // namespace ft

#endif