#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>
# include <iomanip>

class Contact
{
	private:
		std::string	firstName;
		std::string	lastName;
		std::string	nickname;
		std::string	phoneNumber;
		std::string	darkestSecret;

	public:
		void addContact(void);
		void printFormattedEntry(int index);
		void printDetails(void);
		void setFirstName(void);
		void setLastName(void);
		void setNickname(void);
		void setPhoneNumber(void);
		void setDarkestSecret(void);
		std::string getFirstName(void);
		std::string getLastName(void);
		std::string getNickname(void);
		std::string getPhoneNumber(void);
		std::string getDarkestSecret(void);

		Contact(void);
		~Contact(void);
};

#endif
