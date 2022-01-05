#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

int main( void )
{
	Point a( -0.08, 3 );
	Point b( 8, -6 );
	Point c( 8 , 4 );
	Point d( 7, 3 );
	Point e( 8, 3 );

	bsp(a, b, c, d); // point d is located inside ABC (true)
	bsp(a, b, c, e); // point e is located on the edge of ABC (false)
	bsp(a, b, c, c); //	point c coincides with one of the vertices of ABC (false)
	std::cout << '\n';

	float x1 = 0;
	float x2 = 0 + 0.00390625;
	float x3 = 0 - 0.00390625;
	float y1 = 6;
	float y2 = 6 + 0.00390625;
	float y3 = 6 - 0.00390625;

	Point f( -4 , -2 );
	Point g( 4, -2 );
	Point h( x1, y1 );
	Point i1( x2, y1 );
	Point i2( x3, y1 );
	Point i3( x1, y2 );
	Point i4( x1, y3 );

	bsp(f, g, h, i1);	// point i1 is located outside ABC, just to the right of the top vertex. (false)
	bsp(f, g, h, i2);	// point i2 is located outside ABC, just to the left of the top vertex. (false)
	bsp(f, g, h, i3);	// point i3 is located outside ABC, just above the top vertex. (false)
	bsp(f, g, h, i4);	// point i1 is located inside ABC, just below the top vertex. (true)
	std::cout << '\n';
	
	return 0;
}
