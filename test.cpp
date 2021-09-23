#include <iostream>
#include <stack>
#include <vector>
#include <exception>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
	MutantStack() : std::stack<T>(){}
	MutantStack(const T &cpy) : std::stack<T>(cpy){}
	virtual ~MutantStack(){}

	MutantStack<T> &operator=(MutantStack<T> const &s);

	typedef typename std::stack<T>::container_type::iterator iterator;
	typedef typename std::stack<T>::container_type::const_iterator const_iterator;

	iterator begin(void) {return this->c.begin();}
	const_iterator cbegin(void) {return this->c.cbegin();}
	iterator end(void) {return this->c.end();}
	const_iterator cend(void) {return this->c.cend();}
};



int main()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << "mstack size =>\t" << mstack.size() << std::endl;
	std::cout << "mstack top =>\t" << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "mstack pop\n";
	std::cout << "mstack size =>\t" << mstack.size() << std::endl;
	std::cout << "mstack top =>\t" << mstack.top() << std::endl
			  << std::endl;
	mstack.push(3);
	mstack.push(9);
	mstack.push(123);
	mstack.push(737); //[...] mstack.push(0);
	
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	
	std::cout << "***********\nmstack top =>\t" << mstack.top() << std::endl;
	std::cout << "mstack =>   \n";
	while (it != ite)
	{
		std::cout << *it << " | ";
		++it;
	}

	std::stack<int> s1(mstack);
	std::stack<int> s2;
	s2 = s1;
	std::cout << "\n\n************\ns1 top =>\t" << s1.top() << std::endl;
	for (size_t i = 0; i < 4; i++)
	{
		s1.pop();
		std::cout << "s1 pop\n";
		std::cout << "s1 top =>\t" << s1.top() << std::endl;
	}

	mstack.pop();
	std::cout << "\n***************\nms pop" << "\nms top =>\t" << mstack.top() << "\ns1 top =>\t" << s1.top() << "\ns2 top =>\t" << s2.top() << "\n";
	std::cout << "\n\n************\n\n";

	return 0;
}