#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>
# include <deque>

template <typename T>
// 돌연변이 흉물
class MutantStack : public std::stack<T> {
	public:
		// Orthodox Canonical Form
		MutantStack() : std::stack<T>() {}
		MutantStack(const MutantStack& src): std::stack<T>(src) {}
		MutantStack<T>& operator=(const MutantStack<T>& src) {
			if (this != &src) {
				// 저장하는 모든 숫자는 부모 클래스인 `std::stack<T>` 내부에 있는 `c`(컨테이너)라는 변수에 저장되기
				// 때문에 `MutantStack`끼리 대입을 할 때, 부모가 가진 `c`라는 상자 속 내용물을 통째로 복사해온다.
				std::stack<T>::operator=(src);
			}
			return *this;
		}
		// 이 녀석은 나중에 자식이 생길 수도 있는 녀석이므로
		// 부모 클래스 타입의 포인터로 자식 객체를 삭제할 때,
		// 자식의 소멸자까지 안전하게 호출하기 위해서이다.
		virtual ~MutantStack() {}
//==============================================================================
		// Iterators
		// Brings the iterator type of the underlying container hidden inside the stack
		// `std::stack` doesn't store data directly; it uses an internal container (default: `std::deque`).
		// The alias `container_type` holds the information about which container it is currently using.
		// 1. `std::stack<T>: 스택으로 가서
		// 2. `::container_type`: 네가 내부적으로 쓰는 컨테이너 타입을 찾고
		// 3. `::iterator`: 그 컨테이너가 사용하는 반복자 타입을 가져온다.
		// `iterator`: iterator similar to just a pointer (you can modify, read and move...)
		typedef typename std::stack<T>::container_type::iterator iterator;
		// `const_iterator`: iterator similar to a pointer that can only read
		//                   the object it points to, but cannot modify it.
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;
		// `reverse_iterator`: iterator that moves backwards
		typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
		// `const_reverse_iterator`: it can moves backwards but cannot modify the value
		typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

		// ==================== CORE PART OF THE SUBJECT ====================
		// returns the iterator at the beginning
		iterator begin() { return this->c.begin(); }
		// returns the iterator at the end
		iterator end() { return this->c.end(); }

		const_iterator begin() const { return this->c.begin(); }
		const_iterator end() const { return this->c.end(); }

		reverse_iterator rbegin() { return this->c.rbegin(); }
		reverse_iterator rend() { return this->c.rend(); }

		const_reverse_iterator rbegin() const { return this->c.rbegin(); }
		const_reverse_iterator rend() const { return this->c.rend(); }
};

#endif