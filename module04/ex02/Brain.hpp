#ifndef __BRAIN_HPP__
# define __BRAIN_HPP__

# include <string>

class Brain
{
	private:
		std::string	_ideas[100];

	public:
	
	std::string	getIdea( int i ) const;
	void	setIdea( int i, std::string idea );

	Brain( void );
	~Brain( void );
	Brain( const Brain& src );

	Brain& operator=( const Brain& other );
};

#endif
