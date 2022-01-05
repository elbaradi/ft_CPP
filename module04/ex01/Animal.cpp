#include <iostream>
#include <string>

#include "Animal.hpp"

Animal::Animal( void ) : _type("") {
	std::cout << "Animal default constructor called\n";
}

Animal::Animal( std::string type ) : _type(type) {
	std::cout << "Animal( string ) constructor called\n";
}

Animal::~Animal( void ) {
	std::cout << "Animal destructor called\n";
}

Animal::Animal ( const Animal& src ) {
	*this = src;
}

std::string	Animal::getType( void ) const {
	return this->_type;
}

void Animal::makeSound( void ) const {
	std::cout << this->_type << ": I'm an animal.\n";
}

Brain* Animal::getBrain( void ) const {
	return NULL;
}

void Animal::setBrain( Brain& brain ) {
	(void)brain;
}

Animal& Animal::operator=( const Animal& other ) {
	if (this != &other)
	{
		this->_type = other._type;
	}
	return *this;
}
