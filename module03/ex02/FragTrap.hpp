#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <string>
# include "ClapTrap.hpp"

class	FragTrap : public ClapTrap
{
	public:
		void	highFivesGuys( void ) const;
	
	FragTrap( std::string name );
	~FragTrap( void );
	FragTrap( const FragTrap& src );

	FragTrap& operator=( const FragTrap& rhs );
};

#endif
