#include <iostream>
#include <string>

#include "iter.hpp"

int main( void ) {
	{
		int array[] = {
			1,
			1,
			2,
			3,
			5,
			8,
			13,
			21
		};
	
		::iter(array, 8, ::printElement);
	}

	std::cout << std::endl;

	{
		std::string array[] = {
			"Heeeeeee…",
			"   …eeeeeeeey",
			"Hey--",
			"Baby",
			"",
			"Ooh",
			"Aaah",
			"",
			"I wanna knooooo-oo-o-o-ow",
			"If you be my levenspartner"
		};
	
		::iter(array, 10, ::printElement);
	}
	
	return 0;
}
