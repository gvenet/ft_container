#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;
#include "../inc/Stack.hpp"


int main() {
    stack<int> s1;
    stack<int> s2;


    s1.empty();
    s1.push(10);
    s1.push(20);
    s2.push(30);
	s2.operator=(s1);
    cout << "s1 : " << s1.size() << endl;
    cout << "s2 : " << s2.size() << endl;
    s1.pop();
    cout << "s1 : " << s1.top() << endl;
    cout << "s2 : " << s2.top() << endl;

	ft::Stack A;
	cout << A.size() <<endl;


    return 0;
}