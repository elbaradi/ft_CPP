#include <iostream>
#include <string>
#include "ScavTrap.hpp"

ScavTrap::ScavTrap( void ) : ClapTrap()
{
	std::cout << "ScavTrap partial default constructor has been called.\n";
	this->_ep = 50;
	return ;
}

ScavTrap::ScavTrap( std::string name ) : ClapTrap(name)
{
	std::cout << "ScavTrap default constructor has been called.\n";
	this->_hp = 100;
	this->_ep = 50;
	this->_ad = 20;
	return ;
}

ScavTrap::~ScavTrap( void )
{
	std::cout << "ScavTrap deconstructor has been called.\n";
	return ;
}

ScavTrap::ScavTrap( const ScavTrap& src ) : ClapTrap(src)
{
	std::cout << "ScavTrap copy constructor has been called.\n";
	*this = src;
}

void	ScavTrap::guardGate( void ) const
{
	std::cout << "ScavTrap " << this->_name << " has entered in Gatekeeper mode.\n";
}

void	ScavTrap::attack(const std::string & target)
{	
	std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing " << this->_ad << " points of damage!\n";
}

ScavTrap& ScavTrap::operator=( const ScavTrap& rhs )
{
	std::cout << "ScavTrap assignation operator overload has been called.\n";
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_hp = rhs._hp;
		this->_ep = rhs._ep;
		this->_ad = rhs._ad;
	}
	return *this;
}
