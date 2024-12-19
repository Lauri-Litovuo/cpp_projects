#include "easyfind.hpp"
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
		easyfind(intVec2, 77);
	}catch (std::exception &e){
		std::cout << e.what() << std::endl;
	}
	try {
		easyfind(intVec2, 4);
	}catch (std::exception &e){
		std::cout << e.what() << std::endl;
	}
	try {
		easyfind(intVec, 4);
	}catch (std::exception &e){
		std::cout << e.what() << std::endl;
	}

	std::vector<float> floatVec = {1.0f, 3.4f, 55.5f, 74.0f, 74.9f, 9012.0f};
	try {
		easyfind(floatVec, 74);
	}catch (std::exception &e){
		std::cout << e.what() << std::endl;
	}
	try {
		easyfind(floatVec, 75);
	}catch (std::exception &e){
		std::cout << e.what() << std::endl;
	}
	}

	{
	std::cout << "testing with array" << std::endl;
	std::array<int, 5> intArray = {1, 3, 55, 6, 77};
	try {
		easyfind(intArray, 77);
	}catch (std::exception &e){
		std::cout << e.what() << std::endl;
	}
	try {
		easyfind(intArray, 4);
	}catch (std::exception &e){
		std::cout << e.what() << std::endl;
	}
	const std::array<int, 5> constIntArray = {1, 3, 55, 6, 77};
	try {
		easyfind(constIntArray, 77);
	}catch (std::exception &e){
		std::cout << e.what() << std::endl;
	}

	}
	std::cout << "testing with string" << std::endl;
	std::string test = "hello";
	try {
		easyfind(test, 'o');
	}catch (std::exception &e){
		std::cout << e.what() << std::endl;
	}
	try {
		easyfind(test, 'a');
	}catch (std::exception &e){
		std::cout << e.what() << std::endl;
	}
}

