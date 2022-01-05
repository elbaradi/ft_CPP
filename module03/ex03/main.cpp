#include <iostream>
#include "ClapTrap.hpp"
#include "DiamondTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int	main(void)
{
	ClapTrap	Bobbie("Bobbie");

	std::cout << '\n';
	Bobbie.attack("DickJan");
	Bobbie.takeDamage(7);
	Bobbie.beRepaired(2);
	std::cout << '\n';

	ClapTrap 	Bobbie_2 = Bobbie;
	Bobbie_2.takeDamage(9);
	Bobbie_2.beRepaired(3);
	std::cout << '\n';

	Bobbie.takeDamage(1);
	std::cout << '\n';

	ScavTrap	Johannes("Johannes");
	ScavTrap	Johannes_2 = Johannes;
	std::cout << '\n';

	Johannes.guardGate();
	Johannes.attack("DickJan");
	Johannes.takeDamage(15);
	Johannes.beRepaired(20);
	std::cout << '\n';

	Johannes_2.takeDamage(5);
	std::cout << '\n';

	FragTrap	Carlo("Carlo");
	FragTrap	Carlo_2 = Carlo;
	std::cout << '\n';

	Carlo.highFivesGuys();
	Carlo.attack("DickJan");
	Carlo.takeDamage(48);
	Carlo.beRepaired(26);
	std::cout << '\n';

	Carlo_2.takeDamage(20);
	std::cout << '\n';

	DiamondTrap	Braut("Braut");
	std::cout << '\n';
	DiamondTrap	Braut_2 = Braut;
	std::cout << '\n';

	Braut.guardGate();
	Braut.whoAmI();
	Braut.highFivesGuys();
	Braut.attack("DickJan");
	Braut.takeDamage(48);
	Braut.beRepaired(26);
	std::cout << '\n';

	Braut_2.takeDamage(20);
	Braut_2.whoAmI();
	std::cout << '\n';
	return 0;
}
