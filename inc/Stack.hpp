#ifndef STACK_HPP
#define STACK_HPP

namespace ft {

template <typename T>
class Stack {
   private:
    int _size;

   public:
	Stack<T>() :_size(0) {}
    Stack<T>(int size) : _size(size) {}
    int size(void) const { return _size; }
};
}  // namespace ft

#endif