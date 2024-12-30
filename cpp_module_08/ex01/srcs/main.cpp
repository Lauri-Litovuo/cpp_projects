#include "Span.hpp"
#include <vector>
#include <exception>
#include <random>
#include <algorithm>
#include <iostream>


int main(){
 {
	std::cout << "Subject test" << std::endl;
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
 }
 {
	std::cout << "Testing with same number" << std::endl;
	Span sp = Span(2);
	sp.addNumber(6);
	sp.addNumber(6);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
 }

 {
	std::cout << "Testing with one number" << std::endl;
	Span sp = Span(1);
	sp.addNumber(6);
	try{
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(const std::exception &e){
		std::cerr << e.what() << std::endl;
	}
 }
 
 {
	std::cout << "Testing with empty span" << std::endl;
	Span sp = Span(1);
	try{
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(const std::exception &e){
		std::cerr << e.what() << std::endl;
	}
 }
 {
	std::cout << "Testing with range" << std::endl;
	Span sp = Span(5);
	std::array<int, 5> arr = {6, 3, 17, 9, 11};
	sp.addRange(arr.begin(), arr.end());
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
 }

 {
	std::cout << "Testing with 10 001 elements" << std::endl;
	Span sp = Span(10001);
	std::vector<int> vec(10001);
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dis(1, 100000);
	for (int i = 0; i < 10001; i++)
		vec[i] = dis(gen);
	sp.addRange(vec.begin(), vec.end());
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	std::cout << "The smallest and biggest number in the span: " << *std::min_element(vec.begin(), vec.end()) << " " << *std::max_element(vec.begin(), vec.end()) << std::endl;
	// std::cout << "The vector is sorted: " << std::endl;
	// std::sort(vec.begin(), vec.end());
	// for (int i = 0; i < 10001; i++)
	// 	std::cout << vec[i] << " ";
 }

}
