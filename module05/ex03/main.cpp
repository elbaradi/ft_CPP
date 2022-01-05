#include <iostream>

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int main( void ) {
	Bureaucrat Abby("Abby", 40);

	Intern Johnny;

	Form *myForm = Johnny.makeForm("kladblaadje", "Herman");
	std::cout << myForm << std::endl;

	myForm = Johnny.makeForm("robotomy reques", "Indigo");
	std::cout << myForm << std::endl;

	myForm = Johnny.makeForm("robotomy request ", "Paolo");
	std::cout << myForm << std::endl;


	myForm = Johnny.makeForm("robotomy request", "Gustaff");
	std::cout << std::endl << myForm << std::endl << *myForm << std::endl;

	Abby.signForm(*myForm);
	Abby.executeForm(*myForm);

	delete myForm;
	std::cout << std::endl;

	return 0;
}
