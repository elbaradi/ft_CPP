#include <iostream>

#include "AMateria.hpp"
#include "Cure.hpp"

Cure::Cure( void ) : AMateria("cure") {
	std::cout << "Cure default constructor called\n";
}

Cure::~Cure( void ) {
	std::cout << "Cure destructor called\n";
}

Cure::Cure( const Cure& src ) : AMateria("cure") {
	std::cout << "Cure copy constructor called\n";
	*this = src;
}

AMateria* Cure::clone( void ) const {
	std::cout << "Cure::clone called\n";
	return new Cure();
}

void Cure::use( ICharacter& target ) {
	std::cout << "* heals " << target.getName() << "’s wounds *\n";
}

Cure& Cure::operator=( const Cure& other ) {
	std::cout << "Cure assignation operator overload called\n";
	(void)other;
	return *this;
}
