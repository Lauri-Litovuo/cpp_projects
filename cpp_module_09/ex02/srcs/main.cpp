#include <iostream>
#include <string>
#include "PmergeMe.hpp"

static void validateInput(std::string &arg)
{
	for (size_t i = 0; i < arg.length(); i++)
	{
		if (!isdigit(arg[i]))
			throw std::invalid_argument("Invalid input: " + arg);
	}
	try {
		std::stoi(arg);
	}
	catch (std::exception &e) {
		throw std::invalid_argument("Invalid input: " + arg);
	}
}

int main(int ac, char **av)
{
	if (ac < 2 || ac > 3002)
	{
		std::cerr << "Usage: ./PmergeMe <sequence of positive integers>" << std::endl;
		return 1;
	}
	std::string sequence;
	for (int i = 1; i < ac; i++)
	{
		std::string arg(av[i]);
		try{
			validateInput(arg);
		}catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
			return 1;
		}
		if (sequence.find(arg + " ") != std::string::npos && (sequence.find(arg + " ") - 1 == ' ' || sequence.find(arg + " ") == 0))
		{
			std::cerr << "Error: Duplicate input: " << arg << std::endl;
			return 1;
		}
		sequence += arg;
		if (i + 1 < ac)
			sequence += " ";
	}
	try {
		PMergeMe pmm(sequence);
		pmm.fillList();
		pmm.sortList();
		pmm.fillDeque();
		pmm.sortDeque();
		pmm.printSorted();
	}
	catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}
	return 0;
}
