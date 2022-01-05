#include <cstdlib>
#include <ctime>
#include <string>

#include "Form.hpp"
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm( void ) : Form("robotomy request", 72, 45, "random citizen") {
	return ;
}

RobotomyRequestForm::RobotomyRequestForm( std::string target ) : Form("robotomy request", 72, 45, target) {
	return ;
}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm& src ) : Form(src) {
	*this = src;
}

RobotomyRequestForm::~RobotomyRequestForm( void ) {
	return ;
}

void RobotomyRequestForm::execute( Bureaucrat const & executor ) const {
	if (canBeExecutedBy(executor) == true) {
		std::cout << "Drill activated." << std::endl;
		srand(time(NULL));
		if (rand() % 2)
			std::cout << getTarget() << " has been robotomized successfully" << std::endl;
		else
			std::cout << "... it's a failure" << std::endl;	
	}
	return ;
}

RobotomyRequestForm& RobotomyRequestForm::operator=( const RobotomyRequestForm& other ) {
	(void)other;
	return *this;
}
