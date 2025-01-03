#include <iostream>
#include <string>
#include "RPN.hpp"

bool validateRPN(const std::string &s)
{
	//checking that the input has only digits, operators and spaces in right order
	if (s.empty())
		return false;
	if (s.find_first_not_of("0123456789+-*/ ") != std::string::npos)
		return false;
	if (s.front() == ' ' || s.back() == ' ')
		return false;
	if (s.find_first_of("0123456789") == std::string::npos || s.find_first_of("+-*/") == std::string::npos)
		return false;
	if (s.find_last_of("0123456789") == s.size() - 1)
		return false;
	if (s.find_first_of("+-*/") < s.find_first_of("0123456789"))
		return false;

	//checking that there are 2 numbers before the first operator!
	size_t pos = -1;
	int cnt = 0;
	while (cnt != 2)
	{
		pos++;
		pos = s.find_first_of("0123456789", pos);
		if (pos == std::string::npos)
			break;
		cnt++;
	}
	if (cnt != 2 || s.find_first_of("+-*/") < pos)
		return false;

	//checking that numbers are < 10, that there is a space after each number and operator and that there is numbercount - 1 operators
	unsigned int operatorCount = 0;
	unsigned int numberCount = 0;
	for (size_t i = 0; i < s.size(); ++i)
	{
		if (s[i] == ' ')
			continue;
		else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
		{
			if (i + 1 < s.size() && s[i + 1] != ' ')
				return false;
			operatorCount++;
			if (operatorCount > numberCount - 1)
				return false;
			continue;
		}
		else if (isdigit(s[i]))
		{
			numberCount++;
			if (i + 1 < s.size() && s[i + 1] == ' ')
				continue;
			else
				return false;
		}
		else
			return false;
	}
	if (operatorCount + 1 != numberCount)
		return false;
	return true;

}
int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Usage: ./RPN 'inverted Polish mathematical expression'" << std::endl;
		return 1;
	}
	if (validateRPN(av[1]) == false)
	{
		std::cerr << "Error: Invalid RPN expression" << std::endl;
		return 1;
	}
	RPN polish(static_cast<std::string>(av[1]));
	try{
		polish.calculate();
	} catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}
	return 0;
}