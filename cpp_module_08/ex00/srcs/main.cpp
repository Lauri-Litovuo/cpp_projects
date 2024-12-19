#include "EasyFind.hpp"
#include <iostream>
#include <vector>
#include <array>
#include <exception>

int main(){
	{
	std::cout << "testing with vector" << std::endl;
	std::vector<int> intVec = {};
	std::vector<int> intVec2 = {1, 3, 55, 6, 77, 9012};
	try {
		auto it = easyFind(intVec2, 77);
		std::cout << "Found the parameter from index: " << std::distance(intVec2.begin(), it) << std::endl;
	}catch (std::exception &e){
		std::cout << e.what() << std::endl;
	}
	try {
		auto it = easyFind(intVec2, 4);
		std::cout << "Found the parameter from index: " << std::distance(intVec2.begin(), it) << std::endl;
	}catch (std::exception &e){
		std::cout << e.what() << std::endl;
	}
	try {
		auto it = easyFind(intVec, 4);
		std::cout << "Found the parameter from index: " << std::distance(intVec.begin(), it) << std::endl;
	}catch (std::exception &e){
		std::cout << e.what() << std::endl;
	}

	std::vector<float> floatVec = {1.0f, 3.4f, 55.5f, 74.0f, 74.9f, 9012.0f};
	try {
		auto it = easyFind(floatVec, 74);
		std::cout << "Found the parameter from index: " << std::distance(floatVec.begin(), it) << std::endl;
	}catch (std::exception &e){
		std::cout << e.what() << std::endl;
	}
	try {
		auto it = easyFind(floatVec, 75);
		std::cout << "Found the parameter from index: " << std::distance(floatVec.begin(), it) << std::endl;
	}catch (std::exception &e){
		std::cout << e.what() << std::endl;
	}
	}

	{
	std::cout << "testing with array" << std::endl;
	std::array<int, 5> intArray = {1, 3, 55, 6, 77};
	try {
		auto it = easyFind(intArray, 77);
		std::cout << "Found the parameter from index: " << std::distance(intArray.begin(), it) << std::endl;
	}catch (std::exception &e){
		std::cout << e.what() << std::endl;
	}
	try {
		auto it = easyFind(intArray, 4);
		std::cout << "Found the parameter from index: " << std::distance(intArray.begin(), it) << std::endl;
	}catch (std::exception &e){
		std::cout << e.what() << std::endl;
	}
	const std::array<int, 5> constIntArray = {1, 3, 55, 6, 77};
	try {
		easyFind(constIntArray, 77);
		std::cout << "Found the parameter " << std::endl;;
	}catch (std::exception &e){
		std::cout << e.what() << std::endl;
	}

	}
	std::cout << "testing with string" << std::endl;
	std::string test = "hello";
	try {
		auto it = easyFind(test, 'o');
		std::cout << "Found the parameter from index: " << std::distance(test.begin(), it) << std::endl;
	}catch (std::exception &e){
		std::cout << e.what() << std::endl;
	}
	try {
		auto it = easyFind(test, 'a');
		std::cout << "Found the parameter from index: " << std::distance(test.begin(), it) << std::endl;
	}catch (std::exception &e){
		std::cout << e.what() << std::endl;
	}
}
