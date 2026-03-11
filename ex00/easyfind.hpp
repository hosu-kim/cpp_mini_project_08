/*
This exercise is about understanding what STL is.
STL is Standard Template Library; it's a toolbox of pre-built data strutures(containers
) and algorithms frequently used by developers.
and learning about two sequence containers, std::vector and std::list which store data.
1. std::vector: Stores data in a contiguous space in memory
    1. Access speed: very fast
    2. Data modification speed: slow
    3. memory efficiency: high
2. std::list: Stores data in scattered spaces in memory
    1. Acess speed: slow (finds them from the beginning)
    2. Data modification speed: very fast (just changes the link and it's done)
    3. Memory efficiency: low (alse has to store front and back address values)
*/

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm> // std::find
# include <exception> // std::exception

class NotFoundException : public std::exception {
	public: 
		const char* what() const throw() {
			return "Element not found in container";
		}
};

template <typename T>
// the types std::vector<int>, std::list<int> contains a type named `iterator`.
// so what is `iterator`? it's a type of pointer-like object that points to an element
// inside a `container` and has the ability to move to the next element.
typename T::iterator easyfind(T& container, int value) {
	// std::find(): 1. find(start, end, what_to_find);
	// 1. Success: returns an iterator to the position where the value is.
	// 2. Failure: returns `container.end()`
	typename T::iterator it = std::find(container.begin(), container.end(), value);

	// when the value is not found.
	if (it == container.end()) {
		throw NotFoundException();
	}

	return it;
}

#endif