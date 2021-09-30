#include <algorithm>
#include <iostream>
#include <iterator>
#include <map>
#include <string>
#include <typeinfo>
#include <vector>

#include "../inc/utils.hpp"
#include "../inc/vector.hpp"

template <class C>
void test(C &v, int &i) {
	v.reserve(i);
	for ( int i = 0; i < 20; i++ ) {
		v.push_back(6);
		std::cout << v.size() << " " << v.capacity() << " | ";
	}
	std::cout << std::endl;
}

void test1(void) {
	std::vector<int> vstd;
	ft::vector<int>	 vft;

	std::cout << "\n-------- TEST_1 --------\n";
	int r = 10;
	for ( int i = 2; i < r; i++ ) {
		test(vft, i);
		test(vstd, i);
		std::cout << std::endl;
	}
}

template <class C, typename T>
void test2_an(C &v, T elemToAdd, std::string ns) {
	v.insert(v.begin(), elemToAdd);
	ft::print(v, ns);
	std::cout << std::endl;
}

void test2() {
	ft::vector<std::string>	 vft;
	std::vector<std::string> vstd;

	std::cout << "\n-------- TEST_2 --------\n";
	for ( int i = 0; i < 10; i++ ) {
		std::string s = std::to_string(i);
		test2_an(vstd, s, ft::FT);
		test2_an(vft, s, ft::STD);
	}
}

template <class C, typename T>
void test_3_an1(C &v, T &tab, int &nl, std::string ns) {
	for ( int i = 0; i < nl; i++ ) {
		v.insert(v.end(), tab[i]);
	}
	ft::print(v, ns);
}

template <class C>
void test_3_an2(C &v, int &nl, std::string ns) {
	for ( int i = 0; i < nl; i++ ) {
		v.erase(v.begin() + (nl - i - 1));
		ft::print(v, ns);
	}
}

void test3(void) {
	ft::vector<int>	 vft;
	std::vector<int> vstd;
	int				 tab[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int				 nl = 8;

	std::cout << "\n-------- TEST_3 --------\n";
	test_3_an1(vft, tab, nl, ft::FT);
	test_3_an1(vstd, tab, nl, ft::STD);
	test_3_an2(vft, nl, ft::FT);
	test_3_an2(vstd, nl, ft::STD);
}

template <class C, typename T>
void test4_an(C &v, int sizeToAdd, T elemToAdd, std::string ns) {
	v.resize(sizeToAdd, elemToAdd);
	ft::print(v, ns);
	std::cout << "\n";
}

void test4(void) {
	std::cout << "\n-------- TEST_4 --------\n";

	int				 size = 7;
	std::vector<int> vstd(size, 3);
	ft::vector<int>	 vft(size, 3);
	int				 t[] = {19, 4, 56, 1, 41, 0, 83, 111};

	ft::print(vstd, ft::STD);
	ft::print(vft, ft::FT);
	std::cout << "\n";

	// for ( int i = 2; i < 50; i += 9 ) {
	// 	test4_an(vft, vstd, i, 1);
	// }

	for ( int i = 0; i < 8; i++ ) {
		test4_an(vft, t[i], i + 1, ft::FT);
		test4_an(vstd, t[i], i + 1, ft::STD);
	}

	vstd.resize(5);
	vft.resize(5);
	ft::print(vstd, ft::STD);
	ft::print(vft, ft::FT);
	std::cout << "\n";

	vstd.resize(15);
	vft.resize(15);
	ft::print(vstd, ft::STD);
	ft::print(vft, ft::FT);
	std::cout << "\n";
}

template <class C>
void test5_an(C &v) {
	std::vector<int>::size_type s;
	size_t						cap = 7;

	s = v.capacity();
	v.reserve(cap);
	for ( int i = 0; i < 129; i++ ) {
		v.push_back(i);
		if ( s != v.capacity() ) {
			s = v.capacity();
			std::cout << s << "\n";
		}
	}

	std::cout << "\n";
}

void test5(void) {
	std::vector<int> vstd;
	ft::vector<int>	 vft;

	std::cout << "\n-------- TEST_5 --------\n";
	test5_an(vstd);
	test5_an(vft);
}

template <class C>
void test6_an(C &v, int i, size_t sr, std::string ns) {
	v.reserve(sr);
	v.insert(v.begin(), i);
	v.insert(v.end() - 1, i);
	ft::print(v, ns);
}

void test6(void) {
	std::cout << "\n-------- TEST_6 --------\n";

	size_t			 sr = 0;
	ft::vector<int>	 vft;
	std::vector<int> vstd;

	for ( int i = 0; i < 2; i++ ) {
		sr = i * 32;
		for ( int i = 0; i < 4; i++ ) {
			test6_an(vft, i, sr, ft::FT);
			test6_an(vstd, i, sr, ft::STD);
			std::cout << "\n";
		}
	}
}
void test7(void) {
	std::cout << "\n-------- TEST_7 --------\n";

	std::vector<int> vstd;
	ft::vector<int>	 vft;
	int				 t[] = {10, 20, 15, 40};

	for ( int i = 0; i < 4; i++ ) {
		vstd.assign(t[i], i);
		vft.assign(t[i], i);
		ft::print(vstd, ft::STD);
		ft::print(vft, ft::FT);
	}
}

template <class C>
void test8_an(C &v1, C &v2, std::string ns) {
	ft::print(v1, ns);
	ft::print(v2, ns);
	v1.swap(v2);
	ft::print(v1, ns);
	ft::print(v2, ns);
}

void test8(void) {
	std::vector<int> vstd1(5, 100);
	std::vector<int> vstd2(1, 200);
	ft::vector<int>	 vft1(5, 100);
	ft::vector<int>	 vft2(1, 200);

	std::cout << "\n-------- TEST_8 --------\n";
	test8_an(vft1, vft2, ft::STD);
	test8_an(vft1, vft2, ft::FT);
}

void test9(void) {
	ft::vector<int> vft;

	std::cout << "\n-------- TEST_9 --------\n";
	vft.push_back(10);
	vft.push_back(20);
	vft.push_back(30);

	ft::vector<int> v;
	v = vft;
	if ( v == vft ) {
		std::cout << "test ok\n";
	}
}

void test10(void) {
	std::cout << "\n-------- TEST_10 --------\n";

	std::vector<int> x1(4, 5);
	std::vector<int> y1(5, 5);

	ft::vector<int> x2(4, 5);
	ft::vector<int> y2(5, 5);

	for ( int i = 0; i < 10; i++ ) {
		std::cout << "i = " << i << " | ";
		x1.push_back(i);
		x2.push_back(i);
		(x1 < y1) ? std::cout << "\e[01;31mx1 < y1\e[0m | " : std::cout << "\e[01;32mx1 > y1\e[0m | ";
		(x2 < y2) ? std::cout << "\e[01;31mx2 < y2\e[0m\n" : std::cout << "\e[01;32mx2 > y2\e[0m\n";
		x1.pop_back();
		x2.pop_back();
	}
}

void test11(void) {
	std::cout << "\n-------- TEST_11 --------\n";

	ft::vector<int> x(5, 5);
	ft::vector<int> y(x);

	(x == y) ? std::cout << "hotdog\n" : std::cout << "not a hotdog\n";
	y.push_back(42);
	(x == y) ? std::cout << "hotdog\n" : std::cout << "not a hotdog\n";
}

void test12(void) {
	std::cout << "\n-------- TEST_12 --------\n";

	ft::vector<std::string> x(5, "test12");

	for ( size_t i = 0; i < 5; i++ ) {
		std::cout << x[i] << "\n";
	}
}

void test13(void) {
	std::cout << "\n-------- TEST_13 --------\n";

	ft::vector<int>	 x;
	std::vector<int> y;

	for ( int i = 1; i < 6; i++ ) {
		x.push_back(i);
		y.push_back(i);
	}
	ft::print(x, ft::FT);
	ft::print(y, ft::STD);
	std::cout << "ft  : front : " << x.front() << " | back : " << x.back() << "\n";
	std::cout << "std : front : " << y.front() << " | back : " << y.back() << "\n";
}

void test14(void) {
	ft::vector<int>			   x;
	ft::vector<int>::pointer   start;
	ft::vector<int>::pointer   end;
	ft::vector<int>::pointer   end_cap;
	ft::vector<int>::size_type size;
	ft::vector<int>::size_type i;
	size_t					   n = 10;

	std::cout << "\n-------- TEST_14 --------\n";
	start = x.get_allocator().allocate(n);
	end = start;
	end_cap = start + n;
	for ( i = 0; i < 5; i++ ) {
		x.get_allocator().construct(start + i, 5);
		end++;
	}
	size = end - start;
	std::cout << size << " " << end_cap - start << " " << std::endl;
	for ( i = 0; i < 5; i++ ) {
		std::cout << *(start + i) << " ";
	}
	std::cout << "\n";
	x.get_allocator().deallocate(start, n);
}

void test15(void) {
	ft::vector<std::string> x;

	std::cout << "\n-------- TEST_15 --------\n";
	x.push_back("aaa");
	x.push_back("bbb");
	x.push_back("ccc");

	for ( ft::vector<std::string>::iterator it = x.end() - 1; it != x.begin() - 1; it-- ) {
		std::cout << &(*it) << " " << *it << "\n";
	}
	std::cout << "\n";
}

void test16(void) {
	std::vector<int> x;
	std::vector<int> y(5, 9);
	ft::vector<int>	 a;
	ft::vector<int>	 b(5, 9);

	std::cout << "\n-------- TEST_16 --------\n";
	ft::print(x, ft::STD);
	ft::print(y, ft::STD);
	ft::print(a, ft::FT);
	ft::print(b, ft::FT);
	std::cout << "-------------------------\n";

	std::swap(x, y);
	ft::swap(a, b);

	ft::print(x, ft::STD);
	ft::print(y, ft::STD);
	ft::print(a, ft::FT);
	ft::print(b, ft::FT);
}

void test17(void) {
	ft::vector<int>					  x;
	ft::vector<int>::reverse_iterator it;
	ft::vector<int> *				  y;

	std::cout << "\n-------- TEST_17 --------\n";
	y = &x;
	for ( int i = 0; i < 10; i++ ) {
		x.push_back(i);
		y->push_back(i);
	}

	ft::print(x, ft::FT);
	std::cout << "\t\t\t\t\t| rev : ";
	for ( it = x.rbegin(); it != x.rend(); it++ ) {
		std::cout << *it << " ";
	}
	std::cout << "\n";
}

template <class C>
void test18_an(std::string ns) {
	C x;
	for ( int i = 0; i < 16; i++ ) {
		x.push_back(i);
	}

	C y(x.begin() + 2, x.end() - 2);
	ft::print(x, ns);
	ft::print(y, ns);

	typename C::reverse_iterator rit;
	std::cout << "\t\t\t\t\t| rev : ";
	for ( rit = y.rbegin(); rit != y.rend(); rit++ ) {
		std::cout << *rit << " ";
	}
	std::cout << "\n\n";
}

void test18(void) {
	std::cout << "\n-------- TEST_18 --------\n";
	test18_an<ft::vector<int> >(ft::STD);
	test18_an<std::vector<int> >(ft::FT);
}

void test19(void) {
	ft::vector<int> a;

	std::cout << "\n-------- TEST_19 --------\n";
	a.reserve(9);
	for ( int i = 0; i < 9; i++ ) {
		a.push_back(i);
	}

	ft::vector<int>::iterator it = a.begin();
	ft::vector<int>			  b(it, it + 5);
	ft::vector<int>			  c(5, 9);
	ft::vector<std::string>	  d(5, "tata");
	ft::vector<std::string>	  e;
	std::string				  t[] = {"aaa", "bbb", "ccc", "ddd", "eee", "fff"};
	for ( int i = 0; i < 6; i++ )
		e.push_back(t[i]);
	ft::vector<std::string> f(e.begin() + 1, e.end() - 1);

	ft::print(a, ft::FT);
	ft::print(b, ft::FT);
	ft::print(c, ft::FT);
	ft::print(d, ft::FT);
	ft::print(e, ft::FT);
	ft::print(f, ft::FT);
	std::cout << "\n";
}

template <class C>
void test20_an(C &a, int i, std::string ns) {
	a.insert(a.begin(), i, std::to_string(i));
	a.insert(a.begin(), "_");
	ft::print(a, ns);
}

void test20(void) {
	std::vector<std::string> a;
	ft::vector<std::string>	 b;

	std::cout << "\n\n-------- TEST_20 --------\n";
	for ( int i = 0; i != 9; i++ ) {
		test20_an(a, i, ft::STD);
		test20_an(b, i, ft::FT);
		std::cout << "\n";
	}
}

template <class C>
void test21_an(C &v, std::string ns) {
	v.erase(v.end() - 3, v.end() - 1);
	ft::print(v, ns);
}

void test21(void) {
	std::vector<int> x;
	ft::vector<int>	 y;

	std::cout << "\n\n-------- TEST_21 --------\n";
	for ( int i = 0; i < 30; i++ ) {
		x.push_back(i);
		y.push_back(i);
	}
	ft::print(x, ft::STD);
	ft::print(y, ft::FT);

	for ( int i = 0; i < 14; i++ ) {
		test21_an(x, ft::STD);
		test21_an(y, ft::FT);
	}
}

template <class C>
void test22_an(std::string ns) {
	C x, y;

	for ( int i = 0; i < 20; i++ )
		x.push_back(i);
	y.assign(x.begin(), x.end() - 10);
	ft::print(x, ns);
	ft::print(y, ns);
	y.assign(5, 5);
	ft::print(y, ns);
	y.assign(15, 0);
	ft::print(y, ns);
	y.assign(x.begin() + 13, x.end());
	ft::print(y, ns);

	std::cout << "\n";
}

void test22() {
	std::cout << "\n\n-------- TEST_22 --------\n";
	test22_an<std::vector<int> >(ft::STD);
	test22_an<ft::vector<int> >(ft::FT);
}

//darkest test23 challenge
int rdm_gen(int range) {
	return ((rand() % range) + 1);
}

struct random_points {
	random_points(int range) : a(rdm_gen(range)),
							   b(rdm_gen(range)),
							   c(rdm_gen(range)),
							   d(rdm_gen(range)) { }
	int a, b, c, d;
};

template <class C>
bool test23_an(random_points &pts) {
	C x(pts.a, pts.b);
	C y(pts.c, pts.d);
	return (x < y);
}

void test23() {
	typedef std::vector<int> vstd;
	typedef ft::vector<int>	 vft;

	std::cout << "\n-------- TEST_23 --------\n";
	srand((unsigned int)time(NULL));
	int i = 6000;
	while ( i-- ) {
		random_points pts(100);
		if ( test23_an<vstd>(pts) != test23_an<vft>(pts) ) {
			std::cout << "failed\n";
			return;
		}
	}
	std::cout << "test23 ok\n";
}

template <class C, class U>
C container_tab_gen(random_points &pts) {
	C vec_t;
	U v1(pts.a, pts.b);
	U v2(pts.b, pts.c);

	vec_t.push_back(v1);
	vec_t.push_back(v2);
	return vec_t;
}

template <class C>
void print_vt(C &container, std::string ns) {
	typename C::iterator it;
	for ( it = container.begin(); it != container.end(); it++ ) {
		ft::print(*it, ns);
	}
}

void test24(void) {
	srand((unsigned int)time(NULL));
	typedef std::vector<int>  vstd;
	typedef std::vector<vstd> vt_std;
	typedef ft::vector<int>	  vft;
	typedef ft::vector<vft>	  vt_ft;
	int						  counter = 4;

	while ( counter-- ) {
		random_points pts(20);
		vt_std		  v_tab_std = container_tab_gen<vt_std, vstd>(pts);
		vt_ft		  v_tab_ft = container_tab_gen<vt_ft, vft>(pts);
		print_vt(v_tab_std, ft::STD);
		print_vt(v_tab_ft, ft::FT);
		std::cout << std::boolalpha << ft::lexicographical_compare(v_tab_ft[0].begin(),v_tab_ft[0].end(), v_tab_ft[1].begin(),v_tab_ft[1].end()) << std::endl;
		std::cout << std::boolalpha << ft::lexicographical_compare(20,v_tab_ft[0].end(), v_tab_ft[1].begin(),v_tab_ft[1].end()) << std::endl;
		std::cout << "\n";
	}
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
	// test19();
	// test20();
	// test21();
	// test22();
	// test23();
	test24();
	return 0;
}