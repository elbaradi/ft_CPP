#include <iostream>
#include <string>
#include "Contact.hpp"

Contact::Contact(void)
{
	return ;
}

Contact::~Contact(void)
{
	return ;
}

void Contact::addContact(void)
{
	std::cout << "First name: ";
	std::getline(std::cin, this->firstName);
	if (std::cin.eof())
			exit (0);
	std::cout << "Last name: ";
	std::getline(std::cin, this->lastName);
	if (std::cin.eof())
			exit (0);
	std::cout << "Nickname: ";
	std::getline(std::cin, this->nickname);
	if (std::cin.eof())
			exit (0);
	std::cout << "Phone number: ";
	std::getline(std::cin, this->phoneNumber);
	if (std::cin.eof())
			exit (0);
	std::cout << "Darkest secret: ";
	std::getline(std::cin, this->darkestSecret);
	if (std::cin.eof())
			exit (0);
}

void Contact::printFormattedEntry(int index)
{
	std::cout << "|" << std::setw(10) << index << "|";
	if (this->firstName.length() <= 10)
		std::cout << std::setw(10) << this->firstName;
	else
		std::cout << this->firstName.substr(0, 9) + '.';
	if (this->lastName.length() <= 10)
			std::cout << "|" << std::setw(10) << this->lastName;
	else
		std::cout << "|" << this->lastName.substr(0, 9) << '.';
	if (this->nickname.length() <= 10)
		std::cout << "|" << std::setw(10) << this->nickname;
	else
		std::cout << "|" << this->nickname.substr(0, 9) << '.';
	std::cout << "|\n";
}

void Contact::printDetails(void)
{
	std::cout << "First name: " + this->firstName << std::endl;
	std::cout << "Last name: " + lastName << std::endl;
	std::cout << "Nickname: " + getNickname() << std::endl;
	std::cout << "Phone number: " + this->phoneNumber << '\n';
	std::cout << "Darkest secret: " + this->darkestSecret + "\n";
}
void Contact::setFirstName(void)
{
	std::getline(std::cin, this->firstName);
}

void Contact::setLastName(void)
{
	std::getline(std::cin, this->lastName);
}

void Contact::setNickname(void)
{
	std::getline(std::cin, this->nickname);
}

void Contact::setPhoneNumber(void)
{
	std::getline(std::cin, this->phoneNumber);
}

void Contact::setDarkestSecret(void)
{
	std::getline(std::cin, this->darkestSecret);
}

std::string Contact::getFirstName(void)
{
	return this->firstName;
}

std::string Contact::getLastName(void)
{
	return this->lastName;
}

std::string Contact::getNickname(void)
{
	return this->nickname;
}

std::string Contact::getPhoneNumber(void)
{
	return this->phoneNumber;
}

std::string Contact::getDarkestSecret(void)
{
	return this->darkestSecret;
}
