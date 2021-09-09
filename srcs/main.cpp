#include <algorithm>
#include <iostream>
#include <string>
#include <typeinfo>
#include <vector>

#include "../inc/Vector.hpp"

static int rf = 20;

void test_ft(int &i) {
	ft::vector<int> v1(i, 5);
	for ( int i = 0; i < rf; i++ ) {
		v1.push_back(6);
		std::cout << v1.size() << " " << v1.capacity() << " | ";
	}
}

void test_std(int &i) {
	std::vector<int> v1(i, 5);
	for ( int i = 0; i < rf; i++ ) {
		v1.push_back(6);
		std::cout << v1.size() << " " << v1.capacity() << " | ";
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
	std::cout << "\t\t|| s : " << v.size() << " | c : " << v.capacity() << " | ms : " << v.max_size() << std::endl;
}
template <typename T>
void print_std(std::vector<T> &v) {
	std::cout << "std : ";
	typename std::vector<T>::iterator it;
	for ( it = v.begin(); it != v.end(); it++ ) {
		std::cout << *it << " ";
	}
	std::cout << "\t\t|| s : " << v.size() << " | c : " << v.capacity() << " | ms : " << v.max_size() << std::endl;
}

template <typename T>
void test2_an(ft::vector<T> &v1, std::vector<T> &v2, T elemToAdd) {
	v1.insert(v1.begin(), elemToAdd);
	v2.insert(v2.begin(), elemToAdd);
	print_ft(v1);
	print_std(v2);
	std::cout << std::endl;

	(void)elemToAdd;
	(void)v1;
	(void)v2;
}

void test2() {
	ft::vector<std::string>	 v1;
	std::vector<std::string> v2;
	for ( int i = 0; i < 4; i++ ) {
		std::string s = std::to_string(i);
		test2_an(v1, v2, s);
	}
}

	int main(void) {
		test1();
		test2();

		return 0;
	}