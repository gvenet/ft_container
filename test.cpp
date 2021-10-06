#include <map>
#include <random>

#include "inc/utils/binary_search_tree.hpp"
#include "inc/utils/binary_search_tree_iterator.hpp"
#include "inc/utils/functional.hpp"
#include "inc/utils/pair.hpp"
#include "iostream"

double rdm_gen(int range) {
	return ((rand() % range) + 10);
}

struct rdm {
	double a;
	double b;
	double c;

	rdm() : a(rdm_gen(89)), b(rdm_gen(89)), c(a / b) {
	}
};

template <typename I1, typename I2>
void asgn(I1 i1, I2 i2, ft::Binary_search_tree<ft::pair<I1, I2> > &x) {
	ft::pair<I1, I2> p(i1, i2);
	x.insertPair(p);
}

int main(void) {
	srand((unsigned int)time(NULL));

	typedef ft::Binary_search_tree<ft::pair<std::string, int> >					 s_i;
	typedef ft::Binary_search_tree<ft::pair<std::string, std::string> >			 s_s;
	typedef ft::Binary_search_tree<ft::pair<char, rdm> >						 c_r;
	typedef ft::Binary_search_tree<ft::pair<int, int> >							 i_i;
	typedef ft::Binary_search_tree<ft::pair<double, std::string> >				 d_s;
	typedef ft::Binary_search_tree<ft::pair<double, ft::pair<double, double> > > d_dd;

	i_i ii;
	asgn<int, int>(0, 2, ii);
	asgn<int, int>(1, 9, ii);
	asgn<int, int>(2, 7, ii);

	i_i::iterator it0(ii._last_node->left, ii._last_node);
	i_i::iterator it1(ii._last_node->left->parent, ii._last_node);
	// i_i::iterator itb(ii._last_node->right, ii._last_node);

	std::cout << it0->first << "\n";
	std::cout << it1->first << "\n";

	// while ( ite != itb ) {
	// 	std::cout << ite->first << "\t" << ite->second << "\n";
	// 	ite++;
	// }

	return 0;
}
