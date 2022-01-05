#include <iostream>
#include <string>
#include "ClapTrap.hpp"
#include "DiamondTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

DiamondTrap::DiamondTrap( std::string name ) : ClapTrap(name + "_clap_name"), ScavTrap(), FragTrap()
{
	std::cout << "DiamondTrap default constructor has been called.\n";
	this->_name = name;
	this->_hp = _hp;
	this->_ep = _ep;
	this->_ad = _ad;
}

DiamondTrap::~DiamondTrap( void )
{
	std::cout << "DiamondTrap deconstructor has been called.\n";
}

DiamondTrap::DiamondTrap( const DiamondTrap& src ) : ClapTrap(src), ScavTrap(src), FragTrap(src)
{
	std::cout << "DiamondTrap copy constructor has been called.\n";
	*this = src;
}

void DiamondTrap::whoAmI( void ) const
{
	std::cout << "DiamondTrap: name = " << this->_name << std::endl;
	std::cout << "DiamondTrap: clapTrap name = " << this->ClapTrap::_name << "\n";
	std::cout << "DiamondTrap: _hp = " << this->_hp << ", _ep = " << this->_ep << ", _ad = " << this->_ad << "\n";
}

DiamondTrap& DiamondTrap::operator=( const DiamondTrap& rhs )
{
	std::cout << "DiamondTrap assignation operator overload has been called.\n";
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->ClapTrap::_name = rhs.ClapTrap::_name;
		this->_hp = rhs._hp;
		this->_ep = rhs._ep;
		this->_ad = rhs._ad;
	}
	return *this;
}
