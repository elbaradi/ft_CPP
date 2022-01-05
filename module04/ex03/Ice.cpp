#include <iostream>

#include "AMateria.hpp"
#include "Ice.hpp"

Ice::Ice( void ) : AMateria("ice") {
	std::cout << "Ice default constructor called\n";
}

Ice::~Ice( void ) {
	std::cout << "Ice destructor called\n";
}

Ice::Ice( const Ice& src ) : AMateria("ice") {
	std::cout << "Ice copy constructor called\n";
	*this = src;
}

AMateria* Ice::clone( void ) const {
	std::cout << "Ice::clone called\n";
	return new Ice();
}

void Ice::use( ICharacter& target ) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *\n";
}

Ice& Ice::operator=( const Ice& other ) {
	std::cout << "Ice assignation operator overload called\n";
	(void)other;
	return *this;
}
