#ifndef BST_NODE_HPP
#define BST_NODE_HPP

namespace ft {

template <typename T>
struct bst_node {
	typedef T value_type;

	value_type value;
	node*	   left;
	node*	   right;
	node*	   parent;

	node(value_type _value) : value(_value) {}

};
}  // namespace ft
#endif