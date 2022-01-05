#ifndef __ICE_HPP__
# define __ICE_HPP__

# include "AMateria.hpp"
# include "ICharacter.hpp"


class Ice : public AMateria
{
	public:
		AMateria* clone( void ) const;
		void use( ICharacter& target );

	Ice( void );
	~Ice( void );
	Ice( const Ice& src );

	Ice& operator=( const Ice& other );
};

#endif
