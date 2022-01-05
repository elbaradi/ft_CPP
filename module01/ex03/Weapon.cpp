#include <string>
#include "Weapon.hpp"

Weapon::Weapon(void) : _type("Basic hammer")
{
	return;
}

Weapon::Weapon(std::string type) : _type(type)
{
	return;
}

Weapon::~Weapon(void)
{
	return;
}

void	Weapon::setType(std::string type)
{
	this->_type = type;
}

const std::string &	Weapon::getType(void) const
{
	return this->_type;
}
