#include <vector>

int main() {
	std::vector<int> v;
	v.push_back( 42 );
	v.erase(v.begin());
}