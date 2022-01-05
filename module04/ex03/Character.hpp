#ifndef __CHARACTER_HPP__
# define __CHARACTER_HPP__

# include "AMateria.hpp"
# include "ICharacter.hpp"

class Character : public ICharacter
{
	private:
		std::string const	_name;
		AMateria*			_slots[4];	

	public:
		std::string const & getName( void ) const;
		void equip( AMateria* m );
		void unequip( int idx );
		void use( int idx, ICharacter& target );
	
	Character( void );
	Character( std::string const & name );
	~Character( void );
	Character( const Character& src );

	Character& operator=( const Character& other );
};

#endif
