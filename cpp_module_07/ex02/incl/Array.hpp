#pragma once
#include <exception>
#include <iostream>

template <typename T>
class Array
{
public:
	Array<T>(void);
	Array<T>(unsigned int n);
	~Array<T>();
	Array<T>(Array const &src);
	Array<T> &operator=(Array<T> const &rhs);

	T &operator[](unsigned int index);
	const T &operator[](unsigned int index) const;

	unsigned int size() const;

	class OutOfSizeException : public std::exception
	{
		virtual const char *what() const throw()
		{
			return "Index out of limits";
		}
	};

private:
	T *_array;
	unsigned int _size;
};

template <typename T>
std::ostream &operator<<(std::ostream &os, Array<T> const &arr);

#include "Array.tpp"
