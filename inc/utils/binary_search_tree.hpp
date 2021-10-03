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
	typedef T		  value_type;
	typedef Compare	  value_compare;
	typedef Allocator allocator_type;

	binary_search_tree() : _root(nullptr) { }

public:
	bst_node<value_type>* insert(bst_node<value_type>* node, value_type key) {
		if ( !node ) {
			node = new bst_node<value_type>(key);
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
	void printTreeInOrder(bst_node<value_type>* node) {
		if ( node == NULL )
			return;
		printTreeInOrder(node->left);
		std::cout << node->value << " ";
		printTreeInOrder(node->right);
	}

public:
	void printTreeInOrder() {
		printTreeInOrder(_root);
		std::cout << std::endl;
	}

private:
	bst_node<value_type>* search(bst_node<value_type>* node, value_type key) {
		if ( node == NULL )
			return NULL;
		else if ( node->value == key )
			return node;
		else if ( node->value < key )
			return search(node->right, key);
		else
			return search(node->left, key);
	}

public:
	bool search(value_type key) {
		bst_node<value_type>* result = search(_root, key);
		return result == NULL ? false : true;
	}

private:
	value_type findMin(bst_node<value_type>* node) {
		if ( node->left == NULL )
			return node->value;
		else
			return findMin(node->left);
	}

public:
	value_type findMin() {
		return findMin(_root);
	}

private:
	value_type findMax(bst_node<value_type>* node) {
		if ( node->right == NULL )
			return node->value;
		else
			return findMax(node->right);
	}

public:
	value_type findMax() {
		return findMax(_root);
	}

private:
	value_type successor(bst_node<value_type>* node) {
		if ( node->right != NULL ) {
			return findMin(node->right);
		} else {
			bst_node<value_type>* parentNode = node->parent;
			bst_node<value_type>* currentNode = node;
			while ( (parentNode != NULL) && (currentNode == parentNode->right) ) {
				currentNode = parentNode;
				parentNode = currentNode->parent;
			}
			return parentNode->value;
		}
	}

public:
	value_type successor(value_type key) {
		bst_node<value_type>* keyNode = search(_root, key);
		return successor(keyNode);
	}

private:
	value_type predecessor(bst_node<value_type>* node) {
		if ( node->left != NULL ) {
			return findMax(node->left);
		} else {
			bst_node<value_type>* parentNode = node->parent;
			bst_node<value_type>* currentNode = node;
			while ( (parentNode != NULL) &&
					(currentNode == parentNode->left) ) {
				currentNode = parentNode;
				parentNode = currentNode->parent;
			}
			return parentNode->value;
		}
	}

public:
	value_type predecessor(value_type key) {
		bst_node<value_type>* keyNode = search(_root, key);
		return predecessor(keyNode);
	}

private:
	bst_node<value_type>* remove(bst_node<value_type>* node, value_type key) {
		if ( node == NULL )
			return NULL;
		if ( node->value == key ) {
			if ( node->left == NULL && node->right == NULL ) {
				delete node;
				node = NULL;
			}
			else if ( node->left == NULL && node->right != NULL ) {
				node->right->parent = node->parent;
				node = node->right;
			} else if ( node->left != NULL && node->right == NULL ) {
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
	bst_node<value_type>* _root;
};

}  // namespace ft
#endif