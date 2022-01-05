#ifndef __CURE_HPP__
# define __CURE_HPP__

# include "AMateria.hpp"
# include "ICharacter.hpp"

class Cure : public AMateria
{
	public:
		AMateria* clone( void ) const;
		void use( ICharacter& target );
	
	Cure( void );
	~Cure( void );
	Cure( const Cure& src );

	Cure& operator=( const Cure& other );
};

#endif
