#include <iostream>
#include <string>
#include "ClapTrap.hpp"

ClapTrap::ClapTrap( void )
{
	std::cout << "ClapTrap partial default constructor has been called\n";
	return ;
}

ClapTrap::ClapTrap( std::string name ) : _name(name), _hp(10), _ep(10), _ad(0)
{
	std::cout << "ClapTrap default constructor has been called.\n";
	return ;
}

ClapTrap::~ClapTrap( void )
{
	std::cout << "ClapTrap deconstructor has been called.\n";
	return ;
}

ClapTrap::ClapTrap( const ClapTrap& src )
{
	std::cout << "ClapTrap copy constructor has been called.\n";
	*this = src;
}

void	ClapTrap::attack(const std::string & target)
{	
	std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_ad << " points of damage!\n";
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (amount > this->_hp)
		this->_hp = 0;
	else
		this->_hp -= amount;

	std::cout << "ClapTrap " << this->_name << " currently has " << this->_hp << " hitpoints, after taking " << amount << " points of damage!\n";
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	this->_hp += amount;

	std::cout << "ClapTrap " << this->_name << " currently has " << this->_hp << " hitpoints, after being repaired for " << amount << " points!\n";
}

ClapTrap& ClapTrap::operator=( const ClapTrap& rhs )
{
	std::cout << "ClapTrap assignation operator overload has been called.\n";
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_hp = rhs._hp;
		this->_ep = rhs._ep;
		this->_ad = rhs._ad;
	}
	return *this;
}
