#include <iostream>
#include <string>
#include "Zombie.hpp"

Zombie::Zombie(std::string name) :_name(name)
{
	return ;
}

Zombie::~Zombie(void)
{
	std::cout << this->_name + " has been deconstructed.\n";
}

void	Zombie::announce(void)
{
	std::cout << '<' << this->_name + "> BraiiiiiiinnnzzzZ...\n";
}
