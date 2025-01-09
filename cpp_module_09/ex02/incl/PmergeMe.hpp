#pragma once
#include <iostream>
#include <string>
#include <deque>
#include <list>
#include <chrono>
#include <bits/stdc++.h>

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
		std::list<int> _mainList;
		std::list<int> _subList;
		int				_single;
		std::chrono::time_point<std::chrono::system_clock> _listStartTime;
		std::chrono::time_point<std::chrono::system_clock> _listEndTime;

		//list methods
		void generateListPairs();
		void sortPairElementsList();
		void mergeSortMainList();
		void insertSortMainList();
		void getMainAndSubList();

		//deque attributes
		std::deque<int> _inputDeque;
		std::chrono::time_point<std::chrono::system_clock> _dequeStartTime;
		std::chrono::time_point<std::chrono::system_clock> _dequeEndTime;
		std::deque<pair> _deque;
		std::deque <int> _mainDeque;

		//deque methods


		//helper methods
};

int getJacobsthalNumber(int n);
std::list<int>::iterator binarySearchListPosition(std::list<int> & _mainList, int number);
