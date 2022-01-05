#include "ClassContact.hpp"
#include <string>

void	Contact::setFirstName(std::string s) {
			first_name = s;
}

void	Contact::setLastName(std::string s) {
			last_name = s;
}

void	Contact::setNickname(std::string s) {
			nickname = s;
}

void	Contact::setLogin(std::string s) {
			login = s;
}

void	Contact::setPostalAddress(std::string s) {
			postal_address = s;
}

void	Contact::setEmailAddress(std::string s) {
			email_address = s;
}

void	Contact::setPhoneNumber(std::string s) {
			phone_number = s;
}

void	Contact::setBirthdayDate(std::string s) {
			birthday_date = s;
}

void	Contact::setFavoriteMeal(std::string s) {
			favorite_meal = s;
}

void	Contact::setUnderwearColor(std::string s) {
			underwear_color = s;
}

void	Contact::setDarkestSecret(std::string s) {
			darkest_secret = s;
}

void	Contact::setNext(Contact c) {
			next = c;
}

