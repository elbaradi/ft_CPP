#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <string>
# include "ClapTrap.hpp"

class	ScavTrap : virtual public ClapTrap					// added keyword 'virtual' to ensure base class is only used once when creating the derivative DiamondTrap
{
	public:
		void	guardGate( void ) const;

		void	attack( const std::string & target );

	ScavTrap( void );
	ScavTrap( std::string name );
	~ScavTrap( void );
	ScavTrap( const ScavTrap& src );

	ScavTrap& operator=( const ScavTrap& rhs );
};

#endif
