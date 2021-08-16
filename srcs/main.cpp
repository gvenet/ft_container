#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

#include "../inc/ft_vector.hpp"
#include "../inc/ft_stack.hpp"

int main() {
    std::stack<int> s1;
    std::stack<int> s2;

    s1.empty();
    s1.push(10);
    s1.push(20);
    s2.operator=(s1);
    std::cout << "s1 : " << s1.size() << std::endl;
    std::cout << "s2 : " << s2.size() << std::endl;
    s1.pop();
    std::cout << "s1 : " << s1.top() << std::endl;
    std::cout << "s2 : " << s2.top() << std::endl;
    s1.swap(s2);
    std::cout << "s1 : " << s1.top() << std::endl;
    std::cout << "s2 : " << s2.top() << std::endl;
    return 0;
}