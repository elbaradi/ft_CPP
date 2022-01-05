#include <iostream>

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main( void ) {
	Bureaucrat Abby("Abby", 40);
	Bureaucrat Barney("Barney", 120);

	Form myForm("TX009", 120, 120);
	Form firstCopy("First copy of TX009", myForm);

	std::cout << myForm << firstCopy;

	Barney.signForm(myForm);	//
	Abby.signForm(myForm);		// Abby won't be able to sign myForm as it's already signed.
	std::cout << std::endl;

	Form secondCopy("Second copy of TX009", myForm);

	std::cout << secondCopy;	// Confirm that copy copies the sign status of the form.
	secondCopy.beSigned(Abby);	// Abby won't be able to sign as copy is also signed.
	std::cout << std::endl;

	Form anotherForm("USD-C82", 41, 130);

	std::cout << anotherForm;
	anotherForm.beSigned(Barney);	// Barney doesn't meet the requirements to sign this form.
	Barney.signForm(anotherForm);	//
	anotherForm.beSigned(Abby);		// Abby does meet the requirements to sign this form.
	anotherForm.beSigned(Abby);
	std::cout << std::endl;

	// Invalid forms that will throw exceptions when being created:
	try {
		Form invalidForm("EXECUTIVE ORDER", 10, 0);
	} catch (std::exception & e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	try {
		Form invalidForm("redundant paperwork", 151, 150);
	} catch (std::exception & e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	return 0;
}
