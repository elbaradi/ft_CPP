#ifndef __CAT_HPP__
# define __CAT_HPP__

# include <string>

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
	private:
		Brain*	_brain;

	public:
		void makeSound( void ) const;

	std::string	getType( void ) const;
	Brain*	getBrain( void ) const;
	void	setBrain( Brain& brain );

	Cat( void );
	virtual ~Cat( void );
	Cat( const Cat& src );

	Cat& operator=( const Cat& other );
	Animal& operator=( const Animal& other );
};

#endif
