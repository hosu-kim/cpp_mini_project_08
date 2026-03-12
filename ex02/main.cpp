#include <list>
#include "MutantStack.hpp"

int main() {
	// STACK PROPERTIES TEST
	// Tests whether it still has the properties of a stack.
	std::cout << "--- MutantStack Test ---" << std::endl;
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << "Top: " << mstack.top() << std::endl; // 17
	
	// Deletes the element at the top.
	mstack.pop();

	std::cout << "Size: " << mstack.size() << std::endl; // 1

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::iterator iterBegin = mstack.begin();
	MutantStack<int>::iterator iterEnd = mstack.end();

	++iterBegin;
	--iterBegin;
	while (iterBegin != iterEnd) {
		std::cout << *iterBegin << std::endl;
		++iterBegin;
	}

	// COPY CONSTRUCTOR TEST
	std::stack<int> s(mstack);

//==================================================================
	std::cout << "\n--- std::list Comparison Test ---" << std::endl;
	std::list<int> testList;

	testList.push_back(5);
	testList.push_back(17);

	std::cout << "Back: " << testList.back() << std::endl;

	// Deletes the last element in the list
	testList.pop_back();

	std::cout << "Size: " << testList.size() << std::endl;

	testList.push_back(3);
	testList.push_back(5);
	testList.push_back(737);
	testList.push_back(0);

	std::list<int>::iterator listBegin = testList.begin();
	std::list<int>::iterator listEnd = testList.end();

	++listBegin;
	--listBegin;
	while (listBegin != listEnd) {
		std::cout << *listBegin << std::endl;
		++listBegin;
	}
	return 0;
}

// MutantStack should produce the same result as list.