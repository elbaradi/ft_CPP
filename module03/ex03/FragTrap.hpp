#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <string>
# include "ClapTrap.hpp"

class	FragTrap : virtual public ClapTrap					// added keyword 'virtual' to ensure base class is only used once when creating the derivative DiamondTrap
{
	public:
		void	highFivesGuys( void ) const;
	
	FragTrap( void );
	FragTrap( std::string name );
	~FragTrap( void );
	FragTrap( const FragTrap& src );

	FragTrap& operator=( const FragTrap& rhs );
};

#endif
