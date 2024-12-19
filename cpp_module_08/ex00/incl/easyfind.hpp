#pragma once
#include <algorithm>
#include <exception>
#include <iostream>

template <typename T>
void easyfind(T& haystack, int needle){
	if (std::find(haystack.begin(), haystack.end(), needle) != haystack.end())
		std::cout << "found the first occurance of " << needle << std::endl;
	else
		throw std::exception();
};
