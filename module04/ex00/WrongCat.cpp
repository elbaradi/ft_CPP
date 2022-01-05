#include <iostream>

#include "WrongCat.hpp"

WrongCat::WrongCat( void ) : WrongAnimal("Cat") {
	std::cout << "WrongCat default constructor called\n";
}

WrongCat::~WrongCat( void ) {
	std::cout << "WrongCat destructor called\n";
}

WrongCat::WrongCat( const WrongCat& src ) {
	*this = src;
}

void WrongCat::makeSound( void ) const {
	std::cout << this->_type << ": Meo-- shut the fuck up\n";
}

WrongCat& WrongCat::operator=( const WrongCat& other ) {
	if (this != &other)
	{
		this->_type = other._type;
	}
	return *this;
}
