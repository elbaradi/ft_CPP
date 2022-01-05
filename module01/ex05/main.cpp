#include <iostream>
#include <string>
#include "Karen.hpp"

int	main() {
	Karen		bot;
	std::string	input;

	std::cout << "Welcome to my messagebot!\n";
	while (true)
	{
		std::cout << "\nWaiting for your instruction... Please enter DEBUG, INFO, WARNING or ERROR.\n";
		std::getline(std::cin, input);
		if (std::cin.eof())
			break ;
		std::cout << std::endl;
		bot.complain(input);
	}
	return (0);
}
