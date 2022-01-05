#ifndef __ICHARACTER_HPP__
# define __ICHARACTER_HPP__

# include <string>
# include "AMateria.hpp"

class AMateria;

class ICharacter
{
	public:
		virtual std::string const & getName( void ) const = 0;
		virtual void equip( AMateria* m ) = 0;
		virtual void unequip( int idx ) = 0;
		virtual void use( int idx, ICharacter& target ) = 0;
		
	virtual ~ICharacter( void ) {}
};

#endif
