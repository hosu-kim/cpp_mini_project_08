#include <iostream>
#include <vector>
#include <list>

#include "easyfind.hpp"

int main() {
	// 1. VECTOR TEST
	std::vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);

	try {
		std::vector<int>::iterator it = easyfind(v, 20);
		std::cout << "Found: " << *it << std::endl;

		// `42` is not in the vector. => exception
		easyfind(v, 42);
	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	// 2. LIST TEST
	std::list<int> l;
	l.push_back(1);
	l.push_back(2);

	try {
		std::list<int>::iterator it = easyfind(l, 1);
		std::cout << "Found in list: " << *it << std::endl;
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	return 0;
}