#include "Span.hpp"

Span::Span() : _maxSize(0) {}

Span::Span(unsigned int n) : _maxSize(n) {
	_numbers.reserve(n);
}

Span::Span(const Span& src) {
	*this = src;
}

Span& Span::operator=(const Span& src) {
	if (this != &src) {
		this->_maxSize = src._maxSize;
		this->_numbers = src._numbers;
	}
	return *this;
}

Span::~Span() {}

void Span::addNumber(int n) {
	if (_numbers.size() >= _maxSize) {
		throw std::out_of_range("Error: Span is already full!");
	}
	_numbers.push_back(n);
}


int Span::shortestSpan() {
	if (_numbers.size() < 2)
		throw std::logic_error("Not enough numbers to find a span");
	
	std::vector<int> sorted = _numbers;
	std::sort(sorted.begin(), sorted.end());

	int minDiff = sorted[1] - sorted[0];
	for (size_t i = 1; i < sorted.size() - 1; ++i) {
		int diff = sorted[i + 1] - sorted[i];
		if (diff < minDiff)
			minDiff = diff;
	}
	return minDiff;
}

int Span::longestSpan() {
	if (_numbers.size() < 2)
		throw std::logic_error("Not enough numbers to find a span");

	int minVal = *std::min_element(_numbers.begin(), _numbers.end());
	int maxVal = *std::max_element(_numbers.begin(), _numbers.end());

	return maxVal - minVal;
}