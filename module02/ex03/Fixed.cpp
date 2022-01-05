#include <cmath>
#include <iostream>
#include "Fixed.hpp"

const int	Fixed::_fbits = 8;

Fixed::Fixed( void ) : _fvalue(0)
{
	return ;
}

Fixed::~Fixed( void )
{
	return ;
}

Fixed::Fixed ( const int nbr ) : _fvalue(0)
{
	this->_fvalue = nbr << Fixed::_fbits;
	return;
}

Fixed::Fixed ( const float nbr ) : _fvalue(0)
{
	this->_fvalue = roundf(nbr * (1 << Fixed::_fbits));
	return;
}

Fixed::Fixed( const Fixed & src )
{
	*this = src;
}

Fixed& Fixed::operator=( const Fixed& rhs )
{
	if (this != &rhs)
		this->_fvalue = rhs.getRawBits();
	return *this;
}

bool Fixed::operator>( const Fixed& rhs ) const
{
	return this->_fvalue > rhs.getRawBits();
}

bool Fixed::operator<( const Fixed& rhs ) const
{
	return this->_fvalue < rhs.getRawBits();
}

bool Fixed::operator>=( const Fixed& rhs ) const
{
	return this->_fvalue >= rhs.getRawBits();
}

bool Fixed::operator<=( const Fixed& rhs ) const
{
	return this->_fvalue <= rhs.getRawBits();
}

bool Fixed::operator==( const Fixed& rhs ) const
{
	return this->_fvalue == rhs.getRawBits();
}

bool Fixed::operator!=( const Fixed& rhs ) const
{
	return this->_fvalue != rhs.getRawBits();
}

Fixed Fixed::operator+( const Fixed& rhs ) const
{
	Fixed fp;

	fp.setRawBits(this->_fvalue + rhs.getRawBits());

	return fp;
}

Fixed Fixed::operator-( const Fixed& rhs ) const
{
	Fixed fp;

	fp.setRawBits(this->_fvalue - rhs.getRawBits());

	return fp;
}

Fixed Fixed::operator*( const Fixed& rhs ) const
{
	Fixed fp;

	fp.setRawBits((this->_fvalue * rhs.getRawBits()) / (1 << Fixed::_fbits));

	return fp;
}

Fixed Fixed::operator/( const Fixed& rhs ) const
{
	Fixed fp;

	fp.setRawBits((this->_fvalue << Fixed::_fbits) / rhs.getRawBits());

	return fp;
}

Fixed& Fixed::operator++( void )
{
	this->setRawBits(this->_fvalue + 1);
	return *this;
}

Fixed Fixed::operator++( int )
{
	Fixed tmp(*this);

	this->setRawBits(this->_fvalue + 1);
	return tmp;
}

Fixed& Fixed::operator--( void )
{
	this->setRawBits(this->_fvalue - 1);
	return *this;
}

Fixed Fixed::operator--( int )
{
	Fixed tmp(*this);

	this->setRawBits(this->_fvalue - 1);
	return tmp;
}

int		Fixed::getRawBits( void ) const
{
	return this->_fvalue;
}

void	Fixed::setRawBits( const int raw )
{
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

Fixed& Fixed::min( Fixed& fp_1, Fixed& fp_2 )
{
	if (fp_1 <= fp_2)
		return fp_1;
	else
		return fp_2;
}

Fixed& Fixed::max( Fixed& fp_1, Fixed& fp_2 )
{
	if (fp_1 >= fp_2)
		return fp_1;
	else
		return fp_2;
}

const Fixed& Fixed::min( const Fixed& fp_1, const Fixed& fp_2 )
{
	if (fp_1 <= fp_2)
		return fp_1;
	else
		return fp_2;
}

const Fixed& Fixed::max( const Fixed& fp_1, const Fixed& fp_2 )
{
	if (fp_1 >= fp_2)
		return fp_1;
	else
		return fp_2;
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
