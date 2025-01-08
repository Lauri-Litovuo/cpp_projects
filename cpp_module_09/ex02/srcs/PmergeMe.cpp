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
		_input = rhs._input;
		_inputList = rhs._inputList;
		_inputDeque = rhs._inputDeque;
		_ListDMTime = rhs._ListDMTime;
		_DequeDMTime = rhs._DequeDMTime;
		_ListSTime = rhs._ListSTime;
		_DequeSTime = rhs._DequeSTime;
		_deque = rhs._deque;
		_list = rhs._list;
	}
	return *this;
};

void PMergeMe::fillList() {
	std::chrono::time_point<std::chrono::system_clock> start = std::chrono::system_clock::now();
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
	std::chrono::time_point<std::chrono::system_clock> end = std::chrono::system_clock::now();
	_ListDMTime = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
};

void PMergeMe::fillDeque() {
	std::chrono::time_point<std::chrono::system_clock> start = std::chrono::system_clock::now();
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
	std::chrono::time_point<std::chrono::system_clock> end = std::chrono::system_clock::now();
	_DequeDMTime = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
}

void PMergeMe::sortList() {
}

void PMergeMe::sortDeque() {
}

void PMergeMe::printSorted() {
	std::cout << "Before: " << _input << std::endl;
	std::cout << "After : " << std::endl;
	std::cout << "Time to process range of: " << " elements with std::list:" << std::endl;
	std::cout << "Data Management: " << _ListDMTime << " microseconds" << std::endl;
	std::cout << "Sorting: " << _ListSTime << " microseconds" << std::endl;
	std::cout << "Total: " << _ListDMTime + _ListSTime << " microseconds" << std::endl;
	std::cout << "Time to process range of: " << " elements with std::deque:" << std::endl;
	std::cout << "Data Management: " << _DequeDMTime << " microseconds" << std::endl;
	std::cout << "Sorting: " << _DequeSTime << " microseconds" << std::endl;
	std::cout << "Total: " << _DequeDMTime + _DequeSTime << " microseconds" << std::endl;
	

}

