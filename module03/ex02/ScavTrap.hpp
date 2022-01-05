#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <string>
# include "ClapTrap.hpp"

class	ScavTrap : public ClapTrap
{
	public:
		void	guardGate( void ) const;

		void	attack( const std::string & target );
	
	ScavTrap( std::string name );
	~ScavTrap( void );
	ScavTrap( const ScavTrap& src );

	ScavTrap& operator=( const ScavTrap& rhs );
};

#endif
