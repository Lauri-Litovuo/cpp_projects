#include "Span.hpp"

template <typename Iterator>
void Span::addRange(Iterator begin, Iterator end) {
	if (_isFull || std::distance(begin, end) + _size > _maxSize)
		throw SpanException();
	while (begin != end) {
		if (_size >= _maxSize)
			throw SpanException();
		_numbers.push_back(*begin);
		_size++;
		begin++;
	}
}