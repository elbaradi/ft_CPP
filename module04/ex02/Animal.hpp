#ifndef __ANIMAL_HPP__
# define __ANIMAL_HPP__

# include "Brain.hpp"

# include <string>

class Animal
{
	protected:
		std::string	_type;

	Animal( void );
	Animal( std::string type );
	Animal( const Animal& src );

	public:
		virtual void makeSound( void ) const = 0;

	virtual std::string	getType( void ) const = 0;
	virtual Brain* getBrain( void ) const = 0;
	virtual void	setBrain( Brain& brain ) = 0;

	virtual ~Animal( void );

	virtual Animal& operator=( const Animal& other );
};

#endif
