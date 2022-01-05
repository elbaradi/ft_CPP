#ifndef __CAT_HPP__
# define __CAT_HPP__

# include "Animal.hpp"

class Cat : public Animal
{
	public:
		void makeSound( void ) const;

	Cat( void );
	~Cat( void );
	Cat( const Cat& src );

	Cat& operator=( const Cat& other );
};

#endif
