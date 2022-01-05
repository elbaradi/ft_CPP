#include <iostream>
#include <string>

#include "AMateria.hpp"

AMateria::AMateria( void ) : _type("") {
	std::cout << "AMateria default constructor called\n";
}

AMateria::AMateria( std::string const & type ) : _type(type) {
	std::cout << "AMateria( string const & ) constructor called\n";
}

AMateria::~AMateria( void ) {
	std::cout << "AMateria destructor called\n";
}

AMateria::AMateria ( const AMateria& src ) : _type(src.getType()) {
	std::cout << "AMateria copy constructor called\n";
	*this = src;
}

std::string const & AMateria::getType( void ) const {
	return this->_type;
}

void AMateria::use( ICharacter& target ) {
	std::cout << this->_type << " was used on " << target.getName() << "!\n";
}

AMateria& AMateria::operator=( const AMateria& other ) {
	std::cout << "AMateria assignation operator overload called\n";
	if (this != &other)
	{
		// "While assigning one Materia to another, copying the type doesn't make sense"
		// this->_type = other._type;
	}
	return *this;
}
