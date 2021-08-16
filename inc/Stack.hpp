#ifndef STACK_HPP
#define STACK_HPP

namespace ft {

class Stack {
   private:
    int _size;

   public:
	Stack() :_size(0) {}
    Stack(int size) : _size(size) {}
    int size(void) const { return _size; }
};
}  // namespace ft

#endif