#include <iostream>
#include <string>

namespace ft {

template <typename T = float>
class test {
public:
	test(T const &a, T const &b, T const &c) : _a(a), _b(b), _c(c) { }
	~test() { }

	T const &getA(void) { return _a; };
	T const &getB(void) { return _b; };
	T const &getC(void) { return _c; };

private:
	T const _a;
	T const _b;
	T const _c;

	test() { }
};

}  // namespace ft

template <typename T>
std::ostream &operator<<(std::ostream &os, ft::test<T> &rhs) {
	os << "A: " << rhs.getA() << "\nB: " << rhs.getB() << "\nC: " << rhs.getC() << "\n";
	return os;
}

int main(void) {
	ft::test<int> x(2, 4, 6);
	ft::test<>	  y(2.1, 4.1, 6.1);

	std::cout << x << "\n" << y << "\n";
	return 0;
}