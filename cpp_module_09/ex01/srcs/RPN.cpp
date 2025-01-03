#include "RPN.hpp"

RPN::RPN(std::string input) : _input(input)
{
}
RPN::~RPN()
{
}

RPN::RPN(const RPN &other) : _input(other._input)
{
}

RPN &RPN::operator=(const RPN &other)
{
	if (this == &other)
		return *this;
	_input = other._input;
	return *this;
}

void RPN::calculate(){
	std::stack <long long int> stack;
	for (std::string::iterator it = _input.begin(); it != _input.end(); it++)
	{
		if (*it == ' ')
			continue;
		if (isdigit(*it))
		{
			stack.push(*it - '0');
			continue;
		}
		if (*it == '+' || *it == '-' || *it == '*' || *it == '/')
		{
			long long int a = stack.top();
			stack.pop();
			long long int b = stack.top();
			stack.pop();
			if (*it == '+')
				stack.push(b + a);
			else if (*it == '-')
				stack.push(b - a);
			else if (*it == '*')
				stack.push(b * a);
			else if (*it == '/')
			{
				if (a == 0)
					throw DivideByZero();
				stack.push(b / a);
			}
		}
	}
	std::cout << stack.top() << std::endl;
}

const char *RPN::DivideByZero::what() const noexcept
{
	return "Error: Division by zero!";
}
