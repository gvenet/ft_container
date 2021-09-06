#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
#include "../inc/Stack.hpp"
#include "../inc/Vector.hpp"

int main()
{
	ft::Stack<int> s1;
	// std::stack<int> s1;

	s1.push(10);
	s1.push(20);
	s1.push(30);

	std::cout << s1.top() << std::endl;
	s1.pop();
	std::cout << s1.top() << std::endl;
	s1.pop();
	std::cout << s1.top() << std::endl;
	s1.pop();

	return 0;
}