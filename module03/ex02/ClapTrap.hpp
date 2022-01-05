#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>

class ClapTrap
{
	protected:
		std::string		_name;
		unsigned int	_hp;
		unsigned int	_ep;
		unsigned int	_ad;

	public:
		void	attack( const std::string & target );
		void	takeDamage( unsigned int amount );
		void	beRepaired (unsigned int amount );

	ClapTrap( std::string name );
	~ClapTrap( void );
	ClapTrap( const ClapTrap& src );

	ClapTrap& operator=( const ClapTrap& rhs );
};

#endif
