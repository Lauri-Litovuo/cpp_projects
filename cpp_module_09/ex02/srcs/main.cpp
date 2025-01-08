#include <iostream>
#include <string>
#include "PmergeMe.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Usage: ./PmergeMe <sequence of positive integers>" << std::endl;
		return 1;
	}
	std::string sequence;
	for (int i = 1; i < ac; i++)
	{
		std::string arg(av[i]);
		if (arg.find_first_not_of("0123456789") != std::string::npos)
		{
			std::cerr << "Error: invalid input" << std::endl;
			return 1;
		}
		sequence += arg;
		if (i + 1 < ac)
			sequence += " ";
	}
	try {
		std::cout << sequence << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}
	return 0;
}