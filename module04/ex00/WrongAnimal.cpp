#include <iostream>

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal( void ) : _type("") {
	std::cout << "WrongAnimal default constructor called\n";
}

WrongAnimal::WrongAnimal( std::string type ) : _type(type) {
	std::cout << "WrongAnimal( string ) constructor called\n";
}

WrongAnimal::~WrongAnimal( void ) {
	std::cout << "WrongAnimal destructor called\n";
}

WrongAnimal::WrongAnimal( const WrongAnimal& src ) {
	*this = src;
}

std::string	WrongAnimal::getType( void ) const {
	return this->_type;
}

void WrongAnimal::makeSound( void ) const {
	std::cout << this->_type << ": I'm a wrong animal.\n";
}

WrongAnimal& WrongAnimal::operator=( const WrongAnimal& other ) {
	if (this != &other)
	{
		this->_type = other._type;
	}
	return *this;
}
