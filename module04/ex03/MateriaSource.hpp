#ifndef __MATERIASOURCE_HPP__
# define __MATERIASOURCE_HPP__

# include <string>

# include "AMateria.hpp"
# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	private:
		AMateria	*_source[4];

	public:
		void learnMateria( AMateria* );
    	AMateria* createMateria( std::string const & type );

	MateriaSource( void );
	~MateriaSource( void );
	MateriaSource( const MateriaSource& src );

	MateriaSource& operator=( const MateriaSource& other );
};

#endif
