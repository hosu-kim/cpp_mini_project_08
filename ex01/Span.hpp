#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <exception>

class Span {
	private:
		unsigned int _maxSize;
		std::vector<int> _numbers;

	public:
		Span();
		Span(unsigned int n);
		Span(const Span& src);
		Span& operator=(const Span& other);
		~Span();

		void addNumber(int n);

		template <typename T>
		void addNumbers(T begin, T end) {
			if (_numbers.size() + std::distance(begin, end) > _maxSize)
				throw std::out_of_range("Span is full");
			_numbers.insert(_numbers.end(), begin, end);
		}

		int shortestSpan();
		int longestSpan();
};

#endif