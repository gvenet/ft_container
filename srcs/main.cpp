#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <typeinfo>
#include <vector>

#include "../inc/vector.hpp"

static int rf = 20;

void test_ft(int &i) {
	ft::vector<int> vft(i, 5);
	for ( int i = 0; i < rf; i++ ) {
		vft.push_back(6);
		std::cout << vft.size() << " " << vft.capacity() << " | ";
	}
}

void test_std(int &i) {
	std::vector<int> vft(i, 5);
	for ( int i = 0; i < rf; i++ ) {
		vft.push_back(6);
		std::cout << vft.size() << " " << vft.capacity() << " | ";
	}
}

void test1(void) {
	std::cout << "-------- TEST_1 --------\n";
	
	int r = 10;

	for ( int i = 2; i < r; i++ ) {
		test_std(i);
		std::cout << std::endl;
		test_ft(i);
		std::cout << std::endl;
		std::cout << std::endl;
	}
}

template <typename T>
void print_ft(ft::vector<T> &v) {
	typename ft::vector<T>::iterator it;
	std::cout << "ft  | s : " << v.size() << "\t| c : " << v.capacity() << "\t| val : ";
	for ( it = v.begin(); it != v.end(); it++ ) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}
template <typename T>
void print_std(std::vector<T> &v) {
	std::cout << "std | s : " << v.size() << "\t| c : " << v.capacity() << "\t| val : ";
	typename std::vector<T>::iterator it;
	for ( it = v.begin(); it != v.end(); it++ ) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

template <typename T>
void test2_an(ft::vector<T> &vft, std::vector<T> &vstd, T elemToAdd) {
	vft.insert(vft.begin(), elemToAdd);
	vstd.insert(vstd.begin(), elemToAdd);
	print_ft(vft);
	print_std(vstd);
	std::cout << std::endl;

	(void)elemToAdd;
	(void)vft;
	(void)vstd;
}

void test2() {
	std::cout << "-------- TEST_2 --------\n";
	ft::vector<std::string>	 vft;
	std::vector<std::string> vstd;
	for ( int i = 0; i < 10; i++ ) {
		std::string s = std::to_string(i);
		test2_an(vft, vstd, s);
	}
}

void test3(void) {
	std::cout << "-------- TEST_3 --------\n";

	ft::vector<int>	 vft;
	std::vector<int> vstd;
	int				 nl = 8;

	for ( int i = 0; i < nl; i++ ) {
		vstd.insert(vstd.end(), i);
		vft.insert(vft.end(), i);
	}
	print_std(vstd);
	print_ft(vft);
	std::cout << "\n";
	for ( int i = 0; i < nl - 1; i++ ) {
		vstd.erase(vstd.begin() + (nl - i - 1));
		vft.erase(vft.begin() + (nl - i - 1));
		print_std(vstd);
		print_ft(vft);
		std::cout << "\n";
	}
}

template <typename T>
void test4_an(ft::vector<T> &vft, std::vector<T> &vstd, size_t sizeToAdd, T elemToAdd) {
	vstd.resize(sizeToAdd, elemToAdd);
	vft.resize(sizeToAdd, elemToAdd);
	print_std(vstd);
	print_ft(vft);
	std::cout << "\n";
	(void)vft;
}

void test4(void) {
	std::cout << "-------- TEST_4 --------\n";

	int				 size = 7;
	std::vector<int> vstd(size, 3);
	ft::vector<int>	 vft(size, 3);
	int				 t[] = {19, 4, 56, 1, 41, 0, 83, 111};

	print_std(vstd);
	print_ft(vft);
	std::cout << "\n";

	// for ( int i = 2; i < 50; i += 9 ) {
	// 	test4_an(vft, vstd, i, 1);
	// }

	for ( int i = 0; i < 8; i++ ) {
		test4_an(vft, vstd, t[i], i + 1);
	}

	vstd.resize(5);
	vft.resize(5);
	print_std(vstd);
	print_ft(vft);
	std::cout << "\n";

	vstd.resize(15);
	vft.resize(15);
	print_std(vstd);
	print_ft(vft);
	std::cout << "\n";
}

void test5(void) {
	std::cout << "-------- TEST_5 --------\n";

	size_t						cap = 7;
	std::vector<int>			vstd;
	std::vector<int>::size_type sstd;

	sstd = vstd.capacity();
	vstd.reserve(cap);
	for ( int i = 0; i < 129; i++ ) {
		vstd.push_back(i);
		if ( sstd != vstd.capacity() ) {
			sstd = vstd.capacity();
			std::cout << sstd << "\n";
		}
	}

	std::cout << "\n";

	ft::vector<int>			   vft;
	ft::vector<int>::size_type sft;

	sft = vft.capacity();
	vft.reserve(cap);
	for ( int i = 0; i < 129; i++ ) {
		vft.push_back(i);
		if ( sft != vft.capacity() ) {
			sft = vft.capacity();
			std::cout << sft << "\n";
		}
	}
}

void test6(void) {
	std::cout << "-------- TEST_6 --------\n";

	size_t			 sr = 0;
	ft::vector<int>	 vft;
	std::vector<int> vstd;

	for ( int i = 0; i < 2; i++ ) {
		sr = i * 32;
		vft.reserve(sr);
		vstd.reserve(sr);
		for ( int i = 0; i < 4; i++ ) {
			vft.insert(vft.begin(), i);
			vstd.insert(vstd.begin(), i);
			vft.insert(vft.end() - 1, i);
			vstd.insert(vstd.end() - 1, i);
			print_std(vstd);
			print_ft(vft);
			std::cout << "\n";
		}
	}
}
void test7(void) {
	std::cout << "-------- TEST_7 --------\n";

	std::vector<int> vstd;
	ft::vector<int>	 vft;
	int				 t[] = {10, 20, 15, 40};

	for ( int i = 0; i < 4; i++ ) {
		vstd.assign(t[i], i);
		vft.assign(t[i], i);
		print_std(vstd);
		print_ft(vft);
	}
}
void test8(void) {
	std::cout << "-------- TEST_8 --------\n";

	std::vector<int> vstd1(5, 100);
	std::vector<int> vstd2(1, 200);
	print_std(vstd1);
	print_std(vstd2);
	vstd1.swap(vstd2);
	print_std(vstd1);
	print_std(vstd2);

	ft::vector<int> vft1(5, 100);
	ft::vector<int> vft2(1, 200);
	print_ft(vft1);
	print_ft(vft2);
	vft1.swap(vft2);
	print_ft(vft1);
	print_ft(vft2);
}

void test9(void) {
	std::cout << "-------- TEST_9 --------\n";
	
	ft::vector<int> vft;
	vft.push_back(10);
	vft.push_back(20);
	vft.push_back(30);

	std::cout << "coucou\n";

	ft::vector<int> v;
	v = vft;
	if ( v == vft ) {
		std::cout << "yo\n";
	}
}

void test10(void) {
	std::cout << "-------- TEST_10 --------\n";

	std::vector<int> x1(4, 5);
	std::vector<int> y1(5, 5);

	ft::vector<int> x2(4, 5);
	ft::vector<int> y2(5, 5);

	// std::vector<int> x1(1,1);
	// std::vector<int> y1(2,1);

	// ft::vector<int> x2(1,1);
	// ft::vector<int> y2(2,1);

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
	std::cout << "-------- TEST_11 --------\n";

	ft::vector<int> x(5, 5);
	ft::vector<int> y(x);

	(x == y) ? std::cout << "hotdog\n" : std::cout << "not a hotdog\n";

	y.push_back(42);
	(x == y) ? std::cout << "hotdog\n" : std::cout << "not a hotdog\n";
}

void test12(void) {
	std::cout << "-------- TEST_12 --------\n";

	ft::vector<std::string> x(5, "test12");

	for ( size_t i = 0; i < 5; i++ ) {
		std::cout << x[i] << "\n";
	}
}

void test13(void) {
	std::cout << "-------- TEST_13 --------\n";

	ft::vector<int>	 x;
	std::vector<int> y;

	for ( int i = 1; i < 6; i++ ) {
		x.push_back(i);
		y.push_back(i);
	}
	std::cout << "ft  : front : " << x.front() << " | back : " << x.back() << "\n";
	std::cout << "std : front : " << y.front() << " | back : " << y.back() << "\n";

	print_ft(x);
	print_std(y);
}

void test14(void) {
	std::cout << "-------- TEST_14 --------\n";

	ft::vector<int> x;

	ft::vector<int>::pointer   start;
	ft::vector<int>::pointer   end;
	ft::vector<int>::pointer   end_cap;
	ft::vector<int>::size_type size;
	ft::vector<int>::size_type i;
	size_t					   n = 10;

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
	std::cout << "-------- TEST_15 --------\n";
	
	ft::vector<std::string> x;

	x.push_back("aaa");
	x.push_back("bbb");
	x.push_back("ccc");

	for ( ft::vector<std::string>::iterator it = x.end() - 1; it != x.begin() - 1; it-- ) {
		std::cout << &(*it) << " " << *it << "\n";
	}
	std::cout << "\n";
}

void test16(void) {
	std::cout << "-------- TEST_16 --------\n";
	
	std::vector<int> x;
	std::vector<int> y(5, 9);
	ft::vector<int>	 a;
	ft::vector<int>	 b(5, 9);

	print_std(x);
	print_std(y);
	print_ft(a);
	print_ft(b);
	std::cout << "-----------------------------------------------------------------------------------\n";

	std::swap(x, y);
	ft::swap(a, b);

	print_std(x);
	print_std(y);
	print_ft(a);
	print_ft(b);
}

void test17(void) {
	ft::vector<int> x;
	ft::vector<int>::reverse_iterator it; 

	for (int i = 0 ; i < 10 ; i++) {
		x.push_back(i);
	}
	for (it = x.rbegin(); it != x.rend(); it++) {
		std::cout << *it << " ";
	}
	std::cout << "\n";
	// print_std(x);
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
	test17();
	return 0;
}