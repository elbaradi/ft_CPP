#ifndef __ANIMAL_HPP__
# define __ANIMAL_HPP__

# include <string>

class Animal
{
	protected:
		std::string	_type; // preferably I'd make this variable a static const, and create a differently-named static const in Animal's child classes.

	public:
		virtual void makeSound( void ) const;

	std::string	getType( void ) const;

	Animal( void );
	virtual ~Animal( void );
	Animal( std::string type );
	Animal( const Animal& src );

	Animal& operator=( const Animal& other );
};

#endif
