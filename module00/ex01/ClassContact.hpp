#ifndef CLASSCONTACT_HPP
# define CLASSCONTACT_HPP
# include <string>

class	Contact {
	private:
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		std::string	login;
		std::string	postal_address;
		std::string	email_address;
		std::string	phone_number;
		std::string	birthday_date;
		std::string	favorite_meal;
		std::string	underwear_color;
		std::string	darkest_secret;
		Contact	next;
	
	public:
		void	setFirstName(std::string s);
		void	setLastName(std::string s);
		void	setNickname(std::string s);
		void	setLogin(std::string s);
		void	setPostalAddress(std::string s);
		void	setEmailAddress(std::string s);
		void	setPhoneNumber(std::string s);
		void	setBirthdayDate(std::string s);
		void	setFavoriteMeal(std::string s);
		void	setUnderwearColor(std::string s);
		void	setDarkestSecret(std::string s);
		void	setNext(Contact next);
		std::string	getFirstName();
		std::string	getLastName();
		std::string	getNickname();
		Contact	getNext();
};

#endif
