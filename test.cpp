#include <iostream>
#include <vector>

// template <typename T>
// class test {
// public:
// 	typedef size_t size_type;

// 	test() {
// 		std::cout << "default \n";
// 	}

// 	test(size_type x, int val = 0) : _x(x){
// 		std::cout << val << "\n";
// 	}

// 	template <class C>
// 	test(C &c1, C &c2) : _x(0) {
// 		c1.push_back(42);
// 		std::cout << c1[0] << "\n";
// 		(void)c2;
// 	}

// private:
// 	int _x;
// };

// int main() {
// 	std::vector<int> x;
// 	std::vector<int> y;
// 	test<int>		 a;
// 	test<int>		 b(1);
// 	test<int>		 c(1, 1);
// 	test<int>		 d(x, y);
// }

// struct Test {
// 	typedef int foo;
// };

// template <typename T>
// void f(typename T::foo) { }	 // Definition #1

// template <typename T>
// void f(T) { }  // Definition #2

// int main() {
// 	f<Test>(10);  // Call #1.
// 	f<int>(10);	  // Call #2. Without error (even though there is no int::foo)
// 				  // thanks to SFINAE.

// }

// #include <iostream>

// template <typename T>
// struct has_typedef_foobar {
// 	// Types "yes" and "no" are guaranteed to have different sizes,
// 	// specifically sizeof(yes) == 1 and sizeof(no) == 2.
// 	typedef char yes[1];
// 	typedef char no[2];

// 	template <typename C>
// 	static yes& test(typename C::foobar*);

// 	template <typename>
// 	static no& test(...);

// 	// If the "sizeof" of the result of calling test<T>(nullptr) is equal to
// 	// sizeof(yes), the first overload worked and T has a nested type named
// 	// foobar.
// 	static const bool value = sizeof(test<T>(nullptr)) == sizeof(yes);
// };

// struct foo {
// 	typedef float foobar;
// };

// struct toto {
// 	typedef int foobar;
// 	typedef float drill;
// };

// struct jeanjean : foo {};

// int main() {
// 	std::cout << std::boolalpha;
// 	std::cout << has_typedef_foobar<int>::value << std::endl;	 // Prints false
// 	std::cout << has_typedef_foobar<foo>::value << std::endl;	 // Prints true
// 	std::cout << has_typedef_foobar<toto>::value << std::endl;
// 	std::cout << has_typedef_foobar<jeanjean>::value << std::endl;

// }

struct false_type {
	static const bool value = false;
};

struct true_type {
	static const bool value = true;
};

template <typename T, typename U>
struct is_same : false_type {
};

template <typename T>
struct is_same<T, T> : true_type {
};

int main() {
	std::cout << std::boolalpha;
	std::cout << is_same<int, int>::value << "\n";
	std::cout << is_same<int, char>::value << "\n";



	return 0;
}