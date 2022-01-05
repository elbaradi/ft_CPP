#include <iostream>
#include <string>

#include "AMateria.hpp"
#include "Character.hpp"

Character::Character( void ) : _name("") {
	std::cout << "Character default constructor called\n";
	for (int i = 0; i < 4; i++)
		this->_slots[i] = NULL;
}

Character::Character( std::string const & name ) : _name(name) {
	std::cout << "Character( string const & ) constructor called\n";
	for (int i = 0; i < 4; i++)
		this->_slots[i] = NULL;
}

Character::~Character( void ) {
	std::cout << "Character destructor called\n";
	for (int i = 0; i < 4; i++)
		if (this->_slots[i] != NULL)
			delete this->_slots[i];
}

Character::Character( const Character& src ) : _name(src.getName()) {
	std::cout << "Character copy constructor called\n";
	*this = src;
}

std::string const & Character::getName( void ) const {
	return this->_name;
}

void Character::equip( AMateria* m ) {
	for (int i = 0; i < 4; i++)
		if (this->_slots[i] == NULL)
		{
			this->_slots[i] = m;
			break ;
		}
}

void Character::unequip( int idx ) {
	if (idx >= 0 && idx <= 3 && this->_slots[idx] != NULL)
		this->_slots[idx] = NULL;
}

void Character::use( int idx, ICharacter& target ) {
	if (idx >= 0 && idx <= 3 && this->_slots[idx] != NULL)
	{
		this->_slots[idx]->use( target );
		delete this->_slots[idx];
		this->_slots[idx] = NULL;
	}
}

Character& Character::operator=( const Character& other ) {
	std::cout << "Character assignation operator overload called\n";
	if (this != &other)
		for (int i = 0; i < 4; i++)
		{
			if (other._slots[i] == NULL)
				this->_slots[i] = NULL;
			else
				this->_slots[i] = other._slots[i]->clone();
		}
	return *this;
}
