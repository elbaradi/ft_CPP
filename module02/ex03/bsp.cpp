#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

static bool	is_point_same_side_of_line_as_vertex(Point const line_start, Point const line_end, Point const vertex, Point const point)
{
	/*
	Checking (without division) on what side point C is of line AB, and if point D is on the same side as point C.
	Formula is derived from the cross product (Xb - Xa) * (Yc - Ya) - (Yb - Ya) * (Xc - Xa).
	*/
     return ((((line_end.getX() - line_start.getX()) * (vertex.getY() - line_start.getY()) - (line_end.getY() - line_start.getY()) * (vertex.getX() - line_start.getX())) > 0) == (((line_end.getX() - line_start.getX()) * (point.getY() - line_start.getY()) - (line_end.getY() - line_start.getY()) * (point.getX() - line_start.getX())) > 0));
}

bool	bsp( Point const a, Point const b, Point const c, Point const point)
{
	if (a == b || a == c || b == c )
	{
		std::cout << "ERROR: ABC is not a fixed point triangle. [D" << point << "; A" << a << "; B" << b << "; C" << c << "]\n";
		return false;
	}
	if (a == point || b == point || c == point)	// Explicitly making sure points don't coincide, in which case ABC might not be a triangle of D has the same coordinates as one of the vertices.
	{
		std::cout << "FALSE: point D coincides with one of the vertices of triangle ABC. [D" << point << "; A" << a << "; B" << b << "; C" << c << "]\n";
		return false;
	}
	int i = 0;
	i += is_point_same_side_of_line_as_vertex(a, b, c, point);
	i += is_point_same_side_of_line_as_vertex(a, c, b, point);
	i += is_point_same_side_of_line_as_vertex(b, c, a, point);
	if (i == 3)
	{
		std::cout << "TRUE: point D is located inside triangle ABC. [D" << point << "; A" << a << "; B" << b << "; C" << c << "]\n";
		return true;
	}
	else
	{
		std::cout << "FALSE: point D is not located inside triangle ABC. [D" << point << "; A" << a << "; B" << b << "; C" << c << "]\n";
		return false;
	}
}
