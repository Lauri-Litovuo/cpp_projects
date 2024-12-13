#pragma once
#include <iostream>
#include <array>

template <typename T>
void iter(T *array, size_t const length, void (*func)(T& x)) {
	for (size_t i = 0; i < length; i++) {
		func(array[i]);
	}
}

template <typename T>
void iter(const T *array, size_t const length, void (*func)(const T& x)) {
	for (size_t i = 0; i < length; i++) {
		func(array[i]);
	}
}