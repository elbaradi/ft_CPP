#ifndef HUMANA_HPP
# define HUMANA_HPP

# include <string>
# include "Weapon.hpp"

class	HumanA
{
	private:
		const std::string	_name;
		Weapon				&_weapon;

	public:
		void				attack(void);

	HumanA(std::string, Weapon& weapon);
	~HumanA(void);
};

#endif
