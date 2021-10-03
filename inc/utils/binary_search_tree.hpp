#ifndef BINARY_SEARCH_TREE_HPP
#define BINARY_SEARCH_TREE_HPP

#include <memory>

#include "functional.hpp"
#include "node.hpp"

template <class T, class Compare = ft::less<T>, class Allocator = std::allocator<T> >
class binary_search_tree {
public:
	typedef T		  value_type;
	typedef Compare	  value_compare;
	typedef Allocator allocator_type;


};

#endif