#include <iostream>
#include <string>
#include "Phonebook.hpp"

int	main() {
	Phonebook	phonebook;
	std::string	input;

	std::cout << "Welcome to my contact list!\n";
	do
	{
		std::cout << "Waiting for your instruction... Please enter ADD, SEARCH or EXIT.\n";
		std::getline(std::cin, input);
		if (std::cin.eof())
			break ;
		std::cout << std::endl;
		if (!input.compare("ADD"))
		{
			phonebook.findContactSpace()->addContact();
			phonebook.updateOldest();
			phonebook.updateSize();
		}
		else if (!input.compare("SEARCH"))
		{
			phonebook.printHeader();
			phonebook.getContacts();
			phonebook.printFooter();
			phonebook.promptFollowUp();
		}
		else if (!input.compare("EXIT"))
			break ;
		else
			std::cout << "Instruction \"" << input << "\" is unrecognized.\n";
		std::cout << std::endl;
	}
	while (true);
	return (0);
}
