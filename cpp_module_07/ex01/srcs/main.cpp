#include "iter.hpp"
#include <string>
#include <iostream>
#include <array>

template <typename T>
void print(T &x) {
	std::cout << x << std::endl;
};

template <typename T>
void doubleValue(T &x) {
	x *= 2;
};

int main( void ){

	std::cout << "::::::::: Testing with raw array ::::::::::" << std::endl;
	int *array = new int[5]{1, 2, 3, 4, 5};
	::iter(array, 5, print);
	delete [] array;


	std::cout << "\n::::::::: Testing with std::array ::::::::::" << std::endl;
	std::array<int, 5> arr = {1, 2, 3, 4, 5};
	::iter(arr.data(), 5, print);

	std::cout << "\n::::::::: Testing with const raw array ::::::::::" << std::endl;
	const int *carray = new int[5]{1, 2, 3, 4, 5};
	::iter(carray, 5, print);
	delete [] carray;

	std::cout << "\n::::::::: Testing with const std::array ::::::::::" << std::endl;
	const std::array<int, 5> carr = {1, 2, 3, 4, 5};
	::iter(carr.data(), 5, print);

	std::cout << "\n::::::::: Testing with char array ::::::::::" << std::endl;
	char charArr[5] = {'H', 'e', 'l', 'l', 'o'};
	::iter(charArr, 5, print);
	
	std::cout << "\n::::::::: Testing with const char array ::::::::::" << std::endl;
	const char *carr2 = "Hello";
	::iter(carr2, 5, print);

	std::cout << "\n::::::::: Testing with string array ::::::::::" << std::endl;
	std::string strArray[] = {"hello", "world", "is", "burning", "down"};
    size_t strArrayLength = sizeof(strArray) / sizeof(strArray[0]);
	::iter(strArray, strArrayLength, print);

	return 0;
}
