#pragma once
#include <iostream>

template <typename T>
void iter(T *array, size_t length, void (*func)(T const &)) {
	for (size_t i = 0; i < length; i++) {
		func(array[i]);
	}
}


template <typename T>
void iter(const T *array, size_t length, void (*func)(T const &)) {
	for (size_t i = 0; i < length; i++) {
		func(array[i]);
	}
}
