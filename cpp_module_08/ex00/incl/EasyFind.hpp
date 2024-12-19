#pragma once
#include <algorithm>
#include <exception>
#include <iostream>

class NotFoundException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Element not found from the container";
    }
};

template <typename T>
typename T::iterator easyFind(T& haystack, int needle) {
	typename T::iterator it = std::find(haystack.begin(), haystack.end(), needle);
	return (it != haystack.end() ? it : throw NotFoundException());
}

template <typename T>
typename T::const_iterator easyFind(const T& haystack, int needle) {
    typename T::const_iterator it = std::find(haystack.begin(), haystack.end(), needle);
	return (it != haystack.end() ? it : throw NotFoundException());
}