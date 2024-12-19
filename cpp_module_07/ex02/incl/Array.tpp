#include "Array.hpp"


template <typename T>
Array<T>::Array(void) : _array(NULL), _size(0)
{
}


template <typename T>
Array<T>::Array(unsigned int n) : _array(new T[n]()), _size(n)
{
}

template <typename T>
Array<T>::~Array(void)
{
	if (_array)
		delete[] _array;
}

template <typename T>
Array<T>::Array(Array const &src) : _array(NULL), _size(0)
{
	*this = src;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T> &rhs)
{
	if (this != &rhs)
	{
		if (_array)
			delete[] _array;
		_size = rhs.size();
		_array = new T[_size];
		for (unsigned int i = 0; i < _size; i++)
			_array[i] = rhs[i];
	}
	return *this;
}

template <typename T>
T &Array<T>::operator[](unsigned int index)
{
	if (index >= _size)
		throw OutOfSizeException();
	return _array[index];
}

template <typename T>
const T &Array<T>::operator[](unsigned int index) const
{
	if (index >= _size)
		throw OutOfSizeException();
	return _array[index];
}

template <typename T>
unsigned int Array<T>::size() const
{
	return _size;
}

template <typename T>
std::ostream &operator<<(std::ostream &os, Array<T> const &arr)
{
	os << "{";
	for (unsigned int i = 0; i < arr.size(); i++)
		os << arr[i] << " ";
	os << "}";
	return os;
}



