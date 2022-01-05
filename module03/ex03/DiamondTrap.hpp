#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include <string>
# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class	DiamondTrap : public ScavTrap, public FragTrap
{
	private:
		std::string	_name;

	public:
		void	whoAmI( void ) const;
	
	DiamondTrap( std::string name );
	~DiamondTrap( void );
	DiamondTrap( const DiamondTrap& src );

	DiamondTrap& operator=( const DiamondTrap& rhs );
};

#endif
