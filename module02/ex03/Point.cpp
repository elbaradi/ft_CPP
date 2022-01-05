#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

Point::Point( void ) : _x(0), _y(0)
{
	return ;
}

Point::~Point( void )
{
	return ;
}

//Initializing x and y through the initializer list as theyre constants, meaning the asignation operator overload won't work.
Point::Point( const Point& src ) : _x(src._x), _y(src._y)
{
	return ;
}

Point::Point ( const float x, const float y ) : _x(x), _y(y)
{
	return ;
}

const Fixed Point::getX( void ) const
{
	return this->_x;
}

const Fixed Point::getY( void ) const
{
	return this->_y;
}

const Point& Point::operator=( const Point& rhs )
{
	// _x and _y are constants, so this assignation operator overload does effectively nothing;
	(void)rhs;
	return *this;
}

bool Point::operator==( const Point& rhs ) const
{
	return (this->_x == rhs._x && this->_y == rhs._y);
}

std::ostream & operator<<(std::ostream & o, Point const & rhs)
{
	o << '(' << rhs.getX() << "," << rhs.getY() << ')';
	return o;
}
