#pragma once

#include <stack>
#include <iterator>

// Stack is an adaptive container, it's a wrapper around an underlying container object (i.e. std::vector, std::list, std::deque).
// The stack itself has a very limited interface. Aim of this exercise is to implement a class that inherits from std::stack, and add iterator functionalities.
// We add these functionalities by -when called- returning the iterators of the underlying container object.

template <typename T>
class MutantStack : public std::stack<T> {
	public:
		typedef typename std::stack<T>::container_type::iterator				iterator;				// These typedefs are necessary to 'expose' the different iterator members
		typedef typename std::stack<T>::container_type::const_iterator 			const_iterator;
		typedef typename std::stack<T>::container_type::reverse_iterator 		reverse_iterator;
		typedef typename std::stack<T>::container_type::const_reverse_iterator	const_reverse_iterator;
	
		MutantStack( void ) : std::stack<T>() { }
		MutantStack( const MutantStack& src ) : std::stack<T>(src) { }
		virtual ~MutantStack( void ) { }
		MutantStack& operator=( const MutantStack& other ) {
			if (this != &other)
				std::stack<T>::operator=(other);
			return *this;
		}

		iterator begin() { return std::stack<T>::c.begin(); }
		const_iterator begin() const { return std::stack<T>::c.cbegin(); }
		iterator end() { return std::stack<T>::c.end(); }
		const_iterator end() const { return std::stack<T>::c.cend(); }
		reverse_iterator rbegin() { return std::stack<T>::c.rbegin(); }
		const_reverse_iterator rbegin() const { return std::stack<T>::c.crbegin(); }
		reverse_iterator rend() { return std::stack<T>::c.rend(); }
		const_reverse_iterator rend() const { return std::stack<T>::c.crend(); }
};
