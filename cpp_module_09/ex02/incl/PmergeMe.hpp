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

		void fillList();
		void fillDeque();
		void sortList();
		void sortDeque();
		void printSorted();
	private:
		std::string _input;
		std::list<int> _inputList;
		std::deque<int> _inputDeque;
		unsigned int _ListDMTime;
		unsigned int _DequeDMTime;
		unsigned int _ListSTime;
		unsigned int _DequeSTime;
		std::deque<pair> _deque;
		std::list<pair> _list;
};
