#ifndef FT_VECTOR_HPP
#define FT_VECTOR_HPP

#include <iostream>

template <typename T>
class FtVector
{

private:
	T		*_arr;
	int		_capacity;
	int		_current;

public:
	FtVector()
	{
		_arr = new T[1];
		_capacity = 1;
		_current = 0;
	}

	void push_back(T data)
	{
		if (_current == _capacity)
		{
			T *temp = new T[2 * _capacity];
			for (int i = 0; i < _capacity; i++)
				temp[i] = _arr[i];
			delete[] _arr;
			_capacity *= 2;
			_arr = temp;
		}
		_arr[_current] = data;
		_current++;
	}

	T at(int index)
	{
		return _arr[index];
	}

	void pop_back()
	{
		_current--;
	}

	int size()
	{
		return _current;
	}

	int capacity()
	{
		return _capacity;
	}



};

#endif