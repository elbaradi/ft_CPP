#include <iostream>

#include "Cat.hpp"

Cat::Cat( void ) : Animal("Cat") {
	std::cout << "Cat default constructor called\n";
}

Cat::~Cat( void ) {
	std::cout << "Cat destructor called\n";
}

Cat::Cat( const Cat& src ) {
	*this = src;
}

void Cat::makeSound( void ) const {
	std::cout << this->_type << ": Meo-- shut the fuck up\n";
}

Cat& Cat::operator=( const Cat& other ) {
	if (this != &other)
	{
		_type = other._type;
	}
	return *this;
}
