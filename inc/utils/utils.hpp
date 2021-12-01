#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>
#include <limits.h>
#include <map>
#include <string>

#include "algorithm.hpp"
#include "functional.hpp"
#include "iterator.hpp"
#include "iterator_traits.hpp"
#include "pair.hpp"
#include "random_access_iterator.hpp"
#include "reverse_iterator.hpp"
#include "type_traits.hpp"


namespace ft {

const char *FT = " ft\t";
const char *STD = "std\t";

template <class C> void print(C &v, std::string ns) {
  typename C::iterator it;
  std::cout << ns << "  | s : " << v.size() << "\t| c : " << v.capacity()
            << "   \t| val : ";
  for (it = v.begin(); it != v.end(); it++) {
    std::cout << *it << " ";
  }
  std::cout << std::endl;
}

template <typename T1, typename T2>
void print(std::map<T1, T2> &v, std::string ns) {
  typename std::map<T1, T2>::iterator it;
  std::cout << "\n-----------------\n\n";
  std::cout << ns << "  | s : " << v.size() << "\n";
  for (it = v.begin(); it != v.end(); it++) {
    std::cout << it->first << "\t<=>\t" << it->second << "\n";
  }
  std::cout << std::endl;
}

} // namespace ft
#endif