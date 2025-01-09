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
		_input = rhs._input;
		_inputList = rhs._inputList;
		_list = rhs._list;
		_mainList = rhs._mainList;
		_subList = rhs._subList;
		_single = rhs._single;
		_listStartTime = rhs._listStartTime;
		_listEndTime = rhs._listEndTime;
		_inputDeque = rhs._inputDeque;
		_dequeStartTime = rhs._dequeStartTime;
		_dequeEndTime = rhs._dequeEndTime;
		_deque = rhs._deque;
		_mainDeque = rhs._mainDeque;
		_subDeque = rhs._subDeque;
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
	if(_inputList.size() == 0 || _inputList.size() == 1)
	{
		_mainList = _inputList; 
		_listEndTime = std::chrono::system_clock::now();
		return;
	}
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
	if (_inputDeque.size() == 0 || _inputDeque.size() == 1)
	{
		_mainDeque = _inputDeque;
		_dequeEndTime = std::chrono::system_clock::now();
		return;
	}
	generateDequePairs();
	sortPairElementsDeque();
	mergeSortMainDeque();
	insertSortMainDeque();
	_dequeEndTime = std::chrono::system_clock::now();

}

void PMergeMe::printSorted() {
	std::cout << "Before: " << _input << std::endl;
	std::string sortedList;
	for (std::list<int>::iterator it = _mainList.begin(); it != _mainList.end(); it++)
		sortedList += std::to_string(*it) + " ";
	
	std::string sortedDeque;
	for (std::deque<int>::iterator it = _mainDeque.begin(); it != _mainDeque.end(); it++)
		sortedDeque += std::to_string(*it) + " ";
	if (sortedDeque != sortedList){
		std::cerr << "Error: Sorted differently" << std::endl;
		return;
	}
	std::cout << "After : " << sortedList << std::endl;
	unsigned int listTime = std::chrono::duration_cast<std::chrono::microseconds>(_listEndTime - _listStartTime).count();
	unsigned int dequeTime = std::chrono::duration_cast<std::chrono::microseconds>(_dequeEndTime - _dequeStartTime).count();
	std::cout << "Time to process range of: " << _mainList.size() << " elements with std::list " << listTime << " microseconds" << std::endl;
	std::cout << "Time to process range of: " << _mainDeque.size() << " elements with std::deque " << dequeTime << " microseconds" << std::endl;
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
		if (index > _subList.size() - 1)
			index = _subList.size() - 1;
		for (size_t i = index; i > previousIndex; i--)
		{
			it = _subList.begin();
			std::advance(it, i);
			int number = *it;
			std::list<int>::iterator pos = binarySearchListPosition(_mainList.begin(), _mainList.end(), number);
			_mainList.insert(pos, number);
		}
		previousIndex = index;
		n++;
	}
	if (_single != -1)
	{
			std::list<int>::iterator pos = binarySearchListPosition(_mainList.begin(), _mainList.end(), _single);
			_mainList.insert(pos, _single);
	}
}



//deque methods

void PMergeMe::generateDequePairs() {
	for (std::deque<int>::iterator it = _inputDeque.begin(); it != _inputDeque.end(); it++) {
		pair temp;
		temp.min = *it;
		it++;
		if (it == _inputDeque.end())
		{
			_single = temp.min;
			break;
		}
		temp.max = *it;
		_deque.push_back(temp);
	}
}

void PMergeMe::sortPairElementsDeque() {
	for (std::deque<pair>::iterator it = _deque.begin(); it != _deque.end(); it++) {
		if (it->min > it->max) {
			int temp = it->min;
			it->min = it->max;
			it->max = temp;
		}
	}
}

void mergeDeque(std::deque<pair> &deque, int left, int mid, int right){

	int n1 = mid - left + 1;
	int n2 = right - mid;

	std::deque<pair> L(n1), R(n2);

	for (int i = 0; i < n1; i++)
		L[i] = deque[left + i];
	for (int j = 0; j < n2; j++)
		R[j] = deque[mid + 1 + j];
	
	int i = 0, j = 0, k = left;
	while (i < n1 && j < n2){
		if (L[i].max <= R[j].max){
			deque[k] = L[i];
			i++;
		}
		else {
			deque[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < n1){
		deque[k] = L[i];
		i++;
		k++;
	}

	while (j < n2){
		deque[k] = R[j];
		j++;
		k++;
	}
}

void mergeSortDeque(std::deque<pair> &deque, int left, int right){
	if (left >= right)
		return;
	int mid = left + (right - left) / 2;
	mergeSortDeque(deque, left, mid);
	mergeSortDeque(deque, mid + 1, right);
	mergeDeque(deque, left, mid, right);
};

void PMergeMe::mergeSortMainDeque() {
	int left = 0;
	int right = _deque.size() - 1;
	mergeSortDeque(_deque, left, right);
}

void PMergeMe::getMainAndSubDeque() {
	for (std::deque<pair>::iterator it = _deque.begin(); it != _deque.end(); it++) {
		_mainDeque.push_back(it->max);
		_subDeque.push_back(it->min);
	}
}


void PMergeMe::insertSortMainDeque() {
	getMainAndSubDeque();
	std::deque<int>::iterator it = _subDeque.begin();
	_mainDeque.push_front(*it);

	size_t previousIndex = 0, n = 1;
	while (previousIndex != _subDeque.size() - 1)
	{
		size_t index = getJacobsthalNumber(n + 2) - 1;
		if (index > _subDeque.size() - 1)
			index = _subDeque.size() - 1;
		for (size_t i = index; i > previousIndex; i--)
		{
			int number = _subDeque[i];
			size_t pos = binarySearchPositionDeque(_mainDeque, 0, _mainDeque.size(), number);
			pos = std::min(pos, _mainDeque.size());
			_mainDeque.insert(_mainDeque.begin() + pos, number);
		}
		previousIndex = index;
		n++;
	}
	if (_single != -1)
	{
		size_t pos = binarySearchPositionDeque(_mainDeque, 0, _mainDeque.size(), _single);
		pos = std::min(pos, _mainDeque.size());
		_mainDeque.insert(_mainDeque.begin() + pos, _single);
	}
}

//helper functions


int getJacobsthalNumber(int n) {
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	return getJacobsthalNumber(n - 1) + 2 * getJacobsthalNumber(n - 2);
}

std::list<int>::iterator binarySearchListPosition(std::list<int>::iterator begin, std::list<int>::iterator end, int number){
	if (begin == end)
		return begin;
	std::list<int>::iterator mid = begin;
	std::advance(mid, std::distance(begin, end) / 2);
	if (*mid < number)
		return binarySearchListPosition(++mid, end, number);
	else
		return binarySearchListPosition(begin, mid, number);
}

size_t binarySearchPositionDeque(std::deque<int> &mainDeque, size_t begin, size_t end, int number){
	if (begin >= end)
		return begin;
	size_t mid = begin + (end - begin) / 2;
	if (mainDeque[mid] < number)
		return binarySearchPositionDeque(mainDeque, mid + 1, end, number);
	else
		return binarySearchPositionDeque(mainDeque, begin, mid, number);
}


