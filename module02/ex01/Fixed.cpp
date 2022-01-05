#include <cmath>
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

Fixed::Fixed ( const int nbr ) : _fvalue(0)
{
	std::cout << "Int constructor called.\n";
	this->_fvalue = nbr << Fixed::_fbits;
	return;
}

Fixed::Fixed ( const float nbr ) : _fvalue(0)
{
	std::cout << "Float constructor called.\n";
	this->_fvalue = roundf(nbr * (1 << Fixed::_fbits));
	return;
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
		this->_fvalue = rhs._fvalue;
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

int		Fixed::toInt( void ) const
{
	int	nbr;
	
	nbr = this->_fvalue >> Fixed::_fbits;
	if (isBitSet(this->_fvalue, Fixed::_fbits))
		nbr += 1;
	return nbr;
}

float	Fixed::toFloat( void ) const
{
	float nbr;
	
	nbr = (float)this->_fvalue / (float)(1 << Fixed::_fbits);
	return nbr;
}

std::ostream & operator<<(std::ostream & o, Fixed const & rhs)
{
	o << rhs.toFloat();
	return o;
}

int isBitSet(int n, int k)
{
    if ((n >> (k - 1)) & 1)
        return 1;
    else
        return 0;
}
