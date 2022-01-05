#pragma once

#include <exception>
#include <set>

class Span {
	private:
		std::multiset<int> _set;
		unsigned int _currentSize;
		unsigned int _maxSize;
		Span( void );
	
	class NoStorageException : public std::exception {
		const char* what() const throw();
	};

	class NoSpanException : public std::exception {
		const char* what() const throw();
	};

	public:
		void addNumber( int nbr );
		unsigned int shortestSpan( void );
		unsigned int longestSpan( void );
		
		template <class InputIt>
		void addNumbers( InputIt begin, InputIt end ) { 
			for (; begin != end; begin++)
				addNumber(*begin);
		}

	Span( unsigned int N );
	Span( const Span& src );
	~Span( void );

	Span& operator=( const Span& other );
};
