#include <iostream>

#include "../inc/map.hpp"
#include "../inc/utils/pair.hpp"
#include <map>
#include <vector>

using namespace ft;

template <class C1, class C2>
std::ostream & operator<<(std::ostream & os, pair<C1, C2> const & p) {
  os << "(" << p.first << "," << p.second << ")";
  return os;
}

template <class Container>
void print_container(Container const & m) {
  for (typename Container::const_iterator it = m.begin(); it != m.end(); ++it) {
    if (it != m.begin())
      std::cout << ", ";
    std::cout << *it;
  }
}
template <class Container>
void print_container_nl(Container const & m) {
  print_container(m);
  std::cout << std::endl;
}

void test_erase() {
  map<int, int> m;

  for (int i = 0; i < 10; ++i) {
    m[i] = i;
  }
  std::cout << "m.erase(2) = " << m.erase(2) << std::endl;
  print_container_nl(m);
  std::cout << "m.erase(2) = " << m.erase(2) << std::endl;
  print_container_nl(m);
  m.erase(m.begin());
  m.erase(--(m.end()));
  print_container_nl(m);
  map<int, int>::iterator it[2] = {m.begin(), m.end()};
  it[0]++; it[0]++;
  it[1]--; it[1]--;
  m.erase(it[0], it[1]);
  print_container_nl(m);
  std::cout << "size = " << m.size() << std::endl;
}


int main() {

  std::cout << "--- Test erase ---" << std::endl;
  test_erase();

}