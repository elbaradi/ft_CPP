#include "Zombie.hpp"
#include <string>

Zombie*	ZombieHorde(int N, std::string);

int	main(void)
{
	int		n = 6;
	Zombie* horde = ZombieHorde(n, "Niels");

	for (int i = 0; i < n; i++)
		horde[i].announce();
	delete [] horde;
}
