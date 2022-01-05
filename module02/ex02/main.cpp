#include <iostream>
#include "Fixed.hpp"

int main( void )
{
	Fixed a;
	Fixed const b( 10 );
	Fixed const c( 42.42f );
	Fixed const d( b );

	a = Fixed( 1234.4321f );

	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	std::cout << std::endl;

	Fixed const e ( a + b );
	std::cout << "e is " << e << std::endl;
	std::cout << std::endl;
	
	std::cout << "a + b is " << a + b << std::endl;
	std::cout << "a - b is " << a - b << std::endl;
	std::cout << "a * b is " << (a * b) << std::endl;
	std::cout << "a / b is " << (a / b) << std::endl;
	std::cout << "a < b is " << (a < b) << std::endl;
	std::cout << "a > b is " << (a > b) << std::endl;
	std::cout << "a <= b is " << (a <= b) << std::endl;
	std::cout << "a >= b is " << (a >= b) << std::endl;
	std::cout << "a == b is " << (a == b) << std::endl;
	std::cout << "a != b is " << (a != b) << std::endl;
	std::cout << std::endl;

	Fixed g;
	Fixed const h( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << g << std::endl;
	std::cout << ++g << std::endl;
	std::cout << g << std::endl;
	std::cout << g++ << std::endl;
	std::cout << g << std::endl;
	std::cout << h << std::endl;
	std::cout << Fixed::max( g, h ) << std::endl;
	std::cout << Fixed::min( g, h ) << std::endl;
	std::cout << std::endl;

	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;

	return 0;
}
