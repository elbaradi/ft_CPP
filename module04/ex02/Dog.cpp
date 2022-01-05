#include <iostream>

#include "Animal.hpp"
#include "Dog.hpp"

Dog::Dog( void ) : Animal("Dog") {
	std::cout << "Dog default constructor called\n";
	this->_brain = new Brain();
}

Dog::~Dog( void ) {
	std::cout << "Dog destructor called\n";
	delete this->_brain;
}

Dog::Dog( const Dog& src ) {
	this->_brain = new Brain();
	*this = src;
}

void Dog::makeSound( void ) const {
	std::cout << this->_type << ": Woof!\n";
}

std::string	Dog::getType( void ) const {
	return this->_type;
}

Brain*	Dog::getBrain( void ) const {
	return this->_brain;
}

void	Dog::setBrain( Brain& brain )
{
	this->_brain = &brain;
}

Animal& Dog::operator=( const Animal& other ) {
	*this = (Dog&)other;
	return *this;
}

Dog& Dog::operator=( const Dog& other ) {
	if (this != &other)
	{
		this->_type = other._type;
		*(this->_brain) = *(other._brain);
	}
	return *this;
}
