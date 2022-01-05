#include <iostream>

#include "Dog.hpp"

Dog::Dog( void ) : Animal("Dog") {
	std::cout << "Dog default constructor called\n";
}

Dog::~Dog( void ) {
	std::cout << "Dog destructor called\n";
}

Dog::Dog( const Dog& src ) {
	*this = src;
}

void Dog::makeSound( void ) const {
	std::cout << this->_type << ": Woof!\n";
}

Dog& Dog::operator=( const Dog& other ) {
	if (this != &other)
	{
		this->_type = other._type;
	}
	return *this;
}
