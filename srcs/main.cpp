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
	std::cout << "ft  : ";
	for ( it = v.begin(); it != v.end(); it++ ) {
		std::cout << *it << " ";
	}
	std::cout << "\t\t|| s : " << v.size() << " | c : " << v.capacity() << std::endl;
}
template <typename T>
void print_std(std::vector<T> &v) {
	std::cout << "std : ";
	typename std::vector<T>::iterator it;
	for ( it = v.begin(); it != v.end(); it++ ) {
		std::cout << *it << " ";
	}
	std::cout << "\t\t|| s : " << v.size() << " | c : " << v.capacity() << std::endl;
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
	for ( int i = 0; i < 4; i++ ) {
		std::string s = std::to_string(i);
		test2_an(vft, vstd, s);
	}
}

void test3(void) {
	ft::vector<int>	 vft;
	std::vector<int> vstd;
	int nl = 8;
	
	for ( int i = 0; i < nl; i++ ) {
		vstd.insert(vstd.end(), i);
		vft.insert(vft.end(), i);
	}
	print_std(vstd);
	print_ft(vft);
	std::cout << "\n";
	for ( int i = 0; i < nl - 1; i++ ) {
		vstd.erase(vstd.begin() + 1);
		vft. erase( vft.begin() + 1);
		print_std(vstd);
		print_ft(vft);
		std::cout << "\n";
	}
	// print_ft(vft);
	// std::cout << std::endl;
	// vstd.erase(vstd.begin() + 2);
	// vft.erase(vft.begin() + 2);
	// print_std(vstd);
	// print_ft(vft);
}

int main(void) {
	// test1();
	// test2();
	test3();
	return 0;
}