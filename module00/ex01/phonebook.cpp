#include "Phonebook.hpp"

Phonebook::Phonebook(void)
{
	setOldest(0);
	setSize(0);
	return ;
}

Phonebook::~Phonebook(void)
{
	return ;
}

int Phonebook::getOldest(void)
{
	return oldest;
}

void Phonebook::setOldest(int nbr)
{
	oldest = nbr;
}

int Phonebook::getSize(void)
{
	return size;
}

void Phonebook::setSize(int nbr)
{
	size = nbr;
}

void Phonebook::updateSize(void)
{
	if (getSize() < 8)
		setSize(getSize() + 1);
}

void Phonebook::updateOldest(void)
{
	if (getSize() < 8)
		return ;
	else if (getOldest() == 7)
		setOldest(0);
	else
		setOldest(getOldest() + 1);
}

Contact *Phonebook::getContact(int i)
{
	return &this->contacts[i];
}

void Phonebook::getContacts(void)
{
	int	size = getSize();

	for (int i = 0; i < size; i++)
		getContact(i)->printFormattedEntry(i);
}

Contact *Phonebook::findContactSpace(void)
{
	int size = getSize();

	if (size == 8)
		return getContact(getOldest());
	else
		return getContact(size);

}

void Phonebook::printHeader(void)
{
	std::cout << std::setfill('-');
	std::cout << '|' << std::setw(44);
	std::cout << '|' << std::endl;
	std::cout << std::setfill(' ');
	std::cout << '|' << std::setw(10) << "index ";
	std::cout << '|' << std::setw(10) << "name ";
	std::cout << '|' << std::setw(10) << "surname ";
	std::cout << '|' << std::setw(10) << "nickname ";
	std::cout << '|' << std::endl;
	std::cout << std::setfill('-');
	std::cout << '|' << std::setw(44);
	std::cout << '|' << std::endl;
	std::cout << std::setfill(' ');
}

void Phonebook::printFooter(void)
{
	std::cout << '|' << std::setfill('-') << std::setw(44);
	std::cout << '|' << std::endl << std::endl;
	std::cout << std::setfill(' ');
}

void Phonebook::promptFollowUp(void)
{
	std::string	input;
	
	if (getSize() > 0)
	{
		std::cout << "Enter the index of the contact you wish to look up. Otherwise enter anything else to continue.\n";
		getline(std::cin, input);
		if (std::cin.eof())
			exit (0);
		if (input.length() == 1 && input[0] >= '0' && input[0] <= '0' + getSize() - 1)
		{
			std::cout << std::endl;
			std::cout << "Details of contact #" << input[0] << ":\n";
			getContact(input[0] - '0')->printDetails();
		}
	}
}
