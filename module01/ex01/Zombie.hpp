#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>

class Zombie
{
	private:
		std::string _name;

	public:
		void	announce(void);
		void	setName(std::string);

		Zombie(std::string);
		Zombie(void);
		~Zombie(void);
};

#endif
