#include "Span.hpp"

Span::Span(unsigned int N) : _maxSize(N), _size(0), _isFull(false) {
	try{
		_numbers.reserve(N);
	}
	catch(const std::exception &e){
		std::cerr << e.what() << std::endl;
	}
}

Span::Span(const Span &other) : _maxSize(other._maxSize), _size(other._size), _numbers(other._numbers), _isFull(other._isFull) {
}

Span::~Span() {
}

Span &Span::operator=(const Span &other) {
	if (this == &other)
		return *this;
	_maxSize = other._maxSize;
	_size = other._size;
	_numbers = other._numbers;
	_isFull = other._isFull;
	return *this;
}

void Span::addNumber(int number) {
	if (_size >= _maxSize)
		throw SpanFullException();
	_numbers.push_back(number);
	_size++;
	if (_size == _maxSize)
		_isFull = true;
}

unsigned int Span::shortestSpan() {
	if (_size <= 1)
		throw SpanException();
	std::sort(_numbers.begin(), _numbers.end());
	unsigned int min = UINT_MAX;
	for (unsigned int i = 1; i < _size; i++) {
		if (static_cast<unsigned int>(_numbers[i] - _numbers[i - 1]) < min)
			min = _numbers[i] - _numbers[i - 1];
	}
	return min;
}

std::vector<int> Span::getNumbers() const {
	return _numbers;
}

unsigned int Span::longestSpan() {
	if (_size <= 1)
		throw SpanException();
	std::sort(_numbers.begin(), _numbers.end());
	return _numbers[_size - 1] - _numbers[0];
}

const char* Span::SpanException::what() const noexcept {
	return "Error: Span is empty or contains only one element";
}

const char* Span::SpanFullException::what() const noexcept {
	return "Error: Span is full";
}









