#ifndef __AMATERIA_HPP__
# define __AMATERIA_HPP__

# include <string>

# include "ICharacter.hpp"

class ICharacter;

class AMateria
{
	protected:
		const std::string	_type;

	public:
		std::string const & getType( void ) const;

		virtual AMateria* clone( void ) const = 0;
		virtual void use( ICharacter& target );

	AMateria( void );
	AMateria( std::string const & type );
	virtual ~AMateria( void );
	AMateria( const AMateria& src );

	AMateria& operator=( const AMateria& other );
};

#endif
