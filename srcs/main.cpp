#include <iostream>
#include "../inc/ft_vector.hpp"


int main()
{
    FtVector<int> v;
    FtVector<char> v1;
    v.push(10);
    v.push(20);
    v.push(30);
    v.push(40);
    v.push(50);
    v1.push(71);
    v1.push(72);
    v1.push(73);
    v1.push(74);
 
    std::cout << "Vector size : " << v.size() << std::endl;
    std::cout << "Vector capacity : " << v.getcapacity() << std::endl;
 
    std::cout << "Vector elements : ";
    v.print();
 
    v.push(100, 1);
 
    std::cout << "\nAfter updating 1st index" << std::endl;
 
    std::cout << "Vector elements of type int : " << std::endl;
    v.print();
    // This was possible because we used templates
    std::cout << "Vector elements of type char : " << std::endl;
    v1.print();
    std::cout << "Element at 1st index of type int: " << v.get(1)
         << std::endl;
    std::cout << "Element at 1st index of type char: "
         << v1.get(1) << std::endl;
 
    v.pop();
    v1.pop();
 
    std::cout << "\nAfter deleting last element" << std::endl;
 
    std::cout << "Vector size of type int: " << v.size() << std::endl;
    std::cout << "Vector size of type char: " << v1.size()
         << std::endl;
    std::cout << "Vector capacity of type int : "
         << v.getcapacity() << std::endl;
    std::cout << "Vector capacity of type char : "
         << v1.getcapacity() << std::endl;
 
    std::cout << "Vector elements of type int: ";
    v.print();
    std::cout << "Vector elements of type char: ";
    v1.print();
 
    return 0;
}