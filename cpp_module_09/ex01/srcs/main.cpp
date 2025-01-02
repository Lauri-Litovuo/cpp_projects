#include "iostream"
#include "string"

bool validateRPN(const std::string &s)
{
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

	//check that there are exactly 2 numbers before the first operator!
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

	for (size_t i = 0; i < s.size(); ++i)
	{
		if (s[i] == ' ')
			continue;
		else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
			continue;
		else if (isdigit(s[i]))
		{
			if (i + 1 < s.size() && s[i + 1] == ' ')
				continue;
			else if (i + 2 < s.size() && s[i] == '1' && s[i + 1] == '0' && s[i + 2] == ' ')
				i += 2;
			else
				return false;
		}
		else
			return false;
	}
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
		std::cerr << "Invalid RPN expression" << std::endl;
		return 1;
	}
	std::cout << "Valid RPN expression" << std::endl;
	return 0;
}