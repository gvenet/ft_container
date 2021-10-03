#include "inc/utils/node.hpp"
#include "iostream"

using namespace ft;

int main(void) {

node<int> *root = new node<int>(1);
root->right = new node<int>(4);
root->left = new node<int>(2);
root->left->left = new node<int>(3);

std::cout<< root->value << " " << root->left->value << " " << root->left->left->value << "\n";


}
