#include <climits> // UINT_MAX
#include <cstdlib> // std::abs
#include <exception> // std::exception
#include <iterator>

#include "span.hpp"

Span::Span( void ) : _set(), _currentSize(0), _maxSize(0) { }
Span::Span( unsigned int N ) : _set(), _currentSize(0), _maxSize(N) { }
Span::Span( const Span& src ) : _set(src._set), _currentSize(src._currentSize), _maxSize(src._maxSize) { }
Span::~Span( void ) { }

Span& Span::operator=( const Span& other ) {
	if (this != &other) {
		this->_currentSize = other._currentSize;
		this->_maxSize = other._maxSize;
		this->_set = other._set;
	}
	return *this;
}

void Span::addNumber( int nbr ) {
	if (this->_currentSize >= this->_maxSize)
		throw NoStorageException();

	_set.insert(nbr);
	(this->_currentSize)++;
}

unsigned int Span::shortestSpan( void ) {
	if (this->_currentSize < 2)
		throw NoSpanException();
		
	unsigned int shortestSpan = UINT_MAX;
	std::multiset<int>::iterator i = _set.begin(), j = _set.begin();
	for (j++; j != _set.end(); i++, j++) {
		unsigned int diff = std::abs((long)*i - (long)*j);
		if (diff < shortestSpan)
			shortestSpan = diff;
		if (shortestSpan == 0)
			break;
	}
	return shortestSpan;
}

unsigned int Span::longestSpan( void ) {
	if (this->_currentSize < 2)
		throw NoSpanException();
	
	unsigned int longestSpan = *(_set.rbegin()) - *(_set.begin());
	return longestSpan;
}

const char* Span::NoStorageException::what() const throw() {
	return "max capacity to store integers has been reached";
}

const char* Span::NoSpanException::what() const throw() {
	return "not enough elements stored to find a span";
}
