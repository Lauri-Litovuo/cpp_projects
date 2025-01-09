#include "PmergeMe.hpp"

PMergeMe::PMergeMe(std::string input) : _input(input) {
	_single = -1;
};

PMergeMe::~PMergeMe() {
};

PMergeMe::PMergeMe(const PMergeMe &src) {
	*this = src;
};

//keep this updated
PMergeMe &PMergeMe::operator=(const PMergeMe &rhs) {
	if (this != &rhs) {
		// _input = rhs._input;
		// _inputList = rhs._inputList;
		// _inputDeque = rhs._inputDeque;
		// _ListDMTime = rhs._ListDMTime;
		// _DequeDMTime = rhs._DequeDMTime;
		// _ListSTime = rhs._ListSTime;
		// _DequeSTime = rhs._DequeSTime;
		// _deque = rhs._deque;
		// _list = rhs._list;
	}
	return *this;
};

void PMergeMe::fillList() {
	_listStartTime = std::chrono::system_clock::now();
	std::string temp;
	for (size_t i = 0; i < _input.length(); i++) {
		if (_input[i] == ' ') {
			_inputList.push_back(std::stoi(temp));
			temp.clear();
		} else {
			temp += _input[i];
		}
	}
	_inputList.push_back(std::stoi(temp));
};


void PMergeMe::sortList() {
	generateListPairs();
	sortPairElementsList();
	mergeSortMainList();
	insertSortMainList();
	_listEndTime = std::chrono::system_clock::now();

}

void PMergeMe::fillDeque() {
	_dequeStartTime = std::chrono::system_clock::now();
	std::string temp;
	for (size_t i = 0; i < _input.length(); i++) {
		if (_input[i] == ' ') {
			_inputDeque.push_back(std::stoi(temp));
			temp.clear();
		} else {
			temp += _input[i];
		}
	}
	_inputDeque.push_back(std::stoi(temp));
}

void PMergeMe::sortDeque() {
}

void PMergeMe::printSorted() {
	std::cout << "Before: " << _input << std::endl;
	std::string sortedList;
	for (std::list<int>::iterator it = _mainList.begin(); it != _mainList.end(); it++)
		sortedList += std::to_string(*it) + " ";
	std::cout << "After : " << sortedList << std::endl;
	unsigned int listTime = std::chrono::duration_cast<std::chrono::microseconds>(_listEndTime - _listStartTime).count();
	unsigned int dequeTime = std::chrono::duration_cast<std::chrono::microseconds>(_dequeEndTime - _dequeStartTime).count();
	std::cout << "Time to process range of: "<< _mainList.size() << " elements with std::list " << listTime << " microseconds" << std::endl;
	std::cout << "Time to process range of: " << " elements with std::deque " << dequeTime << " microseconds" << std::endl;
}

//list methods
void PMergeMe::generateListPairs() {
	for (std::list<int>::iterator it = _inputList.begin(); it != _inputList.end(); it++) {
		pair temp;
		temp.min = *it;
		it++;
		if (it == _inputList.end())
		{
			_single = temp.min;
			break;
		}
		temp.max = *it;
		_list.push_back(temp);
	}
}

void PMergeMe::sortPairElementsList() {
	for (std::list<pair>::iterator it = _list.begin(); it != _list.end(); it++) {
		if (it->min > it->max) {
			int temp = it->min;
			it->min = it->max;
			it->max = temp;
		}
	}
}

void mergeList(std::list<pair> &list, int left, int mid, int right){

	int n1 = mid - left + 1;
	int n2 = right - mid;

	std::list<pair> L, R;

	std::list<pair>::iterator it = std::next(list.begin(), left);
	for (int i = 0; i < n1; i++){
		L.push_back(*it);
		++it;
	}

	it =  std::next(list.begin(), mid + 1);
	for (int i = 0; i < n2; i++){
		R.push_back(*it);
		++it;
	}

	it = std::next(list.begin(), left);
	std::list<pair>::iterator itL = L.begin(), itR = R.begin();
	while (itL != L.end() && itR != R.end()){
		if (itL->max <= itR->max){
			*it = *itL;
			++itL;
		}
		else {
			*it = *itR;
			++itR;
		}
		++it;
	}

	while (itL != L.end()){
		*it = *itL;
		++itL;
		++it;
	}

	while (itR != R.end()){
		*it = *itR;
		++itR;
		++it;
	}

}

void mergeSortList(std::list<pair> &list, int left, int right){
	if (left >= right)
		return;
	int mid = left + (right - left) / 2;
	mergeSortList(list, left, mid);
	mergeSortList(list, mid + 1, right);
	mergeList(list, left, mid, right);
};

void PMergeMe::mergeSortMainList(){
	int left = 0;
	int right = _list.size() - 1;
	mergeSortList(_list, left, right);
}

void PMergeMe::getMainAndSubList(){
	for (std::list<pair>::iterator it = _list.begin(); it != _list.end(); it++){
		_mainList.push_back(it->max);
		_subList.push_back(it->min);
	}
}

void PMergeMe::insertSortMainList() {
	getMainAndSubList();
	std::list<int>::iterator it = _subList.begin();
	_mainList.push_front(*it);
	size_t previousIndex = 0, n = 1;
	while (previousIndex != _subList.size() - 1)
	{
		size_t index = getJacobsthalNumber(n + 2) - 1;
		if (index > _subList.size())
			index = _subList.size() - 1;
		for (size_t i = index; i > previousIndex; i--)
		{
			it = _subList.begin();
			std::advance(it, i);
			int number = *it;
			std::list<int>::iterator pos = binarySearchListPosition(_mainList, number);
			_mainList.insert(pos, number);
		}
		previousIndex = index;
		n++;
	}
	if (_single != -1)
	{
			std::list<int>::iterator pos = binarySearchListPosition(_mainList, _single);
			_mainList.insert(pos, _single);
	}
}

//deque methods



//helper functions


int getJacobsthalNumber(int n) {
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	return getJacobsthalNumber(n - 1) + 2 * getJacobsthalNumber(n - 2);
}

std::list<int>::iterator binarySearchListPosition(std::list<int> &mainList, int number){
	std::list<int>::iterator begin = mainList.begin();
	std::list<int>::iterator end = mainList.end();
	std::list<int>::iterator mid;

	while (begin != end){
		mid = begin;
		std::advance(mid, std::distance(begin,end) / 2);
		if (*mid < number)
			begin = ++mid;
		else
			end = mid;
	}
	return begin;
}



