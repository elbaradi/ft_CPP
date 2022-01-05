#include <iostream>

#include "MateriaSource.hpp"
#include "IMateriaSource.hpp"

MateriaSource::MateriaSource( void ) : IMateriaSource() {
	std::cout << "MateriaSource default constructor called\n";
	for (int i = 0; i < 4; i++)
		this->_source[i] = NULL;
}

MateriaSource::~MateriaSource( void ) {
	std::cout << "MateriaSource destructor called\n";
}

MateriaSource::MateriaSource( const MateriaSource& src ) {
	std::cout << "MateriaSource copy constructor called\n";
	*this = src;
}

void MateriaSource::learnMateria( AMateria* m ) {
	for (int i = 0; i < 4; i++)
		if (this->_source[i] == NULL)
		{
			this->_source[i] = m;
			break ;
		}
}

AMateria* MateriaSource::createMateria( std::string const & type ) {
	AMateria* m = NULL;
	for (int i = 3; i >= 0; i--)
		if (this->_source[i] != NULL && this->_source[i]->getType() == type)
		{
			m = this->_source[i]->clone();
			delete this->_source[i];
			this->_source[i] = NULL;
			break ;
		}
	return m;
}

MateriaSource& MateriaSource::operator=( const MateriaSource& other ) {
	std::cout << "MateriaSource assignation operator overload called\n";
	if (this != &other)
		for (int i = 0; i < 4; i++)
		{
			if (other._source[i] == NULL)
				this->_source[i] = NULL;
			else
				this->_source[i] = other._source[i]->clone();
		}
	return *this;
}
