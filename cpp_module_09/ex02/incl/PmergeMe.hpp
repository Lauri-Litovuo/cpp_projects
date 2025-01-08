#pragma once
#include <iostream>
#include <string>
#include <deque>
#include <list>
#include <chrono>

struct pair{
	int min;
	int max;
};

class PMergeMe {
	public:
		PMergeMe(std::string);
		~PMergeMe();
		PMergeMe(const PMergeMe &src);
		PMergeMe &operator=(const PMergeMe &rhs);

		bool validateInput();
		void sortList();
		void sortDeque();
		void printResults();
	private:
		std::deque ()
};
