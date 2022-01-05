#include <iostream>
#include "Fixed.hpp"

const int	Fixed::_fbits = 8;

Fixed::Fixed( void ) : _fvalue(0)
{
	std::cout << "Default constructor called.\n";
	return ;
}

Fixed::~Fixed( void )
{
	std::cout << "Destructor called.\n";
	return ;
}

Fixed::Fixed( const Fixed & src )
{
	std::cout << "Copy constructor called.\n";
	*this = src;
}

Fixed& Fixed::operator=( const Fixed& rhs )
{
	std::cout << "Assignation operator called.\n";
	if (this != &rhs)
		this->_fvalue = rhs.getRawBits();
	return *this;
}

int		Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called.\n";
	return this->_fvalue;
}

void	Fixed::setRawBits( const int raw )
{
	std::cout << "setRawBits member function called.\n";
	this->_fvalue = raw;
}
