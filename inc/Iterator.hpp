#ifndef ITERATOR_HPP
#define ITERATOR_HPP

namespace ft {

template <class T>
class Iterator {
public:
	Iterator() : p(0) {}
	Iterator(T *x) : p(x) {}
	Iterator(const Iterator &mit) : p(mit.p) {}

	Iterator &operator++() {
		++p;
		return *this;
	}

	Iterator operator++(int) {
		Iterator tmp(*this);

		operator++();
		return tmp;
	}

	Iterator &operator--() {
		--p;
		return *this;
	}

	Iterator operator--(int) {
		Iterator tmp(*this);

		operator--();
		return tmp;
	}

	Iterator operator-(int x) {
		// Iterator tmp(*this);

		for ( int i = 0; i < x; i++ ) {
			// tmp.operator--();
			operator--();
		}
		return *this;
	}

	Iterator operator+(int x) {
		Iterator tmp(*this);

		for ( int i = 0; i < x; i++ )
			tmp.operator++();
		return tmp;
	}

	bool operator<(const Iterator &rhs) const { return p < rhs.p; }
	bool operator<=(const Iterator &rhs) const { return p <= rhs.p; }
	bool operator>(const Iterator &rhs) const { return p > rhs.p; }
	bool operator>=(const Iterator &rhs) const { return p >= rhs.p; }
	bool operator==(const Iterator &rhs) const { return p == rhs.p; }
	bool operator!=(const Iterator &rhs) const { return p != rhs.p; }

	T &operator*() { return *p; }

private:
	T *p;
};

}  // namespace ft
#endif