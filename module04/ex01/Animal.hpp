#ifndef __ANIMAL_HPP__
# define __ANIMAL_HPP__

# include "Brain.hpp"

# include <string>

class Animal
{
	protected:
		std::string	_type;

	public:
		virtual void makeSound( void ) const;

	std::string	getType( void ) const;
	virtual Brain* getBrain( void ) const;
	virtual void setBrain( Brain& brain );

	Animal( void );
	virtual ~Animal( void );
	Animal( std::string type );
	Animal( const Animal& src );

	virtual Animal& operator=( const Animal& other );
};

#endif
