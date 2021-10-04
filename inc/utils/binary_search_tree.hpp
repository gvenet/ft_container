#ifndef BINARY_SEARCH_TREE_HPP
#define BINARY_SEARCH_TREE_HPP

#include <iostream>
#include <memory>

#include "functional.hpp"

namespace ft {

template <typename T>
struct bst_node {
	typedef T value_type;

	value_type value;
	bst_node*  left;
	bst_node*  right;
	bst_node*  parent;

	bst_node(value_type _value) : value(_value), left(), right(), parent() { }
};

template <class T, class Compare = ft::less<T>, class Allocator = std::allocator<T> >
class binary_search_tree {
public:
	typedef T					 value_type;
	typedef Compare				 value_compare;
	typedef Allocator			 allocator_type;
	typedef bst_node<value_type> node_type;

	binary_search_tree() : _root() { }

	~binary_search_tree() {
		clean(_root);
	}

public:
	node_type* insert(node_type* node, value_type key) {
		if ( !node ) {
			node = new_node(key);
		} else if ( key == node->value ) {
			return node;
		} else if ( key < node->value ) {
			node->left = insert(node->left, key);
			node->left->parent = node;
		} else {
			node->right = insert(node->right, key);
			node->right->parent = node;
		}
		return node;
	}

public:
	void insert(value_type key) {
		_root = insert(_root, key);
	}

private:
	void printTreeInOrder(node_type* node) {
		if ( !node )
			return;
		printTreeInOrder(node->left);
		std::cout << node->value << " ";
		printTreeInOrder(node->right);
	}

public:
	void printTreeInOrder() {
		if ( !_root )
			return;
		printTreeInOrder(_root);
		std::cout << std::endl;
	}

private:
	node_type* search(node_type* node, value_type key) {
		if ( !node )
			return nullptr;
		else if ( node->value == key )
			return node;
		else if ( node->value < key )
			return search(node->right, key);
		else
			return search(node->left, key);
	}

public:
	bool search(value_type key) {
		node_type* result = search(_root, key);
		return result == nullptr ? false : true;
	}

private:
	value_type findMin(node_type* node) {
		if ( !node->left )
			return node->value;
		else
			return findMin(node->left);
	}

public:
	value_type findMin() {
		return findMin(_root);
	}

private:
	value_type findMax(node_type* node) {
		if ( !node->right )
			return node->value;
		else
			return findMax(node->right);
	}

public:
	value_type findMax() {
		return findMax(_root);
	}

private:
	value_type successor(node_type* node) {
		if ( node->right ) {
			return findMin(node->right);
		} else {
			node_type* parentNode = node->parent;
			node_type* currentNode = node;
			while ( (parentNode) && (currentNode == parentNode->right) ) {
				currentNode = parentNode;
				parentNode = currentNode->parent;
			}
			return parentNode->value;
		}
	}

public:
	value_type successor(value_type key) {
		node_type* keyNode = search(_root, key);
		return successor(keyNode);
	}

private:
	value_type predecessor(node_type* node) {
		if ( node->left ) {
			return findMax(node->left);
		} else {
			node_type* parentNode = node->parent;
			node_type* currentNode = node;
			while ( (parentNode) && (currentNode == parentNode->left) ) {
				currentNode = parentNode;
				parentNode = currentNode->parent;
			}
			return parentNode->value;
		}
	}

public:
	value_type predecessor(value_type key) {
		node_type* keyNode = search(_root, key);
		return predecessor(keyNode);
	}

private:
	node_type* remove(node_type* node, value_type key) {
		if ( !node )
			return nullptr;
		if ( node->value == key ) {
			if ( !node->left && !node->right ) {
				delete node;
				node = nullptr;
			} else if ( !node->left && node->right ) {
				node->right->parent = node->parent;
				node = node->right;
			} else if ( node->left && !node->right ) {
				node->left->parent = node->parent;
				node = node->left;
			} else {
				value_type successorKey = successor(key);
				node->value = successorKey;
				node->right = remove(node->right, successorKey);
			}
		} else if ( node->value < key )
			node->right = remove(node->right, key);
		else
			node->left = remove(node->left, key);
		return node;
	}

public:
	void remove(value_type key) {
		_root = remove(_root, key);
	}

private:
private:
	void clean(node_type* node) {
		if ( node->left )
			clean(node->left);
		if ( node->right )
			clean(node->right);
		delete node;
		node = nullptr;
		return;
	}

	void clean() {
		clean(_root);
	}

	node_type* new_node(value_type key) {
		node_type* node = new node_type(key);
		return node;
	}

private:
	node_type* _root;
};

}  // namespace ft
#endif