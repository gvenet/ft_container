#include <iostream>
#include "../inc/ft_vector.hpp"
#include <vector>
#include <algorithm>
using namespace std;

void feprint(int i) {
	cout << i << " ";
}

int main()
{
	FtVector<int> ftVec;
	std::vector<int> stVec;

	ftVec.push_back(1);
	ftVec.push_back(2);
	ftVec.push_back(3);
	ftVec.push_back(4);
	ftVec.push_back(5);
	ftVec.push_back(6);
	ftVec.push_back(7);
	ftVec.push_back(8);
	ftVec.push_back(9);

	stVec.push_back(1);
	stVec.push_back(2);
	stVec.push_back(3);
	stVec.push_back(4);
	stVec.push_back(5);
	stVec.push_back(6);
	stVec.push_back(7);
	stVec.push_back(8);
	stVec.push_back(9);

	cout << endl;
	for_each(ftVec.begin(), ftVec.end(), feprint);
	cout << " : ftVec" << endl;
	for_each(stVec.begin(), stVec.end(), feprint);
	cout << " : stVec" << endl;
	
	cout << "capacity()\n";
	cout << ftVec.capacity() << "\tftVec\n";
	cout << stVec.capacity() << "\tstVec\n\n";

	cout << "size()\n";
	cout << ftVec.size() << "\tftVec\n";
	cout << stVec.size() << "\tstVec\n\n";

	stVec.pop_back();
	ftVec.pop_back();

	cout << "pop_back()\n";
	cout << ftVec.size() << "\tftVec\n";
	cout << stVec.size() << "\tstVec\n\n";



	return 0;
}