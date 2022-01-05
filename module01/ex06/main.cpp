#include <iostream>
#include <string>
#include "Karen.hpp"

int	main(int argc, char **argv)
{
	Karen bot;
	if (argc == 2)
	{
		std::string	input(argv[1]);
		bot.complain(input);
	}
	return (0);
}
