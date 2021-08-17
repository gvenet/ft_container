#ifndef STACK_HPP
#define STACK_HPP

namespace ft {

template <class _Tp, class _Container = std::vector<_Tp> >
class Stack;

template <class _Tp, class _Container>

class Stack {
   private:
    typedef _Container container_type;
    typedef typename container_type::value_type value_type;
    typedef typename container_type::reference reference;
    typedef typename container_type::const_reference const_reference;
    typedef typename container_type::size_type size_type;

   protected:
    container_type c;

   public:
    Stack() : c() {}
    Stack(const Stack& __q) : c(__q.c) {}
    Stack& operator=(const Stack& __q) {
        c = __q.c;
        return *this;
    }

    bool empty() const { return c.empty(); }
    size_type size() const { return c.size(); }
    reference top() { return c.back(); }
    const_reference top() const { return c.back(); }
    void push(const value_type& __v) { c.push_back(__v); }
    void pop() { c.pop_back(); }
};

template <class _Tp, class _Container>
bool
operator==(const Stack<_Tp, _Container>& __x, const Stack<_Tp, _Container>& __y) {
    return __x.c == __y.c;
}

template <class _Tp, class _Container>
bool
operator<(const Stack<_Tp, _Container>& __x, const Stack<_Tp, _Container>& __y) {
    return __x.c < __y.c;
}

template <class _Tp, class _Container>
bool
operator!=(const Stack<_Tp, _Container>& __x, const Stack<_Tp, _Container>& __y) {
    return !(__x == __y);
}

template <class _Tp, class _Container>
bool
operator>(const Stack<_Tp, _Container>& __x, const Stack<_Tp, _Container>& __y) {
    return __y < __x;
}

template <class _Tp, class _Container>
bool
operator>=(const Stack<_Tp, _Container>& __x, const Stack<_Tp, _Container>& __y) {
    return !(__x < __y);
}

template <class _Tp, class _Container>
bool
operator<=(const Stack<_Tp, _Container>& __x, const Stack<_Tp, _Container>& __y) {
    return !(__y < __x);
}

}  // namespace ft

#endif