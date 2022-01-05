#include <string>

#include "Form.hpp"

Form::Form( void ) : _name("Unnamed form"), _gradeRequiredToSign(1), _gradeRequiredToExecute(1), _target("unidentified target"), _isSigned(0) {
	return ;
}

Form::Form( std::string name, int gradeRequiredToSign, int gradeRequiredToExecute ) : _name(name), _gradeRequiredToSign(gradeRequiredToSign), _gradeRequiredToExecute(gradeRequiredToExecute), _target("unidentified target"), _isSigned(0) {
	if (gradeRequiredToSign < 1 || gradeRequiredToExecute < 1)
		throw Form::GradeTooHighException();
	else if (gradeRequiredToSign > 150 || gradeRequiredToExecute > 150)
		throw Form::GradeTooLowException();
}

Form::Form( std::string name, int gradeRequiredToSign, int gradeRequiredToExecute, std::string target ) : _name(name), _gradeRequiredToSign(gradeRequiredToSign), _gradeRequiredToExecute(gradeRequiredToExecute), _target(target), _isSigned(0) {
	if (gradeRequiredToSign < 1 || gradeRequiredToExecute < 1)
		throw Form::GradeTooHighException();
	else if (gradeRequiredToSign > 150 || gradeRequiredToExecute > 150)
		throw Form::GradeTooLowException();
}

Form::~Form( void ) {
	return ;
}

Form::Form( const Form& src ) : _name(src.getName()), _gradeRequiredToSign(src.getGradeRequiredToSign()), _gradeRequiredToExecute(src.getGradeRequiredToExecute()), _target(src.getTarget()) {
	*this = src;
}

Form::Form( std::string name, const Form& src ) : _name(name), _gradeRequiredToSign(src.getGradeRequiredToSign()), _gradeRequiredToExecute(src.getGradeRequiredToExecute()), _target(src.getTarget()) {
	*this = src;
}

void Form::beSigned( const Bureaucrat& signer ) {
	try {
		if (this->_isSigned == true)
			throw Form::AlreadySignedException();
		else if (signer.getGrade() > this->_gradeRequiredToSign)
			throw Form::GradeTooLowException();
	} catch (std::exception & e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
		std::cout << signer.getName() << " could not sign " << this->_name << std::endl;
		return ;
	}
	std::cout << signer.getName() << " signs " << this->_name << ".\n";
	this->_isSigned = true;
}

bool Form::canBeExecutedBy( Bureaucrat const & executor ) const {
	try {
		if (this->_isSigned == false)
			throw Form::UnsignedException();
		else if (this->_gradeRequiredToExecute < executor.getGrade())
			throw Form::UnauthorizedException();
	} catch (std::exception & e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
		std::cout << executor.getName() << " could not execute " << this->_name << std::endl;
		return false;
	}
	std::cout << executor.getName() << " executes " << this->_name << std::endl;
	return true;
}

const std::string& Form::getName( void ) const {
	return this->_name;
}

int Form::getGradeRequiredToSign( void ) const {
	return this->_gradeRequiredToSign;
}

int Form::getGradeRequiredToExecute( void ) const {
	return this->_gradeRequiredToExecute;
}

const std::string& Form::getTarget( void ) const {
	return this->_target;
}

int Form::getIsSignedStatus( void ) const {
	return this->_isSigned;
}

Form& Form::operator=( const Form& other ) {
	if (this != &other)
	{
		this->_isSigned = other._isSigned;
	}
	return *this;
}

const char* Form::GradeTooHighException::what() const throw() {
	return "grade required to sign or required to execute too high";
}

const char* Form::GradeTooLowException::what() const throw() {
	return "grade required to sign or required to execute too low";
}

const char* Form::AlreadySignedException::what() const throw() {
	return "form is already signed";
}

const char* Form::UnsignedException::what() const throw() {
	return "form has not been signed";
}

const char* Form::UnauthorizedException::what() const throw() {
	return "no authorization to execute this form";
}

std::ostream & operator<<(std::ostream & o, Form const & rhs) {
	o << rhs.getName() << " with target " << rhs.getTarget();
	if (rhs.getIsSignedStatus() == true)
		o << " has been signed.\n";
	else
		o << " has not been signed.\n";
	o << "Grade required to sign: " << rhs.getGradeRequiredToSign() << "\n";
	o << "Grade required to execute: " << rhs.getGradeRequiredToExecute() << "\n";

	return o;
}
