#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <string>
# include "Weapon.hpp"

class	HumanB
{
	private:
		const std::string	_name;
		Weapon				*_weapon;
	
	public:
		void				setWeapon(Weapon& weapon);		
		void				attack(void);

	HumanB(const std::string name);
	~HumanB(void);
};

#endif
