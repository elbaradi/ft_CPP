#ifndef __DOG_HPP__
# define __DOG_HPP__

# include "Animal.hpp"

class Dog : public Animal
{
	public:
		void makeSound( void ) const;

	Dog( void );
	~Dog( void );
	Dog( const Dog& src );

	Dog& operator=( const Dog& other );
};

#endif
