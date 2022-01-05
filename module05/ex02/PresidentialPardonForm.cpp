#include <string>

#include "Form.hpp"
#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm( void ) : Form("presidential pardon", 25, 5, "random citizen") {
	return ;
}

PresidentialPardonForm::PresidentialPardonForm( std::string target ) : Form("presidential pardon", 25, 5, target) {
	return ;
}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm& src ) : Form(src) {
	*this = src;
}

PresidentialPardonForm::~PresidentialPardonForm( void ) {
	return ;
}

void PresidentialPardonForm::execute( Bureaucrat const & executor ) const {
	if (canBeExecutedBy(executor) == true) {
		std::cout << this->getTarget() << " has been pardoned by Zafod Beeblebrox." << std::endl;
	}
	return ;
}

PresidentialPardonForm& PresidentialPardonForm::operator=( const PresidentialPardonForm& other ) {
	(void)other;
	return *this;
}
