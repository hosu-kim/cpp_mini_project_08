#include "Span.hpp"
#include <ctime> // std::time
#include <cstdlib> // std::rand;

int main() {
	// 1. DEFAULT TEST FROM THE DOC
	std::cout << "=== Basic Test ===" << std::endl;
	try {
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << "Shortest: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest: " << sp.longestSpan() << std::endl;
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n------------------------------------\n" << std::endl;

	// 2. LARGE DATA TEST
	std::cout << "=== Large Data test (20,000 numbers)" << std::endl;
	try {
		unsigned int limit = 20000;
		Span bigSpan(limit);
		std::vector<int> v;

		// filling up random numbers
		std::srand(std::time(NULL));
		for (unsigned int i = 0; i < limit; i++) {
			v.push_back(std::rand());
		}
		// addNumbers (with range iterator)
		bigSpan.addNumbers(v.begin(), v.end());

		std::cout << "Shortest: " << bigSpan.shortestSpan() << std::endl;
		std::cout << "Longest: " << bigSpan.longestSpan() << std::endl;
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n------------------------------------\n" << std::endl;

	// 3. EXCEPTION TEST (OVERFLOW)
	std::cout << "=== Exception Test (Overflow) ===" << std::endl;
	try {
		Span small(2);
		small.addNumber(1);
		small.addNumber(2);
		small.addNumber(3);
	} catch (const std::exception& e) {
		std::cout << "Caught expected exception: " << e.what() << std::endl;
	}

	return 0;
}
