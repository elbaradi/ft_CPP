#include <iostream>

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int main( void ) {
	Bureaucrat Abby("Abby", 40);
	Bureaucrat Barney("Barney", 146);
	Bureaucrat Chubbo("Chubbo", 138);

	Form *myForm = new ShrubberyCreationForm("meditation room");
	std::cout << *myForm << std::endl;
	
	Chubbo.executeForm(*myForm);
	std::cout << std::endl;

	try {
		Barney.signForm(*myForm);
	} catch(const std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	std::cout << std::endl;
	
	Chubbo.signForm(*myForm);
	Chubbo.executeForm(*myForm);
	Abby.executeForm(*myForm);
	std::cout << std::endl;

	delete myForm;
	std::cout << std::endl;

	Bureaucrat Dickey("Dickey", 72);
	myForm = new RobotomyRequestForm("Michiel de Rooij");
	std::cout << *myForm << std::endl;

	try {
		Chubbo.signForm(*myForm);
	} catch(const std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	Dickey.signForm(*myForm);
	myForm->execute(Dickey);
	myForm->execute(Abby);

	delete myForm;
	std::cout << std::endl;

	Bureaucrat Earhardt("Earhardt", 25);
	Bureaucrat Folsom("Folsom", 5);
	myForm = new PresidentialPardonForm("Adriaan van Bassie en Adriaan");
	std::cout << *myForm << std::endl;

	try {
		Abby.signForm(*myForm);
	} catch(const std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	Earhardt.signForm(*myForm);
	Earhardt.executeForm(*myForm);
	Folsom.executeForm(*myForm);

	delete myForm;
	std::cout << std::endl;

	return 0;
}
