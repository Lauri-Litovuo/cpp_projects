#pragma once
#include <stack>
#include <iostream>
#include <exception>

class RPN
{
public:
	RPN(std::string input);
	RPN(const RPN &other);
	RPN &operator=(const RPN &other);
	~RPN();

	void calculate();

	class DivideByZero : public std::exception
	{
		public:
			virtual const char *what() const noexcept;
	};

	private:
		std::string _input;
};
