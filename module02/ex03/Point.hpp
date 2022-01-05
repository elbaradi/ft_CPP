#ifndef POINT_HPP
# define POINT_HPP

# include <iostream>
# include <Fixed.hpp>

class	Point
{
	private:
		Fixed const _x;
		Fixed const _y;

	public:
		const Fixed getX( void ) const;
		const Fixed getY( void ) const;

	Point( void );
	~Point( void );
	Point( const Point& src );
	Point ( const float x, const float y );

	const Point& operator=( const Point& rhs );
	bool operator==( const Point& rhs ) const;
};

std::ostream & operator<<(std::ostream & o, Point const & rhs);
bool	bsp( Point const a, Point const b, Point const c, Point const point);

#endif
