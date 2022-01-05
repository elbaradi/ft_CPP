#ifndef __WRONGANIMAL_HPP__
# define __WRONGANIMAL_HPP__

# include <string>

class WrongAnimal
{
	protected:
		std::string	_type;

	public:
		void makeSound( void ) const;

	std::string	getType( void ) const;

	WrongAnimal( void );
	virtual ~WrongAnimal( void );
	WrongAnimal( std::string type );
	WrongAnimal( const WrongAnimal& src );

	WrongAnimal& operator=( const WrongAnimal& other );
};

#endif
