#include "inc/utils/binary_search_tree.hpp"
#include "iostream"

using namespace ft;

int main(void) {

bst_node<int> *root = new bst_node<int>(1);
root->right = new bst_node<int>(4);
root->left = new bst_node<int>(2);
root->left->left = new bst_node<int>(3);

std::cout<< root->value << " " << root->left->value << " " << root->left->left->value << "\n";


}
