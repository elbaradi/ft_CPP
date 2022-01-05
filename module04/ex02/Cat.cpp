#include <iostream>

#include "Animal.hpp"
#include "Cat.hpp"

Cat::Cat( void ) : Animal("Cat") {
	std::cout << "Cat default constructor called\n";
	this->_brain = new Brain();
}

Cat::~Cat( void ) {
	std::cout << "Cat destructor called\n";
	delete this->_brain;
}

Cat::Cat( const Cat& src ) {
	this->_brain = new Brain();
	*this = src;
}

void Cat::makeSound( void ) const {
	std::cout << this->_type << ": Meo-- shut the fuck up\n";
}

std::string	Cat::getType( void ) const {
	return this->_type;
}

Brain*	Cat::getBrain( void ) const {
	return this->_brain;
}

void	Cat::setBrain( Brain& brain )
{
	this->_brain = &brain;
}

Animal& Cat::operator=( const Animal& other ) {
	*this = (Cat&)other;
	return *this;
}

Cat& Cat::operator=( const Cat& other ) {
	if (this != &other)
	{
		this->_type = other._type;
		*(this->_brain) = *(other._brain);
	}
	return *this;
}
