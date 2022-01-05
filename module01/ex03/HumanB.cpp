#include <iostream>
#include <string>
#include "HumanB.hpp"
#include "Weapon.hpp"

HumanB::HumanB(const std::string name) : _name(name)
{
	return;
}

HumanB::~HumanB(void)
{
	return;
}

void	HumanB::attack(void)
{
	std::cout << this->_name << " attacks with his " << (*this->_weapon).getType() << std::endl;
}

void	HumanB::setWeapon(Weapon& weapon)
{
	this->_weapon = &weapon;
}
