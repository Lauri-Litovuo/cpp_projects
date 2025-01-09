#include "PmergeMe.hpp"

PMergeMe::PMergeMe(std::string input) : _input(input) {
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

void PMergeMe::sortList() {
	generateListPairs();
	sortPairElementsList();
	// for(auto v : _list)
	// 	std::cout << v.max << " " << v.min << std::endl;
	getMainList();
	// for(auto v : _mainList)
	// 	std::cout << v << std::endl;
	mergeSortMainList();
	// for(auto v : _mainList)
	// 	std::cout << v << std::endl;
	insertSortMainList();
	_listEndTime = std::chrono::system_clock::now();

}

void PMergeMe::sortDeque() {
}

void PMergeMe::printSorted() {
	std::cout << "Before: " << _input << std::endl;
	std::cout << "After : " << std::endl;
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
			temp.max = -1;
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

void PMergeMe::getMainList(){
	std::list<int> mainList;
	for (std::list<pair>::iterator it = _list.begin(); it != _list.end(); it++){
		_mainList.push_back(it->max);
	}


}

void mergeList(std::list<int> &list, int left, int mid, int right){

	int n1 = mid - left + 1;
	int n2 = right - mid;

	std::list<int> L, R;

	std::list<int>::iterator it = std::next(list.begin(), left);
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
	std::list<int>::iterator itL = L.begin(), itR = R.begin();
	while (itL != L.end() && itR != R.end()){
		if (*itL <= *itR){
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

void mergeSortList(std::list<int> &list, int left, int right){
	if (left >= right)
		return;
	int mid = left + (right - left) / 2;
	mergeSortList(list, left, mid);
	mergeSortList(list, mid + 1, right);
	mergeList(list, left, mid, right);
};

void PMergeMe::mergeSortMainList(){
	int left = 0;
	int right = _mainList.size() - 1;
	mergeSortList(_mainList, left, right);
}

void PMergeMe::insertSortMainList() {
	std::list<int> subList;
	for (std::list<int>::iterator it = _mainList.begin(); it != _mainList.end(); it++)

	int jacobstahl = getJacobsthalNumber(i + 2);
}

//deque methods



//helper functions

int PMergeMe::getJacobsthalNumber(int n) {
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	return getJacobsthalNumber(n - 1) + 2 * getJacobsthalNumber(n - 2);
}



