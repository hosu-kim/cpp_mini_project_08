/*
This exercise is about creating a class having a vector
which can store 'N' numbers of integers.
and the class has these member functions:
1. func which you can add a number with in 'N' size if over throw an exception.
2. func which you can add several numbers in a range of another vector or a list.
3. func which finds the shortest span between the provided numbers: 6, 3, 17, 9 => 3
4. func which finds the longest span between the provided numbers: 6, 3, 17, 9 => 14
*/

#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <exception>

// DOC: Develop a Span class that can store a maximum of N integers.
//      N is an unsigned int variable and will be the only parameter passed
//      to the constructor.
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

		// DOC: addNumber() to add a single number to the Span.
		// It will be used in order to fill it.
		void addNumber(int n);

// DOC: Implement a member function to add multiple numbers
// to your Span in a single call.

// Template functions must be implemented immediately upon declaration.
		template <typename T>
		// T begin, T end: a range of numbers from a vector/list
		void addNumbers(T begin, T end) {
			// std::distance: calculates how many numbers there are 
			//                in the range of data from a vector/list.
			if (_numbers.size() + std::distance(begin, end) > _maxSize)
				throw std::out_of_range("Span is full");
			_numbers.insert(_numbers.end(), begin, end);
		}

		// DOC: They will respectively find out the shortest span or the longest span
		int shortestSpan();
		int longestSpan();
};

#endif
