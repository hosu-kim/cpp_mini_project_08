#include "Span.hpp"

// orthodox canonical form
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
// ==================================================================

void Span::addNumber(int n) {
	if (_numbers.size() >= _maxSize) {
		// std::out_of_range: deault exception class;
		// used when the program attemps to access outside the specified range.
		throw std::out_of_range("Error: Span is already full!");
	}
	_numbers.push_back(n);
}


int Span::shortestSpan() {
	// only one number exists
	if (_numbers.size() < 2)
		throw std::logic_error("Not enough numbers to find a span");
	
	std::vector<int> sorted = _numbers;
	// std::sort: sorts data in ascending order
	// begin(): gets the first element <=> end()
	std::sort(sorted.begin(), sorted.end());

	// sets initial value.
	int minDiff = sorted[1] - sorted[0];
	// why sortd.size() '- 1'? at the end, these is only one number left,
    //                         so there is nothing to compare it to.
	for (size_t i = 1; i < sorted.size() - 1; ++i) {
		int diff = sorted[i + 1] - sorted[i];
		if (diff < minDiff)
			minDiff = diff;
	}
	return minDiff;
}

int Span::longestSpan() {
	// only one number exists
	if (_numbers.size() < 2)
		throw std::logic_error("Not enough numbers to find a span");

	// why '*'std::min_element? the function return an iterator.
	//                          you need to take int value to compare with max.
	int minVal = *std::min_element(_numbers.begin(), _numbers.end());
	int maxVal = *std::max_element(_numbers.begin(), _numbers.end());

	return maxVal - minVal;
}