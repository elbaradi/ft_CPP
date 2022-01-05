#include "Zombie.hpp"
#include <string>

void	randomChump(std::string);
Zombie*	newZombie(std::string);

int	main(void)
{
	Zombie* zombie = newZombie("Niels");

	randomChump("Kas");
	zombie->announce();
	delete zombie;
}
