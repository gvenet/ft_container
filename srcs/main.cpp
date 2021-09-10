#include <algorithm>
#include <iostream>
#include <string>
#include <typeinfo>
#include <vector>

#include "../inc/Vector.hpp"

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
	ft::vector<std::string>	 vft;
	std::vector<std::string> vstd;
	for ( int i = 0; i < 10; i++ ) {
		std::string s = std::to_string(i);
		test2_an(vft, vstd, s);
	}
}

void test3(void) {
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
	int				 size = 7;
	std::vector<int> vstd(size, 3);
	ft::vector<int>	 vft(size, 3);

	print_std(vstd);
	print_ft(vft);
	std::cout << "\n";

	for ( int i = 2; i < 50; i += 9 ) {
		test4_an(vft, vstd, i, 1);
	}

	test4_an(vft, vstd, 19, 1);
	test4_an(vft, vstd, 4, 2);
	test4_an(vft, vstd, 56, 3);
	test4_an(vft, vstd, 1, 4);
	test4_an(vft, vstd, 41, 5);
	test4_an(vft, vstd, 0, 6);
	test4_an(vft, vstd, 83, 7);
	test4_an(vft, vstd, 111, 8);

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

int main(void) {
	// test1();
	// test2();
	// test3();
	// test4();
	// test5();
	// test6();
	// test7();
	test8();
	return 0;
}