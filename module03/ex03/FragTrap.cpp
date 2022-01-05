#include <iostream>
#include <string>
#include "FragTrap.hpp"

FragTrap::FragTrap( void ) : ClapTrap()
{
	std::cout << "FragTrap partial default constructor has been called.\n";
	this->_hp = 100;
	this->_ad = 30;
	return ;
}

FragTrap::FragTrap( std::string name ) : ClapTrap(name)
{
	std::cout << "FragTrap default constructor has been called.\n";
	this->_hp = 100;
	this->_ep = 100;
	this->_ad = 30;
	return ;
}

FragTrap::~FragTrap( void )
{
	std::cout << "FragTrap deconstructor has been called.\n";
	return ;
}

FragTrap::FragTrap( const FragTrap& src ) : ClapTrap(src)
{
	std::cout << "FragTrap copy constructor has been called.\n";
	*this = src;
}

void	FragTrap::highFivesGuys( void ) const
{
	std::cout << "FragTrap: \"Good shit brother, up top!\"\n";
}

FragTrap& FragTrap::operator=( const FragTrap& rhs )
{
	std::cout << "FragTrap assignation operator overload has been called.\n";
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_hp = rhs._hp;
		this->_ep = rhs._ep;
		this->_ad = rhs._ad;
	}
	return *this;
}
