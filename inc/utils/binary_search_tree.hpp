#ifndef BINARY_SEARCH_TREE_HPP
#define BINARY_SEARCH_TREE_HPP

#include <memory>

#include "functional.hpp"

namespace ft {

template <typename T>
struct bst_node {
	typedef T value_type;

	value_type value;
	bst_node*	   left;
	bst_node*	   right;
	bst_node*	   parent;

	node(value_type _value) : value(_value) { }
};

template <class T, class Compare = ft::less<T>, class Allocator = std::allocator<T> >
class binary_search_tree {
public:
	typedef T		  value_type;
	typedef Compare	  value_compare;
	typedef Allocator allocator_type;
};

}  // namespace fr
#endif