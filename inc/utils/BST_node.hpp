#ifndef BST_NODE_HPP
#define BST_NODE_HPP

namespace ft {

template <typename T>
struct BST_Node {
	typedef T value_type;

	value_type value;
	BST_Node*  parent;
	BST_Node*  left;
	BST_Node*  right;

	BST_Node()
		: value(), parent(), left(), right() { }

	BST_Node(const value_type& val)
		: value(val), parent(), left(), right() { }

	BST_Node(BST_Node* parent, BST_Node* left, BST_Node* right)
		: value(), parent(parent), left(left), right(right) { }

	BST_Node(const value_type& val, BST_Node* parent, BST_Node* left, BST_Node* right)
		: value(val), parent(parent), left(left), right(right) { }

	BST_Node(const BST_Node& nd)
		: value(nd.value), parent(nd.parent), left(nd.left), right(nd.right) { }

	virtual ~BST_Node() { }

	BST_Node& operator=(const BST_Node& nd) {
		if ( nd == *this )
			return (*this);

		this->value = nd.value;
		this->parent = nd.parent;
		this->left = nd.left;
		this->right = nd.right;

		return (*this);
	}

	bool operator==(const BST_Node& nd) {
		if ( value == nd.value )
			return (true);
		return (false);
	}
};

}  // namespace ft
#endif