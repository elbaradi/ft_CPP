#ifndef __WRONGCAT_HPP__
# define __WRONGCAT_HPP__

# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public:
		void makeSound( void ) const;
	
	WrongCat( void );
	~WrongCat( void );
	WrongCat( const WrongCat& src );

	WrongCat& operator=( const WrongCat& other );
};

#endif
