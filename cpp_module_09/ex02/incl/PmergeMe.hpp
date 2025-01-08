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

		//list attributes
		std::list<int> _inputList;
		std::list<pair> _list;
		std::list <int> _mainList;
		unsigned int _ListDMTime;
		unsigned int _ListSTime;

		//deque attributes
		std::deque<int> _inputDeque;
		unsigned int _DequeDMTime;
		unsigned int _DequeSTime;
		std::deque<pair> _deque;
		std::deque <int> _mainDeque;

		int getJacobsthalNumber(int n);

		//list methods
		void generateListPairs();
		void sortPairElementsList();
		void sortByMaxList();
		void getMainList();
		void insertToMainList();

		//deque methods
		void generateDequePairs();
		void sortDequePairs();
		void mergeMainAndSubDeque();
		void insertToMainDeque();

};
