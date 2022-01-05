#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>

class	Weapon
{
	private:
		std::string	_type;

	public:
		const std::string &	getType(void) const;
		void				setType(const std::string type);

	Weapon(void);
	Weapon(const std::string type);
	~Weapon(void);
};

#endif
