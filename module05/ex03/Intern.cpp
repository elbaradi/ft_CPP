#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

#define NUMBER_OF_FORM_TYPES 3

Intern::PTR	Intern::_pmf[NUMBER_OF_FORM_TYPES] = { &Intern::_makeShrubberyCreationForm, &Intern::_makeRobotomyRequestForm , &Intern::_makePresidentialPardonForm };
const std::string Intern::_formTypes[NUMBER_OF_FORM_TYPES] = {"shrubbery creation", "robotomy request", "presidential pardon"};

Intern::Intern( void ) {
	return ;
}

Intern::Intern( const Intern& src ) {
	*this = src;
}

Intern::~Intern( void ) {
	return ;
}

Form*	Intern::_makeShrubberyCreationForm( std::string target ) const {
	return new ShrubberyCreationForm(target);
}

Form*	Intern::_makeRobotomyRequestForm( std::string target ) const {
	return new RobotomyRequestForm(target);
}

Form*	Intern::_makePresidentialPardonForm( std::string target ) const {
	return new PresidentialPardonForm(target);
}

Form* Intern::makeForm( const std::string type, const std::string target ) const {
	for (int i = 0; i < NUMBER_OF_FORM_TYPES ; i++) {
		if (type == _formTypes[i]) {
			std::cout << "Intern makes " << type << std::endl;
			return (this->*_pmf[i])(target);
		}
	}
	std::cout << "Intern can't make \'" << type << "\', as it's an invalid form type" << std::endl;
	return NULL;
}

Intern& Intern::operator=( const Intern& other ) {
	(void)other;
	return *this;
}
