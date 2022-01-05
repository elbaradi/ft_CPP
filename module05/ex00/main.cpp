#include <iostream>

#include "Bureaucrat.hpp"

int main( void ) {
	Bureaucrat Abby("Abby");
	Bureaucrat Barney("Barney", 120);
	Bureaucrat Unnamed_1;
	Bureaucrat Unnamed_2(80);

	std::cout << Abby << Barney << Unnamed_1 << Unnamed_2 << std::endl;
	
	Bureaucrat copy = Barney;
	Barney.incrementGrade();
	copy.decrementGrade();
	std::cout << Barney << copy << std::endl;

	// These should all throw exceptions;

	try {
		Bureaucrat Cody("Cody", -20);
	} catch (std::exception & e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	
	try {
		Bureaucrat Dom("Dom", 200);
	} catch (std::exception & e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	Bureaucrat Egbert("Egbert", 150);
	std::cout << Egbert;
	try {
		Egbert.decrementGrade();
	} catch (std::exception & e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	Bureaucrat Feiko("Feiko", 1);
	std::cout << Feiko;
	try {
		Feiko.incrementGrade();
	} catch (std::exception & e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	return 0;
}
