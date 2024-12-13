#pragma once

template <typename T>
inline void swap(T &a, T &b) {
	T tmp = a;
	a = b;
	b = tmp;
}

template <typename T>
inline const T& min(const T& a, const T& b) {
	return a < b ? a : b;
}

template <typename T>
inline const T& max(const T &a, const T& b) {
	return a > b ? a : b;
}
