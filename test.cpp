#include <map>
#include <random>

#include "inc/utils/binary_search_tree.hpp"
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
ft::Binary_search_tree<ft::pair<I1, I2> > asgn(I1 i1, I2 i2) {
	ft::Binary_search_tree<ft::pair<I1, I2> >			x;
	ft::Binary_search_tree<ft::pair<I1, I2> >::iterator it;

	ft::pair<I1, I2> p(i1, i2);
	x.insertPair(p);
	return x;
}

int main(void) {
	srand((unsigned int)time(NULL));

	typedef ft::Binary_search_tree<ft::pair<std::string, int> >					 s_i;
	typedef ft::Binary_search_tree<ft::pair<std::string, std::string> >			 s_s;
	typedef ft::Binary_search_tree<ft::pair<char, rdm> >						 c_r;
	typedef ft::Binary_search_tree<ft::pair<int, int> >							 i_i;
	typedef ft::Binary_search_tree<ft::pair<double, std::string> >				 d_s;
	typedef ft::Binary_search_tree<ft::pair<double, ft::pair<double, double> > > d_dd;

	std::string s = "toto";
	s_i si = asgn(s, 2);

		return 0;
}
