#ifndef __DOG_HPP__
# define __DOG_HPP__

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
	private:
		Brain* _brain;

	public:
		void makeSound( void ) const;

	Brain*	getBrain( void ) const;
	void	setBrain( Brain& brain );

	Dog( void );
	virtual ~Dog( void );
	Dog( const Dog& src );

	Dog& operator=( const Dog& other );
	Animal& operator=( const Animal& other );
};

#endif
