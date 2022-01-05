#include <string>
#include <iostream>

#include "Brain.hpp"

Brain::Brain( void ) {
	std::cout << "Brain default constructor called\n";
}

Brain::~Brain( void ) {
	std::cout << "Brain destructor called\n";
}

Brain::Brain( const Brain& src ) {
	*this = src;
}

std::string	Brain::getIdea( int i ) const
{
	if (i < 0 || i >= 100)
		return NULL;
	else
		return this->_ideas[i];
}

void	Brain::setIdea( int i, std::string idea )
{
	if (i < 0 || i >= 100)
		return ;
	else
		this->_ideas[i] = idea;
}

Brain& Brain::operator=( const Brain& other ) {
	if (this != &other)
	{
		for (int i = 0; i < 100; i++)
			this->_ideas[i] = other._ideas[i];
	}
	return *this;
}
