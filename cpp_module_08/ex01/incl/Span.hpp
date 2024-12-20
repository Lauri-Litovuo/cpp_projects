#pragma once
#include <algorithm>
#include <vector>
#include <exception>
#include <iostream>
#include <climits>

class Span {
	
	private:
		unsigned int _maxSize;
		unsigned int _size;
		std::vector<int> _numbers;
		bool _isFull;

	public:
		Span();
		Span(unsigned int N);
		Span(const Span &other);
		~Span();
		Span &operator=(const Span &other);

		void addNumber(int number);

		unsigned int shortestSpan();
		unsigned int longestSpan();
		
		template <typename Iterator>
		void addRange(Iterator begin, Iterator end);

		class SpanException : public std::exception {
			public:
				const char* what() const noexcept override;
		};
};

#include "Span.tpp"