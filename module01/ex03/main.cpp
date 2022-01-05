#include <iostream>
#include <string>
#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"

int	main(void)
{
	{
		Weapon        club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("XXL inflatable club");
		bob.attack();
	}
	{
		Weapon        club = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("\'Club mate\'-sponsored club");
		jim.attack();
	}
	return 0;
}
