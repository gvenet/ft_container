#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

#include "../inc/ft_vector.hpp"
#include "../inc/Stack.hpp"

int main() {
    std::stack<int> s1;
    std::stack<int> s2;
 	std::stack<int,std::vector<int> > s3;


    s1.empty();
    s1.push(10);
    s1.push(20);
    s2.operator=(s1);
    std::cout << "s1 : " << s1.size() << std::endl;
    std::cout << "s2 : " << s2.size() << std::endl;
    s1.pop();
    std::cout << "s1 : " << s1.top() << std::endl;
    std::cout << "s2 : " << s2.top() << std::endl;

    return 0;
}