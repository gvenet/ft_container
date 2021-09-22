#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <typeinfo>
#include <vector>

#include "../inc/vector.hpp"

#define FT	" ft"
#define STD "std"

template <class C>
void print(C &v, std::string ns) {
	typename C::iterator it;
	std::cout << ns << "  | s : " << v.size() << "\t| c : " << v.capacity() << "\t| val : ";
	for ( it = v.begin(); it != v.end(); it++ ) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

// template <class C>
// void test(C &v, int &i) {
// 	v.reserve(i);
// 	for ( int i = 0; i < 20; i++ ) {
// 		v.push_back(6);
// 		std::cout << v.size() << " " << v.capacity() << " | ";
// 	}
// 	std::cout << std::endl;
// }

// void test1(void) {
// 	std::vector<int> vstd;
// 	ft::vector<int>	 vft;

// 	std::cout << "-------- TEST_1 --------\n";
// 	int r = 10;
// 	for ( int i = 2; i < r; i++ ) {
// 		test(vft, i);
// 		test(vstd, i);
// 		std::cout << std::endl;
// 	}
// }

// template <class C, typename T>
// void test2_an(C &v, T elemToAdd, std::string ns) {
// 	v.insert(v.begin(), elemToAdd);
// 	print(v, ns);
// 	std::cout << std::endl;
// }

// void test2() {
// 	ft::vector<std::string>	 vft;
// 	std::vector<std::string> vstd;

// 	std::cout << "-------- TEST_2 --------\n";
// 	for ( int i = 0; i < 10; i++ ) {
// 		std::string s = std::to_string(i);
// 		test2_an(vstd, s, FT);
// 		test2_an(vft, s, STD);
// 	}
// }

// template <class C, typename T>
// void test_3_an1(C &v, T &tab, int &nl, std::string ns) {
// 	for ( int i = 0; i < nl; i++ ) {
// 		v.insert(v.end(), tab[i]);
// 	}
// 	print(v, ns);
// }

// template <class C>
// void test_3_an2(C &v, int &nl, std::string ns) {
// 	for ( int i = 0; i < nl; i++ ) {
// 		v.erase(v.begin() + (nl - i - 1));
// 		print(v, ns);
// 	}
// }

// void test3(void) {
// 	ft::vector<int>	 vft;
// 	std::vector<int> vstd;
// 	int				 tab[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
// 	int				 nl = 8;

// 	std::cout << "-------- TEST_3 --------\n";
// 	test_3_an1(vft, tab, nl, FT);
// 	test_3_an1(vstd, tab, nl, STD);
// 	test_3_an2(vft, nl, FT);
// 	test_3_an2(vstd, nl, STD);
// }

// template <class C, typename T>
// void test4_an(C &v, int sizeToAdd, T elemToAdd, std::string ns) {
// 	v.resize(sizeToAdd, elemToAdd);
// 	print(v, ns);
// 	std::cout << "\n";
// }

// void test4(void) {
// 	std::cout << "-------- TEST_4 --------\n";

// 	int				 size = 7;
// 	std::vector<int> vstd(size, 3);
// 	ft::vector<int>	 vft(size, 3);
// 	int				 t[] = {19, 4, 56, 1, 41, 0, 83, 111};

// 	print(vstd, STD);
// 	print(vft, FT);
// 	std::cout << "\n";

// 	// for ( int i = 2; i < 50; i += 9 ) {
// 	// 	test4_an(vft, vstd, i, 1);
// 	// }

// 	for ( int i = 0; i < 8; i++ ) {
// 		test4_an(vft, t[i], i + 1, FT);
// 		test4_an(vstd, t[i], i + 1, STD);
// 	}

// 	vstd.resize(5);
// 	vft.resize(5);
// 	print(vstd, STD);
// 	print(vft, FT);
// 	std::cout << "\n";

// 	vstd.resize(15);
// 	vft.resize(15);
// 	print(vstd, STD);
// 	print(vft, FT);
// 	std::cout << "\n";
// }

// template <class C>
// void test5_an(C &v) {
// 	std::vector<int>::size_type s;
// 	size_t						cap = 7;

// 	s = v.capacity();
// 	v.reserve(cap);
// 	for ( int i = 0; i < 129; i++ ) {
// 		v.push_back(i);
// 		if ( s != v.capacity() ) {
// 			s = v.capacity();
// 			std::cout << s << "\n";
// 		}
// 	}

// 	std::cout << "\n";
// }

// void test5(void) {
// 	std::vector<int> vstd;
// 	ft::vector<int>	 vft;

// 	std::cout << "-------- TEST_5 --------\n";
// 	test5_an(vstd);
// 	test5_an(vft);
// }

// template <class C>
// void test6_an(C &v, size_t sr, std::string ns) {
// 	v.reserve(sr);
// 	for ( int i = 0; i < 4; i++ ) {
// 		v.insert(v.begin(), i);
// 		v.insert(v.end() - 1, i);
// 		print(v, ns);
// 		std::cout << "\n";
// 	}
// }

// void test6(void) {
// 	std::cout << "-------- TEST_6 --------\n";

// 	size_t			 sr = 0;
// 	ft::vector<int>	 vft;
// 	std::vector<int> vstd;

// 	for ( int i = 0; i < 2; i++ ) {
// 		sr = i * 32;
// 		test6_an(vft, sr, FT);
// 		test6_an(vstd, sr, STD);
// 	}
// }
// void test7(void) {
// 	std::cout << "-------- TEST_7 --------\n";

// 	std::vector<int> vstd;
// 	ft::vector<int>	 vft;
// 	int				 t[] = {10, 20, 15, 40};

// 	for ( int i = 0; i < 4; i++ ) {
// 		vstd.assign(t[i], i);
// 		vft.assign(t[i], i);
// 		print(vstd, STD);
// 		print(vft, FT);
// 	}
// }

// template <class C>
// void test8_an(C &v1, C &v2, std::string ns) {
// 	print(v1, ns);
// 	print(v2, ns);
// 	v1.swap(v2);
// 	print(v1, ns);
// 	print(v2, ns);
// }

// void test8(void) {
// 	std::vector<int> vstd1(5, 100);
// 	std::vector<int> vstd2(1, 200);
// 	ft::vector<int>	 vft1(5, 100);
// 	ft::vector<int>	 vft2(1, 200);

// 	std::cout << "-------- TEST_8 --------\n";
// 	test8_an(vft1, vft2, STD);
// 	test8_an(vft1, vft2, FT);
// }

// void test9(void) {
// 	ft::vector<int> vft;

// 	std::cout << "-------- TEST_9 --------\n";
// 	vft.push_back(10);
// 	vft.push_back(20);
// 	vft.push_back(30);

// 	ft::vector<int> v;
// 	v = vft;
// 	if ( v == vft ) {
// 		std::cout << "test ok\n";
// 	}
// }

// void test10(void) {
// 	std::cout << "-------- TEST_10 --------\n";

// 	std::vector<int> x1(4, 5);
// 	std::vector<int> y1(5, 5);

// 	ft::vector<int> x2(4, 5);
// 	ft::vector<int> y2(5, 5);

// 	for ( int i = 0; i < 10; i++ ) {
// 		std::cout << "i = " << i << " | ";
// 		x1.push_back(i);
// 		x2.push_back(i);
// 		(x1 < y1) ? std::cout << "\e[01;31mx1 < y1\e[0m | " : std::cout << "\e[01;32mx1 > y1\e[0m | ";
// 		(x2 < y2) ? std::cout << "\e[01;31mx2 < y2\e[0m\n" : std::cout << "\e[01;32mx2 > y2\e[0m\n";
// 		x1.pop_back();
// 		x2.pop_back();
// 	}
// }

// void test11(void) {
// 	std::cout << "-------- TEST_11 --------\n";

// 	ft::vector<int> x(5, 5);
// 	ft::vector<int> y(x);

// 	(x == y) ? std::cout << "hotdog\n" : std::cout << "not a hotdog\n";
// 	y.push_back(42);
// 	(x == y) ? std::cout << "hotdog\n" : std::cout << "not a hotdog\n";
// }

// void test12(void) {
// 	std::cout << "-------- TEST_12 --------\n";

// 	ft::vector<std::string> x(5, "test12");

// 	for ( size_t i = 0; i < 5; i++ ) {
// 		std::cout << x[i] << "\n";
// 	}
// }

// void test13(void) {
// 	std::cout << "-------- TEST_13 --------\n";

// 	ft::vector<int>	 x;
// 	std::vector<int> y;

// 	for ( int i = 1; i < 6; i++ ) {
// 		x.push_back(i);
// 		y.push_back(i);
// 	}
// 	print(x, FT);
// 	print(y, STD);
// 	std::cout << "ft  : front : " << x.front() << " | back : " << x.back() << "\n";
// 	std::cout << "std : front : " << y.front() << " | back : " << y.back() << "\n";
// }

// void test14(void) {
// 	ft::vector<int>			   x;
// 	ft::vector<int>::pointer   start;
// 	ft::vector<int>::pointer   end;
// 	ft::vector<int>::pointer   end_cap;
// 	ft::vector<int>::size_type size;
// 	ft::vector<int>::size_type i;
// 	size_t					   n = 10;

// 	std::cout << "-------- TEST_14 --------\n";
// 	start = x.get_allocator().allocate(n);
// 	end = start;
// 	end_cap = start + n;
// 	for ( i = 0; i < 5; i++ ) {
// 		x.get_allocator().construct(start + i, 5);
// 		end++;
// 	}
// 	size = end - start;
// 	std::cout << size << " " << end_cap - start << " " << std::endl;
// 	for ( i = 0; i < 5; i++ ) {
// 		std::cout << *(start + i) << " ";
// 	}
// 	std::cout << "\n";
// 	x.get_allocator().deallocate(start, n);
// }

// void test15(void) {
// 	ft::vector<std::string> x;

// 	std::cout << "-------- TEST_15 --------\n";
// 	x.push_back("aaa");
// 	x.push_back("bbb");
// 	x.push_back("ccc");

// 	for ( ft::vector<std::string>::iterator it = x.end() - 1; it != x.begin() - 1; it-- ) {
// 		std::cout << &(*it) << " " << *it << "\n";
// 	}
// 	std::cout << "\n";
// }

// void test16(void) {
// 	std::vector<int> x;
// 	std::vector<int> y(5, 9);
// 	ft::vector<int>	 a;
// 	ft::vector<int>	 b(5, 9);

// 	std::cout << "-------- TEST_16 --------\n";
// 	print(x, STD);
// 	print(y, STD);
// 	print(a, FT);
// 	print(b, FT);
// 	std::cout << "-------------------------\n";

// 	std::swap(x, y);
// 	ft::swap(a, b);

// 	print(x, STD);
// 	print(y, STD);
// 	print(a, FT);
// 	print(b, FT);
// }

// void test17(void) {
// 	ft::vector<int>					  x;
// 	ft::vector<int>::reverse_iterator it;
// 	ft::vector<int> *				  y;

// 	y = &x;
// 	for ( int i = 0; i < 10; i++ ) {
// 		x.push_back(i);
// 		y->push_back(i);
// 	}

// 	for ( it = x.rbegin(); it != x.rend(); it++ ) {
// 		std::cout << *it << " ";
// 	}
// 	std::cout << "\n";
// 	print(x, FT);
// }

// void test18(void) {
// 	ft::vector<int> x;

// 	for ( int i = 0; i < 16; i++ ) {
// 		x.push_back(i);
// 	}

// 	ft::vector<int> y(x.begin() + 2, x.end() - 2);
// 	print(x, STD);
// 	print(y, STD);

// 	ft::vector<int>::reverse_iterator rit;
// 	for (rit = y.rbegin(); rit != y.rend(); rit++) {
// 		std::cout << *rit <<" ";
// 	}
// 	std::cout << "\n";

// }

void test19(void) {
	ft::vector<int> a;

	a.reserve(9);
	for ( int i = 0; i < 9; i++ ) {
		a.push_back(i);
	}
	ft::vector<int> b(a.begin(), a.end() - 5);

	print(a, FT);
	print(b, FT);

	ft::vector<std::string> c(9);
	print(c, FT);

	// ft::vector<std::string> d(1, 1);
}

int main(void) {
	// test1();
	// test2();
	// test3();
	// test4();
	// test5();
	// test6();
	// test7();
	// test8();
	// test9();
	// test10();
	// test11();
	// test12();
	// test13();
	// test14();
	// test15();
	// test16();
	// test17();
	// test18();
	test19();
	return 0;
}